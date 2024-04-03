#include <iostream>
#include <string>
using namespace std;

class Funcionario {
    string nome;
    int id;
    float salario;

    public:
    Funcionario(){nome = " "; id = 0; salario = 0;}
    string getNome(){return nome;}
    void setNome(string nome){this->nome = nome;}
    int getId(){return id;}
    void setId(int id){this->id = id;}
    float getSalario(){return salario;}
    void setSalario(float salario){this->salario = salario;}
    void Exibir()
    {
        cout << "Nome: "<< getNome() << endl;
        cout << "Salario: "<< getSalario() <<endl;
        cout << "Numero de identificacao: "<< getId() <<endl;
    }
    void aumentarSalario(float p)
    {
        float novoSalario = getSalario()*(1+(p/100));
        setSalario(novoSalario);
    }
};

class Gerente : public Funcionario {
    protected:
    string departamento;

    public:
    Gerente()
    {
        departamento = " ";
    }
    string getDepartamento(){return departamento;}
    void setDepartamento(string departamento){this->departamento = departamento;}
    void ExibirG()
    {
        Exibir();
        cout << "Departamento que ele supervisiona: "<< getDepartamento() <<endl;
    }
};


int main()
{   
    int i=0; //quant de funcionario
    int j=0; //quant de gerente
    int q=0; 
    int aux = 0;
    int aux2 = 0;
    string nome;
    int id;
    float salario;
    string departamento;
    Gerente *g;
    Funcionario *f;
    int op;
    string op2;
    cout <<"Você deseja cadastrar quantos gerentes? ";
    cin >> j;
    cout <<"Você deseja cadastrar quantos funcionarios? ";
    cin >> i;

    g = new Gerente[j];
    f = new Funcionario[i];
    do{
        cout<<"------ Planilha de funcionarios e gerentes ------" <<endl<<"[0]- Sair do programa"<<endl<<"[1] - Cadastro"<<endl<<"[2]-Aumento de salário"<<endl<<"[3]-Remover individuo"<<endl<<"[4]-Listar DADOS"<<endl;
        cin >> op;
        switch(op)
        {   
            case 0:
            break;
            case 1:
            {
            cout << "Quer cadastrar funcionario ou gerente? ";
            cin >> op2;
            if (op2 == "funcionario")
            {   if (aux == i){cout << "Nao eh possivel mais cadastrar"<<endl; break;}
                cout<< "Digite o nome do funcionario "<< aux+1 << " : " <<endl;
                cin >> nome;
                (f+aux)->setNome(nome);
                cout<< "Digite o Id: ";
                cin >> id;
                (f+aux)->setId(id);
                cout<< "Digite o Salario: ";
                cin >> salario;
                (f+aux)->setSalario(salario);
                aux++;
            }
            else if (op2 == "gerente")
            {   if (aux2 == j){cout << "Nao eh possivel mais cadastrar"<<endl; break;}
                cout<< "Digite o nome do gerente "<< aux2+1 << " : " <<endl;
                cin >> nome;
                (g+aux2)->setNome(nome);
                cout<< "Digite o Id: ";
                cin >> id;
                (g+aux2)->setId(id);
                cout<< "Digite o Salario: ";
                cin >> salario;
                (g+aux2)->setSalario(salario);
                cout << "Digite o nome que departamento que o gerente supervisiona: ";
                cin >> departamento;
                (g+aux2)->setDepartamento(departamento);
                aux2++;
            }
            else{cout<<"Classificacao do individuo invalida"<<endl;}
            break;
            }
            case 2:
            {
                float porcentagem=0; 
                cout << "Quer aumentar salario de quem? "<<endl;
                cout << "fucionario ou gerente? "<< endl;
                cin >> op2;
                if(op2 == "funcionario")
                {
                    for(int w=0; w<i; w++)
                    {   if((f+w)->getNome() != " "){
                        cout << w + 1 <<" - "<<(f+w)->getNome()<<endl;
                    }
                        else{continue;}
                    }
                    cout << "Digite o numero: ";
                    cin >> q;
                    q--;
                    cout << "Quantos porcento(%)? ";
                    cin >> porcentagem;
                    (f+q)->aumentarSalario(porcentagem);
                }
                else if (op2 == "gerente")
                {
                    cout << "Gerentes: "<< endl;
                    for(int w=0;w<j;j++)
                    {   if((g+w)->getNome() != " "){
                        cout << w + 1 <<" - "<<(g+w)->getNome()<<endl;
                    }
                        else{continue;}
                    }
                    cout << "Digite o numero: ";
                    cin >> q;
                    q--;
                    cout << "Quantos porcento(%)? ";
                    cin >> porcentagem;
                    (g+q)->aumentarSalario(porcentagem);
                }
                else {continue;}
            break;
        }
            case 3:
            {
                cout << "Quer demitir quem? funcionario ou gerente ? ";
                cin >> op2;
                if(op2 == "funcionario"){
                    for(int w=0; w<i; w++)
                    {   if((f+w)->getNome() != " "){
                        cout << w + 1 <<" - "<<(f+w)->getNome()<<endl;
                    }
                        else{continue;}
                    }
                    cout << "Digite o numero do funcionario: ";
                    cin >> q;
                    q--;
                    (f+q)->setNome("Demitido");
                    (f+q)->setId(0);
                    (f+q)->setSalario(0);
                }
                else if(op2 == "gerente"){
                    for(int w=0; w<j; w++)
                    {   if((g+w)->getNome() != " "){
                        cout << w + 1 <<" - "<<(g+w)->getNome()<<endl;
                    }
                        else{continue;}
                    }
                    cout << "Digite o numero do gerente: ";
                    cin >> q;
                    q--;
                    (g+q)->setNome("Demitido");
                    (g+q)->setId(0);
                    (g+q)->setSalario(0);
                    (g+q)->setDepartamento("X");
                } 
                else {continue;}
            break;
            }
            case 4:
            {
            cout << "Voceh quer qual relacao? funcionario ou gerente : ";
            cin >> op2;
            if (op2 == "funcionario")
            {
                for(int w=0; w<i; w++)
                    {   if((f+w)->getNome() != " "){
                        cout << w + 1 <<" - "<<(f+w)->getNome()<<endl;
                    }
                        else{continue;}
                    }
                cout << "Digite o numero do funcionario: ";
                cin >> q;
                q--;
                (f+q)->Exibir();
            }
            else if (op2 == "gerente")
            {
                for(int w=0; w<j; w++)
                    {   if((g+w)->getNome() != " "){
                        cout << w + 1 <<" - "<<(g+w)->getNome()<<endl;
                    }
                        else{continue;}
                    }
                cout << "Digite o numero do gerente: ";
                cin >> q;
                q--;
                (g+q)->ExibirG();
            }
            else {continue;}   
            break;
            }
            default:
            {
                cout << "Opcao inválida"<<endl;
            }
            
        }
    }while(op!=0);
            
    delete[] g;
    delete[] f;
    return 0;
}
