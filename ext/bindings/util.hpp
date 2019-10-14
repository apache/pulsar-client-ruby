#ifndef __PULSAR_RUBY_CLIENT_UTIL_HPP
#define __PULSAR_RUBY_CLIENT_UTIL_HPP

#include "rice/Module.hpp"
#include <pulsar/Client.h>

using namespace pulsar;

void CheckResult(Result res);

void bind_errors(Rice::Module& module);

#endif
