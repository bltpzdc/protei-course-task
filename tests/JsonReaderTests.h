#include <gtest/gtest.h>
#include "../include/JsonReaderImpl.h"
#include <string>

class JsonReaderTests : public testing::Test {
public:
    static JsonReaderImpl *reader;
protected:
    static void SetUpTestCase() {
        reader = new JsonReaderImpl();
    }

    static void TearDownTestCase() {
        delete reader;
    }
};

JsonReaderImpl *JsonReaderTests::reader = nullptr;

TEST_F(JsonReaderTests, ReadingEmtpyString) {
    ASSERT_THROW(json data = reader->readRaw(""), nlohmann::detail::parse_error);
}

TEST_F(JsonReaderTests, ReadingInvalidString) {
    ASSERT_THROW(json data = reader->readRaw("{\"hello\": 3"), nlohmann::detail::parse_error);
}

TEST_F(JsonReaderTests, ReadingEmptyJson) {
    json data;
    ASSERT_NO_THROW(data = reader->readRaw("{}"));
}

TEST_F(JsonReaderTests, SearchingEmptyJson) {
    json data;
    EXPECT_NO_THROW(data = reader->readRaw("{}"));
    ASSERT_THROW(std::string sth = data["sth"], nlohmann::detail::type_error);
}

TEST_F(JsonReaderTests, SearchingStringInNonEmptyJson) {
    json data;
    EXPECT_NO_THROW(data = reader->readRaw("{\"value\": \"3\"}"));
    std::string value;
    EXPECT_NO_THROW(value = data["value"]);
    ASSERT_EQ(value, "3");
}

TEST_F(JsonReaderTests, SearchingIntInNonEmptyJson) {
    json data;
    EXPECT_NO_THROW(data = reader->readRaw("{\"value\": 3}"));
    int value;
    EXPECT_NO_THROW(value = data["value"]);
    ASSERT_EQ(value, 3);
}

TEST_F(JsonReaderTests, ReadingNonExistingFile) {
    ASSERT_THROW(reader->readFile("randomname.json"), NoSuchFileException);
}

TEST_F(JsonReaderTests, ReadingExistingFile) {
    json data;
    ASSERT_NO_THROW(data = reader->readFile("../tests/files/valid.json"));
    std::string hello = data["hello"];
    EXPECT_EQ(hello, "hello");
}