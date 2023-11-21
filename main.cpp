#include <iostream>
#include "include/Config.h"
#include "./include/JsonReaderImpl.h"

int main()
{
    Config &config = Config::getInstance();
    JsonReader *reader = new JsonReaderImpl();
    std::cout << reader->readFile("./../config.json")["pi"];
    delete reader;
    return 0;
}
