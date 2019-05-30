#ifndef __PULSAR_RUBY_CLIENT_UTIL_HPP
#define __PULSAR_RUBY_CLIENT_UTIL_HPP

#include <pulsar/Client.h>

using namespace pulsar;

struct PulsarException {
    Result _result;
    PulsarException(Result res) :
            _result(res) {}
};

void CheckResult(Result res);

#endif
