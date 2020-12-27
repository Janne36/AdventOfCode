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

} //namespace utils
} //namespace code