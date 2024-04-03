#include <iostream>
using namespace std;
class Retangulo {
    float x, y;
    public:
        Retangulo (){x =0 ; y = 0;}
        Retangulo operator + (Retangulo);
        Retangulo operator * (Retangulo);
        Retangulo operator / (Retangulo);
        void operator ++ () { x++; y++; }
        void set(int a, int b){x =a; y = b;}
        void mostra(){cout << "(x= " << x << ", y= " << y << ")" << endl;};
        float area () {return x * y;}
};

Retangulo Retangulo::operator + (Retangulo Temp){
    Retangulo temp2;
    temp2.x = x + Temp.x;
    temp2.y = y + Temp.y;
    return temp2;
}

Retangulo Retangulo::operator * (Retangulo Temp)
{
    Retangulo temp2;
    temp2.x = x * Temp.x;
    temp2.y = y * Temp.y;
    return temp2;
}

Retangulo Retangulo::operator / (Retangulo Temp)
{
    if (Temp.x != 0 && Temp.y != 0) {
        Retangulo temp2;
        temp2.x = x / Temp.x;
        temp2.y = y / Temp.y;
        return temp2;
    } else {
        cout << "Erro: divisão por zero!" << endl;
        return Retangulo();
    }
}


int main () {
    Retangulo A, B, C;
    A.set(1,2);
    B.set(3,4);
    C = A + B;
    C.mostra();
    //++A;
    //A.mostra();
    C = A * B;
    C.mostra();
    C = A / B;
    C.mostra();
    return 0;
}