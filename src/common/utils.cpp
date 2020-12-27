#include "utils.hpp"

namespace code {
namespace utils {

bool ReadFileToVec(const std::string& filePath, std::vector<std::string>& vec) 
{
    std::ifstream in(filePath.c_str());

    if(!in) 
    {
        std::cerr << "File not open : " << filePath << "\n";
        return false;
    }

    std::string str;
    while (std::getline(in, str))
    {
        if(str.size() > 0) vec.push_back(str);
    }
    in.close();

    return true;
};

const uint32_t accumulateVec(const std::vector<uint32_t>& vec)
{
    return std::accumulate(vec.begin(), vec.end(), 1, std::multiplies<int>());
}


} //namespace utils
} //namespace code