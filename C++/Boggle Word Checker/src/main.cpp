#include <iostream>
#include "Boggle.h"

int main(int argc, char const* argv[])
{
    board_t test_board = { {'E','A','R','A'},
                            {'N','L','E','C'},
                            {'I','A','I','S'},
                            {'B','Y','O','R'} };
    
    std::cout << check_word(test_board, "LAR") << '\n';
    return 0;
}
