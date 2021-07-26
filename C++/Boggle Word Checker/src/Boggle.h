#include <vector>
#include <string>
#include <utility>
#include <optional>
#include <set>

typedef std::vector<std::vector<char>> t_board;

bool check_word(const std::vector<std::vector<char>> &board, const std::string &word)
{

    return false;
}

bool valid_pos(std::pair<int, int> pos, const t_board &board)
{
    if (pos.first < 0 || pos.first > board.size() - 1 || pos.second < 0 || pos.second > board.size() - 1)
        return false;
    else
        return true;
}

char charAt(const std::pair<int, int> &pos, const t_board &board)
{
    if (valid_pos(pos, board))
        return board[pos.second][pos.first];
    else
        return '0';
}

std::vector<char> valid_chars(const t_board &board, const std::pair<int, int> &pos, std::set<std::pair<int, int>> used_spots)
{
    std::vector<char> output;
    bool test = -1 < 2;
    for (int y = -1; y <= 1; y++)
    {
        for (int x = -1; x <= 1; x++)
        {
            if (valid_pos({pos.first + x, pos.second + y}, board) && !used_spots.contains({pos.first + x, pos.second + y}))
                if (x != 0 || y != 0)
                    output.emplace_back(charAt({pos.first + x, pos.second + y}, board));
        }
    }
    return output;
}

std::pair<int, int> find_pos(const t_board &board, const char &c)
{
    static std::pair<int, int> last(-1, -1);
    for (size_t y = 0; y < board.size(); y++)
    {
        for (size_t x = 0; x < board[0].size(); x++)
        {
            if (board[y][x] == c)
                if (x != last.first && y != last.second)
                {
                    last = std::pair<int, int>(x, y);
                    return last;
                }
        }
    }
    return std::pair<int, int>(-1, -1);
    ;
}
