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
        int d;
    }config{};
    struct {
        int num_ships;
        char ship_symbol;
    }ship{};
    char empty_board_symbol = '~';
    std::string column_name[10] = {"A","B","C","D","E","F","G","H","I","J"};

public:
    void init();
    void print_board() const;
    void print_board_hidden() const;
    void PrintBoardPlayerH() const;
    void TakeTheShot(const std::string& cord);
    void TakeTheShotPc(const std::vector<int>& arr);
    void ShipsGenerate();
    void ShipsGeneratePlayerH();
    std::vector<std::vector<char>> matrix;
    std::vector<std::vector<char>> matrix_hidden;
    std::vector<std::vector<char>> matrix_player_h;
    std::vector<std::vector<char>> matrix_hidden_player_h;
    int enemy_ships_number = 0;
    int player_ships_number = 0;

    Board(int d, int num_ships, char ship_symbol);
};


#endif //STATKI_BOARD_H
