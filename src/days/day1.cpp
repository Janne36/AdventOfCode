#include "day1.hpp"

namespace code {
namespace day1 {

namespace {

std::vector<uint32_t> GetReport(const std::string filePath) 
{
    std::vector<std::string> dataStr;
    // FIXME: ../
    bool success = code::utils::ReadFileToVec(filePath, dataStr);
    
    if (false == success) throw "Could not read vec !!!";

    std::vector<uint32_t> dataInt; 
    const auto strToInt = [](const std::string str)  {
        return static_cast<uint32_t>(std::stoi(str));
    };

    // Transform str vec to int
    std::transform(
        dataStr.begin(), 
        dataStr.end(),
        std::back_inserter(dataInt),
        strToInt
    );

    return dataInt;
}
// TODO: Is there a way to merge these two functions?
std::vector<uint32_t> FindTwoValues(
    const uint32_t& sumToFind,
    const std::vector<uint32_t>& expenseReport)
{
    std::vector<uint32_t> matches;
    for (const auto& val1 : expenseReport) 
    {
        for (const auto& val2 : expenseReport) 
        {   
            if(val1 + val2 == sumToFind)
            {
                matches.push_back(val1);
                matches.push_back(val2);
                return matches;
            }
        }
    }
    return {}; 
};

std::vector<uint32_t> FindThreeValues(
    const uint32_t& sumToFind,
    const std::vector<uint32_t>& expenseReport)
{
    std::vector<uint32_t> matches;
    for (const auto& val1 : expenseReport) 
    {
        for (const auto& val2 : expenseReport) 
        {   
            for (const auto& val3 : expenseReport) 
            {  
                if(val1 + val2 + val3 == sumToFind)
                {
                    matches.push_back(val1);
                    matches.push_back(val2);
                    matches.push_back(val3);
                    return matches;
                }
            }
        }
    }
    return {}; 
};

const uint32_t accumulateVec(const std::vector<uint32_t>& vec)
{
    return std::accumulate(vec.begin(), vec.end(), 1, std::multiplies<int>());
}

} // namespace

void Run()
{
    std::cout << "Day1" << "\n";
    constexpr uint16_t sumToFind = 2020;
    const std::vector<uint32_t> expenseReport = GetReport("../inputs/inputDay1.txt");

    const std::vector<uint32_t> values1 = FindTwoValues(sumToFind, expenseReport);
    const std::vector<uint32_t> values2 = FindThreeValues(sumToFind, expenseReport);
    
    const uint32_t solution1 = accumulateVec(values1);
    const uint32_t solution2 = accumulateVec(values2);

    //code::utils::PrintVector<uint32_t>(values1);
    //code::utils::PrintVector<uint32_t>(values2);

    // TODO: Ut
    std::cout << "Solution1: " << solution1 << "\n"; // correct: 793524
    std::cout << "Solution2: " << solution2 << "\n"; // correct: 61515678
}

} //namespace day1
} //namespace code