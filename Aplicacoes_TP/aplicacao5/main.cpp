#include <iostream>
#include <string>

using namespace std;

void set_name(void);
void set_idade(void);
void set_CRA(void);

int idade_ex;
string name_ex;
float CRA_ex;
bool na;
	class Aluno{
		string n[100];
		int idade[100];
		float CRA[100]; 
	public: 
		string resposta;
		
		void consultar(string );
		void maior();
		void cadastro(int quantidade){
			for (int j=0; j<quantidade; j++){
				do{
					cout << "Digite o nome do aluno: "<< j+1 <<" ";
					set_name();
				}while(!na);
				n[j] = name_ex;
				do{
					cout << "Digite a idade de: "<< n[j] <<" ";
					set_idade();
					idade[j] = idade_ex;
				}while(idade[j] < 0);
				
				do{
					cout<< "Digite o CRA de " << n[j] << ": ";
					set_CRA();
					CRA[j] = CRA_ex;
				}while(CRA[j] < 0 || CRA[j] > 10);
				
				cout <<endl<<endl;
			}
			
			do{
				
				cout << "\nDeseja consultar algum cadastro de aluno? Digite sim ou nao: ";
				cin >> resposta;
				consultar(resposta);
				
			}while(resposta == "sim");
		}
		
	};
	
void Aluno::consultar(string resposta){
	int numero;
	if (resposta == "sim"){
		cout << "Digite o número do aluno: ";
		cin >> numero;
		cout<<"Nome do aluno: " <<n[numero-1]<< endl;
		cout<<"Idade: "<<idade[numero-1]<< endl ;
		cout<<"CRA: "<< CRA[numero-1] << endl ; 
	}
	if (resposta == "nao"){
		cout << "Sistema finalizado";
	}
}
void Aluno::maior(){
	
}
	int main() {
		Aluno objeto1;
		int quant;
		cout <<"Quantos cadastros voceh deseja realizar? ";
		cin >>quant;
		objeto1.cadastro(quant);
		
	return 0;
}