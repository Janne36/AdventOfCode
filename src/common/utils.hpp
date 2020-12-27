#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>

namespace code {
namespace utils {

bool ReadFileToVec(const std::string& filePath, std::vector<std::string>& vec);

template <typename T>
void PrintVector(const std::vector<T> vector) 
{
    for (const auto& val : vector) 
    {
        std::cout << val << "\n";
    }
};

} //namespace utils
} //namespace code