#include <iostream>
#include "classes.h"
using namespace std;

int main()
{
    Moto *v1 = new Moto();
    cout << "Quantidade de rodas da moto eh: " << v1->rodas <<endl;
    cout << "Quantidade de velocidade da moto eh: " << v1->velocidade<<endl;
    return 0;
}