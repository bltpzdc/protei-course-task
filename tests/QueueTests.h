#include <gtest/gtest.h>
#include "../include/CallQueue.h"
#include <exception>

class QueueTests : public testing::Test {
public:
    static CallQueue *queue;
protected:
    static void SetUpTestCase() {
        Config::setFilename("../config.json");
        Config::getInstance();
    }

    void SetUp() {
        queue = new CallQueue();
    }

    void TearDown() {
        delete queue;
    }
};

CallQueue *QueueTests::queue = nullptr;

TEST_F(QueueTests, CorrectPushAndPop) {
    CallInfo callInfo;
    callInfo.number = "1234";
    queue->tryPush(callInfo);
    EXPECT_EQ(queue->size(), 1);
    ASSERT_EQ(queue->pop(), callInfo);
}

TEST_F(QueueTests, CorrectSize) {
    EXPECT_EQ(queue->size(), 0);
    CallInfo call;
    queue->tryPush(call);
    EXPECT_EQ(queue->size(), 1);
}

TEST_F(QueueTests, FullQueue) {
    CallInfo callInfo;
    for (int i = 0; i < 3; ++i) {
        queue->tryPush(callInfo);
    }
    EXPECT_EQ(queue->size(), 3);
    ASSERT_EQ(queue->tryPush(callInfo), false);
}

TEST_F(QueueTests, PopEmptyQueue) {
    EXPECT_EXIT(queue->pop(), ::testing::KilledBySignal(SIGSEGV), "");
}