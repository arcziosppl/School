//
// Created by recke on 05.01.2024.
//

#include "Player.h"

Player::Player(const int d) {
    this->matrix_size = d;
}

std::string Player::GetCords() const {
    bool failed = true;
    std::string cord;
    std::cout<<"Podaj koordynaty salwy: ";
    std::cin>>cord;
    std::transform(cord.begin(),cord.end(),cord.begin(),::toupper);
    std::string str_x;
    std::string str_y;

    if(cord.length() == 2){
        str_x = cord.substr(0,1);
        str_y = cord.substr(1,2);
    } else{
        str_x = cord.substr(0,1);
        str_y = cord.substr(1,3);
    }

    if(cord.length() == 1 || cord.length() > 3){
        std::cout<<"Podaj poprawne koordynaty salwy!"<<'\n';
    } else if(!std::isdigit(cord[1]) || std::isdigit(cord[0])){
        std::cout<<"Podaj poprawne koordynaty salwy!"<<'\n';
    } else if(std::stoi(str_y) > matrix_size){
        std::cout<<"Podaj poprawne koordynaty salwy!"<<'\n';
    } else{
        return cord;
    }

    return "-1";
}
