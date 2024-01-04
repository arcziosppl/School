//
// Created by recke on 03.01.2024.
//

#ifndef STATKI_BOARD_H
#define STATKI_BOARD_H
#include "iostream"
#include "vector"
#include "fstream"
#include "random"
#include "algorithm"

class Board {
private:
    struct {
        int w;
        int h;
    }size{};
    struct {
        int num_ships;
        char ship_symbol;
    }ship{};
    char empty_board_symbol = '~';
    std::string column_name[10] = {"A","B","C","D","E","F","G","H","I","J"};

public:
    Board(int w, int h, int s_num, char symbol);
    void init();
    void print_board();
    void print_board_hidden();
    void Savetxt();
    void Shoot(const std::string& cord);
    void ShipsGenerate();
    std::vector<std::vector<char>> matrix;
    std::vector<std::vector<char>> matrix_hidden;
    int bot_ships_number = 10;
};


#endif //STATKI_BOARD_H
