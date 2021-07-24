#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

int sum_intervals(std::vector<std::pair<int, int>> intervals)
{
    std::size_t i = 0;
    std::size_t j = 0;
    while (i != intervals.size())
    {
        j = i + 1;
        auto &pair = intervals.at(i);
        while (j != intervals.size() - 1)
        {
            auto &comp = intervals.at(j);
            if (pair.first >= comp.first && pair.second <= comp.second)
            {
                pair.first = comp.first;
                pair.second = comp.second;
                intervals.erase(intervals.begin() + j);
            }
            else if (comp.first <= pair.second)
            {
                pair.first = std::min(pair.first, comp.first);
                pair.second = std::max(pair.second, comp.second);
                intervals.erase(intervals.begin() + j);
            }
        }
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    std::vector<std::pair<int, int>> intervals = {{1, 5}, {3, 10}};
    sum_intervals(intervals);
    for (auto &&i : intervals)
    {
        std::cout << i.first << i.second << '\n';
    }
    
    return 0;
}
