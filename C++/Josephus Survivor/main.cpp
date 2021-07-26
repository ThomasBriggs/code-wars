#include <forward_list>
#include <algorithm>
#include <iostream>
#include <numeric>

int josephusSurvivor(int n, int k)
{
    if (k == 1)
      return n;
    std::forward_list<int> list(n);
    std::iota(list.begin(), list.end(), 1);
    int count = k;
    auto currentNode = list.begin();
    while (n > 1)
    {
        count--;
        if (count == 1)
        {
            if (currentNode._M_next() == list.end())
                list.pop_front();
            else
                list.erase_after(currentNode);
            n--;
            count = k;
        }
        if (currentNode._M_next() == list.end())
            currentNode = list.begin();
        else
            currentNode = currentNode._M_next();
    }
    return list.front();
}

int main(int argc, char const *argv[])
{
    std::cout << josephusSurvivor(100, 1) << '\n';
    return 0;
}
