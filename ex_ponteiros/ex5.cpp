#include <iostream>
using namespace std;

float soma(float *M , int linha , int coluna){
    float s = 0;
        for (int i = 0; i < linha; ++i) {
            for (int j = 0; j < coluna; ++j) {
                s += *(M + (i * coluna) + j);
        }
    }
    return s;
}

int main(){
    int l, c;
    cout << "Quantidade de linhas: ";
    cin >> l;
    cout << "Quantidade de colunas: ";
    cin >> c;

    float *matriz = new float[l*c];
    float valor;

    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << "Elemento [" << i+1 << "][" << j+1 << "]: ";
            cin >> valor;
            *(matriz + (i * c) + j) = valor;
        }
    }

    cout << "A soma eh: " << soma(matriz, l, c);

    delete[] matriz;
    return 0;
}