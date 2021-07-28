#include <vector>
#include <string>
#include <utility>
#include <optional>
#include <set>

typedef std::vector<std::vector<char>> board_t;
typedef std::vector<std::pair<int, int>> posList_t;

bool valid_pos(std::pair<int, int> pos, const board_t& board)
{
    if (pos.first < 0 || pos.first > board.size() - 1 || pos.second < 0 || pos.second > board.size() - 1)
        return false;
    else
        return true;
}

char charAt(const std::pair<int, int>& pos, const board_t& board)
{
    if (valid_pos(pos, board))
        return board[pos.second][pos.first];
    else
        return '0';
}

/**
 * For given position, and a list of used positions and a char, it will return a list of availble new positions that contain c from the current position
 **/
posList_t find_valid_pos(const board_t& board, const std::pair<int, int>& currentPos, const char& c, const std::set<std::pair<int, int>> used_spots)
{
    posList_t output;
    for (int y = -1; y <= 1; y++)
    {
        for (int x = -1; x <= 1; x++)
        {
            std::pair<int, int> pos = { currentPos.first + x, currentPos.second + y };
            if (valid_pos(pos, board) && !used_spots.contains(pos) && charAt(pos, board) == c)
                if (x != 0 || y != 0)
                    output.emplace_back(pos);
        }
    }
    return output;
}

/**
 * Finds all positions of the board that contain the char c
 **/
posList_t find_pos_of_char(const board_t& board, const char& c)
{
    posList_t list;
    for (size_t y = 0; y < board.size(); y++)
    {
        for (size_t x = 0; x < board[0].size(); x++)
        {
            if (board[y][x] == c)
                list.emplace_back(x, y);
        }
    }
    return list;
}

bool find_word(const board_t& board, const std::pair<int, int> pos, const std::string& word, std::set<std::pair<int, int>> used_spots)
{
    if (word.size() == 0)
        return true;
    auto list = find_valid_pos(board, pos, word[0], used_spots);
    for (auto &&i : list)
    {
        used_spots.emplace(pos);
        if (find_word(board, i, word.substr(1), used_spots))
            return true;
        used_spots.erase(used_spots.end());
    }
    return false;   
}

bool check_word(const std::vector<std::vector<char>>& board, const std::string& word)
{
    std::set<std::pair<int, int>> used_spots;
    auto starting_pos = find_pos_of_char(board, word[0]);
    if (starting_pos.size() == 0)
        return false;
    for (auto&& i : starting_pos)
    {
        if(find_word(board, i, word, used_spots))
            return true;
    }
    return false;
}