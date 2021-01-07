#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <vector>

class WeightSort
{
public:
    static std::string orderWeight(const std::string &strng);
private:
    static bool weightSort(std::string i, std::string j);
};

bool WeightSort::weightSort(std::string i, std::string j) {
    int temp_i = 0;
    int temp_j = 0;
    for (auto &&c_i : i)
    {
        temp_i += c_i - '0';
    }
    for (auto &&c_j : j)
    {
        temp_j += c_j - '0';
    }
    if (temp_i == temp_j) return (i < j);
    else return (temp_i < temp_j);
}

std::string WeightSort::orderWeight(const std::string &string) {
    std::vector<std::string> output;
    std::stringstream ss(string);
    std::string temp;
    while (ss >> temp) {
        output.push_back(temp);
    }
    std::sort(output.begin(), output.end(), weightSort);

    if (output.size() == 0) return "";
    else {
        std::ostringstream oss;
        for (size_t i = 0; i < output.size()-1; i++)
        {
            oss << output.at(i) << " ";
        }
        oss << output.back();
        return oss.str();
    }
}

int main(int argc, char const *argv[])
{
    // std::vector<std::string> output = WeightSort::orderWeight(" 103  123 4444 99 2000");

    // std::cout << sortFunc("2000", "11") << std::endl;

    std::string output;
    output = WeightSort::orderWeight("103 123 4444 99 2000");
    std::cout << output << std::endl;
    output = WeightSort::orderWeight("2000 10003 1234000 44444444 9999 11 11 22 123");
    std::cout << output << std::endl;
    output = WeightSort::orderWeight("");
    std::cout << output << std::endl;
    output = WeightSort::orderWeight("103 123 4444 99 2000 ");
    std::cout << output << std::endl;
}
