#pragma once

#include <iostream>
#include <fstream>
#include "json.hpp"

using namespace nlohmann;

class CParser
{
    public:
        CParser(const char* inputJasonFile);
        ~CParser();
        void    parseJSONInput(void);
    private:
        std::ifstream mInputFileStream;
};