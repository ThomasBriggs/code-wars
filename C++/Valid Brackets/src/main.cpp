#include <vector>
#include <iostream>
#include <string>

bool valid(const std::string &braces) {
    char closeBrackets[] = {')', '}', ']'};
    std::vector<int> open;
    open.reserve(braces.size()/2);
    for (auto && c : braces)
    {
        switch (c)
        {
        case '(':
            open.push_back(0);
            break;
        case '{':
            open.push_back(1);
            break;
        case '[':
            open.push_back(2);
            break;
        default:
            if (c == closeBrackets[open.back()]) {
                open.pop_back();
            } else {
                return false;
            }
        }
    }
    return open.empty();
}

int main(int argc, char const *argv[])
{
    std::cout << valid("{()()}{}") << std::endl;
    return 0;
}
