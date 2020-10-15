#include <pulsar/Client.h>

#include "util.hpp"
#include "rice/Exception.hpp"

using namespace Rice;

// Result enum found in pulsar-*/pulsar-client-cpp/include/pulsar/Result.h

VALUE rb_ePulsarError = Qnil;
VALUE rb_ePulsarError_UnknownError = Qnil;
VALUE rb_ePulsarError_InvalidConfiguration = Qnil;
VALUE rb_ePulsarError_Timeout = Qnil;
VALUE rb_ePulsarError_LookupError = Qnil;
VALUE rb_ePulsarError_ConnectError = Qnil;
VALUE rb_ePulsarError_ReadError = Qnil;
VALUE rb_ePulsarError_AuthenticationError = Qnil;
VALUE rb_ePulsarError_AuthorizationError = Qnil;
VALUE rb_ePulsarError_ErrorGettingAuthenticationData = Qnil;
VALUE rb_ePulsarError_BrokerMetadataError = Qnil;
VALUE rb_ePulsarError_BrokerPersistenceError = Qnil;
VALUE rb_ePulsarError_ChecksumError = Qnil;
VALUE rb_ePulsarError_ConsumerBusy = Qnil;
VALUE rb_ePulsarError_NotConnected = Qnil;
VALUE rb_ePulsarError_AlreadyClosed = Qnil;
VALUE rb_ePulsarError_InvalidMessage = Qnil;
VALUE rb_ePulsarError_ConsumerNotInitialized = Qnil;
VALUE rb_ePulsarError_ProducerNotInitialized = Qnil;
VALUE rb_ePulsarError_ProducerBusy = Qnil;
VALUE rb_ePulsarError_TooManyLookupRequestException = Qnil;
VALUE rb_ePulsarError_InvalidTopicName = Qnil;
VALUE rb_ePulsarError_InvalidUrl = Qnil;
VALUE rb_ePulsarError_ServiceUnitNotReady = Qnil;
VALUE rb_ePulsarError_OperationNotSupported = Qnil;
VALUE rb_ePulsarError_ProducerBlockedQuotaExceededError = Qnil;
VALUE rb_ePulsarError_ProducerBlockedQuotaExceededException = Qnil;
VALUE rb_ePulsarError_ProducerQueueIsFull = Qnil;
VALUE rb_ePulsarError_MessageTooBig = Qnil;
VALUE rb_ePulsarError_TopicNotFound = Qnil;
VALUE rb_ePulsarError_SubscriptionNotFound = Qnil;
VALUE rb_ePulsarError_ConsumerNotFound = Qnil;
VALUE rb_ePulsarError_UnsupportedVersionError = Qnil;
VALUE rb_ePulsarError_TopicTerminated = Qnil;
VALUE rb_ePulsarError_CryptoError = Qnil;
VALUE rb_ePulsarError_IncompatibleSchema = Qnil;
VALUE rb_ePulsarError_ConsumerAssignError = Qnil;

void bind_errors(Module &module) {
  rb_ePulsarError = rb_define_class_under(module.value(), "Error", rb_eStandardError);
  rb_ePulsarError_UnknownError = rb_define_class_under(rb_ePulsarError, "UnknownError", rb_ePulsarError);
  rb_ePulsarError_InvalidConfiguration = rb_define_class_under(rb_ePulsarError, "InvalidConfiguration", rb_ePulsarError);
  rb_ePulsarError_Timeout = rb_define_class_under(rb_ePulsarError, "Timeout", rb_ePulsarError);
  rb_ePulsarError_LookupError = rb_define_class_under(rb_ePulsarError, "LookupError", rb_ePulsarError);
  rb_ePulsarError_ConnectError = rb_define_class_under(rb_ePulsarError, "ConnectError", rb_ePulsarError);
  rb_ePulsarError_ReadError = rb_define_class_under(rb_ePulsarError, "ReadError", rb_ePulsarError);
  rb_ePulsarError_AuthenticationError = rb_define_class_under(rb_ePulsarError, "AuthenticationError", rb_ePulsarError);
  rb_ePulsarError_AuthorizationError = rb_define_class_under(rb_ePulsarError, "AuthorizationError", rb_ePulsarError);
  rb_ePulsarError_ErrorGettingAuthenticationData = rb_define_class_under(rb_ePulsarError, "ErrorGettingAuthenticationData", rb_ePulsarError);
  rb_ePulsarError_BrokerMetadataError = rb_define_class_under(rb_ePulsarError, "BrokerMetadataError", rb_ePulsarError);
  rb_ePulsarError_BrokerPersistenceError = rb_define_class_under(rb_ePulsarError, "BrokerPersistenceError", rb_ePulsarError);
  rb_ePulsarError_ChecksumError = rb_define_class_under(rb_ePulsarError, "ChecksumError", rb_ePulsarError);
  rb_ePulsarError_ConsumerBusy = rb_define_class_under(rb_ePulsarError, "ConsumerBusy", rb_ePulsarError);
  rb_ePulsarError_NotConnected = rb_define_class_under(rb_ePulsarError, "NotConnected", rb_ePulsarError);
  rb_ePulsarError_AlreadyClosed = rb_define_class_under(rb_ePulsarError, "AlreadyClosed", rb_ePulsarError);
  rb_ePulsarError_InvalidMessage = rb_define_class_under(rb_ePulsarError, "InvalidMessage", rb_ePulsarError);
  rb_ePulsarError_ConsumerNotInitialized = rb_define_class_under(rb_ePulsarError, "ConsumerNotInitialized", rb_ePulsarError);
  rb_ePulsarError_ProducerNotInitialized = rb_define_class_under(rb_ePulsarError, "ProducerNotInitialized", rb_ePulsarError);
  rb_ePulsarError_ProducerBusy = rb_define_class_under(rb_ePulsarError, "ProducerBusy", rb_ePulsarError);
  rb_ePulsarError_TooManyLookupRequestException = rb_define_class_under(rb_ePulsarError, "TooManyLookupRequestException", rb_ePulsarError);
  rb_ePulsarError_InvalidTopicName = rb_define_class_under(rb_ePulsarError, "InvalidTopicName", rb_ePulsarError);
  rb_ePulsarError_InvalidUrl = rb_define_class_under(rb_ePulsarError, "InvalidUrl", rb_ePulsarError);
  rb_ePulsarError_ServiceUnitNotReady = rb_define_class_under(rb_ePulsarError, "ServiceUnitNotReady", rb_ePulsarError);
  rb_ePulsarError_OperationNotSupported = rb_define_class_under(rb_ePulsarError, "OperationNotSupported", rb_ePulsarError);
  rb_ePulsarError_ProducerBlockedQuotaExceededError = rb_define_class_under(rb_ePulsarError, "ProducerBlockedQuotaExceededError", rb_ePulsarError);
  rb_ePulsarError_ProducerBlockedQuotaExceededException = rb_define_class_under(rb_ePulsarError, "ProducerBlockedQuotaExceededException", rb_ePulsarError);
  rb_ePulsarError_ProducerQueueIsFull = rb_define_class_under(rb_ePulsarError, "ProducerQueueIsFull", rb_ePulsarError);
  rb_ePulsarError_MessageTooBig = rb_define_class_under(rb_ePulsarError, "MessageTooBig", rb_ePulsarError);
  rb_ePulsarError_TopicNotFound = rb_define_class_under(rb_ePulsarError, "TopicNotFound", rb_ePulsarError);
  rb_ePulsarError_SubscriptionNotFound = rb_define_class_under(rb_ePulsarError, "SubscriptionNotFound", rb_ePulsarError);
  rb_ePulsarError_ConsumerNotFound = rb_define_class_under(rb_ePulsarError, "ConsumerNotFound", rb_ePulsarError);
  rb_ePulsarError_UnsupportedVersionError = rb_define_class_under(rb_ePulsarError, "UnsupportedVersionError", rb_ePulsarError);
  rb_ePulsarError_TopicTerminated = rb_define_class_under(rb_ePulsarError, "TopicTerminated", rb_ePulsarError);
  rb_ePulsarError_CryptoError = rb_define_class_under(rb_ePulsarError, "CryptoError", rb_ePulsarError);
  rb_ePulsarError_IncompatibleSchema = rb_define_class_under(rb_ePulsarError, "IncompatibleSchema", rb_ePulsarError);
  rb_ePulsarError_ConsumerAssignError = rb_define_class_under(rb_ePulsarError, "ConsumerAssignError", rb_ePulsarError);
}

void CheckResult(pulsar::Result res) {
  if (res != pulsar::ResultOk) {
    switch(res) {
      case pulsar::ResultUnknownError:
        throw Exception(rb_ePulsarError_UnknownError, "Unknown error happened on broker"); break;
      case pulsar::ResultInvalidConfiguration:
        throw Exception(rb_ePulsarError_InvalidConfiguration, "Invalid configuration"); break;
      case pulsar::ResultTimeout:
        throw Exception(rb_ePulsarError_Timeout, "Operation timed out"); break;
      case pulsar::ResultLookupError:
        throw Exception(rb_ePulsarError_LookupError, "Broker lookup failed"); break;
      case pulsar::ResultConnectError:
        throw Exception(rb_ePulsarError_ConnectError, "Failed to connect to broker"); break;
      case pulsar::ResultReadError:
        throw Exception(rb_ePulsarError_ReadError, "Failed to read from socket"); break;
      case pulsar::ResultAuthenticationError:
        throw Exception(rb_ePulsarError_AuthenticationError, "Authentication failed on broker"); break;
      case pulsar::ResultAuthorizationError:
        throw Exception(rb_ePulsarError_AuthorizationError, "Client is not authorized to create producer/consumer"); break;
      case pulsar::ResultErrorGettingAuthenticationData:
        throw Exception(rb_ePulsarError_ErrorGettingAuthenticationData, "Client cannot find authorization data"); break;
      case pulsar::ResultBrokerMetadataError:
        throw Exception(rb_ePulsarError_BrokerMetadataError, "Broker failed in updating metadata"); break;
      case pulsar::ResultBrokerPersistenceError:
        throw Exception(rb_ePulsarError_BrokerPersistenceError, "Broker failed to persist entry"); break;
      case pulsar::ResultChecksumError:
        throw Exception(rb_ePulsarError_ChecksumError, "Corrupt message checksum failure"); break;
      case pulsar::ResultConsumerBusy:
        throw Exception(rb_ePulsarError_ConsumerBusy, "Exclusive consumer is already connected"); break;
      case pulsar::ResultNotConnected:
        throw Exception(rb_ePulsarError_NotConnected, "Producer/Consumer is not currently connected to broker"); break;
      case pulsar::ResultAlreadyClosed:
        throw Exception(rb_ePulsarError_AlreadyClosed, "Producer/Consumer is already closed and not accepting any operation"); break;
      case pulsar::ResultInvalidMessage:
        throw Exception(rb_ePulsarError_InvalidMessage, "Error in publishing an already used message"); break;
      case pulsar::ResultConsumerNotInitialized:
        throw Exception(rb_ePulsarError_ConsumerNotInitialized, "Consumer is not initialized"); break;
      case pulsar::ResultProducerNotInitialized:
        throw Exception(rb_ePulsarError_ProducerNotInitialized, "Producer is not initialized"); break;
      case pulsar::ResultProducerBusy:
        throw Exception(rb_ePulsarError_ProducerBusy, "Producer with same name is already connected"); break;
      case pulsar::ResultTooManyLookupRequestException:
        throw Exception(rb_ePulsarError_TooManyLookupRequestException, "Too Many concurrent LookupRequest"); break;
      case pulsar::ResultInvalidTopicName:
        throw Exception(rb_ePulsarError_InvalidTopicName, "Invalid topic name"); break;
      case pulsar::ResultInvalidUrl:
        throw Exception(rb_ePulsarError_InvalidUrl, "Client Initialized with Invalid Broker Url (VIP Url passed to Client Constructor)"); break;
      case pulsar::ResultServiceUnitNotReady:
        throw Exception(rb_ePulsarError_ServiceUnitNotReady, "Service Unit unloaded between client did lookup and producer/consumer got created"); break;
      case pulsar::ResultOperationNotSupported:
        throw Exception(rb_ePulsarError_OperationNotSupported, "Operation not supported"); break;
      case pulsar::ResultProducerBlockedQuotaExceededError:
        throw Exception(rb_ePulsarError_ProducerBlockedQuotaExceededError, "Producer is blocked"); break;
      case pulsar::ResultProducerBlockedQuotaExceededException:
        throw Exception(rb_ePulsarError_ProducerBlockedQuotaExceededException, "Producer is getting exception"); break;
      case pulsar::ResultProducerQueueIsFull:
        throw Exception(rb_ePulsarError_ProducerQueueIsFull, "Producer queue is full"); break;
      case pulsar::ResultMessageTooBig:
        throw Exception(rb_ePulsarError_MessageTooBig, "Trying to send a messages exceeding the max size"); break;
      case pulsar::ResultTopicNotFound:
        throw Exception(rb_ePulsarError_TopicNotFound, "Topic not found"); break;
      case pulsar::ResultSubscriptionNotFound:
        throw Exception(rb_ePulsarError_SubscriptionNotFound, "Subscription not found"); break;
      case pulsar::ResultConsumerNotFound:
        throw Exception(rb_ePulsarError_ConsumerNotFound, "Consumer not found"); break;
      case pulsar::ResultUnsupportedVersionError:
        throw Exception(rb_ePulsarError_UnsupportedVersionError, "Error when an older client/version doesn't support a required feature"); break;
      case pulsar::ResultTopicTerminated:
        throw Exception(rb_ePulsarError_TopicTerminated, "Topic was already terminated"); break;
      case pulsar::ResultCryptoError:
        throw Exception(rb_ePulsarError_CryptoError, "Error when crypto operation fails"); break;
      case pulsar::ResultIncompatibleSchema:
        throw Exception(rb_ePulsarError_IncompatibleSchema, "Specified schema is incompatible with the topic's schema"); break;
      case pulsar::ResultConsumerAssignError:
        throw Exception(rb_ePulsarError_ConsumerAssignError, "Error when a new consumer connected but can't assign messages to this consumer"); break;
      default:
        throw Exception(rb_ePulsarError, "unexpected pulsar exception: %d", res);
    }
  }
}
