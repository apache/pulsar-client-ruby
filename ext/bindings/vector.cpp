#include "rice/Array.hpp"

#include "vector.hpp"

template<>
std::vector<std::string> from_ruby<std::vector<std::string>>(Rice::Object o)
{
  Rice::Array a(o);
  std::vector<std::string> v;
  Rice::Array::iterator it = a.begin();
  Rice::Array::iterator end = a.end();
  for(; it != end; ++it) {
    v.push_back(it->to_s().str());
  }
  return v;
}
