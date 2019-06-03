#ifndef __PULSAR_RUBY_CLIENT_PRODUCER_HPP
#define __PULSAR_RUBY_CLIENT_PRODUCER_HPP

#include "rice/Module.hpp"
#include "rice/Data_Object.hpp"
#include <pulsar/Client.h>

#include "message.hpp"

namespace pulsar_rb {
  class Producer {
  public:
    pulsar::Producer _producer;
    Producer() {};
    Producer(const pulsar::Producer& producer) : _producer(producer) {}

    void send(const Message& message);

    typedef Rice::Data_Object<Producer> ptr;
  };
};

void bind_producer(Rice::Module& module);

#endif
