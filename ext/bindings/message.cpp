#include "rice/Data_Type.hpp"
#include "rice/Constructor.hpp"
#include "rice/Exception.hpp"
#include <pulsar/Client.h>

#include "message.hpp"
#include "stringmap.hpp"

namespace pulsar_rb {

Rice::String MessageId::toString() {
  std::stringstream ss;
  ss << _msgId;
  return Rice::String(ss.str());
}

Message::Message(const std::string& data, Rice::Object arg = Rice::Object()) {
  pulsar::MessageBuilder mb;
  mb.setContent(data);

  if (arg && arg.rb_type() != T_NONE) {
    Rice::Hash opts = Rice::Hash(arg);
    Rice::Hash::iterator it = opts.begin();
    Rice::Hash::iterator end = opts.end();
    std::string key;
    for (; it != end; ++it) {
      key = it->key.to_s().str();
      if (key == "properties"){
        Rice::Object value = Rice::Object(it->value);
        if (value.rb_type() != T_NIL) {
          mb.setProperties(from_ruby<pulsar::StringMap>(value));
        }
      } else if (key == "partition_key") {
        mb.setPartitionKey(Rice::Object(it->value).to_s().str());
      } else if (key == "ordering_key") {
        mb.setOrderingKey(Rice::Object(it->value).to_s().str());
      } else {
        throw Rice::Exception(rb_eArgError, "Unknown keyword argument: %s", key.c_str());
      }
    }
  }

  _msg = mb.build();
  received = false;
}

Rice::String Message::getData() {
  std::string str((const char*)_msg.getData(), _msg.getLength());
  return Rice::String(str);
}

MessageId::ptr Message::getMessageId() {
  pulsar::MessageId messageId = _msg.getMessageId();
  return MessageId::ptr(new MessageId(messageId));
}

Rice::Hash Message::getProperties() {
  return to_ruby(_msg.getProperties());
}

Rice::String Message::getPartitionKey() {
  return to_ruby(_msg.getPartitionKey());
}

Rice::String Message::getOrderingKey() {
  return to_ruby(_msg.getOrderingKey());
}

Rice::Object Message::getTopicName() {
  // If the message topic hasn't been set (it gets set when received, not when
  // built) getTopicName will try to dereference a null pointer.
  return received ? to_ruby(_msg.getTopicName()) : Rice::Nil;
}

}

using namespace Rice;

void bind_message(Module& module) {
  define_class_under<pulsar_rb::MessageId>(module, "MessageId")
    .define_constructor(Constructor<pulsar_rb::MessageId, const pulsar::MessageId&>())
    .define_method("to_s", &pulsar_rb::MessageId::toString)
    ;

  define_class_under<pulsar_rb::Message>(module, "Message")
    .define_constructor(Constructor<pulsar_rb::Message, const pulsar::Message&>())
    .define_constructor(Constructor<pulsar_rb::Message, const std::string&, const Rice::Object>(),
          (Rice::Arg("data"), Rice::Arg("options") = Rice::Object()))
    .define_method("data", &pulsar_rb::Message::getData)
    .define_method("message_id", &pulsar_rb::Message::getMessageId)
    .define_method("properties", &pulsar_rb::Message::getProperties)
    .define_method("partition_key", &pulsar_rb::Message::getPartitionKey)
    .define_method("ordering_key", &pulsar_rb::Message::getOrderingKey)
    .define_method("topic", &pulsar_rb::Message::getTopicName)
    ;
}
