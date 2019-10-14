#include <pulsar/Client.h>

#include "util.hpp"
#include "rice/Exception.hpp"

using namespace Rice;

VALUE rb_ePulsarError = Qnil;
VALUE rb_ePulsarError_Timeout = Qnil;

void bind_errors(Module &module) {
  rb_ePulsarError = rb_define_class_under(module.value(), "Error", rb_eStandardError);
  rb_ePulsarError_Timeout = rb_define_class_under(rb_ePulsarError, "Timeout", rb_ePulsarError);
}

void CheckResult(pulsar::Result res) {
  if (res == pulsar::ResultTimeout) {
    throw Exception(rb_ePulsarError_Timeout, "pulsar timeout");
  }
  else if (res != ResultOk) {
    throw Exception(rb_ePulsarError, "unexpected pulsar exception: %d", res);
  }
}
