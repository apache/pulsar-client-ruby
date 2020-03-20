#
# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied.  See the License for the
# specific language governing permissions and limitations
# under the License.
#

require 'pulsar/client/version'
require 'pulsar/bindings'

module Pulsar
  class ReaderConfiguration

    module RubySideTweaks
      def initialize(config={})
        super()
        self.receiver_queue_size = config[:receiver_queue_size] if config.has_key?(:receiver_queue_size)
        self.reader_name = config[:reader_name] if config.has_key?(:reader_name)
        self.subscription_role_prefix = config[:subscription_role_prefix] if config.has_key?(:subscription_role_prefix)
        self.read_compacted = config[:read_compacted] if config.has_key?(:read_compacted)
      end
    end

    prepend RubySideTweaks
  end
end
