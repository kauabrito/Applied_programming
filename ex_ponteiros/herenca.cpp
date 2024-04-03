#include <iostream>
using namespace std;

class MAE {
private:
    int a = 4;
protected:
    int b = 3;
public:
    int c = 5;
};

class FILHO : private MAE {
public:
    int getb() { return b; } // OK
    int getc() { return c; } // OK
};

class NETO : public FILHO {
public:
    int getB() {
        return getb(); 
    } 
    int getC() {
      
        return getc(); 
    } 
};

int main() {
    MAE maria;
    
    cout << maria.c << endl; // OK

    NETO joao;
    
    cout << joao.getB() << endl; // OK
    cout << joao.getC() << endl; // OK

    return 0;
}
