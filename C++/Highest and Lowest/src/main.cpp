#include <string>
#include <iostream>

std::string highAndLow(const std::string& numbers){
    int highest = INT32_MIN;
    int lowest = INT32_MAX;
    int j = 0;
    std::string number;
    for (auto &&i : numbers)
    {
        if (j == numbers.size()-1) number += i;
        if (i == ' ' || j == numbers.size()-1) {
            int num = std::stoi(number);
            if (num > highest) highest = num;
            if (num < lowest) lowest = num;
            number = "";
        } else {
            number += i;
        }
        j++;
    }
    return (std::to_string(highest) + " " + std::to_string(lowest));
}

#include <string>
#include <sstream>
#include <limits>

std::string highAndLowV2(const std::string& numbers){
  std::stringstream ss(numbers);
  int temp, min = std::numeric_limits<int>::max(), max = std::numeric_limits<int>::min();
  while (ss >> temp) {
    min = (temp < min) ? temp : min;
    max = (temp > max) ? temp : max;
  };
  return std::to_string(max) + " " + std::to_string(min);
}

int main(int argc, char const *argv[])
{
    std::cout << highAndLow("6 7 -20 7 1 3 5 1 0") << std::endl;
    return 0;
}
