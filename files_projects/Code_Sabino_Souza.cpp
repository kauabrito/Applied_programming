/*
Autor: SABINO SOUZA AGUIAR FILHO
Linkedin: https://www.linkedin.com/in/sabino-souza-aguiar-filho-96b44a309/
*/


/*Crie um codigo que usa a class "Banco" para a criação, saque, deposito e exibição de contas bancárias.
A class ultilizada contém os métodos de get, que retornam a variável requisitada, além de metodos que supram o que foi requisitado.
Crie um menu que opere o que foi pedido.*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

class Banco {
protected:
    string nome;
    int senha, numConta;
    float saldo;

public:
    Banco(string nome, int senha, int numConta, float saldo) {
        this->nome = nome;
        this->senha = senha;
        this->numConta = numConta;
        this->saldo = saldo;
    }

    ~Banco() {}

    void depositar(float valor) {
        saldo += valor;
        cout << endl << "----------------------------------------------------" << endl;
        cout << "Deposito de R$" << valor << " realizado com sucesso na conta de " << nome << "." << endl;
        cout << "----------------------------------------------------" << endl;
    }

    void sacar(float valor) {
        if (valor > saldo) {
            cout << endl << "----------------------------------------------------" << endl;
            cout << "Saldo insuficiente para realizar o saque." << endl;
            cout << "----------------------------------------------------" << endl;
        }
        else {
            saldo -= valor;
            cout << endl << "----------------------------------------------------" << endl;
            cout << "Saque de R$" << valor << " realizado com sucesso." << endl;
            cout << "----------------------------------------------------" << endl;
        }
    }

    string getNome() {
        return nome;
    }
    int getSenha() {
        return senha;
    }
    int getNumeroConta() {
        return numConta;
    }
    float getSaldo() {
        return saldo;
    }

    void exibirDados() {
        cout << endl << "----------------------------------------------------" << endl;
        cout << "Nome do titular: " << nome << endl;
        cout << "Senha: " << senha << endl;
        cout << "Numero da conta: " << numConta << endl;
        cout << "Saldo: R$" << saldo << endl;
    }
};

class ContaCorrente : public Banco {  //Classe herdeira como pedido na questão 2.
private:
    float limiteChequeEspecial;

public:
    ContaCorrente(string nome, int senha, int numConta, float saldo, float limiteChequeEspecial) : Banco(nome, senha, numConta, saldo) {
        this->limiteChequeEspecial = limiteChequeEspecial;
    }
    ~ContaCorrente(){}
    void transferir(float valor, string nomeDestino) {
        saldo -= valor;
        cout << endl << "----------------------------------------------------" << endl;
        cout << "Transferencia de R$" << valor << " realizada com sucesso para a conta de " << nomeDestino << "." << endl;
        cout << "----------------------------------------------------" << endl;
    }
    void exibirContaCorrente(){
    	exibirDados();
    	cout << "Limite de cheque especial: R$" << limiteChequeEspecial << endl;
    	cout << "----------------------------------------------------" << endl;
	}

    float getLimiteChequeEspecial() {
        return limiteChequeEspecial;
    }
};

int main() {
	
	ofstream saida0("LEITURA.txt", ios::app); // Criando o arquivo .txt
	vector<ContaCorrente*> contas;
    int op, i;
    string nome, nomeDestino;
    int senha, numConta;
    float valor, limiteChequeEspecial;
    float saldo = 0;
    
    ifstream entrada0("LEITURA.txt");
    cout << "LODING ";
    system("timeout /t 1 > nul");
    cout << ". ";
    system("timeout /t 1 > nul");
    cout << ". ";
    system("timeout /t 1 > nul");
    cout << ". " << endl;
    system("timeout /t 1 > nul");
	if(!entrada0){
		cout << "O arquivo nao pode ser aberto!";
		return 1;
	}
	while (true) {
	    getline(entrada0, nome);
	    if (entrada0.fail()) {  // Verifica se a leitura deu erro, que pode ocorrer ou pq já chegou no final ou pq ouve algum emprevisto na leitura.
	        if (entrada0.eof()) {
	            cout << "Leitura do arquivo concluida." << endl;
	            system("timeout /t 3 > nul");
	            system("cls");
	            break; // Verifica se chegou ao final do arquivo.
	        } 
			else {
	            cout << "Erro de formato ao ler o arquivo!" << endl;
	            return 1;
	        }
	    }
	    entrada0 >> senha >> numConta >> saldo >> limiteChequeEspecial;
	    contas.push_back(new ContaCorrente(nome, senha, numConta, saldo, limiteChequeEspecial));  // Criando vetores a partir do que já foi criado anteriormente
	    entrada0.ignore();
	}  
    do {
        i = 0;
        cout << "Escolha a operacao:" << endl << "[1]Cadastrar conta" << endl << "[2]Depositar" << endl << "[3]Sacar" << endl << "[4]Consultar dados da conta" << endl << "[5]Realizar transferencia" << endl << "[0]Sair" << endl;
        cin >> op;
        switch (op) {
            case 1:
            	system("cls");
                cin.ignore();
                cout << "Digite o nome do titular: " << endl;
                getline(cin, nome);
                cout << "Digite o numero da conta: " << endl;
                cin >> numConta;
                cout << "Digite a nova senha: " << endl;
                cin >> senha;
                cout << "Digite o limite do cheque especial: ";
                cin >> limiteChequeEspecial;
                for(auto ptr : contas){
                    if(ptr->getNome() == nome || ptr->getNumeroConta() == numConta){  //Verificaçao de erro.
                        cout << "DADOS JA CADASTRADOS" << endl;
                        system("timeout /t 3 > nul");
                        system("cls");
                        break;
                    }
                }
                contas.push_back(new ContaCorrente(nome, senha, numConta, saldo, limiteChequeEspecial));
                system("timeout /t 3 > nul");
                system("cls");
                break;
            case 2:
            	system("cls");
                cout << "Digite o numero da conta: " << endl;
                cin >> numConta;
                cout << "Digite o valor para depositar:" << endl;
                cin >> valor;
                if(contas.empty()){
                    cout << "NENHUMA CONTA CADASTRADA" << endl;  //Verificaçao de erro.
                    system("timeout /t 3 > nul");
                    system("cls");
                    break;
                }
                for(auto ptr : contas){
                    if(ptr->getNumeroConta() == numConta){
                        ptr->depositar(valor);
                        system("timeout /t 3 > nul");
                        system("cls");
                        break;
                    }
                    else if(i == contas.size()-1) cout << "CONTA NAO CADASTRADA!" << endl;
                    i++;
                }
                system("timeout /t 3 > nul");
                system("cls");
                break;
            case 3:
            	system("cls");
                cin.ignore();
                cout << "Digite o nome do titular: " << endl;
                getline(cin, nome);
                cout << "Digite o numero da conta: " << endl;
                cin >> numConta;
                cout << "Digite a senha: " << endl;
                cin >> senha;
                cout << "Digite o valor que deseja sacar: " << endl;
                cin >> valor;
                if(contas.empty()){
                    cout << "NENHUMA CONTA CADASTRADA" << endl;  //Verificaçao de erro.
                    system("timeout /t 3 > nul");
                    system("cls");
                    break;
                }
                for(auto ptr : contas){
                    if(ptr->getNome() == nome && ptr->getSenha() == senha && ptr->getNumeroConta() == numConta){
                        ptr->sacar(valor);
                        system("timeout /t 3 > nul");
                        system("cls");
                        break;
                    }
                    else if(i == contas.size()-1) cout << "DADOS NAO CADASTRADOS!" << endl;
                    i++;
                }
                system("timeout /t 3 > nul");
                system("cls");
                break;
            case 4:
            	system("cls");
                cout << "Digite o numero da conta: " << endl;
                cin >> numConta;
                cout << "Digite a senha: " << endl;
                cin >> senha;
                if(contas.empty()){
                    cout << "NENHUMA CONTA CADASTRADA" << endl;  //Verificaçao de erro.
                    system("timeout /t 3 > nul");
                    system("cls");
                    break;
                }
                for(auto ptr : contas){
                    if(ptr->getSenha() == senha && ptr->getNumeroConta() == numConta){
                        ptr->exibirContaCorrente();
                        break;
                    } 
                    else if(i == contas.size()-1) cout << "DADOS NAO CADASTRADOS!" << endl;
                    i++;
                }
                break;  
            default:
                if (op != 0)cout << "OPCAO INVALIDA" << endl;
                system("timeout /t 3 > nul");
                system("cls");
                break;
            
			case 5:  //Nova opção para transferências.
				system("cls");
                if(contas.empty()){
                    cout << "NENHUMA CONTA CADASTRADA" << endl;  //Verificaçao de erro.
                    system("timeout /t 3 > nul");
                    system("cls");
                    break;
                }
                cin.ignore();
                cout << "Digite o nome do titular: " << endl;
                getline(cin, nome);
                cout << "Digite o numero da conta: " << endl;
                cin >> numConta;
                cout << "Digite a senha: " << endl;
                cin >> senha;
                cin.ignore();
                cout << "Digite o nome do destinatario: " << endl;
                getline(cin, nomeDestino);
                cout << "Digite o valor que deseja transferir para " << nomeDestino << ":" << endl;
                cin >> valor;
                for(auto ptr : contas){
                    if(ptr->getNome() == nome && ptr->getSenha() == senha && ptr->getNumeroConta() == numConta && ptr->getLimiteChequeEspecial() + ptr->getSaldo() >= valor){
                        ptr->transferir(valor, nomeDestino);
                        for (auto ptr : contas){
                            if(ptr->getNome() == nomeDestino){
                                ptr->depositar(valor);
                                system("timeout /t 3 > nul");
                                system("cls");
                                break;
                            }
                            else if(i == contas.size()-1){
                            	cout << "DESTINATARIO NAO ENCONTRADO!" << endl;
                            	for (auto ptr : contas){
                            		if(ptr->getNome() == nome)	ptr->depositar(valor);
                                }
                        	}
                            i++;                       
                    	}	
                	}	
            	}
            	system("timeout /t 3 > nul");
            	system("cls");
                break;    
        }
    } while (op != 0);
    
    ofstream saida("CONTAS.txt", ios::app);
    saida0.close();
	saida.close();
	saida.open("CONTAS.txt"); // Maneira pra reescrever os dados
	saida0.open("LEITURA.txt");

    for(auto ptr : contas){
    	saida0 << ptr->getNome() << endl;
    	saida0 << ptr->getSenha() << endl;
    	saida0 << ptr->getNumeroConta() << endl;  //  Salvando em LEITURA.txt, para conseguir ter a leitura de contas criadas anteriormente.
    	saida0 << ptr->getSaldo() << endl;
    	saida0 << ptr->getLimiteChequeEspecial() << endl;
	}
	  
    ifstream entrada("CONTAS.txt");
	string linha1 = "--------------CONTAS SALADINHA BANK--------------";
	string linha;
	getline(entrada, linha); // Lê a primeira linha do arquivo
	if (linha != linha1) saida << "--------------CONTAS SALADINHA BANK--------------" << endl; // Verifica se o arquivo já possui a parte de inicialização
    	
    
    for(auto ptr : contas){
    	saida << "NOME: " << ptr->getNome() << endl;
    	saida << "SENHA: " << ptr->getSenha() << endl;
    	saida << "NUMERO DA CONTA: " << ptr->getNumeroConta() << endl;  //  Salvando em CONTAS.txt, para melhor visualização.
    	saida << "SALDO: R$" << ptr->getSaldo() << endl;
    	saida << "CHEQUE ESPECIAL: R$" << ptr->getLimiteChequeEspecial() << endl;
    	saida << "---------------------------------------------------------------------------------" << endl;
	}
	entrada.close();
	entrada0.close();
	saida0.close();
	saida.close();
    
    for(auto ptr : contas){  //Excluindo os vectors.
        delete ptr;
    }
    return 0;
}