//
// Created by sevastian on 24.11.23.
//

#include "../include/CallServiceImpl.h"

uint64_t CallServiceImpl::idGen = 0;

int CallServiceImpl::handleCall(std::string &number) {
    if (uniqueNumbers.count(std::hash<std::string>{}(number)) > 0) {
        BOOST_LOG_TRIVIAL(info) << "Service: duplicated call from number " << number;
        return -1;
    }
    else {
        uniqueNumbers.insert(std::hash<std::string>{}(number));
    }
    CallInfo callInfo;
    callInfo.callId = ++idGen;
    callInfo.incomeDt = std::time(nullptr);
    callInfo.endDt = std::time(nullptr);
    callInfo.number = number;
    bool result = queue.tryPush(callInfo);
    if (!result) {
        callInfo.status = CallStatus::OVERFLOW; 
        BOOST_LOG_TRIVIAL(info) << "Service: number " << callInfo.number.number << " have not added to queue "
                                                                                   "due to overflow";
        callInfo.endDt = callInfo.incomeDt;
        cdrWriter.writeCDR(callInfo);
        return -2;
    } else {
        BOOST_LOG_TRIVIAL(info) << "Service: number " << callInfo.number.number << " was added to queue";
        return callInfo.callId.id;
    }
}

void CallServiceImpl::service() {
    while (true) {
        //do nothing
    }
}

void CallServiceImpl::handleCleanExpired() {
    while (true) {
        for (auto callInfo : queue.getQueue()) {
            if (callInfo.endDt <= std::time(nullptr)) {
                callInfo.status = CallStatus::EXPIRED;
                BOOST_LOG_TRIVIAL(info) << "Service: number " << callInfo.number.number << " was removed from queue" <<
                                                                                    " due to expiration of time";
                cdrWriter.writeCDR(callInfo);
                queue.getQueue().remove(callInfo);
                uniqueNumbers.erase(std::hash<std::string>{}(callInfo.number.number));
                break;
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

void CallServiceImpl::handleSchedulingReady() {
    while (true) {
        for (auto oper : operators) {
            if (oper->getStatus() == OperatorStatus::BUSY && oper->getProcessingCall()->endDt <= std::time(nullptr)) {
                CallInfo *callInfo = oper->getProcessingCall();
                callInfo->status = CallStatus::PROCESSED;
                callInfo->duration = static_cast<std::time_t>(callInfo->endDt) - static_cast<std::time_t>(callInfo->operatorAnswerDt);
                BOOST_LOG_TRIVIAL(info) << "Service: operator#" << oper->getId().id << " processed call " << callInfo->callId.id << " and became free";
                cdrWriter.writeCDR(*callInfo);
                uniqueNumbers.erase(std::hash<std::string>{}(callInfo->number.number));
                oper->setStatus(OperatorStatus::FREE);
            }
            if (oper->getStatus() == OperatorStatus::FREE) {
                if (queue.size() > 0) {
                    //std::cout << 1 << std::endl;
                    CallInfo *callInfo = &queue.pop();
                    callInfo->status = CallStatus::PROCESSING;
                    callInfo->operatorId = oper->getId();
                    callInfo->operatorAnswerDt = std::time(nullptr);
                    callInfo->endDt = std::time(nullptr);
                    oper->setProcessingCall(callInfo);
                    oper->setStatus(OperatorStatus::BUSY);
                    BOOST_LOG_TRIVIAL(info) << "Service: operator#" << oper->getId().id << " started process call " << callInfo->callId.id << " and became busy";
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    
}
