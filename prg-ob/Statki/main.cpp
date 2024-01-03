#include <iostream>
#include "Board/Board.h"


Board GameBoard(10,10);

int main() {
    GameBoard.init();
    GameBoard.print_board();
    return 0;
}
