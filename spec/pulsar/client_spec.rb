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

RSpec.describe Pulsar::Client do
  it "has a version number" do
    expect(Pulsar::Client::VERSION).not_to be nil
  end

  context 'with pulsar' do
    let(:broker_uri) { ENV['PULSAR_BROKER_URI'] }
    let(:namespace) { ENV['PULSAR_CLIENT_RUBY_TEST_NAMESPACE'].to_s.sub(%r{^[-a-z]:/+}, '') }
    let(:configured?) { broker_uri && !namespace.empty? }
    let(:client) { Pulsar::Client.from_environment(broker_uri: broker_uri) }
    let(:topic) { "non-persistent://#{namespace}/test#{sprintf "%06d", rand(1_000_000)}" }
    let(:producer) { client.create_producer(topic) }
    let(:subscription_name) { "#{topic}-consumer" }
    let(:timeout_ms) { 10_000 }

    before(:each) do
      skip('Live Pulsar tests not configured: Set PULSAR_CLIENT_RUBY_TEST_NAMESPACE to enable') unless configured?
    end

    after(:each) do
      # Close any producers/consumers to avoid test pollution.
      client.close
    end

    it "can consume a single topic" do
      consumer = client.subscribe(topic, subscription_name)
      t = Thread.new { consumer.receive(timeout_ms).data }
      client.create_producer(topic).send("single")
      expect(t.join.value).to eq("single")
    end
  end
end
