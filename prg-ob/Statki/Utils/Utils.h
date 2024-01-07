//
// Created by recke on 03.01.2024.
//

#ifndef STATKI_UTILS_H
#define STATKI_UTILS_H
#include "iostream"
#include "ctime"
#include "vector"
#include "fstream"
#include "string"


class Utils {
public:
    static std::string GetCurrentDate();
    static std::vector<int> GenerateRandom(int max,int dm);
    static void SaveToTxt(std::vector<std::vector<char>> matrix, int d);
    static void SaveCordsToTxt(int x, int y);
    static void WelocmeAscii();
};


#endif //STATKI_UTILS_H
