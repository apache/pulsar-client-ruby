#include "rice/Module.hpp"
#include "../../../ext/bindings/util.hpp"

using namespace Rice;

extern "C"

void Init_bindings();
void check_result_Ok();
void check_result_UnknownError();
void check_result_InvalidConfiguration();
void check_result_Timeout();
void check_result_LookupError();
void check_result_ConnectError();
void check_result_ReadError();
void check_result_AuthenticationError();
void check_result_AuthorizationError();
void check_result_ErrorGettingAuthenticationData();
void check_result_BrokerMetadataError();
void check_result_BrokerPersistenceError();
void check_result_ChecksumError();
void check_result_ConsumerBusy();
void check_result_NotConnected();
void check_result_AlreadyClosed();
void check_result_InvalidMessage();
void check_result_ConsumerNotInitialized();
void check_result_ProducerNotInitialized();
void check_result_ProducerBusy();
void check_result_TooManyLookupRequestException();
void check_result_InvalidTopicName();
void check_result_InvalidUrl();
void check_result_ServiceUnitNotReady();
void check_result_OperationNotSupported();
void check_result_ProducerBlockedQuotaExceededError();
void check_result_ProducerBlockedQuotaExceededException();
void check_result_ProducerQueueIsFull();
void check_result_MessageTooBig();
void check_result_TopicNotFound();
void check_result_SubscriptionNotFound();
void check_result_ConsumerNotFound();
void check_result_UnsupportedVersionError();
void check_result_TopicTerminated();
void check_result_CryptoError();
void check_result_IncompatibleSchema();
void check_result_ConsumerAssignError();
void check_result_CumulativeAcknowledgementNotAllowedError();
void check_result_TransactionCoordinatorNotFoundError();
void check_result_InvalidTxnStatusError();
void check_result_NotAllowedError();

void Init_bindings()
{
  Module rb_mPulsarTestExt = define_module("PulsarTestExt")
    .define_singleton_method("check_result_Ok", &check_result_Ok)
    .define_singleton_method("check_result_UnknownError", &check_result_UnknownError)
    .define_singleton_method("check_result_InvalidConfiguration", &check_result_InvalidConfiguration)
    .define_singleton_method("check_result_Timeout", &check_result_Timeout)
    .define_singleton_method("check_result_LookupError", &check_result_LookupError)
    .define_singleton_method("check_result_ConnectError", &check_result_ConnectError)
    .define_singleton_method("check_result_ReadError", &check_result_ReadError)
    .define_singleton_method("check_result_AuthenticationError", &check_result_AuthenticationError)
    .define_singleton_method("check_result_AuthorizationError", &check_result_AuthorizationError)
    .define_singleton_method("check_result_ErrorGettingAuthenticationData", &check_result_ErrorGettingAuthenticationData)
    .define_singleton_method("check_result_BrokerMetadataError", &check_result_BrokerMetadataError)
    .define_singleton_method("check_result_BrokerPersistenceError", &check_result_BrokerPersistenceError)
    .define_singleton_method("check_result_ChecksumError", &check_result_ChecksumError)
    .define_singleton_method("check_result_ConsumerBusy", &check_result_ConsumerBusy)
    .define_singleton_method("check_result_NotConnected", &check_result_NotConnected)
    .define_singleton_method("check_result_AlreadyClosed", &check_result_AlreadyClosed)
    .define_singleton_method("check_result_InvalidMessage", &check_result_InvalidMessage)
    .define_singleton_method("check_result_ConsumerNotInitialized", &check_result_ConsumerNotInitialized)
    .define_singleton_method("check_result_ProducerNotInitialized", &check_result_ProducerNotInitialized)
    .define_singleton_method("check_result_ProducerBusy", &check_result_ProducerBusy)
    .define_singleton_method("check_result_TooManyLookupRequestException", &check_result_TooManyLookupRequestException)
    .define_singleton_method("check_result_InvalidTopicName", &check_result_InvalidTopicName)
    .define_singleton_method("check_result_InvalidUrl", &check_result_InvalidUrl)
    .define_singleton_method("check_result_ServiceUnitNotReady", &check_result_ServiceUnitNotReady)
    .define_singleton_method("check_result_OperationNotSupported", &check_result_OperationNotSupported)
    .define_singleton_method("check_result_ProducerBlockedQuotaExceededError", &check_result_ProducerBlockedQuotaExceededError)
    .define_singleton_method("check_result_ProducerBlockedQuotaExceededException", &check_result_ProducerBlockedQuotaExceededException)
    .define_singleton_method("check_result_ProducerQueueIsFull", &check_result_ProducerQueueIsFull)
    .define_singleton_method("check_result_MessageTooBig", &check_result_MessageTooBig)
    .define_singleton_method("check_result_TopicNotFound", &check_result_TopicNotFound)
    .define_singleton_method("check_result_SubscriptionNotFound", &check_result_SubscriptionNotFound)
    .define_singleton_method("check_result_ConsumerNotFound", &check_result_ConsumerNotFound)
    .define_singleton_method("check_result_UnsupportedVersionError", &check_result_UnsupportedVersionError)
    .define_singleton_method("check_result_TopicTerminated", &check_result_TopicTerminated)
    .define_singleton_method("check_result_CryptoError", &check_result_CryptoError)
    .define_singleton_method("check_result_IncompatibleSchema", &check_result_IncompatibleSchema)
    .define_singleton_method("check_result_ConsumerAssignError", &check_result_ConsumerAssignError)
    .define_singleton_method("check_result_CumulativeAcknowledgementNotAllowedError", &check_result_CumulativeAcknowledgementNotAllowedError)
    .define_singleton_method("check_result_TransactionCoordinatorNotFoundError", &check_result_TransactionCoordinatorNotFoundError)
    .define_singleton_method("check_result_InvalidTxnStatusError", &check_result_InvalidTxnStatusError)
    .define_singleton_method("check_result_NotAllowedError", &check_result_NotAllowedError)
    ;

}

void check_result_Ok() { CheckResult(pulsar::ResultOk); }
void check_result_UnknownError() { CheckResult(pulsar::ResultUnknownError); }
void check_result_InvalidConfiguration() { CheckResult(pulsar::ResultInvalidConfiguration); }
void check_result_Timeout() { CheckResult(pulsar::ResultTimeout); }
void check_result_LookupError() { CheckResult(pulsar::ResultLookupError); }
void check_result_ConnectError() { CheckResult(pulsar::ResultConnectError); }
void check_result_ReadError() { CheckResult(pulsar::ResultReadError); }
void check_result_AuthenticationError() { CheckResult(pulsar::ResultAuthenticationError); }
void check_result_AuthorizationError() { CheckResult(pulsar::ResultAuthorizationError); }
void check_result_ErrorGettingAuthenticationData() { CheckResult(pulsar::ResultErrorGettingAuthenticationData); }
void check_result_BrokerMetadataError() { CheckResult(pulsar::ResultBrokerMetadataError); }
void check_result_BrokerPersistenceError() { CheckResult(pulsar::ResultBrokerPersistenceError); }
void check_result_ChecksumError() { CheckResult(pulsar::ResultChecksumError); }
void check_result_ConsumerBusy() { CheckResult(pulsar::ResultConsumerBusy); }
void check_result_NotConnected() { CheckResult(pulsar::ResultNotConnected); }
void check_result_AlreadyClosed() { CheckResult(pulsar::ResultAlreadyClosed); }
void check_result_InvalidMessage() { CheckResult(pulsar::ResultInvalidMessage); }
void check_result_ConsumerNotInitialized() { CheckResult(pulsar::ResultConsumerNotInitialized); }
void check_result_ProducerNotInitialized() { CheckResult(pulsar::ResultProducerNotInitialized); }
void check_result_ProducerBusy() { CheckResult(pulsar::ResultProducerBusy); }
void check_result_TooManyLookupRequestException() { CheckResult(pulsar::ResultTooManyLookupRequestException); }
void check_result_InvalidTopicName() { CheckResult(pulsar::ResultInvalidTopicName); }
void check_result_InvalidUrl() { CheckResult(pulsar::ResultInvalidUrl); }
void check_result_ServiceUnitNotReady() { CheckResult(pulsar::ResultServiceUnitNotReady); }
void check_result_OperationNotSupported() { CheckResult(pulsar::ResultOperationNotSupported); }
void check_result_ProducerBlockedQuotaExceededError() { CheckResult(pulsar::ResultProducerBlockedQuotaExceededError); }
void check_result_ProducerBlockedQuotaExceededException() { CheckResult(pulsar::ResultProducerBlockedQuotaExceededException); }
void check_result_ProducerQueueIsFull() { CheckResult(pulsar::ResultProducerQueueIsFull); }
void check_result_MessageTooBig() { CheckResult(pulsar::ResultMessageTooBig); }
void check_result_TopicNotFound() { CheckResult(pulsar::ResultTopicNotFound); }
void check_result_SubscriptionNotFound() { CheckResult(pulsar::ResultSubscriptionNotFound); }
void check_result_ConsumerNotFound() { CheckResult(pulsar::ResultConsumerNotFound); }
void check_result_UnsupportedVersionError() { CheckResult(pulsar::ResultUnsupportedVersionError); }
void check_result_TopicTerminated() { CheckResult(pulsar::ResultTopicTerminated); }
void check_result_CryptoError() { CheckResult(pulsar::ResultCryptoError); }
void check_result_IncompatibleSchema() { CheckResult(pulsar::ResultIncompatibleSchema); }
void check_result_ConsumerAssignError() { CheckResult(pulsar::ResultConsumerAssignError); }
void check_result_CumulativeAcknowledgementNotAllowedError() { CheckResult(pulsar::ResultCumulativeAcknowledgementNotAllowedError); }
void check_result_TransactionCoordinatorNotFoundError() { CheckResult(pulsar::ResultTransactionCoordinatorNotFoundError); }
void check_result_InvalidTxnStatusError() { CheckResult(pulsar::ResultInvalidTxnStatusError); }
void check_result_NotAllowedError() { CheckResult(pulsar::ResultNotAllowedError); }
