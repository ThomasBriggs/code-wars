#include <iostream>
#include "Boggle.h"

int main(int argc, char const* argv[])
{
    board_t test_board = { {'E','A','R','A'},
                            {'N','L','E','C'},
                            {'I','A','I','S'},
                            {'B','Y','O','R'} };
    
    // std::cout << check_word(test_board, "E") << '\n';
    std::string test = "Hello, World";
    std::cout << test.substr(7) << '\n';
    return 0;
}
