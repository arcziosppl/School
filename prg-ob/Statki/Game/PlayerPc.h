//
// Created by arczi on 09.01.24.
//

#ifndef PLAYERPC_H
#define PLAYERPC_H
#include <string>
#include "random"
#include "ctime"

class PlayerPc {
private:
    int matrix_size;

public:
    explicit PlayerPc(int d);
    std::vector<int> GenerateCordsToShoot() const;
};



#endif //PLAYERPC_H
