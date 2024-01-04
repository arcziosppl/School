//
// Created by recke on 03.01.2024.
//

#include "Board.h"
#include "../Utils/Utils.h"

Board::Board(int w, int h, int s_num, char symbol) {
    this->size.w = w;
    this->size.h = h;
    this->ship.num_ships = s_num;
    this->ship.ship_symbol = symbol;
}

void Board::init() {
    if(this->size.w != this->size.h){
        std::cout<<"Rozmiary planszy są nieprawidłowe";
        exit(0);
    }
    matrix.resize(this->size.w, std::vector<char>(this->size.h, this->empty_board_symbol));
    matrix_hidden.resize(this->size.w, std::vector<char>(this->size.h, this->empty_board_symbol));
}

void Board::print_board() {
    for(auto & i : column_name){
        std::cout<<'\t'<<i;
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
    for(auto & i : column_name){
        std::cout<<'\t'<<i;
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


void Board::Savetxt() {
    std::ofstream file;
    file.open(R"(C:\Users\recke\IdeaProjects\School\prg-ob\Statki\Saved\Saved.txt)", std::ios_base::app);
    file<<Utils::GetCurrentDate();
    file<<'\n';
    for(auto & i : column_name){
        file<<'\t'<<i;
    }
    file<<'\n';
    for(int i=0;i<matrix.size();i++){
        file<<(i + 1);
        for(char j : matrix[i]) {
            file << '\t' << j;
        }
        file<<'\n';
    }
    file<<'\n';
    file.close();
}

void Board::ShipsGenerate() {
    int *rnd = Utils::GenerateRandom(ship.num_ships,ship.num_ships);
    int r_x[ship.num_ships];

    for (int i = 0; i < ship.num_ships; ++i) {
        r_x[i] = *(rnd + i);
    }

    srand(time(nullptr));
    for(int i = 0; i < ship.num_ships; i++){
        int rand_x = r_x[i];
        int rand_y = (1 + (rand() % 9));

        matrix_hidden[rand_x][rand_y] = ship.ship_symbol;
    }
}

void Board::Shoot(const std::string& cord) {
    std::string str_x = cord.substr(0,1);
    std::string str_y = cord.substr(1,2);
    int x;
    int y = (std::stoi(str_y) - 1);
    for (int i = 0; i < this->size.w; ++i) {
        if(column_name[i] == str_x){
            x = i;
            break;
        }
    }


    if(matrix_hidden[y][x] == '~'){
        std::cout<<"Pudlo!";
        matrix[y][x] = 'o';
        matrix_hidden[y][x] = 'o';
    } else if(matrix_hidden[y][x] == '|'){
        std::cout<<"Trafiony, zatoiopny!";
        matrix[y][x] = 'x';
        matrix_hidden[y][x] = 'x';
        bot_ships_number--;
        std::cout<<bot_ships_number;
    } else{
        std::cout<<"Już tu strzelałeś!";
    }

    std::cout<<"X: "<<x<<"Y: "<<y<<'\n';
}