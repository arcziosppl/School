//
// Created by arczi on 09.01.24.
//

#include "PlayerPc.h"

PlayerPc::PlayerPc(const int d) {
    this->matrix_size = d;
}

std::vector<int> PlayerPc::GenerateCordsToShoot() const{
    std::vector<int> cords(2);
    srand(time(nullptr));
    cords[0] = rand() % matrix_size;
    cords[1] = rand() % matrix_size;

    return cords;
}


