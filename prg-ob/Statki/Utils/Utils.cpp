//
// Created by recke on 03.01.2024.
//

#include "Utils.h"

std::string Utils::GetCurrentDate(){
    time_t now = time(nullptr);
    char *dt = ctime(&now);
    return  dt;
}
