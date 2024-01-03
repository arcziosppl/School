#include <iostream>
#include "Board/Board.h"
#include "Utils/Utils.h"

Board GameBoard(10,10);

int main() {
    GameBoard.init();
    GameBoard.print_board();
    GameBoard.Savetxt();
    return 0;
}
