#include <gtest/gtest.h>
#include "../include/Config.h"

class ConfigTests : public testing::Test {
protected:
    void SetUp() {
        Config::clear();
        Config::setFilename("../tests/files/valid_config.json");
        Config::getInstance();
    }
};

TEST_F(ConfigTests, CorrectInit) {
    EXPECT_EQ(Config::getInstance().getQLen(), 3);
    EXPECT_EQ(Config::getInstance().getOperatorsCount(), 2);
    EXPECT_EQ(Config::getInstance().getNextUpdateTime(), 20);
    EXPECT_EQ(Config::getInstance().getRandomExpirationTimeMax(), 20);
    EXPECT_EQ(Config::getInstance().getRandomExpirationTimeMin(), 10);
    EXPECT_EQ(Config::getInstance().getCDRFile(), "../cdr.txt");
}

TEST_F(ConfigTests, CorrectUpdate) {
    Config::setFilename("../tests/files/update_config_valid.json");
    ASSERT_NO_THROW(Config::update());
    EXPECT_EQ(Config::getInstance().getQLen(), 2);
    EXPECT_EQ(Config::getInstance().getOperatorsCount(), 1);
    EXPECT_EQ(Config::getInstance().getNextUpdateTime(), 10);
    EXPECT_EQ(Config::getInstance().getRandomExpirationTimeMax(), 10);
    EXPECT_EQ(Config::getInstance().getRandomExpirationTimeMin(), 5);
    EXPECT_EQ(Config::getInstance().getCDRFile(), "../cdr2.txt");
}

TEST_F(ConfigTests, CorrectUpdateWithoutCDR) {
    Config::setFilename("../tests/files/update_config_without_cdr.json");
    ASSERT_NO_THROW(Config::update());
    EXPECT_EQ(Config::getInstance().getQLen(), 3);
    EXPECT_EQ(Config::getInstance().getOperatorsCount(), 2);
    EXPECT_EQ(Config::getInstance().getNextUpdateTime(), 20);
    EXPECT_EQ(Config::getInstance().getRandomExpirationTimeMax(), 20);
    EXPECT_EQ(Config::getInstance().getRandomExpirationTimeMin(), 10);
    EXPECT_EQ(Config::getInstance().getCDRFile(), "");
}

TEST_F(ConfigTests, UpdateWithInvalidJson) {
    Config::setFilename("../tests/files/invalid_config.json");
    ASSERT_NO_THROW(Config::update());
    EXPECT_EQ(Config::getInstance().getQLen(), 3);
    EXPECT_EQ(Config::getInstance().getOperatorsCount(), 2);
    EXPECT_EQ(Config::getInstance().getNextUpdateTime(), 20);
    EXPECT_EQ(Config::getInstance().getRandomExpirationTimeMax(), 20);
    EXPECT_EQ(Config::getInstance().getRandomExpirationTimeMin(), 10);
    EXPECT_EQ(Config::getInstance().getCDRFile(), "../cdr.txt");
}



