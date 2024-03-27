#include <iostream>
#include <cmath>
using namespace std;

float Vcone(float, float);
float Acircunferencia(float);

int main() {
    float raio, altura;
    float (*p)(float, float); 
    float (*p2)(float ); 
    cout << "Digite o raio[m]: ";
    cin >> raio;
    cout << "Digite a altura[m]: ";
    cin >> altura;
    p2 = &Acircunferencia; 
    cout << "A area da circunferencia eh: " << (*p2)(raio) << endl; 
    p = &Vcone;
    cout << "O volume do cone eh: " << (*p)(raio, altura) << endl; 
    return 0;
}

float Acircunferencia(float r) {
    float a = 3.14 * pow(r, 2);
    return a;
}

float Vcone(float r, float h) {
    float v = (1.0 / 3.0) * Acircunferencia(r) * h; 
    return v;
}

