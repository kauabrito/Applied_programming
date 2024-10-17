#include <iostream>
#include <cmath>
using namespace std;

class EquacaoQ{
	float r1, i1, r2, i2;
	public:
		void calcular0(int a, int b, int c){
			int delta = pow(b,2) +((-4)*a*c);
			if (delta <0){
				r1 = (-1*b)/(2*a);
				i1 = sqrt((-1)*delta)/(2*a);
				r2 = (-1*b)/(2*a);
				i2 = sqrt((-1)*delta)/(2*a);
				cout << r1  <<" + "<< i1 <<"i"<<endl;
				cout << r2  <<" - "<< i2 <<"i"<<endl;
			}
			else {
				r1 = ((-1*b)+ sqrt(delta))/(2*a);
				i1 = 0;
				r2 = ((-1*b)- sqrt(delta))/(2*a);
				i2 = 0;
				cout << r1 + i1<<" + "<< i1<<"i" <<endl;
				cout << r2 - i2<<" + "<< i1<<"i" <<endl;
			} 
		}
		float real1(){return r1;}
		float img1(){return i1;}
		float real2(){return r2;}
		float img2(){return i2;}
};


int main() {
	EquacaoQ objeto;
	int c1, c2,c3;
	cout << "Digite o coeficiente a: ";
	cin >> c1;
	cout << "Digite o coeficiente b: ";
	cin >> c2;
	cout << "Digite o coeficiente c: ";
	cin >> c3;
	objeto.calcular0(c1, c2, c3);
	
	return 0;
}