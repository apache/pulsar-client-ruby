#include <pulsar/Client.h>

#include "util.hpp"

using namespace pulsar;

void CheckResult(Result res) {
  if (res != ResultOk) {
    throw PulsarException(res);
  }
}
