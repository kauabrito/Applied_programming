#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Gerenciamento
{
    string tarefa;
    float status;
    string nome_membro;

    public:
    Gerenciamento(string tarefa, float status, string nome_membro)
    {this->tarefa=tarefa; this->status = status; this->nome_membro = nome_membro;}
    string getTarefa(){return tarefa;}
    string getNomeMembro(){return nome_membro;}
    float getStatus(){return status;}
};

vector<Gerenciamento*>g;
int main()
{
    fstream arquivo;
    int op, i;
    string nome, tarefa;
    float status, aux1, aux2;
    //vector<Gerenciamento*>g;
    void carregar_dado();
    carregar_dado();
    arquivo.open("gerenciamento.txt", ios::out | ios::app);
    if(!arquivo.is_open()){cout << "nao foi possivel criar BANCO DE DADOS NAO CRIADO" << endl; return 1;}
    arquivo.close();
    do
    {   
        cout << "[0] - Sair do programa" << endl << "[1] - Cadastrar tarefas e status" << endl << "[2] - A média de conclusão das tarefas para toda a equipe" << endl << "[3] - A média de conclusão das tarefas de cada membro" << endl << "[4] - Listar todas as tarefas pendentes" << endl << "[5] - membro da equipe com o menor percentual de conclusão de tarefas" << endl << "[6] - membro da equipe com o maior percentual de conclusão de tarefas" << endl << "[7] - Procurar membro" << endl;
        cin >> op;
        switch(op)
        {
            case 1:
            {
                cout << "------------------------" << endl;
                cout << "--------Cadastro--------" << endl;
                cout << "------------------------" << endl;
                cout << "Digite o nome do membro: ";
                cin.ignore();
                getline(cin, nome);
                cout << "Digite o tarefa do membro: ";
                getline(cin, tarefa);
                cout << "Digite o status da tarefa (%): ";
                cin >> status;
                g.push_back(new Gerenciamento(tarefa, status ,nome));
                arquivo.open("gerenciamento.txt", ios::out | ios::app);
                arquivo << nome << endl << tarefa << endl << status << endl;
                arquivo.close();
            break;
            }
            case 2:
            { aux1 = 0;
                if(g.empty()){cout << "Nenhuma atividade cadastrada!" << endl;}
                else{
                    for(auto x : g)
                    {
                        aux1 += x->getStatus();
                    }
                    cout << aux1/g.size() << "% das atividades foram concluidas" << endl;
                }
            break;
            }
            case 3:
            {   
                if(g.empty()){cout << "Nenhuma atividade cadastrada!" << endl;}
                else
                {
                    for(auto x:g)
                    {
                        cout << x->getNomeMembro() << "realizou "<< x->getStatus()<< "% da atidade" << endl;
                    }
                }
            break;
            }
            case 4:
            {
                if(g.empty()){cout << "Nenhuma atividade cadastrada!" << endl;}
                else
                {
                    cout << "Atividades pendentes: " << endl;
                    for(auto x :g)
                    {
                        if(x->getStatus() < 100)
                        {
                            cout << x->getTarefa()  << " " << x->getStatus() << endl;
                        }
                    }
                }
            break;
            }
            case 5:
            {   i = 0;
                if(g.empty()){cout << "Nenhuma atividade cadastrada!" << endl;}
                else
                {
                    if(g.size() == 1){cout << "Nao eh possivel estabelecer comparacao pois so tem uma atividade" << endl;}
                    else
                    {   
                        for(auto x : g)
                        {   
                            if(i == 0){
                            aux1 = x->getStatus();
                            aux2 = x->getStatus();}
                            aux1 = x->getStatus();
                            if(aux1 <= aux2){aux2 = x->getStatus(); nome = x->getNomeMembro();}
                            if(i == g.size()-1){cout << "o membro da equipe com o menor percentual de conclusao de tarefas: " << nome << endl;}
                            i++;
                        }
                    }
                }
            break;
            }
            case 6:
            { i = 0;
                if(g.empty()){cout << "Nenhuma atividade cadastrada!" << endl;}
                else
                {
                    if(g.size() == 1){cout << "Nao eh possivel estabelecer comparacao pois so tem uma atividade" << endl;}
                    else
                    {   
                        for(auto x : g)
                        {   
                            if(i == 0)
                            {
                                aux1 = x->getStatus();
                                aux2 = x->getStatus();
                            }
                            aux1 = x->getStatus();
                            if(aux1 >= aux2){aux2 = x->getStatus(); nome = x->getNomeMembro();}
                            if(i == g.size()-1){cout << "o membro da equipe com o maior percentual de conclusão de tarefas: " << nome << endl;}
                            i++;
                        }
                    }
                }
            break;
            }
            case 7:
            {   i = 0;
                if(g.empty()){cout << "Nenhuma atividade cadastrada!" << endl;}
                else
                {       
                        cout << "Digite o nome do membro que deseja procurar: "<<endl;
                        cin.ignore();
                        getline(cin, nome);
                        for(auto x:g)
                        {
                            if(x->getNomeMembro() == nome){cout << "Membro no banco de dados" << endl;}
                            else if(i == g.size()-1){cout << "Membro nao encontrado!"<< endl;}
                            i++;
                        }
                }
            break;
            }
            default:
            break;    
            

        }
    }while( op != 0);


    g.clear();
    return 0;
}


void carregar_dado()
{
    fstream arquivo;
    string nome, tarefa, status1;
    float status;
    arquivo.open("gerenciamento.txt", ios::in);
    if(arquivo.is_open())
    {
        while(!arquivo.eof())
        {   
            getline(arquivo, nome);
            if(arquivo.eof() && nome == ""){break;}
            getline(arquivo, tarefa);
            getline(arquivo, status1);
            status = stof(status1);
            g.push_back(new Gerenciamento(tarefa, status ,nome));
        }
        arquivo.close();
    }
}