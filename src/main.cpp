#include <iostream>
#include "main.hpp"
#include "StringUtils.hpp"

#include <vector>
#include <string>
#include <tuple>

int main(int argc, char** argv)
{
    // Tests unitaires (vector de tuple de string)
    std::vector<std::tuple<std::string, std::string, bool>> unitTests = {
        std::make_tuple("Hello, World!", "Hello, World!", true),
        std::make_tuple("Hello, World!", "Hello, World!*", true),
        std::make_tuple("Hello, World!", "*Hello, World!", true),
        std::make_tuple("Hello, World!", "Hello,*World!", true),
        std::make_tuple("Hello, World!", "Hello, *World!", true),
        std::make_tuple("Hello, World!", "*H**Wo*ld!**", true),
        std::make_tuple("Hello, World!", "S**Wo*ld!**", false),
        std::make_tuple("Hello, World!", "H**Wo*ld!**S", false),
        std::make_tuple("Hello, World!", "Hello,World!", false),
        std::make_tuple("Hello, World!", "Hello,World!*", false),
        std::make_tuple("Hello, World!", "Hel*l*lo, World!", false),
        std::make_tuple("Hello, World!", "Rien a voir", false),
    };

    bool testSucceed = true;
    for (const auto& test : unitTests)
    {
        const std::string& str = std::get<0>(test);
        const std::string& pattern = std::get<1>(test);
        const bool res = std::get<2>(test);

        const bool isMatch = StringUtils::match(str, pattern);

        if (isMatch != res)
        {
            std::cout << "Test failed: " << str << " ; " << pattern << " ; " << isMatch << " ; " << res << std::endl;
            testSucceed = false;
        }
    }

    if (testSucceed)
    {
        std::cout << "All tests succeed!" << std::endl;
    }
    
    std::cout << "Hello, World!" << std::endl;
    return 0;
}