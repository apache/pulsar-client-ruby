#ifndef __PULSAR_RUBY_CLIENT_CLIENT_HPP
#define __PULSAR_RUBY_CLIENT_CLIENT_HPP

#include "rice/Module.hpp"
#include "rice/String.hpp"
#include "rice/Data_Object.hpp"
#include <pulsar/Client.h>

#include "producer.hpp"
#include "consumer.hpp"

namespace pulsar_rb {
  // direct typedef instead of wrapping because implementations don't need any
  // wrapping. but still re-namespaced for consistency
  typedef pulsar::ClientConfiguration ClientConfiguration;

  class Client {
  public:
    pulsar::Client _client;
    Client(Rice::String service_url, const ClientConfiguration& config);

    Producer::ptr create_producer(Rice::String topic, const ProducerConfiguration& config);
    Consumer::ptr subscribe(Rice::String topic, Rice::String subscriptionName, const ConsumerConfiguration& config);
    void close();

    typedef Rice::Data_Object<Client> ptr;
  };
};

void bind_client(Rice::Module &module);

#endif
