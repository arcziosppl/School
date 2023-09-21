#include "iostream"

using namespace std;

class Prostopadloscian{
private:
    float a,b,c;

public:
    void get_dm(){
        cout<<"Podaj a: ";
        cin>> this->a;
        cout<<"Podaj b: ";
        cin>> this->b;
        cout<<"Podaj c: ";
        cin>> this->c;
    }

    float ObliczPole(){
        float result;
        result =(a*b+a*c+b*c);
        result*=2;
        return  result;
    }

};

Prostopadloscian pole;

int main(){
    pole.get_dm();
    cout<<to_string(pole.ObliczPole()) + " cm²";
}