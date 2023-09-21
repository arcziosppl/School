#include <iostream>
#include <time.h>
#include <limits>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

enum SIGN { sCIRCLE='O', sCROSS='X' };
enum FIELD { EMPTY, CIRCLE = sCIRCLE, CROSS = sCROSS };

FIELD Plansza[3][3] = {
        { EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY }
};

enum GAMESTATE { NOTSTARTED, MOVE, WON, DRAW };
GAMESTATE StanGry = NOTSTARTED;

SIGN AktualnyGracz;

const int LINIE[][3][2] {
        { {0,0}, {0,1}, {0,2} }, //górna pozioma
        { {1,0}, {1,1}, {1,2} }, //środkowa pozioma
        { {2,0}, {2,1}, {2,2} }, //środkowa dolna
        { {0,0}, {1,0}, {2,0} }, //lewa pionowa
        { {0,1}, {1,1}, {2,1} }, //środek pionowa
        { {0,2}, {1,2}, {2,2} }, //prawa pionowa
        { {0,0}, {1,1}, {2,2} }, //backslah
        { {2,0}, {1,1}, {0,2} }, //slash
};

//==========================================================================

bool StartGry() {
    if (StanGry != NOTSTARTED) return false;
    srand(time(NULL));
    AktualnyGracz = ( rand()%2 == 0 ? sCIRCLE : sCROSS);
    StanGry = MOVE;
    return true;
}

bool Ruch(int NumerPola) {
    if (StanGry != MOVE) return false;
    if (NumerPola<1 || NumerPola>9) return false;
    int y = (NumerPola - 1)/3;
    int x = (NumerPola - 1)%3;
    if (Plansza[y][x] == EMPTY) {
        Plansza[y][x] = static_cast<FIELD>(AktualnyGracz);
    } else {
        return false;
    }

    FIELD Pole, ZgodnePole;
    int LiczbaZgodnychPol = 0;
    //czy jest wygrana?
    for (int i=0; i<8; i++) {
        Pole = ZgodnePole = EMPTY;
        LiczbaZgodnychPol = 0;
        for(int j=0; j<3; j++) {
            Pole = Plansza[LINIE[i][j][0]][LINIE[i][j][1]];
            if(Pole!=ZgodnePole) {
                ZgodnePole = Pole;
                LiczbaZgodnychPol = 1;
            } else {
                LiczbaZgodnychPol += 1;
            }
        }
        if(LiczbaZgodnychPol == 3 && ZgodnePole != EMPTY) {
            StanGry = WON;
            return true;
        }
    }
    //czy jest remis?
    int LiczbaZapelnionychPol = 0;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if (Plansza[i][j] != EMPTY)
                LiczbaZapelnionychPol+=1;
        }
    }
    if (LiczbaZapelnionychPol==9) {
        StanGry=DRAW;
        return true;
    }
    //zmiana gracza
    AktualnyGracz = (AktualnyGracz == sCIRCLE ? sCROSS : sCIRCLE);
    return true;
}

bool RysujPlansze() {
    if (StanGry == NOTSTARTED) return false;
    system("cls");

    cout<<"            Kółko i krzyżyk"<<endl;
    cout<<"-----------------------------------"<<endl<<endl;

    cout<<"-----"<<endl;
    for(int i=0; i<3; i++) {
        cout<<"|";
        for(int j=0; j<3; j++) {
            if (Plansza[i][j]==EMPTY)
                cout<<i*3+j+1;
            else {
                cout<<static_cast<char>(Plansza[i][j]);
            }
        }
        cout<<"|"<<endl;
    }
    cout<<"-----"<<endl;
    cout<<endl;

    switch(StanGry) {
        case MOVE:
            cout<<"Podaj numer pola w którym chcesz postawić ";
            cout<< (AktualnyGracz == CIRCLE ? "kółko" : "krzyżyk" )<<" :";
            break;
        case WON:
            cout<<"Wygrał gracz stawiający ";
            cout<< (AktualnyGracz == CIRCLE ? "kółko" : "krzyżyk" )<<".";
            break;
        case DRAW:
            cout<<"Remis!";
            break;
    }
    return true;
}

void check_input(int symbol){
    if(cin.fail() || symbol <1 || symbol >9)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout<<"Podaj poprawne dane \n";
    } else{
        Ruch(symbol);
    }
}

//===========================================================================
int main(int argc, char** argv) {
    setlocale(LC_ALL, "pl_PL");
    StartGry();

    for(;;) {
        RysujPlansze();
        if (StanGry==MOVE) {
            int NumerPola;
            cin>>NumerPola;
            check_input(NumerPola);
        } else if (StanGry==WON || StanGry==DRAW) {
            break;
        }
    }
    return 0;
}