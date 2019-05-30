#ifndef __PULSAR_RUBY_CLIENT_CLIENT_HPP
#define __PULSAR_RUBY_CLIENT_CLIENT_HPP

#include "rice/Module.hpp"
#include "rice/String.hpp"
#include "rice/Data_Object.hpp"
#include <pulsar/Client.h>

#include "producer.hpp"
#include "consumer.hpp"

namespace pulsar_rb {
  class Client {
  public:
    pulsar::Client _client;
    Client(Rice::String service_url);

    Producer::ptr create_producer(Rice::String topic);
    Consumer::ptr subscribe(Rice::String topic, Rice::String subscriptionName);
    void close();

    typedef Rice::Data_Object<Client> ptr;
  };
};

void bind_client(Rice::Module &module);

#endif
