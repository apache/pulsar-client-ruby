#include "rice/Data_Type.hpp"
#include "rice/Enum.hpp"
#include "rice/Constructor.hpp"
#include <pulsar/Client.h>
#include <ruby/thread.h>

#include "reader.hpp"
#include "util.hpp"

namespace pulsar_rb {

/* TODO in newer pulsar C++ lib
typedef struct {
  pulsar::Reader& reader;
  const pulsar::MessageId& msgId;
  pulsar::Result result;
} reader_seek_task;

void* reader_seek_nogvl(void* taskPtr) {
  reader_seek_task& task = *(reader_seek_task*)taskPtr;
  task.result = task.reader.seek(task.msgId);
  return nullptr;
}

void Reader::seek(MessageId::ptr msgId) {
  reader_seek_task task = { _reader, msgId->_msgId };
  rb_thread_call_without_gvl(&reader_seek_nogvl, &task, RUBY_UBF_IO, nullptr);
  CheckResult(task.result);
}
*/

typedef struct {
  pulsar::Reader& reader;
  pulsar::Result result;
  bool answer;
} reader_message_available_task;

void* reader_message_available_nogvl(void* taskPtr) {
  reader_message_available_task& task = *(reader_message_available_task*)taskPtr;
  task.result = task.reader.hasMessageAvailable(task.answer);
  return nullptr;
}

bool Reader::hasMessageAvailable() {
  reader_message_available_task task = { _reader };
  rb_thread_call_without_gvl(&reader_message_available_nogvl, &task, RUBY_UBF_IO, nullptr);
  CheckResult(task.result);
  return task.answer;
}

typedef struct {
  pulsar::Reader& reader;
  unsigned int timeout_ms;
  pulsar::Result result;
  pulsar::Message message;
} reader_read_next_task;

void* reader_read_next_nogvl(void* taskPtr) {
  reader_read_next_task& task = *(reader_read_next_task*)taskPtr;
  if (task.timeout_ms > 0) {
    task.result = task.reader.readNext(task.message, task.timeout_ms);
  } else {
    task.result = task.reader.readNext(task.message);
  }
  return nullptr;
}

Message::ptr Reader::readNext(unsigned int timeout_ms) {
  reader_read_next_task task = { _reader, timeout_ms };
  rb_thread_call_without_gvl(&reader_read_next_nogvl, &task, RUBY_UBF_IO, nullptr);
  CheckResult(task.result);
  return Message::ptr(new Message(task.message));
}

}

using namespace Rice;

void bind_reader(Module &module) {
  define_class_under<pulsar_rb::Reader>(module, "Reader")
    .define_constructor(Constructor<pulsar_rb::Reader>())
    // TODO .define_method("seek", &pulsar_rb::Reader::seek)
    .define_method("message_available?", &pulsar_rb::Reader::hasMessageAvailable)
    .define_method("next_message", &pulsar_rb::Reader::readNext, (Arg("timeout_ms") = 0))
    ;

  define_class_under<pulsar_rb::ReaderConfiguration>(module, "ReaderConfiguration")
    .define_constructor(Constructor<pulsar_rb::ReaderConfiguration>())
    // TODO .define_method("schema", &ReaderConfiguration::getSchema)
    // TODO .define_method("schema=", &ReaderConfiguration::setSchema)
    // TODO .define_method("message_listener", &ReaderConfiguration::setMessageListener)
    .define_method("receiver_queue_size", &ReaderConfiguration::getReceiverQueueSize)
    .define_method("receiver_queue_size=", &ReaderConfiguration::setReceiverQueueSize)
    .define_method("reader_name", &ReaderConfiguration::getReaderName)
    .define_method("reader_name=", &ReaderConfiguration::setReaderName)
    .define_method("subscription_role_prefix", &ReaderConfiguration::getSubscriptionRolePrefix)
    .define_method("subscription_role_prefix=", &ReaderConfiguration::setSubscriptionRolePrefix)
    .define_method("read_compacted?", &ReaderConfiguration::isReadCompacted)
    .define_method("read_compacted=", &ReaderConfiguration::setReadCompacted)
    ;
}
