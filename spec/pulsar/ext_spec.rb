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

require "rbconfig"

RSpec.describe "pulsar ext" do
  RUBY = RbConfig::CONFIG['RUBY_INSTALL_NAME']
  EXT_DIR = File.join(__dir__, "ext")

  before(:all) do
    Dir.chdir(EXT_DIR) do
      system("#{RUBY} ./extconf.rb")
      system("make clean all")
    end
    require_relative "#{File.join(".", "ext", "bindings")}"
  end

  describe "errors" do
    it "inherits from Pulsar::Error" do
      expect(Pulsar::Error::UnknownError.new.is_a?(Pulsar::Error)).to be true
    end
  end

  describe "check_result" do
    it "doesn't raise for ok" do
      expect { PulsarTestExt.check_result_Ok }.not_to raise_exception
    end

    it "raises UnknownError" do
      expect { PulsarTestExt.check_result_UnknownError }.to raise_exception(Pulsar::Error::UnknownError)
    end
    it "raises InvalidConfiguration" do
      expect { PulsarTestExt.check_result_InvalidConfiguration }.to raise_exception(Pulsar::Error::InvalidConfiguration)
    end
    it "raises Timeout" do
      expect { PulsarTestExt.check_result_Timeout }.to raise_exception(Pulsar::Error::Timeout)
    end
    it "raises LookupError" do
      expect { PulsarTestExt.check_result_LookupError }.to raise_exception(Pulsar::Error::LookupError)
    end
    it "raises ConnectError" do
      expect { PulsarTestExt.check_result_ConnectError }.to raise_exception(Pulsar::Error::ConnectError)
    end
    it "raises ReadError" do
      expect { PulsarTestExt.check_result_ReadError }.to raise_exception(Pulsar::Error::ReadError)
    end
    it "raises AuthenticationError" do
      expect { PulsarTestExt.check_result_AuthenticationError }.to raise_exception(Pulsar::Error::AuthenticationError)
    end
    it "raises AuthorizationError" do
      expect { PulsarTestExt.check_result_AuthorizationError }.to raise_exception(Pulsar::Error::AuthorizationError)
    end
    it "raises ErrorGettingAuthenticationData" do
      expect { PulsarTestExt.check_result_ErrorGettingAuthenticationData }.to raise_exception(Pulsar::Error::ErrorGettingAuthenticationData)
    end
    it "raises BrokerMetadataError" do
      expect { PulsarTestExt.check_result_BrokerMetadataError }.to raise_exception(Pulsar::Error::BrokerMetadataError)
    end
    it "raises BrokerPersistenceError" do
      expect { PulsarTestExt.check_result_BrokerPersistenceError }.to raise_exception(Pulsar::Error::BrokerPersistenceError)
    end
    it "raises ChecksumError" do
      expect { PulsarTestExt.check_result_ChecksumError }.to raise_exception(Pulsar::Error::ChecksumError)
    end
    it "raises ConsumerBusy" do
      expect { PulsarTestExt.check_result_ConsumerBusy }.to raise_exception(Pulsar::Error::ConsumerBusy)
    end
    it "raises NotConnected" do
      expect { PulsarTestExt.check_result_NotConnected }.to raise_exception(Pulsar::Error::NotConnected)
    end
    it "raises AlreadyClosed" do
      expect { PulsarTestExt.check_result_AlreadyClosed }.to raise_exception(Pulsar::Error::AlreadyClosed)
    end
    it "raises InvalidMessage" do
      expect { PulsarTestExt.check_result_InvalidMessage }.to raise_exception(Pulsar::Error::InvalidMessage)
    end
    it "raises ConsumerNotInitialized" do
      expect { PulsarTestExt.check_result_ConsumerNotInitialized }.to raise_exception(Pulsar::Error::ConsumerNotInitialized)
    end
    it "raises ProducerNotInitialized" do
      expect { PulsarTestExt.check_result_ProducerNotInitialized }.to raise_exception(Pulsar::Error::ProducerNotInitialized)
    end
    it "raises ProducerBusy" do
      expect { PulsarTestExt.check_result_ProducerBusy }.to raise_exception(Pulsar::Error::ProducerBusy)
    end
    it "raises TooManyLookupRequestException" do
      expect { PulsarTestExt.check_result_TooManyLookupRequestException }.to raise_exception(Pulsar::Error::TooManyLookupRequestException)
    end
    it "raises InvalidTopicName" do
      expect { PulsarTestExt.check_result_InvalidTopicName }.to raise_exception(Pulsar::Error::InvalidTopicName)
    end
    it "raises InvalidUrl" do
      expect { PulsarTestExt.check_result_InvalidUrl }.to raise_exception(Pulsar::Error::InvalidUrl)
    end
    it "raises ServiceUnitNotReady" do
      expect { PulsarTestExt.check_result_ServiceUnitNotReady }.to raise_exception(Pulsar::Error::ServiceUnitNotReady)
    end
    it "raises OperationNotSupported" do
      expect { PulsarTestExt.check_result_OperationNotSupported }.to raise_exception(Pulsar::Error::OperationNotSupported)
    end
    it "raises ProducerBlockedQuotaExceededError" do
      expect { PulsarTestExt.check_result_ProducerBlockedQuotaExceededError }.to raise_exception(Pulsar::Error::ProducerBlockedQuotaExceededError)
    end
    it "raises ProducerBlockedQuotaExceededException" do
      expect { PulsarTestExt.check_result_ProducerBlockedQuotaExceededException }.to raise_exception(Pulsar::Error::ProducerBlockedQuotaExceededException)
    end
    it "raises ProducerQueueIsFull" do
      expect { PulsarTestExt.check_result_ProducerQueueIsFull }.to raise_exception(Pulsar::Error::ProducerQueueIsFull)
    end
    it "raises MessageTooBig" do
      expect { PulsarTestExt.check_result_MessageTooBig }.to raise_exception(Pulsar::Error::MessageTooBig)
    end
    it "raises TopicNotFound" do
      expect { PulsarTestExt.check_result_TopicNotFound }.to raise_exception(Pulsar::Error::TopicNotFound)
    end
    it "raises SubscriptionNotFound" do
      expect { PulsarTestExt.check_result_SubscriptionNotFound }.to raise_exception(Pulsar::Error::SubscriptionNotFound)
    end
    it "raises ConsumerNotFound" do
      expect { PulsarTestExt.check_result_ConsumerNotFound }.to raise_exception(Pulsar::Error::ConsumerNotFound)
    end
    it "raises UnsupportedVersionError" do
      expect { PulsarTestExt.check_result_UnsupportedVersionError }.to raise_exception(Pulsar::Error::UnsupportedVersionError)
    end
    it "raises TopicTerminated" do
      expect { PulsarTestExt.check_result_TopicTerminated }.to raise_exception(Pulsar::Error::TopicTerminated)
    end
    it "raises CryptoError" do
      expect { PulsarTestExt.check_result_CryptoError }.to raise_exception(Pulsar::Error::CryptoError)
    end
    it "raises IncompatibleSchema" do
      expect { PulsarTestExt.check_result_IncompatibleSchema }.to raise_exception(Pulsar::Error::IncompatibleSchema)
    end
    it "raises ConsumerAssignError" do
      expect { PulsarTestExt.check_result_ConsumerAssignError }.to raise_exception(Pulsar::Error::ConsumerAssignError)
    end
    it "raises CumulativeAcknowledgementNotAllowedError" do
      expect { PulsarTestExt.check_result_CumulativeAcknowledgementNotAllowedError }.to raise_exception(Pulsar::Error::CumulativeAcknowledgementNotAllowedError)
    end
    it "raises TransactionCoordinatorNotFoundError" do
      expect { PulsarTestExt.check_result_TransactionCoordinatorNotFoundError }.to raise_exception(Pulsar::Error::TransactionCoordinatorNotFoundError)
    end
    it "raises InvalidTxnStatusError" do
      expect { PulsarTestExt.check_result_InvalidTxnStatusError }.to raise_exception(Pulsar::Error::InvalidTxnStatusError)
    end
    it "raises NotAllowedError" do
      expect { PulsarTestExt.check_result_NotAllowedError }.to raise_exception(Pulsar::Error::NotAllowedError)
    end
  end
end
