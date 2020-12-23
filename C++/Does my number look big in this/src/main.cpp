#include <iostream>
#include <cmath>
#include <chrono>

bool narcissistic( int value ){
    std::string digits = std::to_string(value);
    int length = digits.length();
    int total = 0;
    for (size_t i = 0; i < length; i++) {
        total += std::pow(digits[i] - '0', length);
    }
    return (total == value);
}

bool narcissisticV2( int value ){

  int n = value;
  int i = log10(value) + 1; //get the number of digits in "number"
  int sum = 0;
  
  while (n) {
    sum += pow(n%10, i);
    n /= 10;
  }
  
  return sum == value;
}

int main(int argc, char const *argv[])
{
    std::cout << narcissistic(37112342) << std::endl;
    return 0;
}
