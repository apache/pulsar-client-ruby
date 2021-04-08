#ifndef __PULSAR_RUBY_CLIENT_VECTOR_HPP
#define __PULSAR_RUBY_CLIENT_VECTOR_HPP

#include "rice/Object.hpp"
#include <pulsar/Client.h>

template<>
std::vector<std::string> from_ruby<std::vector<std::string>>(Rice::Object o);

#endif
