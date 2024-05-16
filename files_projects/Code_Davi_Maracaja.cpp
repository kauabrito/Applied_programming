/*
Autor: Davi Maracaja Bastos
Linkedin: https://www.linkedin.com/in/davi-maracaj%C3%A1-b45a41234/
*/
#include<iostream>
#include<vector>

using namespace std;
class midia{
	string titulo;
	int ano;
	int id;
	int emprestado;
	public:
	midia(string titulo,int ano,int id,int emprestado)
		{
			this->titulo = titulo;
			this->ano = ano;
			this->id = id;
			this->emprestado = emprestado;
		}
		~midia(){}
	void emprestar(){emprestado = 1;}
	void devolvida(){emprestado = 0;}
	string getTitulo(){return titulo;}
	int getAno(){return ano;}
	int getId(){return id;}
	int getEmprestado(){return emprestado;}	
	void setEmprestado(int emprestado)
	{
		this->emprestado = emprestado;	
	}
	
};

class livro: public midia{
	string autor;
	public:
	livro(string titulo,int ano,int id,int emprestado,string autor) : midia(titulo,ano,id,emprestado)
	{
		this->autor = autor;
	}
	~livro(){}
	string getAutor(){return autor;}
	
	
};

class revista: public midia{
	int edicao;
	public:
		revista(string titulo,int ano,int id,int emprestado,int edicao) : midia(titulo,ano,id,emprestado) 
		{
			this->edicao = edicao;
		}
		~revista(){}
	int getEdicao(){return edicao;}
};

class audioLivro : public midia{
	string narrador;
	public:
		audioLivro(string titulo,int ano,int id,int emprestado,string narrador) : midia(titulo,ano,id,emprestado)
		{
			this->narrador = narrador; 
		}
		~audioLivro();
	string getNarrador(){return narrador;}
};

vector<livro*> livros;
vector<revista*> revistas;
vector<audioLivro*> audioLivros;

int main()
{
	string autor,narrador,titulo;
	int ano;
	int id;
	int edicao;
	int tipo;
	int op;
	int verificador = 1;
	int achou = 0;
	int i = 0;
	
	do{	
	cout<<"digite a opcao desejada"<<endl<<"1-adicionar midia\n2-visualizar\n3-emprestar\n4-devolver\n5-sair\n";
	cin>>op;
	switch(op)
	{
		case 1:
			system("cls");
			cout<<"qual midia deseja cadastrar\n"<<"1-livro\n2-revista\n3-ano publicado\n";
			cin>>tipo;
			switch(tipo)
			{
				case 1:
					
					cout<<"titulo : "<<endl;
					cin.ignore();
					getline(cin,titulo);
					cout<<"ano publicado"<<endl;
					cin>>ano;
					cout<<"id"<<endl;
					cin>>id;
					cout<<"autor :"<<endl;	
					cin.ignore();
					getline(cin,autor);
					livros.push_back(new livro(titulo,ano,id,0,autor));
					break;
				case 2:
					cout<<"titulo : "<<endl;
					cin.ignore();
					getline(cin,titulo);
					cout<<"ano publicado"<<endl;
					cin>>ano;
					cout<<"id"<<endl;
					cin>>id;
					cout<<"edicao :"<<endl;
					cin>>edicao;
					revistas.push_back(new revista(titulo,ano,id,0,edicao));
					break;
				case 3:
					cout<<"titulo : "<<endl;
					cin.ignore();
					getline(cin,titulo);
					cout<<"ano publicado"<<endl;
					cin>>ano;
					cout<<"id"<<endl;
					cin>>id;
					cout<<"narrador :"<<endl;
					cin.ignore();
					getline(cin,narrador);
					audioLivros.push_back(new audioLivro(titulo,ano,id,0,narrador));
					break;			
			}
				system("cls");
			break;
		case 2:
				system("cls");
			cout<<"\ndigite o id da midia a ser procurada\n";
			cin>>id;
			
			for(auto y:livros)
			{
				if(id == y->getId())
				{	cout<<"---------------------\n";
					cout<<"titulo :"<<y->getTitulo()<<endl;
					cout<<"ano publicado :"<<y->getAno()<<endl;
					cout<<"id :"<<y->getId()<<endl;
					cout<<"autor :"<<y->getAutor()<<endl;
					cout<<"emprestado : "<<y->getEmprestado()<<endl;
					achou = 1;
					cout<<"---------------------\n";
				}
				
			}
			for(auto z:revistas)
			{
				if(id == z->getId())
				{		cout<<"---------------------\n";
					cout<<"titulo :"<<z->getTitulo()<<endl;
					cout<<"ano publicado :"<<z->getAno()<<endl;
					cout<<"id :"<<z->getId()<<endl;
					cout<<"edicao :"<<z->getEdicao()<<endl;
					cout<<"emprestado : "<<z->getEmprestado()<<endl;
						cout<<"---------------------\n";
					achou = 1;
				}
				
			}
			for(auto w:audioLivros)
			{
				if(id == w->getId())
				{
						cout<<"---------------------\n";
					cout<<"titulo :"<<w->getAno()<<endl;
					cout<<"ano publicado :"<<w->getAno()<<endl;
					cout<<"id :"<<w->getId()<<endl;
					cout<<"autor :"<<w->getNarrador()<<endl;
					cout<<"emprestado : "<<w->getEmprestado()<<endl;
					achou = 1;
						cout<<"---------------------\n";
				}
				
			}
			if(!achou)
			{
				cout<<"midia nao encontrada";
			}
			
			break;
		case 3:
				system("cls");
			cout<<"digite o id da midia a ser emprestada";
			cin>>id;
				for(auto y:livros)
			{
				if(id == y->getId())
				{
					y->setEmprestado(1);
				}
				
			}
			for(auto z:revistas)
			{
				if(id == z->getId())
				{
					z->setEmprestado(1);
				}
				
			}
			for(auto w:audioLivros)
			{
				if(id == w->getId())
				{
					w->setEmprestado(1);
				}
				
			}
			break;
				system("cls");
		case 4:
			cout<<"digite o id da midia a ser devolver";
			cin>>id;
				for(auto y:livros)
			{
				if(id == y->getId())
				{
					y->setEmprestado(0);
				}
				
			}
			for(auto z:revistas)
			{
				if(id == z->getId())
				{
					z->setEmprestado(0);
				}
				
			}
			for(auto w:audioLivros)
			{
				if(id == w->getId())
				{
					w->setEmprestado(0);
				}
				
			}
			
			break;
		case 5:
			verificador = 0;
			break;
	}
	}while(verificador);
	
	audioLivros.clear();
	livros.clear();
	revistas.clear();
}