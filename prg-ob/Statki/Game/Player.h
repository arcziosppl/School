//
// Created by recke on 05.01.2024.
//

#ifndef STATKI_PLAYER_H
#define STATKI_PLAYER_H
#include "Board.h"
#include "iostream"


class Player  {
private:
     int matrix_size;

public:
    Player(int d);
    std::string GetCords() const;
    std::string cords;
};


#endif //STATKI_PLAYER_H
