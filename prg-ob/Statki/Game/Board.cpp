//
// Created by recke on 03.01.2024.
//

#include "Board.h"
#include "../Utils/Utils.h"

Board::Board(const int d, const int num_ships, const char ship_symbol) {
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
    matrix_player_h.resize(this->config.d, std::vector<char>(this->config.d, this->empty_board_symbol));
    matrix_hidden_player_h.resize(this->config.d, std::vector<char>(this->config.d, this->empty_board_symbol));
}

void Board::print_board() const{
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

void Board::print_board_hidden() const{
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

void Board::PrintBoardPlayerH() const {
    for (int i = 0; i < config.d; ++i) {
        std::cout<<'\t'<<column_name[i];
    }
    std::cout<<'\n';
    for(int i=0;i<matrix_player_h.size();i++){
        std::cout<<(i + 1);
        for(char j : matrix_player_h[i]) {
            std::cout << '\t' << j;
        }
        std::cout<<'\n';
    }
}

void Board::ShipsGenerate() {
    srand(time(nullptr));
    enemy_ships_number = ship.num_ships;

    const std::vector<int> arr = Utils::GenerateRandom(ship.num_ships, config.d);
    std::vector<int> arr_2 = arr;
    std::vector<std::vector<int>> data = Utils::ReadSavedUserCords();

//    for (int i = 0; i < data.size(); ++i) {
//        for (int j = 0; j < data[i].size(); ++j) {
//            std::cout << data[i][j] << " ";
//        }
//        std::cout << "\n";
//    }

    std::random_device rd;
    std::mt19937 gen(rd());

    std::shuffle(arr_2.begin(), arr_2.end(), gen);

    for(int i = 0; i < ship.num_ships; i++){
        const int rand_x = arr[i];
        const int rand_y = arr_2[i];

//        for (int j = 0; j < data.size(); ++j) {
//            if(rand_x == data[j][0]){
//                std::cout<<"tre";
//            }
//        }

        matrix_hidden[rand_x][rand_y] = ship.ship_symbol;
    }

}

void Board::ShipsGeneratePlayerH() {
    srand(time(nullptr));
    player_ships_number = ship.num_ships;

    const std::vector<int> arr = Utils::GenerateRandom(ship.num_ships, config.d);
    std::vector<int> arr_2 = arr;
    std::vector<std::vector<int>> data = Utils::ReadSavedUserCords();

    std::random_device rd;
    std::mt19937 gen(rd());

    std::shuffle(arr_2.begin(), arr_2.end(), gen);

    for(int i = 0; i < ship.num_ships; i++){
        const int rand_x = arr[i];
        const int rand_y = arr_2[i];

        //        for (int j = 0; j < data.size(); ++j) {
        //            if(rand_x == data[j][0]){
        //                std::cout<<"tre";
        //            }
        //        }

        matrix_player_h[rand_x][rand_y] = ship.ship_symbol;
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
        int x = 0;
        const int y = (std::stoi(str_y) - 1);
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

void Board::TakeTheShotPc(const std::vector<int>& arr) {
    srand(time(nullptr));

    const int x = arr[0];
    const int y = arr[1];

    if (matrix_player_h[y][x] == '~') {
        matrix_player_h[y][x] = 'o';
    } else if (matrix_player_h[y][x] == ship.ship_symbol) {
        std::cout << "Zostałeś trafiony!" << '\n';
        matrix_player_h[y][x] = 'x';
        player_ships_number--;
    }
}








