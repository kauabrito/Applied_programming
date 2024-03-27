#include <iostream>
using namespace std;
void calcularT (float* , float* );
int main() {
    int o;
    float valor;
    cout << "Digite a ordem da matriz: ";
    cin >> o;
    float matriz[o][o];
    float Tmatriz[o][o];

    for (int l = 0; l < o; l++) {
        for (int c = 0; c < o; c++) {
            cout << "Digite o elemento a" << l + 1 << c + 1 << " da matriz: ";
            cin >> valor;
            matriz[l][c] = valor;
        }
    }

    float *p; 
    float *p1;
    for (int l = 0; l < o; l++) {
        for (int c = 0; c < o; c++) {
                p = &matriz[c][l];
                p1 = &Tmatriz[l][c];
                calcularT(p, p1);
                //Tmatriz[l][c] = *p; 
        }
    }

    cout << "Matriz original:" << endl;
    for (int l = 0; l < o; l++) {
        for (int c = 0; c < o; c++) {
            cout << matriz[l][c] << " ";
        }
        cout << endl;
    }
    
    cout << "Matriz transposta:" << endl;
    for (int l = 0; l < o; l++) {
        for (int c = 0; c < o; c++) {
            cout << Tmatriz[l][c] << " ";
        }
        cout << endl;
    }
    return 0;
}

void calcularT (float *x, float *y){*y = *x;}