//
// Created by recke on 03.01.2024.
//

#include "Board.h"
#include "fstream"

Board::Board(int w, int h) {
    this->size.w = w;
    this->size.h = h;
}

void Board::init() {
    if(this->size.w != this->size.h){
        std::cout<<"Rozmiary planszy są nieprawidłowe";
        exit(0);
    }
    matrix.resize(this->size.w, std::vector<char>(this->size.h, this->empty_board_symbol));
}

void Board::print_board() {
    for(char i : column_name){
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