//
// Created by sevastian on 24.11.23.
//

#ifndef CALLCENTER_CALLSERVICEIMPL_H
#define CALLCENTER_CALLSERVICEIMPL_H

#include "CallService.h"
#include "CallQueue.h"
#include "CDRWriterImpl.h"
#include <list>
#include <vector>
#include "../include/Operator.h"
#include "Config.h"
#include <thread>
#include <chrono>
#include <unordered_set>

class CallServiceImpl : public CallService {
    std::unordered_set<size_t> uniqueNumbers;
    CallQueue &queue;
    static uint64_t idGen;
    CDRWriter &cdrWriter;
    std::vector<Operator *> operators;

public:
    CallServiceImpl(CallQueue &queue, CDRWriter &cdrWriter): queue(queue), cdrWriter(cdrWriter) {
        for (uint64_t i = 0; i < Config::getInstance().getOperatorsCount(); ++i) {
            operators.push_back(new Operator(i + 1));
        }
    };

    int handleCall(std::string &number) override;
    void handleCleanExpired() override;
    void handleSchedulingReady() override;
    void service() override;

    ~CallServiceImpl() {
        while (operators.size() > 0) {
            Operator *cur = operators.back();
            operators.pop_back();
            delete cur;
        }
        
    }
};

#endif //CALLCENTER_CALLSERVICEIMPL_H
