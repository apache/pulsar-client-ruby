#ifndef __PULSAR_RUBY_CLIENT_LOGGER_HPP
#define __PULSAR_RUBY_CLIENT_LOGGER_HPP

#include <pulsar/Logger.h>

namespace pulsar_rb {

class SilentLoggerFactory : public pulsar::LoggerFactory {
  public:
    pulsar::Logger* getLogger(const std::string& fileName);

    static std::unique_ptr<pulsar::LoggerFactory> create();
};

}

#endif
