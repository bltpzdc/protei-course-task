//
// Created by sevastian on 24.11.23.
//

#include "../include/CallServiceImpl.h"

uint64_t CallServiceImpl::idGen = 0;

bool CallServiceImpl::handleCall(std::string &number) {
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
        //TODO CDR writer
    } else {
        BOOST_LOG_TRIVIAL(info) << "Service: number " << callInfo.number.number << " was added to queue";
    }
    //std::cout << callInfo.callId.id << " " << callInfo.number.number << " " << callInfo.incomeDt.time <<
    //        " " << callInfo.status << " " << callInfo.endDt.time << std::endl;
    return result;
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
                BOOST_LOG_TRIVIAL(info) << "Service: number " << callInfo.number.number << " was removed from queue" <<
                                                                                    " due to expiration of time";
                queue.getQueue().remove(callInfo);
                break;
            }
        }
    }
}
