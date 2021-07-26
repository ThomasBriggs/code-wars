#include <iostream>
#include "Boggle.h"

int main(int argc, char const *argv[])
{
    t_board test_board = {{'E', 'A', 'R', 'A'},
                          {'N', 'L', 'E', 'C'},
                          {'I', 'A', 'I', 'S'},
                          {'B', 'Y', 'O', 'R'}};

    std::set<std::pair<int, int>> set;
    auto list = valid_chars(test_board, find_pos(test_board, 'R'), set);
    for (auto &&i : list)
    {
        std::cout << i << '\n';
    }
    std::cout << "\n\n";


    list = valid_chars(test_board, find_pos(test_board, 'R'), set);
    for (auto &&i : list)
    {
        std::cout << i << '\n';
    }
    return 0;
}
