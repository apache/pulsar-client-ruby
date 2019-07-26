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

require 'pulsar/bindings'

module Pulsar
  class ClientConfiguration
    def self.from(config)
      case config
      when self then config # already a config object
      when nil then self.new # empty (all defaults) config object
      when Hash then self.new(config) # config object from hash
      else raise ArgumentError
      end
    end

    def self.from_environment(config={})
      env_config = {}
      if ENV.key?('PULSAR_CERT_PATH')
        env_config[:use_tls] = true
        env_config[:tls_allow_insecure_connection] = false
        env_config[:tls_validate_hostname] = false
        env_config[:tls_trust_certs_file_path] = ENV['PULSAR_CERT_PATH']
      end
      if ENV.key?('PULSAR_AUTH_TOKEN')
        env_config[:authentication_token] = ENV['PULSAR_AUTH_TOKEN']
      end
      self.from(env_config.merge(config))
    end

    module RubySideTweaks
      def initialize(config={})
        super()
        populate(config)
      end
    end

    prepend RubySideTweaks

    def populate(config={})
      populate_one(config, :authentication_token)
      populate_one(config, :operation_timeout_seconds)
      populate_one(config, :io_threads)
      populate_one(config, :message_listener_threads)
      populate_one(config, :concurrent_lookup_requests)
      populate_one(config, :log_conf_file_path)
      populate_one(config, :use_tls)
      populate_one(config, :tls_trust_certs_file_path)
      populate_one(config, :tls_allow_insecure_connection)
      populate_one(config, :tls_validate_hostname)
    end

    def populate_one(config, key)
      if config.key?(key)
        self.send(:"#{key}=", config[key])
      elsif config.key?(key.to_s)
        self.send(:"#{key}=", config[key.to_s])
      end
    end
  end
end
