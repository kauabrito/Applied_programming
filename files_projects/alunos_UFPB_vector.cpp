#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Aluno
{
    protected:
    string nome;
    int idade;
    float CRA;
    public:
    Aluno(string nome, int idade, float CRA)
    {
        this -> nome = nome;
        this -> idade = idade;
        this -> CRA = CRA;
    }
    void setNome(string nome){this->nome = nome;}
    string getNome(){return nome;}
    void setIdade(int idade){this->idade = idade;}
    int getIdade(){return idade;}
    void setCRA(float CRA){this->CRA = CRA;}
    float getCRA(){return CRA;}
    void Exibir()
    {
        cout <<"Nome :" << getNome()<<endl;
        cout <<"Idade :" << getIdade()<<endl;
        cout <<"CRA :" << getCRA()<<endl;
    }
};

class Professor : protected Aluno{
    private:
        int id;
        string departamento;
    public:
        Professor(string nome, int idade, float CRA, int id, string departamento) : Aluno(nome, idade, CRA){
            setNome(nome);
            setIdade(idade);
            setCRA(CRA);
            this->id=id;
            this->departamento=departamento;
        }
        string getNome2(){
            return getNome();
        }
        void setId(int id){
            this->id=id;
        }
        int getId(){
            return id;
        }
        void setDepartamento(int departamento){
            this->departamento=departamento;
        }
        string getDepartamento(){
            return departamento;
        }

        void exibir2(){
            Exibir();
            cout << "ID: " << getId() << endl;
            cout << "Departamento de " << getNome2() << ": "<< getDepartamento() << endl;
        }
};

int main()
{   
    int i;
    int op, idade,id;
    float CRA;
    string departamento,nome;

    vector<Aluno*>alunos;
    vector<Professor*>professores;
    //alunos.push_back(new Aluno("Caua", 20, 9));
    //alunos.back()->Exibir();
    //professores.push_back(new Professor("Caua", 20, 9, 2022, "CEAR"));
    //professores.back()->exibir2();

    do
    {
        cout <<"[0] - Sair do programa"<< endl<<"[1] - Cadastrar Aluno"<<endl<<"[2] - Cadastrar Professor"<<endl<<"[3] - Remover Aluno"<<endl<<"[4] - Remover Professor"<<endl<<"[5] - Exbir"<<endl<<"[6] - Ficha"<<endl;
        cin >> op;
        switch(op)
        {
            case 1:
                cout << "Digite o nome do aluno: "<<endl;
                cin >> nome;
                cout << "Digite a idade do aluno: "<<endl;
                cin >> idade;
                cout << "Digite o CRA do aluno: "<<endl;
                cin >> CRA;
                alunos.push_back(new Aluno(nome, idade, CRA));
            break;
            case 2:
                cout << "Digite o nome do professor: "<<endl;
                cin >> nome;
                cout << "Digite a idade do professor: "<<endl;
                cin >> idade;
                cout << "Digite o CRA do professor: "<<endl;
                cin >> CRA;
                cout << "Digite o id do professor: "<<endl;
                cin >> id;
                cout << "Digite o departamento do professor: "<<endl;
                cin >> departamento;
                professores.push_back(new Professor(nome, idade, CRA, id, departamento));
            break;
            case 3:
                i=0;
                if(alunos.empty()){cout << "NENHUM ALUNO CADASTRADO";}
                else
                {
                    cout <<"Digite o nome do aluno: "<<endl;
                    cin >> nome;
                    for(auto x:alunos)
                    {
                        if(x->getNome() == nome)
                        {
                            alunos.erase(alunos.begin() + i);
                            cout << "ALUNO DELETADO"<<endl;
                            break;
                        }
                        else if (i == alunos.size()-1)
                        {
                            cout <<"Aluno nao encontrado"<<endl;
                        }
                        i++;
                    }
                }

            break;
            case 4:
                i=0;
                if(professores.empty()) cout << "NENHUM PROFESSOR CADASTRADO" << endl;
                else{
                    cout << "Digite o nome do professor que sera removido: " << endl;
                    cin >> nome;
                    for(auto ptr : professores){
                        if(ptr->getNome2() == nome){
                            professores.erase(professores.begin() + i);
                            cout << "Professor '"<< nome << "' expulso!!!"<< endl;
                            break;
                        }
                        else if(i == professores.size() - 1) cout << "Professor nao encontrado." << endl;
                        i++;
                    }
                }
            break;
            case 5:
                if(professores.empty()){cout<< "BANCO DE PROFESSORES VAZIO"<<endl;}
                else{
                    cout <<"Lista de professores: "<<endl;
                    for(auto x:professores)
                    {
                        cout<< "- "<< x->getNome2()<<endl;
                    }
                }
                if(alunos.empty()){cout<< "BANCO DE Alunos VAZIO"<<endl;}
                else{
                    cout << "Lista de alunos: " << endl;
                    for(auto ptr : alunos){
                        cout << "- " << ptr->getNome() << endl;
                    }
                }
                
            break;
            case 6:
                i=0;
                if(alunos.empty()){cout << "BANCO DE DADOS VAZIO"<<endl;}
                else
                {
                    cout << "Digite o nome do aluno: "<<endl;
                    cin >> nome;
                    for(auto x : alunos)
                    {
                        if(x->getNome()==nome){x->Exibir(); break;}
                        else if (i == alunos.size()-1){cout <<"ALUNO NAO ENCONTRADO"<<endl;}
                        i++;
                    }
                }
                if(professores.empty()) cout << "NENHUM PROFESSOR CADASTRADO" << endl;
                else{
                    i=0;
                    cout << "Digite o nome do professor: " << endl;
                    cin >> nome;
                    for(auto ptr : professores){
                        if(ptr->getNome2() == nome){
                            ptr->exibir2();
                            break;
                        }
                        else if(i == professores.size() - 1) cout << "Professor " << nome << " nao encontrado." << endl;
                        i++;
                    }
                }
            break;
            default:
                if(op !=0){cout << "Opcao invalida"<<endl;}
            break;
        }
    }while(op !=0);
    
    alunos.clear();
    professores.clear();
    return 0;
}