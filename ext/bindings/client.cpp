#include "rice/Data_Type.hpp"
#include "rice/Constructor.hpp"
#include <pulsar/Client.h>
#include <ruby/thread.h>

#include "client.hpp"
#include "util.hpp"

namespace pulsar_rb {

Client::Client(Rice::String service_url) : _client(service_url.str()) {
}

typedef struct {
  pulsar::Client& client;
  const Rice::String& topic;
  const pulsar::ProducerConfiguration& config;
  pulsar::Producer producer;
  pulsar::Result result;
} client_create_producer_task;

void* client_create_producer_worker(void* taskPtr) {
  client_create_producer_task& task = *(client_create_producer_task*)taskPtr;
  task.result = task.client.createProducer(task.topic.str(), task.config, task.producer);
  return nullptr;
}

Producer::ptr Client::create_producer(Rice::String topic, const ProducerConfiguration& config) {
  client_create_producer_task task = { _client, topic, config };
  rb_thread_call_without_gvl(&client_create_producer_worker, &task, RUBY_UBF_IO, nullptr);
  CheckResult(task.result);
  return Producer::ptr(new Producer(task.producer));
}

typedef struct {
  pulsar::Client& client;
  const Rice::String& topic;
  const Rice::String& subscriptionName;
  pulsar::ConsumerConfiguration& config;
  pulsar::Consumer consumer;
  pulsar::Result result;
} client_subscribe_task;

void* client_subscribe_worker(void* taskPtr) {
  client_subscribe_task& task = *(client_subscribe_task*)taskPtr;
  task.result = task.client.subscribe(task.topic.str(), task.subscriptionName.str(), task.config, task.consumer);
  return nullptr;
}

Consumer::ptr Client::subscribe(Rice::String topic, Rice::String subscriptionName) {
  pulsar::ConsumerConfiguration config; // TODO allow providing as argument
  client_subscribe_task task = { _client, topic, subscriptionName, config };
  rb_thread_call_without_gvl(&client_subscribe_worker, &task, RUBY_UBF_IO, nullptr);
  CheckResult(task.result);
  return Consumer::ptr(new Consumer(task.consumer));
}

typedef struct {
  pulsar::Client& client;
  pulsar::Result result;
} client_close_task;

void* client_close_worker(void* taskPtr) {
  client_close_task& task = *(client_close_task*)taskPtr;
  task.result = task.client.close();
  return nullptr;
}

void Client::close() {
  client_close_task task = { _client };
  rb_thread_call_without_gvl(&client_close_worker, &task, RUBY_UBF_IO, nullptr);
  CheckResult(task.result);
}

}

using namespace Rice;

void bind_client(Module& module) {
  define_class_under<pulsar_rb::Client>(module, "Client")
    .define_constructor(Constructor<pulsar_rb::Client, const std::string&>())
    .define_method("_create_producer", &pulsar_rb::Client::create_producer)
    .define_method("subscribe", &pulsar_rb::Client::subscribe)
    .define_method("close", &pulsar_rb::Client::close)
    ;
}
