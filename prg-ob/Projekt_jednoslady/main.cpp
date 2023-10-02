#include "iostream"

using namespace std;

class jednoslad{
protected:
    float pojemnosc_silnika;
    float kolor;
    float marka;
    float skrzynia_biegow;

public:
    virtual void zmien_poj(float poj){
       this->pojemnosc_silnika = poj;
    }

    virtual void print() const{
        cout<<"Pojemnosc silnika"<<this->pojemnosc_silnika;
    }
};

class skuter : public  jednoslad{
public:
    void zmien_poj(float poj){
        this->pojemnosc_silnika = poj;
    }

    void print() const{
        cout<<"Pojemnosc silnika: "<<this->pojemnosc_silnika<<" cm3\n";
    }
};

class motocykl : public jednoslad{
public:
    void zmien_poj(float poj){
        this->pojemnosc_silnika = poj;
    }

    void print() const{
        cout<<"Pojemnosc silnika: "<<this->pojemnosc_silnika<<" cm3\n";
    }
};

int main(){

    jednoslad jd;
    skuter sk;
    motocykl mo;

    float p;
    cout<<"Podaj pojemnosc silnika w cm3: \n";
    cin>>p;
    sk.zmien_poj(p);
    mo.zmien_poj(p);

    sk.print();
    mo.print();

}