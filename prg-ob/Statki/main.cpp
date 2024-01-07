#include <iostream>
#include "Game/Board.h"
#include "Utils/Utils.h"
#include "Game/Player.h"
#include "clocale"

#define MATRIX_SIZE 5
#define NUMBER_OF_SHIPS 1
#define SHIP_SYMBOL '|'

Board GameBoard(MATRIX_SIZE,NUMBER_OF_SHIPS,SHIP_SYMBOL);
Player player(MATRIX_SIZE);

int main() {
    setlocale(LC_ALL, "Polish");

    GameBoard.init();
    GameBoard.ShipsGenerate();
    Utils::WelocmeAscii();
    while (GameBoard.enemy_ships_number != 0){
        GameBoard.print_board();
        GameBoard.print_board_hidden();
        GameBoard.TakeTheShot(player.GetCords());
    }
    Utils::SaveToTxt(GameBoard.matrix, MATRIX_SIZE);
    std::cout<<"Gratulacje wygrałeś"<<'\n';

    return 0;
}
