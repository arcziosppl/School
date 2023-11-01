#include "iostream"
#include "cstdlib"
#include "array"

using namespace std;


class linearSearch{
private:
    int array_to_search[61];
    int search_number;
    int array_length = 0;

public:
    void fill_array(){
        srand(time(nullptr));
        this->array_length = sizeof(array_to_search)/ sizeof(array_to_search[0]);

        array_to_search[array_length-1] = search_number;
        for(int i=0; i<array_length; i++){
            array_to_search[i] = rand() % 100 +1;
        }
    }

    void get_search_number(){
        cin>>this->search_number;
    }

    int search_array(){
        int index = 0;
        for (int i = 0; i <this->array_length; ++i) {
            if(this->array_to_search[i] == this->search_number){
                index = i;
                break;
            }
        }

        return index;
    }

    void print_array() const{
        cout<<"Szukana tablica: [";
        for(int i=0; i< this->array_length; i++){
            cout<< this->array_to_search[i]<<",";
        }
        cout<<"]";
        cout<<"\n";
    }

};

linearSearch search;

int main(){
    cout<<"Szukana liczba: ";
    search.get_search_number();
    search.fill_array();
    search.print_array();
    if(search.search_array() == 0){
        cout<<"Nie znaleziono podanego elementu";
    } else{
        cout<<"Znaleziono podany element pod indexem: "<<search.search_array();
    }
}