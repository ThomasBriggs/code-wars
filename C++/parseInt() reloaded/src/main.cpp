#include <string>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

std::unordered_map<std::string, int> numDict = {
    {"zero", 0},    {"one", 1},     {"two", 2},     {"three", 3},   {"four", 4},
    {"five", 5},    {"six", 6},     {"seven", 7},   {"eight", 8},   {"nine", 9},

    {"ten", 10},    {"twenty", 20},     {"thirty", 30}, {"fourty", 40}, {"fifty", 50},
    {"sixty", 60},  {"seventy", 70},    {"eighty", 80}, {"ninety", 90},

    {"eleven", 11},     {"twelve", 12},     {"thirteen", 13},   {"fourteen", 14},   {"fifteen", 15},
    {"sixteen", 16},    {"seventeen", 17},  {"eighteen", 18},   {"nineteen", 19},

    {"hundred", 100},   {"thousand", 1000}, {"million", 1000000}

};

std::vector<std::string> split(const std::string& data)
{
    std::vector<std::string> output;
    std::istringstream iss(data);
    std::string buff;
    while (std::getline(iss, buff, ' '))
        output.push_back(buff);
    return output;
}


int stringToInt(const std::string& input)
{
    int total = 0;
    auto list = split(input);
    for (auto &&i : list)
    {
        if (numDict.contains(
            
        ))
        total += numDict[i];
    }
    return total;
}

int main(int argc, char const* argv[])
{
    std::cout << stringToInt("thirty-two") << '\n';
    return 0;
}
