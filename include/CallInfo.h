//
// Created by sevastian on 24.11.23.
//

#ifndef CALLCENTER_CALLINFO_H
#define CALLCENTER_CALLINFO_H

#include <ctime>
#include <cstdint>
#include <string>
#include <utility>
#include <random>
#include "Config.h"

struct AbstractTime {
    std::time_t time;
    virtual ~AbstractTime() = default;

    explicit operator std::time_t() const {
        return time;
    }

    virtual AbstractTime &operator=(const std::time_t val) {
        this->time = val;
        return *this;
    }

    bool operator==(const AbstractTime &abstractTime) const {
        return this->time == abstractTime.time;
    }

    bool operator<=(const std::time_t val) const {
        return this->time <= val;
    }
};

struct IncomeTime : public AbstractTime {
    IncomeTime &operator=(const std::time_t val) override {
        this->time = val;
        return *this;
    }
};

struct EndTime : public AbstractTime {
    EndTime &operator=(const std::time_t val) override {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distribution(Config::getInstance().getRandomExpirationTimeMin(),
                                                        Config::getInstance().getRandomExpirationTimeMax());
        this->time = val + distribution(gen);
        return *this;
    }
};

struct AnswerTime : public AbstractTime {
    AnswerTime &operator=(const std::time_t val) override {
        this->time = val;
        return *this;
    }
};

struct CallID {
    uint64_t id;
    explicit CallID(uint64_t id): id(id) {}
    CallID() = default;

    CallID &operator=(const uint64_t val) {
        this->id = val;
        return *this;
    }

    explicit operator uint64_t() const {
        return this->id;
    }
};

struct Number {
    std::string number;
    explicit Number(std::string number): number(std::move(number)) {}
    Number() = default;

    explicit operator std::string () const {
        return number;
    }

    Number &operator=(std::string val) {
        this->number = std::move(val);
        return *this;
    }
};

enum CallStatus{READY, PROCESSING, PROCESSED, EXPIRED, DOUBLE, OVERFLOW};

struct OperatorID {
    uint64_t id;
    explicit OperatorID(uint64_t id): id(id) {}
    OperatorID() = default;

    explicit operator uint64_t() const {
        return id;
    }

    OperatorID &operator=(const uint64_t val) {
        this->id = val;
        return *this;
    }
};

struct Duration {
    std::time_t duration;
    explicit Duration(std::time_t duration): duration(duration) {}
    Duration() = default;

    explicit operator std::time_t() const {
        return duration;
    }

    Duration &operator=(const std::time_t val) {
        this->duration = val;
        return *this;
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

    CallInfo() = default;

    bool operator==(const CallInfo &callInfo) const {
        return this->callId.id == callInfo.callId.id;
    }
};

#endif //CALLCENTER_CALLINFO_H
