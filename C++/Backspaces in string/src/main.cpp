#include <string>
#include <iostream>

std::string cleanString(const std::string &s) {
    std::string output;
    for (auto &&i : s)
    {
        if (i == '#' && output.size() > 0) {
            output.pop_back();
        } else if (i != '#'){
            output.push_back(i);
        }
    }
    return output;
}

int main(int argc, char const *argv[])
{
    std::cout << cleanString("Hello######") << std::endl;
    return 0;
}
