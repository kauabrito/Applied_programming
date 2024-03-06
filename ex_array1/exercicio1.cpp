#include <iostream>
using namespace std;

class organizar{
    private:
        int i=0;
        int array[10];

    public:
        void set_array(void);
        void organizar_array(void);
        void get_array(void);
};
void organizar::set_array(){
    for(int i=0; i<10; i++){
        cout << "Digite o numero "<< i+1 <<" : "<<endl;
        cin >> array[i];
    }
}
void organizar::organizar_array(){
    int aux;
    for(int frente = 1; frente<10; frente++){
        for(int atras =0; atras<frente; atras++){
            if (array[frente] < array[atras]){
                aux = array[frente];
                array[frente] = array[atras];
                array[atras] = aux;
            }
        }
    }
}
void organizar::get_array(){
    cout << "\nArray: ";
    for(int i = 0; i<10 ;i++){
        if (i <9){
            cout << array[i] <<", ";
        }
        else cout << array[i];
    }
}
int main(){
    organizar nome_objeto;
    nome_objeto.set_array();
    nome_objeto.get_array();
    nome_objeto.organizar_array();
    nome_objeto.get_array();
    return 0;
}