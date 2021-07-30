#include <string>
#include <iostream>
#include <unordered_map>
#include <set>
#include <sstream>
#include <algorithm>

class Mix
{
public:
    static std::string mix(const std::string& s1, const std::string& s2)
    {
        auto s1Freq = getFreq(s1);
        auto s2Freq = getFreq(s2);

        auto cmp = [](auto x, auto y)
        {
            auto& [x1, x2, x3] = x;
            auto& [y1, y2, y3] = y;
            if (y1 == x1)
                if (y2 == x2)
                    if (y3 == x3)
                        return x2 < y2;
                    else
                        return x3 < y3;
                else
                    return x2 < y2;
            else
                return x1 < y1;
        };
        std::set < std::tuple<int, char, char>, decltype(cmp)> maxFreqList(cmp);
        for (auto&& i : s1Freq)
        {
            if (s2Freq[i.first] == 0 || std::max(s1Freq[i.first], s2Freq[i.first]) < 2)
                ;
            else if (s1Freq[i.first] > s2Freq[i.first])
                maxFreqList.emplace(s1Freq[i.first], i.first, '1');
            else if (s1Freq[i.first] == s2Freq[i.first])
                maxFreqList.emplace(s1Freq[i.first], i.first, '=');
            else
                maxFreqList.emplace(s2Freq[i.first], i.first, '2');
        }


        std::stringstream ss;
        for (auto j = maxFreqList.rbegin(); j != maxFreqList.rend(); ++j)
        {
            auto&& [amount, c, s] = *j;
            ss << s << ':' << std::string(amount, c) << '/';
        }
        return ss.str();
    }

    static std::unordered_map<char, int> getFreq(const std::string& s)
    {
        std::unordered_map<char, int> freqMap;
        for (auto&& i : s)
        {
            if (std::isalpha(i) && std::islower(i))
            {
                freqMap[i]++;
            }
        }
        return freqMap;
    }
};

int main(int argc, char const* argv[])
{
    auto s1 = "Are they here";
    auto s2 = "yes, they are here";
    std::cout << Mix::mix(s1, s2) << '\n';
    return 0;
}

