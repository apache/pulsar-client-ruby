#include "rice/Data_Type.hpp"
#include "rice/Constructor.hpp"
#include <pulsar/Client.h>
#include <ruby/thread.h>

#include "producer.hpp"
#include "util.hpp"

namespace pulsar_rb {

typedef struct {
  pulsar::Producer& producer;
  const pulsar::Message& message;
  pulsar::Result result;
} producer_send_task;

void* producer_send_worker(void* taskPtr) {
  producer_send_task& task = *(producer_send_task*)taskPtr;
  task.result = task.producer.send(task.message);
  return nullptr;
}

void Producer::send(const Message& message) {
  producer_send_task task = { _producer, message._msg };
  rb_thread_call_without_gvl(&producer_send_worker, &task, RUBY_UBF_IO, nullptr);
  CheckResult(task.result);
}

}

using namespace Rice;

void bind_producer(Module& module) {
  define_class_under<pulsar_rb::Producer>(module, "Producer")
    .define_constructor(Constructor<pulsar_rb::Producer>())
    .define_method("_send", &pulsar_rb::Producer::send)
    ;
}
