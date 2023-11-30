//
// Created by sevastian on 28.11.23.
//

#ifndef CALLCENTER_OPERATOR_H
#define CALLCENTER_OPERATOR_H

#include "CallInfo.h"

class Operator {
    OperatorID id;
    OperatorStatus status;
    CallInfo *processingCall;

public:
    Operator(uint64_t id) {
        this->id = id;
        status = OperatorStatus::FREE;
    } 

    OperatorID getId() const;
    OperatorStatus getStatus() const;
    CallInfo *getProcessingCall() const;
    void setStatus(OperatorStatus status);
    void setProcessingCall(CallInfo *processingCall);
};

#endif //CALLCENTER_OPERATOR_H
