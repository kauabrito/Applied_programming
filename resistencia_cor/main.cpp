#include <iostream>
#include <string>
#include <cmath>
#include "externo.cpp"
using namespace std;

class Resistor {
	string faixa1, faixa2, faixa3, faixa4, faixa5, faixa6;
	public:
		int c1(string );
		int c2(string );
		int c3(string );
		int c4(string );
		float c5(string );
		int c6(string );
		void p_6f(string, string, string, string, string, string);
		void p_5f(string, string, string, string, string);
		void p_4f(string, string, string, string);
		void p_3f(string, string, string);
};
void Resistor::p_3f(string co1, string co2, string co3){
	double resistor = (c2(co1)+c3(co2))*(pow(10, c4(co3)));
	cout << resistor <<endl;
	cout << resistor*1.2<<"ohm "<< endl;
	cout << resistor*0.8<<"ohm "<< endl;
}
void Resistor::p_4f(string co1, string co2, string co3, string co4){
	double resistor = (c2(co1)+c3(co2))*(pow(10, c4(co3)));
	cout << "Restencia: " <<resistor<<"ohm"<< endl;
	cout << resistor*(1 + (c5(co4))/100)<<"ohm "<<" +ou-"<<c5(co4)<<"% "<< endl;
	cout << resistor*(1 - (c5(co4))/100)<<"ohm "<<" +ou-"<<c5(co4)<<"% "<< endl;
}
void Resistor::p_5f(string co1, string co2, string co3, string co4, string co5){
	double resistor = (c1(co1)+c2(co2)+c3(co3))*(pow(10, c4(co4)));
	cout << "Resistencia "<<resistor<<"Ohms" <<endl;
	cout << "Resistencia (+t) = "<<resistor*(1 + (c5(co5))/100)<<"Ohms "<<" +ou-"<<c5(co5)<<"% "<< endl;
	cout << "Resistencia (-t) = "<<resistor*(1 - (c5(co5))/100)<<"ohm "<<" +ou-"<<c5(co5)<<"% "<< endl;
}
void Resistor::p_6f(string co1, string co2, string co3, string co4, string co5, string co6){
	double resistor = (c1(co1)+c2(co2)+c3(co3))*(pow(10, c4(co4)));
	cout << "Resistencia = "<<resistor <<"Ohms"<<endl;
	cout << "Resistencia (+t) = "<<resistor*(1 + (c5(co5))/100)<<"ohm "<<" +ou-"<<c5(co5)<<"% "<<c6(co6)<<" PPM/C"<< endl;
	cout << "Resistencia (-t) = "<<resistor*(1 - (c5(co5))/100)<<"ohm "<<" +ou-"<<c5(co5)<<"% "<<c6(co6)<<" PPM/C"<< endl;}
int Resistor::c1(string co1){
	if (co1 == "preto"){return 0;}
	if (co1 == "marrom"){return 100;}
	if (co1 == "vermelho"){return 200;}
	if (co1 == "laranja"){return 300;}
	if (co1 == "amarelo"){return 400;}
	if (co1 == "verde"){return 500;}
	if (co1 == "azul"){return 600;}
	if (co1 == "violeta"){return 700;}
	if (co1 == "cinza"){return 800;}
	if (co1 == "branco"){return 900;}}
int Resistor::c2(string co2){
	if (co2 == "preto"){return 0;}
	if (co2 == "marrom"){return 10;}
	if (co2 == "vermelho"){return 20;}
	if (co2 == "laranja"){return 30;}
	if (co2 == "amarelo"){return 40;}
	if (co2 == "verde"){return 50;}
	if (co2 == "azul"){return 60;}
	if (co2 == "violeta"){return 70;}
	if (co2 == "cinza"){return 80;}
	if (co2 == "branco"){return 90;}
}
int Resistor::c3(string co3){
	if (co3 == "preto"){return 0;}
	if (co3 == "marrom"){return 1;}
	if (co3 == "vermelho"){return 2;}
	if (co3 == "laranja"){return 3;}
	if (co3 == "amarelo"){return 4;}
	if (co3 == "verde"){return 5;}
	if (co3 == "azul"){return 6;}
	if (co3 == "violeta"){return 7;}
	if (co3 == "cinza"){return 8;}
	if (co3 == "branco"){return 9;}
	}
int Resistor::c4(string co4){ //numero_mutiplicador
	if (co4 == "preto"){return 0;}
	if (co4 == "marrom"){return 1;}
	if (co4 == "vermelho"){return 2;}
	if (co4 == "laranja"){return 3;}
	if (co4 == "amarelo"){return 4;}
	if (co4 == "verde"){return 5;}
	if (co4 == "azul"){return 6;}
	if (co4 == "violeta"){return 7;}
	if (co4 == "cinza"){return 8;}
	if (co4 == "branco"){return 9;}
	if (co4 == "dourado"){return -1;}
	if (co4 == "prata"){return -2;}
}
float Resistor::c5(string co5){    //tolerancia
	if (co5 == "preto"){return 0;}
	if (co5 == "marrom"){return 1;}
	if (co5 == "vermelho"){return 2;}
	if (co5 == "laranja"){return 0;}
	if (co5 == "amarelo"){return 0;}
	if (co5 == "verde"){return 0.5;}
	if (co5 == "azul"){return 0.25;}
	if (co5 == "violeta"){return 0.1;}
	if (co5 == "cinza"){return 0.05;}
	if (co5 == "branco"){return 0;}
	if (co5 == "dourado"){return 5;}
	if (co5 == "prata"){return 10;}
}
int Resistor::c6(string co6)
{
	if (co6 == "preto"){return 0;}
	if (co6 == "marrom"){return 100;}
	if (co6 == "vermelho"){return 50;}
	if (co6 == "laranja"){return 15;}
	if (co6 == "amarelo"){return 25;}
	if (co6 == "verde"){return 0;}
	if (co6 == "azul"){return 10;}
	if (co6 == "violeta"){return 5;}
	if (co6 == "cinza"){return 0;}
	if (co6 == "branco"){return 0;}
	if (co6 == "dourado"){return 0;}
	if (co6 == "prata"){return 0;}
}
int main() {
    int quant;
	Resistor res;
	string cor1,cor2, cor3, cor4, cor5, cor6;
	do{
		cout<< "Digite a quantidade de faixa "<<endl;
		quant = quantidade();
		if (quant == 6){
			cout<< "Digite o valor da faixa 1: ";
			cin >> cor1;
			cout<< "Digite o valor da faixa 2: ";
			cin >> cor2;
			cout<< "Digite o valor da faixa 3: ";
			cin >> cor3;
			cout<< "Digite o valor da faixa 4: ";
			cin >> cor4;
			cout<< "Digite o valor da faixa 5: ";
			cin >> cor5;
			cout<< "Digite o valor da faixa 6: ";
			cin >> cor6;
			res.p_6f(cor1,cor2, cor3, cor4, cor5, cor6);
		}
		else if (quant == 5){
			cout<< "Digite o valor da faixa 1: ";
			cin >> cor1;
			cout<< "Digite o valor da faixa 2: ";
			cin >> cor2;
			cout<< "Digite o valor da faixa 3: ";
			cin >> cor3;
			cout<< "Digite o valor da faixa 4: ";
			cin >> cor4;
			cout<< "Digite o valor da faixa 5: ";
			cin >> cor5;
			res.p_5f(cor1,cor2, cor3, cor4, cor5);
		}
		else if (quant == 4){
			cout<< "Digite o valor da faixa 1: ";
			cin >> cor1;
			cout<< "Digite o valor da faixa 2: ";
			cin >> cor2;
			cout<< "Digite o valor da faixa 3: ";
			cin >> cor3;
			cout<< "Digite o valor da faixa 4: ";
			cin >> cor4;
			res.p_4f(cor1,cor2, cor3, cor4);
		}
		else if (quant == 3){
			cout<< "Digite o valor da faixa 1: ";
			cin >> cor1;
			cout<< "Digite o valor da faixa 2: ";
			cin >> cor2;
			cout<< "Digite o valor da faixa 3: ";
			cin >> cor3;
			res.p_3f(cor1,cor2, cor3);
		}
		else {
			cout << "Quantidade digitada errada" <<endl;
		}
	}while(quant!=6 && quant!=5 && quant!=4 && quant!=3);
	return 0;
}