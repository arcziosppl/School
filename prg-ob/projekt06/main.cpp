#include "iostream"

using namespace std;

class Only_int{
private:
    int number;

public:
    void set_number(){
        cout<<"Podaj liczbę: ";
        cin>>number;
    }

    void print_number() const{
        cout<<"Wartość liczby to: "<<number<<"\n";
    }

    void set_number_arg(int n){
        number = n;
    }

    int abs() {
        int n = number;
        if(n < 0){
            return n*-1;
        } else{
            return n;
        }
    }

    int return_number() {
        return number;
    }
};

Only_int onlyint;
int main(){

    onlyint.set_number();
    onlyint.print_number();
    onlyint.set_number_arg(20);
    cout << "Wartość liczby to: " << onlyint.return_number() << "\n";
    cout << "Wartość bezwzględna liczby to: " << onlyint.abs() << "\n";
}