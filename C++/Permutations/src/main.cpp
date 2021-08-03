#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <unordered_set>
#include <sstream>

void perm_rec(int k, std::string& s, std::unordered_set<std::string>& perms)
{
    if (k == 1)
    {
        if (perms.find(s) == perms.end())
            perms.insert(s);
        return;
    }
    else
    {
        perm_rec(k - 1, s, perms);
        for (int i = 0; i < k-1; i++)
        {
            if (k % 2 == 0)
                std::swap(s[i], s[k-1]);
            else
                std::swap(s[0], s[k-1]);
            perm_rec(k-1, s, perms);
        }
    }
}

std::vector<std::string> permutations(std::string s) {
    std::unordered_set<std::string> perms;
    perm_rec(s.size(), s, perms);
    std::vector<std::string> o;
    o.reserve(perms.size());
    o.insert(o.end(), perms.begin(), perms.end());
    return o;
}

int main()
{
    auto output = permutations("abcde");
    std::stringstream ss;
    for (auto &&i : output)
    {
        ss << i << ", ";
    }
    std::cout << ss.rdbuf();
    return 0;
}
