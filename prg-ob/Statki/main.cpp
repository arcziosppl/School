#include <iostream>
#include "Game/Board.h"
#include "Utils/Utils.h"
#include "Game/Player.h"
#include "clocale"
#include "Game/PlayerPc.h"

#define MATRIX_SIZE 10
#define NUMBER_OF_SHIPS 10
#define SHIP_SYMBOL '|'

Board GameBoard(MATRIX_SIZE,NUMBER_OF_SHIPS,SHIP_SYMBOL);
Player player(MATRIX_SIZE);
PlayerPc player_pc(MATRIX_SIZE);

int main() {
    setlocale(LC_ALL, "Polish");

    GameBoard.init();
    GameBoard.ShipsGenerate();
    GameBoard.ShipsGeneratePlayerH();
    std::cout<<GameBoard.GameWin();

    Utils::WelocmeAscii();
    while (GameBoard.GameWin() != 1 && GameBoard.GameWin() != 2){
        GameBoard.print_board();
        GameBoard.print_board_hidden();
        GameBoard.PrintBoardPlayerH();
        GameBoard.TakeTheShot(player.GetCords());
        GameBoard.TakeTheShotPc(player_pc.GenerateCordsToShoot());
    }
    Utils::SaveToTxt(GameBoard.matrix, MATRIX_SIZE);
    if(GameBoard.GameWin() == 1) {
        std::cout<<"Niestety przegrałeś";
    }else {
        std::cout<<"Gratulacje, Wygrałeś";
    }

    return 0;
}
