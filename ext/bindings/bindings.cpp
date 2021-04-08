#include "rice/Module.hpp"

#include "message.hpp"
#include "producer.hpp"
#include "consumer.hpp"
#include "client.hpp"
#include "util.hpp"

using namespace Rice;

extern "C"
void Init_bindings()
{
  Module rb_mPulsar = define_module("Pulsar");
  bind_errors(rb_mPulsar);
  bind_message(rb_mPulsar);
  bind_producer(rb_mPulsar);
  bind_consumer(rb_mPulsar);
  bind_client(rb_mPulsar);
}
