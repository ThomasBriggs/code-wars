#include <string>
#include <iostream>

int largest_five_digits(const std::string &digits)
{
    int largest_pos = 0;
    for (size_t i = 0; i < digits.length() - 4; i++)
    {
        if (digits.at(i) > digits.at(largest_pos))
        {
            largest_pos = i;
        }
    }
    std::string largest = digits.substr(largest_pos, 5);
    return std::stoi(largest);
}

int main(int argc, char const *argv[])
{
    int largest;
    largest = largest_five_digits("1234567890");
    std::cout << largest << std::endl;
    std::cin.get();
    return 0;
}
