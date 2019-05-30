#include "rice/Data_Type.hpp"
#include "rice/Constructor.hpp"
#include <pulsar/Client.h>
#include <ruby/thread.h>

#include "consumer.hpp"
#include "util.hpp"

namespace pulsar_rb {

typedef struct {
  pulsar::Consumer& consumer;
  pulsar::Message message;
  pulsar::Result result;
} consumer_receive_job;

void* consumer_receive_nogvl(void* jobPtr) {
  consumer_receive_job& job = *(consumer_receive_job*)jobPtr;
  job.result = job.consumer.receive(job.message);
  return nullptr;
}

pulsar::Message consumer_receive(pulsar::Consumer& consumer) {
  consumer_receive_job job = { consumer };
  rb_thread_call_without_gvl(&consumer_receive_nogvl, &job, RUBY_UBF_IO, nullptr);
  CheckResult(job.result);
  return job.message;
}

Message::ptr Consumer::receive() {
  pulsar::Message message = consumer_receive(_consumer);
  return Message::ptr(new Message(message));
}

void Consumer::acknowledge(const Message& message) {
  _consumer.acknowledgeAsync(message._msg, nullptr);
}

void Consumer::negative_acknowledge(const Message& message) {
  // error: no member named 'negativeAcknowledge' in 'pulsar::Consumer'
  // TODO maybe my libpulsar is older than the source I was looking at?
  //_consumer.negativeAcknowledge(message._msg);
}

}

using namespace Rice;

void bind_consumer(Module &module) {
  define_class_under<pulsar_rb::Consumer>(module, "Consumer")
    .define_constructor(Constructor<pulsar_rb::Consumer>())
    .define_method("receive", &pulsar_rb::Consumer::receive)
    .define_method("acknowledge", &pulsar_rb::Consumer::acknowledge)
    .define_method("negative_acknowledge", &pulsar_rb::Consumer::negative_acknowledge)
    ;
}
