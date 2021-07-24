#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>

std::string sum_strings(const std::string &a, const std::string &b)
{
    std::stringstream ss;
    bool hit_max = false;
    long long total = 0;
    int mult = 1;
    int max_size = std::max(a.size(), b.size());
    for (size_t i = 0; i < max_size; i++)
    {
        total += mult * ((int)(*a.rbegin()-i) - '0' + (int)(*b.rbegin()-i) - '0');
        mult *= 10;
    }
    return std::to_string(total);
}

int main(int argc, char const *argv[])
{
    std::cout << sum_strings("123", "123") << '\n';
    return 0;
}
