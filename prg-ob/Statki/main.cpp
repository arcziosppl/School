#include <iostream>
#include "Board/Board.h"
#include "Utils/Utils.h"
#include "algorithm"
#include "clocale"

Board GameBoard(10,10,10,'|');

void CheckSetCords(std::string xy){
    std::transform(xy.begin(),xy.end(),xy.begin(),::toupper);
   GameBoard.Shoot(xy);
}

int main() {
    setlocale(LC_ALL, "Polish");

    std::string shoot_cord;
    GameBoard.init();
    GameBoard.ShipsGenerate();
    Utils::WelocmeAscii();
    while (GameBoard.bot_ships_number != 0){
        GameBoard.print_board();
        GameBoard.print_board_hidden();
        std::cout<<'\n';
        std::cout<<"Podaj koordynaty strzału: ";
        std::cin>>shoot_cord;
        CheckSetCords(shoot_cord);
    }
    std::cout<<"Gratulacje wygrałeś"<<'\n';

    return 0;
}
