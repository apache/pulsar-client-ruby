require 'mkmf-rice'
$LOCAL_LIBS << "-lpulsar"
create_makefile('pulsar/bindings')
