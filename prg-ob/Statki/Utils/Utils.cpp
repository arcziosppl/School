//
// Created by recke on 03.01.2024.
//

#include "Utils.h"

std::string Utils::GetCurrentDate(){
    time_t now = time(nullptr);
    char *dt = ctime(&now);
    return  dt;
}

int *Utils::GenerateRandom(int max, int amount) {
    srand(time(nullptr));
    int *value = new int[amount];

    for (int i=0;i<amount;i++){
        bool check;
        int n;
        do{
            n=rand()%max;
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
