#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

class Resistor
{
	string cor1, cor2, cor3, cor4, cor5;
	public:
		int set_faixa1(string );
		int set_faixa2(string );
		int set_faixa3(string );
		float set_mult(string );
		float set_tolerancia(string );
		void set_resistencia(string, string, string, string, string);
};
void Resistor::set_resistencia(string f1,string f2,string f3,string f4,string f5){
	/*cout<<set_mult(f4)<<endl;
	cout<<set_tolerancia(f5)<<endl;
	cout<<set_faixa1(f1 )<<endl;
	cout<<set_faixa2(f2)<<endl;
	cout<<set_faixa3(f3 )<<endl;
	*/
	cout<<(set_faixa1(f1)+set_faixa2(f2)+set_faixa3(f3))*(pow(10,set_mult(f4))) <<" +ou-"<<set_tolerancia(f5)<<"%"<<endl;
	float resistencia = ((set_faixa1(f1)+set_faixa2(f2)+set_faixa3(f3))*(pow(10,set_mult(f4))));
	cout << fixed << setprecision(2)<< resistencia*(1.0+ (set_tolerancia(f5)/100.0))<<endl;
	cout << fixed << setprecision(2)<< resistencia*(1.0- (set_tolerancia(f5)/100.0))<<endl;
}
int Resistor::set_faixa1(string c1){
	cor1 = c1;
	if (cor1 == "preto"){return 0;}
	if (cor1 == "marrom"){return 100;}
	if (cor1 == "vermelho"){return 200;}
	if (cor1 == "laranja"){return 300;}
	if (cor1 == "amarelo"){return 400;}
	if (cor1 == "verde"){return 500;}
	if (cor1 == "azul"){return 600;}
	if (cor1 == "violeta"){return 700;}
	if (cor1 == "cinza"){return 800;}
	if (cor1 == "branco"){return 900;}
}
int Resistor::set_faixa2(string c2){
	cor2 = c2;
	if (cor2 == "preto"){return 0;}
	if (cor2 == "marrom"){return 10;}
	if (cor2 == "vermelho"){return 20;}
	if (cor2 == "laranja"){return 30;}
	if (cor2 == "amarelo"){return 40;}
	if (cor2 == "verde"){return 50;}
	if (cor2 == "azul"){return 60;}
	if (cor2 == "violeta"){return 70;}
	if (cor2 == "cinza"){return 80;}
	if (cor2 == "branco"){return 90;}
}

int Resistor::set_faixa3(string c3){
	cor3 = c3;
	if (cor3 == "preto"){return 0;}
	if (cor3 == "marrom"){return 1;}
	if (cor3 == "vermelho"){return 2;}
	if (cor3 == "laranja"){return 3;}
	if (cor3 == "amarelo"){return 4;}
	if (cor3 == "verde"){return 5;}
	if (cor3 == "azul"){return 6;}
	if (cor3 == "violeta"){return 7;}
	if (cor3 == "cinza"){return 8;}
	if (cor3 == "branco"){return 9;}
}

float Resistor::set_mult(string cor4){
	this->cor4 = cor4;
	if (cor4 == "preto"){return 0;}
	if (cor4 == "marrom"){return 1;}
	if (cor4 == "vermelho"){return 2;}
	if (cor4 == "laranja"){return 3;}
	if (cor4 == "amarelo"){return 4;}
	if (cor4 == "verde"){return 5;}
	if (cor4 == "azul"){return 6;}
	if (cor4 == "violeta"){return 7;}
	if (cor4 == "cinza"){return 8;}
	if (cor4 == "branco"){return 9;}
	if (cor4 == "dourado"){return -1;}
	if (cor4 == "prata"){return -2;}
}
float Resistor::set_tolerancia(string cor5){
	this->cor5 = cor5;
	if (cor5 == "preto"){return 0;}
	if (cor5 == "marrom"){return 1;}
	if (cor5 == "vermelho"){return 2;}
	if (cor5 == "laranja"){return 0;}
	if (cor5 == "amarelo"){return 0;}
	if (cor5 == "verde"){return 0.5;}
	if (cor5 == "azul"){return 0.25;}
	if (cor5 == "violeta"){return 0.1;}
	if (cor5 == "cinza"){return 0.05;}
	if (cor5 == "branco"){return 0;}
	if (cor5 == "dourado"){return 5;}
	if (cor5 == "prata"){return 10;}
}
int main() {
	Resistor r;
	string faixa1,faixa2, faixa3,faixa4, faixa5;
	cout<< "QUESTÃO 03_POO"<<endl<<endl;
	cout<< "Resistores de 5 faixas"<<endl;
	cout<< "Digite a faixa1: "<<endl;
	getline(cin, faixa1);
	
	cout<< "Digite a faixa2: "<<endl;
	getline(cin, faixa2);
	
	cout<< "Digite a faixa3: "<<endl;
	getline(cin, faixa3);
	
	cout<< "Digite a faixa4(Nº de zero): "<<endl;
	getline(cin, faixa4);
	
	cout<< "Digite a faixa5(Tolerancia): "<<endl;
	getline(cin, faixa5);
	
	r.set_resistencia(faixa1,faixa2, faixa3, faixa4, faixa5);
	return 0;
}