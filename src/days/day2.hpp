#pragma once

#include <iostream>
#include "../common/utils.hpp" // TODO: Fix ..

namespace code {
namespace day2 {
namespace {

struct PasswordData 
{
    uint16_t min;
    uint16_t max;
    char policy;
    std::string password;
};

}

void Run();

} //namespace day2
} //namespace code