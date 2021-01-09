#include <string>
#include <sstream>
#include <iostream>
#include <cctype>

std::string pig_it(std::string str)
{
    std::string token;
    std::stringstream ss(str);
    std::ostringstream oss;
    while (ss >> token) {
        if (std::isalpha(token.at(0)))
        oss << token.substr(1, token.size() - 1) << token.at(0) << "ay" << " ";
        else oss << token << " ";
    }
    return oss.str().substr(0, oss.str().size() - 1);
}

#include <regex>

std::string pig_it_regex(std::string Z) {
    std::regex reg(("(\\w)(\\w*)(\\s|$)"));
    return regex_replace(Z, reg, "$2$1ay$3");
}

int main(int argc, char const *argv[])
{
    std::cout << pig_it("Hello how are you ?") << std::endl;
    return 0;
}
