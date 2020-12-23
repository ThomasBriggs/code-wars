#include <vector>
#include <iostream>
#include <string>

std::vector<std::string> wave(std::string y) {
    std::vector<std::string> output;
    for (size_t i = 0; i < y.length(); i++)
    {
        if (y[i] != ' ') {
            char Uppercase = toupper(y[i]);
            output.push_back(y.substr(0, i) + Uppercase + y.substr(i + 1, y.length()));
        }
    }
    return output;
}

int main(int argc, char const *argv[])
{
    auto test = wave("");
    for (auto &&i : test)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
    return 0;
}
