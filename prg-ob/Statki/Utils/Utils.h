//
// Created by recke on 03.01.2024.
//

#ifndef STATKI_UTILS_H
#define STATKI_UTILS_H
#include "iostream"
#include "ctime"
#include "vector"
class Utils {
public:
    static std::string GetCurrentDate();
    static int *GenerateRandom(int max, int amount);
    static void WelocmeAscii();
};


#endif //STATKI_UTILS_H
