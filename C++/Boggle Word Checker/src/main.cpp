#include <iostream>
#include "Boggle.h"

int main()
{
    board_t test_board = { {'E','A','R','A'},
                            {'N','L','E','C'},
                            {'I','A','I','S'},
                            {'B','Y','O','R'} };
    
    std::cout << check_word(test_board, "BINARAEL") << '\n';
    return 0;
}
