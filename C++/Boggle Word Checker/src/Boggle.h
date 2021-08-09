#include <vector>
#include <string>
#include <unordered_set>

typedef std::vector<std::vector<char>> board_t;
typedef std::pair<unsigned int, unsigned int> pos_t;
typedef std::vector<pos_t> posList_t;


struct pos_t_hash
{
    std::size_t operator()(const pos_t& x) const
    {
        return std::hash<unsigned int>()(x.first) ^ std::hash<unsigned int>()(x.second);
    }
};
typedef std::unordered_set<pos_t, pos_t_hash> usedspots_t;

bool valid_pos(const pos_t& pos, const board_t& board)
{
    if (pos.first > board.size() - 1 || pos.second > board.size() - 1)
        return false;
    else
        return true;
}

char charAt(const pos_t& pos, const board_t& board)
{
    if (valid_pos(pos, board))
        return board[pos.second][pos.first];
    else
        return '0';
}

/**
 * For given position, a list of used positions and a char, it will return a list of availble new positions that contain c from the current position
 **/
posList_t find_valid_pos(const board_t& board, const pos_t& currentPos, const char& c, const usedspots_t used_spots)
{
    posList_t output;
    for (int y = -1; y <= 1; y++)
    {
        for (int x = -1; x <= 1; x++)
        {
            pos_t pos = { currentPos.first + x, currentPos.second + y };
            if (valid_pos(pos, board) && used_spots.find(pos) == used_spots.end() && charAt(pos, board) == c)
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

bool find_word(const board_t& board, const pos_t pos, const std::string& word, usedspots_t used_spots)
{
    if (word.size() == 0)
        return true;
    auto list = find_valid_pos(board, pos, word[0], used_spots);
    for (auto&& i : list)
    {
        used_spots.emplace(pos);
        if (find_word(board, i, word.substr(1), used_spots))
            return true;
        used_spots.erase(used_spots.find(pos));
    }
    return false;
}

bool check_word(const std::vector<std::vector<char>>& board, const std::string& word)
{
    usedspots_t used_spots;
    auto starting_pos = find_pos_of_char(board, word[0]);
    if (word.size() == 1 && starting_pos.size() > 0)
        return true;
    if (starting_pos.size() == 0)
        return false;
    for (auto&& i : starting_pos)
    {
        if (find_word(board, i, word.substr(1), used_spots))
            return true;
    }
    return false;
}