#include <vector>
#include <string>
#include <unordered_map>
#include <array>

#include <iostream>

std::array<std::array<char, 7>, 6> readBoard(std::vector<std::string> moveList) {

    std::array<std::array<char, 7>, 6> board = {{'0'}};

    std::unordered_map<char, int> cols_map = {
        {'A', 0},
        {'B', 1},
        {'C', 2},
        {'D', 3},
        {'E', 4},
        {'F', 5},
        {'G', 6}
    };

    std::unordered_map<std::string, char> player_map = {
        {"Red", 'R'},
        {"Yellow", 'Y'},
    };

    for (auto &&i : moveList)
    {
        int col = cols_map.at(i.at(0));
        int player = player_map.at(i.substr(2, i.back()));
        int row = board.size() - 1;
        while (board[row][col] != 0) {
            row -= 1;
        }
        board[row][col] = player;
    }
    return board;
}

int main(int argc, char const *argv[])
{
    std::vector<std::string> a;
    // a = {"A_Red", "B_Yellow", "A_Red"};
    a = {
                "A_Yellow",
                "B_Red",
                "B_Yellow",
                "C_Red",
                "G_Yellow",
                "C_Red",
                "C_Yellow",
                "D_Red",
                "G_Yellow",
                "D_Red",
                "G_Yellow",
                "D_Red",
                "F_Yellow",
                "E_Red",
                "D_Yellow"
    };


    auto board = readBoard(a);
    
    for (auto &&i : board)
    {
        for (auto &&j : i)
        {
            if (j != '')
                std::cout << j << ", ";
            else 
                std::cout << "0" << ", ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}
