#ifndef __PULSAR_RUBY_CLIENT_MESSAGE_HPP
#define __PULSAR_RUBY_CLIENT_MESSAGE_HPP

#include "rice/Module.hpp"
#include "rice/String.hpp"
#include "rice/Data_Object.hpp"
#include <pulsar/Client.h>

namespace pulsar_rb {
  class MessageId {
  public:
    pulsar::MessageId _msgId;
    MessageId(const pulsar::MessageId& msgId) : _msgId(msgId) {};

    Rice::String toString();
    Rice::String serialize();

    typedef Rice::Data_Object<MessageId> ptr;

    static MessageId::ptr deserialize(const Rice::String& serialized) {
      return MessageId::ptr(new MessageId(pulsar::MessageId::deserialize(serialized.str())));
    }

    static MessageId::ptr earliest() {
      return MessageId::ptr(new MessageId(pulsar::MessageId::earliest()));
    }

    static MessageId::ptr latest() {
      return MessageId::ptr(new MessageId(pulsar::MessageId::latest()));
    }
  };

  class Message {
  public:
    pulsar::Message _msg;
    Message(const pulsar::Message& msg) : _msg(msg) {};
    Message(const std::string& data);

    Rice::String getData();
    MessageId::ptr getMessageId();

    typedef Rice::Data_Object<Message> ptr;
  };
};

void bind_message(Rice::Module& module);

#endif
