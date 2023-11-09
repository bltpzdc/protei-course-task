#include <iostream>
#include "include/config.h"

int main()
{
    Config& config = Config::getInstance();
    std::cout << config.getQLen() << std::endl;
}
