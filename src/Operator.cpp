#include "../include/Operator.h"

OperatorID Operator::getId() const {
    return id;
}

OperatorStatus Operator::getStatus() const {
    return status;
}

CallInfo *Operator::getProcessingCall() const {
    return processingCall;
}

void Operator::setStatus(OperatorStatus status) {
    this->status = status;
}

void Operator::setProcessingCall(CallInfo *processingCall) {
    this->processingCall = processingCall;
}