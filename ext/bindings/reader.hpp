#ifndef __PULSAR_RUBY_CLIENT_READER_HPP
#define __PULSAR_RUBY_CLIENT_READER_HPP

#include "rice/Module.hpp"
#include "rice/Data_Object.hpp"
#include <pulsar/Client.h>

#include "message.hpp"

namespace pulsar_rb {
  class Reader {
  public:
    pulsar::Reader _reader;
    Reader() {};
    Reader(const pulsar::Reader& reader) : _reader(reader) {}

    // void seek(const MessageId::ptr msgId, unsigned int timeout_ms=0);
    bool hasMessageAvailable();
    Message::ptr readNext(unsigned int timeout_ms=0);

    typedef Rice::Data_Object<Reader> ptr;
  };

  // direct typedef instead of wrapping because implementations don't need any
  // wrapping. but still re-namespaced for consistency
  typedef pulsar::ReaderConfiguration ReaderConfiguration;
};

void bind_reader(Rice::Module& module);

#endif
