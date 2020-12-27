#include "day3.hpp"

namespace code {
namespace day3 {

namespace {

const uint32_t CheckMap(
    const std::vector<std::string>& map, 
    const uint8_t& xOffset,
    const uint8_t& yOffset) 
{
    uint32_t treesCount = 0;
    uint32_t xPos = xOffset;
    uint32_t yPos = yOffset;
    const uint16_t lineSize = map.front().size();

    for(yPos; yPos < map.size(); yPos += yOffset)
    {
        const char square = map[yPos].at(xPos);
        if (square == tree) treesCount++;

        // Add xOffset to xPos and check if we are out-of-pounds
        // if so, "reset" xPos by removing lineSize
        // TODO: Quite ugly, can this be done better?
        xPos += xOffset;
        if(xPos >= lineSize) xPos -= lineSize;      
    }

    return treesCount;
}

} // namespace

void Run() 
{
    std::cout << "Day3" << "\n";
    std::vector<std::string> dataStr;
    // FIXME: ../
    bool success = code::utils::ReadFileToVec("../inputs/inputDay3.txt", dataStr);
    if (false == success) throw "Could not read vec !!!";

    // xPos, yPos
    const std::vector<std::pair<uint8_t, uint8_t>> slopes {
        {1, 1}, // Correct: 66
        {3, 1}, // Correct: 200
        {5, 1}, // Correct: 76
        {7, 1}, // Correct: 81
        {1, 2}  // Correct: 46
    };

    std::vector<uint32_t> values;
    for (const auto& slope : slopes) 
    {
        const uint32_t treesFound = CheckMap(dataStr, slope.first, slope.second);
        values.push_back(treesFound);
    }
    const uint32_t solutionPart2 = code::utils::accumulateVec(values);

    std::cout << "Part 1 " << values.at(1) << "\n"; // 200
    std::cout << "Part 2 " << solutionPart2 << "\n"; // correct 3737923200
}

} //namespace day3
} //namespace code