#include <string>
#include <vector>
#include <iostream>

std::string likes(const std::vector<std::string> &names)
{
    if (names.size() == 0) return "no one likes this";
    else if (names.size() == 1) return (names.at(0) + " likes this");
    else if (names.size() == 2) return (names.at(0) + " and " + names.at(1) + " like this");
    else if (names.size() == 3) return (names.at(0) + ", " + names.at(1) + " and " + names.at(2) + " like this");
    else return (names.at(0) + ", " + names.at(1) + " and " + std::to_string(names.size()-2) + " others like this");
}

int main(int argc, char const *argv[])
{
    std::cout << likes({"Thomas", "Bob", "Mark", "Clo"}) << std::endl;
    return 0;
}