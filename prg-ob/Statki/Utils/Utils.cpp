//
// Created by recke on 03.01.2024.
//

#include "Utils.h"

std::string Utils::GetCurrentDate(){
    time_t now = time(nullptr);
    char *dt = ctime(&now);
    return  dt;
}

std::vector<int> Utils::GenerateRandom(int max, int dm) {
    srand(time(nullptr));
    std::vector<int> value(max);

    for (int i=0;i<max;i++){
        bool check;
        int n;
        do{
            n=rand()%dm;
            check=true;
            for (int j=0;j<i;j++) {
                if (n == value[j]) {
                    check = false;
                    break;
                }
            }
        } while (!check);
        value[i]=n;
    }
    return value;
}

void Utils::WelocmeAscii() {

    std::cout<<" _       _____    ____  _____ __  __________  _____"<<'\n'<<'\t';
    std::cout<<"| |     / /   |  / __ \\/ ___// / / /  _/ __ \\/ ___/"<<'\n'<<'\t';
    std::cout<<"| | /| / / /| | / /_/ /\\__ \\/ /_/ // // /_/ /\\__ \\ "<<'\n'<<'\t';
    std::cout<<"| |/ |/ / ___ |/ _, _/___/ / __  // // ____/___/ / "<<'\n'<<'\t';
    std::cout<<"|__/|__/_/  |_/_/ |_|/____/_/ /_/___/_/    /____/  "<<'\n'<<'\t';
    std::cout<<'\n';
    std::cout<<"                      _==|"<<'\n'<<'\t';
std::cout<<"            _==|   )__)  |"<<'\n'<<'\t';
std::cout<<"              )_)  )___) ))"<<'\n'<<'\t';
std::cout<<"             )___) )____))_)"<<'\n'<<'\t';
std::cout<<"        _    )____)_____))__)\'"<<'\n'<<'\t';
std::cout<<"         \---__|____/|___|___-\\---"<<'\n'<<'\t';
std::cout<<" ^^^^^^^^^\   oo oo oo oo     /~~^^^^^^^"<<'\n'<<'\t';
std::cout<<"   ~^^^^ ~~~~^^~~~~^^~~^^~~~~~"<<'\n'<<'\t';
std::cout<<"     ~~^^      ~^^~     ~^~ ~^ ~^"<<'\n'<<'\t';
std::cout<<"          ~^~~        ~~~^^~"<<'\n'<<'\t';
std::cout<<'\n';
}

void Utils::SaveToTxt(std::vector<std::vector<char>> matrix, int d) {
    std::string column_name[10] = {"A","B","C","D","E","F","G","H","I","J"};

    std::ofstream file;
    file.open(R"(/home/arczi/CLionProjects/School/prg-ob/Statki/Saved/Saved.txt)", std::ios::app);
    file<<Utils::GetCurrentDate();
    file<<'\n';
    for (int i = 0; i < d; i++) {
        file<<'\t'<<column_name[i];
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

void Utils::SaveCordsToTxt(int x, int y){
  std::ofstream file;
    file.open(R"(/home/arczi/CLionProjects/School/prg-ob/Statki/Saved/Cords.txt)", std::ios::app);
    file<<x<<y<<'\n';
    file.close();
}

std::vector<std::vector<int>> Utils::ReadSavedUserCords() {
    std::fstream file;
    std::string buffer;
    std::vector<std::vector<int>> data;

    file.open(R"(/home/arczi/CLionProjects/School/prg-ob/Statki/Saved/Cords.txt)", std::ios::in);

    if (file.is_open()){
        while (std::getline(file,buffer)){
            std::string x = buffer.substr(0,1);
            std::string y;
            if(buffer.length() == 2) {
                 y = buffer.substr(1, 2);
            } else{
                 y = buffer.substr(1, 3);
            }
            data.push_back({std::stoi(x),std::stoi(y)});
        }
        std::reverse(data.begin(), data.end());
    }

    return data;
}

