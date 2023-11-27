//
// Created by sevastian on 24.11.23.
//

#ifndef CALLCENTER_CALLINFO_H
#define CALLCENTER_CALLINFO_H

#include <ctime>
#include <stdint.h>
#include <string>

struct AbstractTime {
    std::time_t time;
    AbstractTime(std::time_t time): time(time) {}
    AbstractTime() = default;

    explicit operator std::time_t() {
        return time;
    }
};

struct IncomeTime : public AbstractTime {};
struct EndTime : public AbstractTime {};
struct AnswerTime : public AbstractTime {};

struct CallID {
    uint64_t id;
    CallID(uint64_t id): id(id) {}
    CallID() = default;

    explicit operator uint64_t() {
        return id;
    }
};

struct Number {
    std::string number;
    Number(std::string number): number(number) {}
    Number() = default;

    explicit operator std::string () {
        return number;
    }
};

enum CallStatus{OK = 0, OVERLOAD = -1, ALREADY_IN_QUEUE = -2};

struct OperatorID {
    uint64_t id;
    OperatorID(uint64_t id): id(id) {}
    OperatorID() = default;

    explicit operator uint64_t() {
        return id;
    }
};

struct Duration {
    std::time_t duration;
    Duration(std::time_t duration): duration(duration) {}
    Duration() = default;

    explicit operator std::time_t() {
        return duration;
    }
};

struct CallInfo {
    IncomeTime incomeDt;
    CallID callId;
    Number number;
    EndTime endDt;
    CallStatus status;
    AnswerTime operatorAnswerDt;
    OperatorID operatorId;
    Duration duration;

    CallInfo(std::string &number) {
        status = CallStatus::OK;
        this->number = Number(number);
    }
    CallInfo() = default;
};

#endif //CALLCENTER_CALLINFO_H
