#include <string>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

std::unordered_map<std::string, int> numDict = {
    {"zero", 0},    {"one", 1},     {"two", 2},     {"three", 3},   {"four", 4},
    {"five", 5},    {"six", 6},     {"seven", 7},   {"eight", 8},   {"nine", 9},

    {"ten", 10},    {"twenty", 20},     {"thirty", 30}, {"forty", 40}, {"fifty", 50},
    {"sixty", 60},  {"seventy", 70},    {"eighty", 80}, {"ninety", 90},

    {"eleven", 11},     {"twelve", 12},     {"thirteen", 13},   {"fourteen", 14},   {"fifteen", 15},
    {"sixteen", 16},    {"seventeen", 17},  {"eighteen", 18},   {"nineteen", 19},

    {"hundred", 100},   {"thousand", 1000}, {"million", 1000000}

};

int commaSep(const std::string& input, std::size_t index)
{
    return numDict[input.substr(0, index)] + numDict[input.substr(index + 1)];
}

std::vector<int> toIntList(const std::string& input)
{
    std::vector<int> output;
    std::istringstream iss(input);
    std::string buff;
    while (std::getline(iss, buff, ' '))
    {
        if (numDict.find(buff) != numDict.end())
            output.push_back(numDict[buff]);
        else if (auto location = buff.find('-'); location != std::string::npos)
            output.push_back(commaSep(buff, location));
    }
    return output;
}

bool isMult(int input) { return input % 10 == 0 && input != 10; }

int stringToInt(const std::string& input)
{
    int total = 0;
    auto list = toIntList(input);
    for (auto&& i : list)
    {

    }
    return total;
}

int main(int argc, char const* argv[])
{
    std::string word = "seven hundred eighty-three thousand nine hundred and nineteen";

    for (auto&& i : toIntList(word))
        std::cout << i << ',' << '\n';

    std::cout << stringToInt(word) << '\n';
    return 0;
}
