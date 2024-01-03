//
// Created by recke on 03.01.2024.
//

#ifndef STATKI_BOARD_H
#define STATKI_BOARD_H
#include "iostream"
#include "vector"


class Board {
private:
    struct {
        int w;
        int h;
    }size;
    char empty_board_symbol = '~';
    char column_name[10] = {'A','B','C','D','E','F','G','H','I','J'};

public:
    Board(int w,int h);
    void init();
    void print_board();
    std::vector<std::vector<char>> matrix;
};


#endif //STATKI_BOARD_H
