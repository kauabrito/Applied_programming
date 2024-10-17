#include <iostream>

using namespace std;

class circulo{
		private:
			float raio;
		public:
			void set_raio(float raio);
			float get_raio();
			float area();
			float comprimento();
			circulo(){
				raio = 5.5;
			}
	};

int main() 
{
	
	float ra;
	circulo c1;
	circulo construtor;
	cout << "Digite o valor do raio: ";
	cin >> ra;
	c1.set_raio(ra);
	cout << c1.area()<<endl;
	cout << c1.comprimento()<<endl;
	cout << "Construdor(c), r = "<<construtor.get_raio()<<endl;
	cout << "Area, Ac = "<<construtor.area()<<endl;
	cout << "Comprimento, Cc = "<<construtor.comprimento()<<endl;
	return 0;
}
void  circulo::set_raio(float raio)
{
	this->raio=raio;
}
float  circulo::get_raio(){
	return raio;
}
float circulo::area()
{
	float a = 3.14*raio*raio ;
	return a; 
}

float circulo::comprimento()
{
 	float c = 2*3.14*raio ;
	return c;
}