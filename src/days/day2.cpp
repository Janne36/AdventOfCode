#include "day2.hpp"

namespace code {
namespace day2 {

namespace {

const inline std::string GetMinMax(const std::string& s) 
{
    // Find first whitespace, then pick min-max part
    const size_t wPos = s.find(" ");
    return s.substr(0, wPos);
}

const inline uint16_t GetMin(const std::string& s) 
{
    // Find delimiter, then use it to find min (from start to delimiter)
    const std::string minMax = GetMinMax(s);
    const size_t dPos = s.find("-");
    const std::string min = minMax.substr(0, dPos);

    return std::stoi(min);
}

const inline uint16_t GetMax(const std::string& s) 
{
    // Find delimiter, then use it to find min (from delimiter to string end)
    const std::string minMax = GetMinMax(s);
    const size_t dPos = s.find("-");
    const std::string max = minMax.substr(dPos + 1, std::string::npos);

    return std::stoi(max);
}

const inline std::string GetPassword(const std::string& s) 
{
    // Get start position of "password" part. Add +1 for whitespace
    // Could also just remove it with s.erase. but data is consistent so there is no real need.
    const std::string delimiter = ":";
    const size_t startPos = s.find(delimiter) + delimiter.length() + 1;
    const std::string password = s.substr(startPos, std::string::npos);

    return password;
}

const inline char GetPolicy(const std::string& s) 
{
    // "Policy" is next to delimiter so find it and remove one.
    // Then pick one char after startPos. A litte janky but works
    const std::string delimiter = ":";
    const size_t startPos = s.find(delimiter) - 1;
    const char policy = s.substr(startPos, 1)[0];

    return policy;
}

const std::vector<PasswordData> ParseData(const std::vector<std::string>& dataStr) 
{
    std::vector<PasswordData> pwData;
    for(const auto& dataLine : dataStr)
    {
        pwData.push_back({
            .min = GetMin(dataLine),
            .max = GetMax(dataLine),
            .policy = GetPolicy(dataLine),
            .password = GetPassword(dataLine)
        });      
    }

    return pwData;
}

const uint32_t CheckPwDataPart1(const std::vector<PasswordData>& pwData)
{
    uint32_t validCount = 0;
    for(const auto& data : pwData)
    {
        const uint16_t pCount = std::count(
            data.password.begin(), 
            data.password.end(), 
            data.policy
        );
        // We could also map each data structure to be valid or invalid but it isn't required here
        if (data.min <= pCount && pCount <= data.max) validCount++;       
    }
    return validCount;
}

const uint32_t CheckPwDataPart2(const std::vector<PasswordData>& pwData)
{
    uint32_t validCount = 0;
    for(const auto& data : pwData)
    {
        try 
        {
            // Substract one due to moronic corporate... :)
            const char cFirst = data.password.at(data.min - 1);
            const char cSecond = data.password.at(data.max - 1);

            if ((data.policy == cFirst || data.policy == cSecond) && cFirst != cSecond) validCount++;

        } catch (...) {
            continue;
        }
    }
    return validCount;
}

} // namespace

void Run() 
{
    std::cout << "Day2" << "\n";
    std::vector<std::string> dataStr;
    // FIXME: ../
    bool success = code::utils::ReadFileToVec("../inputs/inputDay2.txt", dataStr);
    if (false == success) throw "Could not read vec !!!";

    const std::vector<PasswordData> pwData = ParseData(dataStr);
    const uint32_t validPws1 = CheckPwDataPart1(pwData); // Correct: 572
    const uint32_t validPws2 = CheckPwDataPart2(pwData); // Correct: 306

    std::cout << "Part 1:" << validPws1 << "\n";
    std::cout << "Part 2:" << validPws2 << std::endl;
}

} //namespace day2
} //namespace code