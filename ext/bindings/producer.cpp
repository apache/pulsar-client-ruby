#include "rice/Data_Type.hpp"
#include "rice/Constructor.hpp"
#include <pulsar/Client.h>
#include <ruby/thread.h>

#include "producer.hpp"
#include "util.hpp"

namespace pulsar_rb {

typedef struct {
  pulsar::Producer& producer;
  pulsar::Message& message;
  pulsar::Result result;
} producer_send_task;

void* producer_send_worker(void* taskPtr) {
  producer_send_task& task = *(producer_send_task*)taskPtr;
  task.result = task.producer.send(task.message);
  return nullptr;
}

void Producer::send(const std::string& data /* TODO should be Message::ptr message */) {
  /* TODO should be: auto _msg = message->_msg; */
  pulsar::MessageBuilder mb;
  mb.setContent(data);
  auto _msg = mb.build();
  producer_send_task task = { _producer, _msg };
  rb_thread_call_without_gvl(&producer_send_worker, &task, RUBY_UBF_IO, nullptr);
  CheckResult(task.result);
}

}

using namespace Rice;

void bind_producer(Module& module) {
  define_class_under<pulsar_rb::Producer>(module, "Producer")
    .define_constructor(Constructor<pulsar_rb::Producer>())
    .define_method("send", &pulsar_rb::Producer::send)
    ;
}
