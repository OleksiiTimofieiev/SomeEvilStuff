#include "CParser.hpp"

CParser::CParser(const char* inputJasonFile) : mInputFileStream(inputJasonFile) {}
CParser::~CParser() {}

void    CParser::parseJSONInput(void)
{
    json j = json::parse(mInputFileStream, nullptr, false);

    for (auto & el : j.items()) 
    {
        if (el.key() == "boxes")
        {
            // std::cout << el.key() << " : " << el.value() << "\n";
            // std::cout << el["maxCarryingCapacity"];

            auto test = el.value();

            auto test1 = test[0];

            // auto test1 = test["maxCarryingCapacity"];
            
            // std::cout << test1["half_x"];

            std::cout << test1["boxId"];
        }
    }
}