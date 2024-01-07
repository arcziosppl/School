//
// Created by recke on 03.01.2024.
//

#include "Board.h"
#include "../Utils/Utils.h"

Board::Board(int d, int num_ships, char ship_symbol) {
    this->config.d = d;
    this->ship.num_ships = num_ships;
    this->ship.ship_symbol = ship_symbol;
}

void Board::init() {
    if(this->config.d < 0 || this->config.d > 10){
        std::cout<<"Rozmiary planszy są nieprawidłowe";
        exit(0);
    }
    matrix.resize(this->config.d, std::vector<char>(this->config.d, this->empty_board_symbol));
    matrix_hidden.resize(this->config.d, std::vector<char>(this->config.d, this->empty_board_symbol));
}

void Board::print_board() {
    for (int i = 0; i < config.d; ++i) {
        std::cout<<'\t'<<column_name[i];
    }
    std::cout<<'\n';
    for(int i=0;i<matrix.size();i++){
        std::cout<<(i + 1);
        for(char j : matrix[i]) {
            std::cout << '\t' << j;
        }
        std::cout<<'\n';
    }
}

void Board::print_board_hidden() {
    for (int i = 0; i < config.d; ++i) {
        std::cout<<'\t'<<column_name[i];
    }
    std::cout<<'\n';
    for(int i=0;i<matrix_hidden.size();i++){
        std::cout<<(i + 1);
        for(char j : matrix_hidden[i]) {
            std::cout << '\t' << j;
        }
        std::cout<<'\n';
    }
}

void Board::ShipsGenerate() {

    enemy_ships_number = ship.num_ships;

    std::vector<int> arr = Utils::GenerateRandom(ship.num_ships, config.d);
    std::vector<int> arr_2 = arr;

    std::random_device rd;
    std::mt19937 gen(rd());

    std::shuffle(arr_2.begin(), arr_2.end(), gen);

    for(int i = 0; i < ship.num_ships; i++){
        int rand_x = arr[i];
        int rand_y = arr_2[i];

        matrix_hidden[rand_x][rand_y] = ship.ship_symbol;
    }
}

void Board::TakeTheShot(const std::string& cord) {
    if(cord != "-1") {
        std::string str_x;
        std::string str_y;
        if (cord.length() == 2) {
            str_x = cord.substr(0, 1);
            str_y = cord.substr(1, 2);
        } else {
            str_x = cord.substr(0, 1);
            str_y = cord.substr(1, 3);
        }
        int x;
        int y = (std::stoi(str_y) - 1);
        for (int i = 0; i < this->config.d; ++i) {
            if (column_name[i] == str_x) {
                x = i;
                break;
            }
        }


        if (matrix_hidden[y][x] == '~') {
            std::cout << "Pudlo!" << '\n';
            matrix[y][x] = 'o';
            matrix_hidden[y][x] = 'o';
            Utils::SaveCordsToTxt(x,y);
        } else if (matrix_hidden[y][x] == ship.ship_symbol) {
            std::cout << "Trafiony, zatoiopny!" << '\n';
            matrix[y][x] = 'x';
            matrix_hidden[y][x] = 'x';
            enemy_ships_number--;
        } else {
            std::cout << "Już tu strzelałeś!" << '\n';
        }

        std::cout << "X: " << (x + 1) << " Y: " << (y + 1) << '\n';
    }
}





