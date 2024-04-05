#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Midia{
	string titulo;
	int anoPublicacao;
	int id;
	string v; //verifica se foi emprestada, devolvida ou nunca emprestada
	public:
		Midia()
		{
			titulo = "Nao cadastrado";
			anoPublicacao = 0;
			id = 0;
			v = "Nunca emprestada";
		}
		string getT(){
			return titulo;
		}
		void setT(string titulo){
			this->titulo= titulo;
		}
		int getA(){
			return anoPublicacao;
		}
		void setA (int anoPublicacao){
			this->anoPublicacao= anoPublicacao;
		}
		int getI(){
			return id;
		}
		void setI(int id){
			this->id= id;
		}
		void emprestar(int V){
			if(V == 1){
				this->v = "EMPRESTADO";
			}
		}
		void devolver(int V){
			if(V == 0){
				this->v = "Devolvido. Portanto, esta no biblioteca";
			}
		}
		string getStatus(){
			return v;
		}
		void Exibir(){
			cout << "Titulo: "<<getT()<<endl;
			cout << "Ano publicacao: "<<getA()<<endl;
			cout << "Id: "<<getI()<<endl;
		}
};

class Livro : public Midia{
	string autor;
	public:
		Livro()
		{
			autor = "Nao cadastrado";	
		}
	string getAutor(){
		return autor;
	}
	void setAutor(string autor){
		this->autor=autor;
	}
	void ExibirL(){
			Exibir();
			cout <<"Autor: "<<getAutor()<<endl;
		}
};

class Revista : public Midia{
	int numeroEdicao;
	public:
		Revista(){
			numeroEdicao = -1;
		}
	void setNumeroEdicao(int numeroEdicao){
		this->numeroEdicao=numeroEdicao;
	}
	int getNumeroEdicao(){
		return numeroEdicao;
	}
	void ExibirR(){
		Exibir();
		cout << "Numero da Edicao: "<< getNumeroEdicao()<<endl;
	}
};

class Audiolivro : public Midia{
	string narrador;
	public:
		Audiolivro(){
			narrador = "Ainda nao cadastrado";
		}
		string getNarrador(){
			return narrador;
		}
		void setNarrador(string narrador){
			this->narrador = narrador;
		}
		void ExibirAL(){
		Exibir();
		cout << "Nome do Narrador: "<< getNarrador()<<endl;
	}
};
int main() {
	vector<Livro*>livro;
	vector<Revista*>revista;
	vector<Audiolivro*>AL;
	int i; //auxiliadora
	string titulo, autor, narrador, aux, aux2;
	int anoPublicacao, id, numeroEdicao, op;
	do{
		cout << "[0] - Sair do programa"<<endl<<"[1] - Cadastrar livro"<<endl<<"[2] - Cadastrar Revista"<< endl<<"[3] - Cadastrar AudioLivro"<<endl<<"[4] - Buscar Livro"<<endl<<"[5] - Buscar Revista"<<endl<<"[6] - Buscar AudioLivro"<<endl<<"[7] - Emprestar ou Devolver"<<endl;
		cin >> op;
		switch(op){
			case 1:
				livro.push_back(new Livro);
				cout << "Escreva o nome do livro: "<<endl;
				cin.ignore();
				getline(cin, titulo);
				livro.back()->setT(titulo);
				cout << "Escreva o anoPublicado do livro: "<<endl;
				cin >> anoPublicacao;
				livro.back()->setA(anoPublicacao);
				cout << "Escreva o id do livro: ";
				cin >> id;
				livro.back()->setI(id);
				cout << "Escreva o Autor do livro: "<<endl;
				cin.ignore();
				getline(cin, autor);
				livro.back()->setAutor(autor);
				break;
			case 2:
				revista.push_back(new Revista);
				cout << "Escreva o nome do Revista: "<<endl;
				cin.ignore();
				getline(cin, titulo);
				revista.back()->setT(titulo);
				cout << "Escreva o anoPublicado do Revista: "<<endl;
				cin >> anoPublicacao;
				revista.back()->setA(anoPublicacao);
				cout << "Escreva o id do Revista: ";
				cin >> id;
				revista.back()->setI(id);
				cout << "Escreva o NumeroEdicao do Revista: "<<endl;
				cin >> numeroEdicao;
				revista.back()->setNumeroEdicao(numeroEdicao);
				break;
			case 3:
				AL.push_back(new Audiolivro);
				cout << "Escreva o nome do AudioLivro: "<<endl;
				cin.ignore();
				getline(cin, titulo);
				AL.back()->setT(titulo);
				cout << "Escreva o anoPublicado do AudioLivro: "<<endl;
				cin >> anoPublicacao;
				AL.back()->setA(anoPublicacao);
				cout << "Escreva o id do AudioLivro: "<<endl;
				cin >> id;
				AL.back()->setI(id);
				cout << "Escreva o narrador do AudioLivro: "<<endl;
				cin.ignore();
				getline(cin, titulo);
				AL.back()->setNarrador(narrador);
				break;
			case 4:
				i=0;
				if(livro.empty()){
					cout << "Nao existe livro cadastrado"<<endl;
				}
				else{
					cout << "Digite o id do livro: ";
					cin >> id;
					for(auto x:livro){
						if(x->getI() == id)
						{
							cout << "Livro encontrado"<<endl;
							cout << "O status eh: "<< x->getStatus()<<endl;
							x->ExibirL();
							break;
						}
						else if (i == livro.size()-1){
							cout << "Nao tem na biblioteca"<<endl;
						}
						i++;
					}
				}
				break;
			case 5:
				i=0;
				if(revista.empty()){
					cout << "Nao existe Revista cadastrado"<<endl;
				}
				else{
					cout << "Digite o id da Revista: ";
					cin >> id;
					for(auto x:revista){
						if(x->getI() == id)
						{
							cout << "Revista encontrada"<<endl;
							cout << "O status eh: "<<x->getStatus()<<endl;
							x->ExibirR();
							break;
						}
						else if (i == revista.size()-1){
							cout << "Nao tem na biblioteca"<<endl;
						}
						i++;
					}
				}
				break;
			case 6:
				i=0;
				if(AL.empty()){
					cout << "Nao existe AudioLivro cadastrado"<<endl;
				}
				else{
					cout << "Digite o id do AudioLivro: ";
					cin >> id;
					for(auto x:AL){
						if(x->getI() == id)
						{
							cout << "AudioLivro encontrado"<<endl;
							cout << "O status eh: "<<x->getStatus()<<endl;
							x->ExibirAL();
							break;
						}
						else if (i == AL.size()-1){
							cout << "Nao tem na biblioteca"<<endl;
						}
						i++;
					}
				}
				break;
			case 7:
				i=0;
				if(livro.empty() && revista.empty() && AL.empty()){
					cout << "BANCO DE DADOS VAZIO"<<endl;
				}
				else{
					cout << "Voce quer emprestar ou devolver"<<endl;
                    cin.ignore();
					getline(cin, aux);
					if(aux == "emprestar"){
						cout << "Voce quer Livro, revista ou AudioLivro? "<<endl;
                        //cin.ignore();
						getline(cin, aux2);
						if(aux2 == "livro"){
                            if(livro.empty()){cout <<"Nenhum livro cadastrado"<<endl;}
                            else
                            {
                                cout << "Digite o id do Livro: "<<endl;
								cin >> id;
								
							    for(auto x:livro){
								    if(x->getI() == id)
								{	
									if(x->getStatus() == "Nunca emprestada" || x->getStatus() == "Devolvido. Portanto, esta no biblioteca"){
										cout << "Livro Na biblioteca"<<endl;
										x->emprestar(1);
										break;
									}
									else{cout << "Nao eh possivel pegar emprestado, pois tem alguem com o livro!"<<endl;}
									
									break;
								}
								else if (i == livro.size()-1)
								    {
									    cout << "Nao tem na biblioteca"<<endl;
								    }
								i++;
						        }
                            }
						}
						
						else if(aux2 == "revista"){
                            if(revista.empty()){cout <<"Nenhuma revista no cadastro"<<endl;}

                            else{
                                cout << "Digite o id da revista: "<<endl;
								cin >> id;
								
							for(auto x:revista){
								if(x->getI() == id)
								{
									if(x->getStatus() == "Nunca emprestada" || x->getStatus() == "Devolvido. Portanto, esta no biblioteca"){
										cout << "Revista encontrada, revista na biblioteca!"<<endl;
										x->emprestar(1);
										break;
									}
									else{cout << "Nao eh possivel pegar emprestado, pois tem alguem com a Revista!"<<endl;}
									
									break;
								}
								else if (i == revista.size()-1)
								{
									cout << "Nao tem na biblioteca"<<endl;
								}
								    i++;
						    }
                            }
								
						}
						else if(aux2 == "audiolivro"){
                            if(AL.empty()){cout << "Nao existe nenhum audioLivro cadastrado" <<endl;}

                            else{
                                cout << "Digite o id da audiolivro: "<<endl;
								cin >> id;
								
							for(auto x:AL){
								if(x->getI() == id)
								{
									if(x->getStatus() == "Nunca emprestada" || x->getStatus() == "Devolvido. Portanto, esta no biblioteca"){
										cout << "AudioLivro encontrado, AudioLivro na biblioteca"<<endl;
										x->emprestar(1);
										break;
									}
									else{cout << "Nao eh possivel pegar emprestado, pois tem alguem com o AudioLivro!"<<endl;}
									
									break;
								}
								else if (i == AL.size()-1)
								{
									cout << "Nao tem na biblioteca"<<endl;
								}
								i++;
						    }
                            }
								
						}
					}
					
					else if(aux == "devolver"){
						cout << "Voce quer devolver Livro, revista ou AudioLivro? "<<endl;
                        //cin.ignore();
						//getline(cin, aux2);
						cin >> aux2;
						if(aux2 == "livro"){
								cout << "Digite o id do Livro: "<<endl;
								cin >> id;
								
							for(auto x:livro){
								if(x->getI() == id)
								{
									if(x->getStatus() == "EMPRESTADO"){
										cout << "Livro devolvido"<<endl;
										x->devolver(0);
										break;
									}
									else{
										cout << "Nao eh possivel devolver se nao pegou emprestado" <<endl;
										break;
									}
									
								}
								else if (i == livro.size()-1)
								{
									cout << "Nao tem na biblioteca"<<endl;
								}
								i++;
						}
						}
						
						else if(aux2 == "revista"){
								cout << "Digite o id da revista: ";
								cin >> id;
								
							for(auto x:revista){
								if(x->getI() == id)
								{	if(x->getStatus() == "EMPRESTADO"){
										cout << "Revista devolvida"<<endl;
										x->devolver(0);
										break;
									}
									else{
										cout << "Nao eh possivel devolver se nao pegou emprestado" <<endl;
										break;
									}
								}
								else if (i == revista.size()-1)
								{
									cout << "Nao tem na biblioteca"<<endl;
								}
								i++;
						}
						}
						else if(aux2 == "audiolivro"){
								cout << "Digite o id da audiolivro: ";
								cin >> id;
								
							for(auto x:AL){
								if(x->getI() == id)
								{
									if(x->getStatus() == "EMPRESTADO"){
										cout << "AudioLivro devolvido"<<endl;
										x->devolver(0);
										break;
									}
									else{
										cout << "Nao eh possivel devolver se nao pegou emprestado" <<endl;
										break;
									}
								}
								else if (i == AL.size()-1)
								{
									cout << "Nao tem na biblioteca"<<endl;
								}
								i++;
						}
						}
						else{
							cout <<"Opcao invalida"<<endl;
						}
					}
					
				}
				break;
				
				default:
					if(op !=0){cout << "Digite o numero da opcao correta"<<endl;}
				break;
	}
	}while(op!=0);
	return 0;
}