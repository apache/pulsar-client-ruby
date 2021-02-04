#include <pulsar/Logger.h>

#include "logger.hpp"

namespace pulsar_rb {

class SilentLogger : public pulsar::Logger {
  std::string _logger;

  public:
    SilentLogger(const std::string &logger) : _logger(logger) {}

    bool isEnabled(Level level) { return false; }
    void log(Level level, int line, const std::string &message) { }
};

pulsar::Logger *SilentLoggerFactory::getLogger(const std::string& file) { return new SilentLogger(file); }

std::unique_ptr<pulsar::LoggerFactory> SilentLoggerFactory::create() {
  return std::unique_ptr<pulsar::LoggerFactory>(new SilentLoggerFactory());
}

}
