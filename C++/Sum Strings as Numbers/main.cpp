#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

std::string sum_strings(const std::string &a, const std::string &b)
{
    const int DEFAULT_CHUNK_SIZE = 10;
    std::string total = "";
    int max_size = std::max(a.size(), b.size());
    int min_size = std::min(a.size(), b.size());
    const int CHUNK_SIZE = std::min(min_size, DEFAULT_CHUNK_SIZE);
    int loop_amount = max_size / CHUNK_SIZE;
    for (size_t i = 0; i < loop_amount; i++)
    {
        long long i1 = stoll(a.substr(a.size() - (i * CHUNK_SIZE) - CHUNK_SIZE, CHUNK_SIZE));
        long long i2 = stoll(b.substr(b.size() - (i * CHUNK_SIZE) - CHUNK_SIZE, CHUNK_SIZE));
        total = std::to_string(i1 + i2) + total;
    }
    long long i1 = stoll(a.substr(0, min_size - (CHUNK_SIZE * loop_amount)));
    long long i2 = stoll(b.substr(0, min_size - (CHUNK_SIZE * loop_amount)));
    total = std::to_string(i1 + i2) + total;
    return total;
}

void test(const char *str)
{
    std::cout << "Input Len: " << std::strlen(str) << '\n'
              << '\n';
    std::cout << "Output Len: " << sum_strings(str, str).size() << '\n';
    std::cout << sum_strings(str, str) << '\n';
}

int main(int argc, char const *argv[])
{
    const char *working = "1111111111";
    test(working);
    return 0;
}
