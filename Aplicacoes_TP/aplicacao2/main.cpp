#include <iostream>
#include <random>
using namespace std;

class Globo 
{
	private:
		int n[5];
	public:
		Globo(){
			n[0] = -1;n[1] = -1;n[2] = -1;n[3] = -1;n[4] = -1; //construtor
		}
		void numero_aleatorio(int );//fazer o set do numero aleatorio
		int get_numero(int contador){return n[contador];} //mostrar o numero aleatorio
};

void Globo::numero_aleatorio(int i){
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(0, 60);
	n[i] = dist(mt);
}
int main(){
	int palpite,quantidade;
	Globo mega;
	cout << "Quantos bilhetes você quer comprar? "<<endl;
	cin >>quantidade;
	for (int k=0; k<5;k++){
		cout<<"Construdor " <<mega.get_numero(k)<<endl;
	}

	for (int n = 0; n<quantidade ;n++)
	{
		cout <<endl<< "Bilhete "<< n+1 <<endl;
		for(int j=0; j<5;j++){
			cout <<"Digite seu palpite "<< j+1 <<" :";
			cin >> palpite;
			mega.numero_aleatorio(j);
			if (mega.get_numero(j) == palpite){
				cout << "Numero gerado: "<< mega.get_numero(j)<<endl;
				cout << "O palpite "<< j+1 <<" ACERTOU"<<endl;
			}
			else{
				cout << "Numero gerado: "<< mega.get_numero(j)<<endl;
				cout << "O palpite "<< j+1 <<" errou!"<<endl;
			}	
		}
		
	}
	return 0;
}

