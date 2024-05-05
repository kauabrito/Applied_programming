#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Cadastro {
    string nome;
    string cargo;
    string email;

public:
    Cadastro(string nome, string cargo, string email)
    {
        this->nome = nome;
        this->cargo = cargo;
        this->email = email;
    }

    string getNome() { return nome; }
    string getCargo() { return cargo; }
    string getEmail() { return email; }
    //bool verifica_arquivo(string nome_arquivo);
};
vector<Cadastro*>membro; // COLOQUEI GLOBAL PRA TER ACESSO EM CARREGAR_DADOS
int main() {
    int verifica_arquivo(string , string, string, string);
    fstream arquivo;
    string nome_arquivo, nome, cargo, email;
    int op;
    int v;
    void carregar_dados();
    carregar_dados();
    do
    {
        cout <<"[0] - Fechar programa"<< endl << "[1] - Criar arquivo" << endl << "[2] - Cadastrar" << endl << "[3] - listar membros" << endl;
        cin >> op;
        switch(op)
        {
            case 1:
            {   
                arquivo.open("file_file.txt", ios::out| ios::app);
                cout << "Digite o nome do arquivo .txt que voce quer salvar as informacoes dos membros"<< endl;
                cin >> nome_arquivo;
                arquivo << nome_arquivo << endl;
                arquivo.close();
                arquivo.open(nome_arquivo, ios::out|ios::app);
                arquivo.close();
            break;
        }
            case 2:
            {
                cout << "Digite o nome do membro: ";
                cin.ignore();
                getline(cin, nome);
                cout << "Digite o cargo do membro: ";
                getline(cin, cargo);
                cout << "Digite o email do membro: ";
                cin >> email;
                do
                {
                    cout << "Digite o nome do arquivo: ";
                    cin >> nome_arquivo;
                    v = verifica_arquivo(nome_arquivo, nome, cargo, email);
                    if(v == 1){membro.push_back(new Cadastro(nome, cargo, email));}
                    else if(v == 2){break;}
                }while(v == 3);
                
            break;
            }
            case 3:
            {   if(membro.empty()){cout << "Banco de membros vazio!" << endl;}
                else
                {
                    cout << "Lista de todos os membros"<< endl;
                    for(auto x : membro)
                    {
                        cout << "- " << x->getNome()<< endl;
                    }
                }
            break;
            }
            default:
            {
                if (op!=0){cout << "Opcao invalida!!!"<<endl<< endl;}
            break;
            }
        }
    }while(op !=0);

    return 0;
}


int verifica_arquivo (string nome_arquivo, string nome, string cargo, string email)
{
    fstream arquivo;
    string dados;
    arquivo.open(nome_arquivo, ios::in);
    if(arquivo.is_open())
    {   arquivo.close();
        arquivo.open(nome_arquivo, ios::out | ios :: app);
        cout<< nome_arquivo << endl << nome << endl << cargo <<endl<< email << endl << endl;
        arquivo << nome << endl << cargo << endl << email << endl;
        //membro.push_back(new Cadastro(nome, cargo, email));
        arquivo.close();
        cout << "Cadastro realizado!"<< endl;
        return 1;
    }
    else
    {
        arquivo.open("file_file.txt", ios::in);
        if(!arquivo.is_open()){cout << "Cadastro nao realizado, Crie pelo menos 1 arquivo" <<endl; return 2;} //verifica se o arquivo base("file_file.txt") foi criado ou n
        
        getline(arquivo, dados);
        arquivo.close();
        if(dados == "")
        {
            cout << "Nao foi criado nenhum arquivo para armazenamento dos dados" << endl;
            return 2;
        }
        else
        {
            arquivo.open("file_file.txt", ios::in);
            cout << "Arquivos existentes: "<< endl;
            while(!arquivo.eof())
            {   
                getline(arquivo, dados);
                if(arquivo.eof() && dados == ""){break;}
                cout << "- " << dados << endl;
            }
            arquivo.close();
            return 3;
        }
        
        
    }
}

void carregar_dados()
{
    fstream arquivo, arquivo2;
    string dado, nome_arquivo, nome, cargo, email;
    arquivo.open("file_file.txt", ios::in);
    if(arquivo.is_open())
    {   
        getline(arquivo, dado);
        if(dado == ""){ arquivo.close(); return;} // verifica se ainda o arquivo file_file tem algum arquivo de cadastro de membro
        else{
            arquivo.close();
            arquivo.open("file_file.txt", ios::in);//arquivo que contem os nome arquivos criados para o armazenamento dos membros
            while(!arquivo.eof())
        {   
            getline(arquivo, nome_arquivo);
            if (arquivo.eof() && nome_arquivo == ""){break;}
            arquivo2.open(nome_arquivo, ios::in);// dado eh o nome do arquivo encontrado em file_file
            cout << "Carregando dados do arquivo: " << nome_arquivo<< endl;
            while(true){ // percorre os membros
                
                getline(arquivo2, nome);
                if (arquivo2.eof()&& nome == ""){arquivo2.close(); break;} //coloquei isso pq estava dando um loop com VAZIO
                getline(arquivo2, cargo);
                getline(arquivo2, email);
                membro.push_back(new Cadastro(nome, cargo, email)); //colocar no vector
            }
        }
        }
    }
    else{cout << "Arquivo base_Nao criado"<<endl;}
}