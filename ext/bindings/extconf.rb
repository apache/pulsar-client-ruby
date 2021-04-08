require 'mkmf-rice'
$LOCAL_LIBS << "-lpulsar"
$CXXFLAGS += " -std=c++11 "
create_makefile('pulsar/bindings')
