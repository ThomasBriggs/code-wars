#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

int sum_intervals(std::vector<std::pair<int, int>> v)
{
    std::sort(v.begin(), v.end(), [](auto i, auto o)
              { return i.first == o.first ? i.second < o.second
                                          : i.first < o.first; });
    int total = 0;
    int start = v[0].first;
    int max = 0;
    for (auto &&i : v)
    {
        if (i.first != start && i.first > max)
        {
            total += max - start;
            start = i.first;
            max = i.second;
        }
        else if (i.second > max)
            max = i.second;
    }
    return total += max - start;
}

int main(int argc, char const *argv[])
{
    std::vector<std::pair<int, int>> intervals = {{-433, -298},
                                                  {-290, 268},
                                                  {-268, 172},
                                                  {-40, 203},
                                                  {141, 348},
                                                  {195, 332},
                                                  {316, 317},
                                                  {433, 464}};
    std::cout << sum_intervals(intervals) << '\n';
    return 0;
}
