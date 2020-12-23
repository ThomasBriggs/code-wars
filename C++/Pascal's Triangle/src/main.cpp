#include <vector>
#include <iostream>

std::vector<long long> pascalsTriangle(int n)
{
  std::vector<long long> res;
  for (int i = 0; i < n; i++)
  {
    long long num = 1;
    for (int j = 0; j < i + 1; j++)
    {
      res.push_back(num);

      num = (num * (i - j)) / (j + 1);
    }
  }
  return res;
}

int main()
{
  auto test = pascalsTriangle(10);
  for (auto &&i : test)
  {
    std::cout << i << ", ";
  }
  std::cout << std::endl;
}