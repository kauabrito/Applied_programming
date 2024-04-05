#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CadastroP {
private:
    string nome;
    int idade;
    int cep;
    int numero; // número para contato
public:
    CadastroP() {
        nome = " ";
        idade = 0;
        cep = 0;
        numero = 0;
    }
    void setNome(string nome) { this->nome = nome; }
    string getNome() { return nome; }
    void setIdade(int idade) { this->idade = idade; }
    int getIdade() { return idade; }
    void setCep(int cep) { this->cep = cep; }
    int getCep() { return cep; }
    void setNumero(int numero) { this->numero = numero; }
    int getNumero() { return numero; }
};

class ConsultaP : protected CadastroP {
    
    string sintoma;
    int estado; // 0 - ainda não consultado, 1 - moderado , 2 - ruim , 3 - emergência
public:
    ConsultaP() {
        sintoma = "Ainda nao diagnosticado";
        estado = 0;
    }
    string getNome2() { return getNome(); }
    void setNome2(string n) { setNome(n); }
    int getIdade2() { return getIdade(); }
    void setIdade2(int id) { setIdade(id); }
    int getCep2() { return getCep(); }
    void setCep2(int c) { setCep(c); }
    int getNumero2() { return getNumero(); }
    void setNumero2(int n) { setNumero(n); }
    string getEstado() {
        if (estado == 0) { return "ainda nao consultado"; }
        else if (estado == 1) { return "Estado moderado"; }
        else if (estado == 2) { return "Estado ruim"; }
        else if (estado == 3) { return "Estado Emergencia"; }
        else { return "Estado invalido"; }
    }
    void setEstado(int estado) { this->estado = estado; }
    string getSintoma() { return sintoma; }
    void setSintoma(string sintoma) { this->sintoma = sintoma; }
};

class Cirurgia : public ConsultaP {
    float valor;
public:
    Cirurgia() {
        valor = 0;
    }
    void setValor(float valor) { this->valor = valor; }
    float getValor() { return valor; }
    void Exibir()
    {
        cout <<"Nome .........: "<<getNome2()<<endl;
        cout <<"Idade ........: "<<getIdade2()<<endl;
        cout <<"CEP ..........: "<<getCep2()<<endl;
        cout <<"Contato ......: "<<getNumero2()<<endl;
        cout <<"Estado .......: "<<getEstado()<<endl;
        cout <<"Sintoma ......: "<<getSintoma()<<endl;
        cout <<"Valor Cirurgia: "<<getValor()<<endl;
    }
};

int main()
{   int i; //variavel auxiliar
    string nome, sintoma;
    int idade, cep, numero, estado;
    float valor;
    int v;
    vector <Cirurgia*> paciente;
    do {
        cout << "[1] - Cadastrar paciente" << endl << "[2] - Cadastrar consulta" << endl << "[3] - Inserir valor da cirurgia " << endl << "[4] - Lista de pacientes" << endl << "[5] - Ficha do paciente" << endl <<"[6] - Remover paciente"<<endl<<"[0] - Sair do programa" << endl;
        cin >> v;
        switch (v)
        {
        case 1:
            paciente.push_back(new Cirurgia);
            cout << "Digite o nome do paciente: " << endl;
            cin >> nome;
            paciente.back()->setNome2(nome);
            cout << "Digite o idade do paciente: " << endl;
            cin >> idade;
            paciente.back()->setIdade2(idade);
            cout << "Digite o cep do paciente: " << endl;
            cin >> cep;
            paciente.back()->setCep2(cep);
            cout << "Digite o numero de telefone do paciente (somente numeros): " << endl;
            cin >> numero;
            paciente.back()->setNumero2(numero);
            break;
        case 2:
        i = 0;
        if(paciente.empty()) {
            cout << "Banco de dados vazio" << endl;
        } 
        else 
        {
            cout << "Digite o nome do paciente: ";
            cin >> nome;
            for(auto p : paciente) {
                if(p->getNome2() == nome) {
                    cout << "Digite o Estado do paciente: "<<endl<<"[1] - moderado"<<endl<<"[2] - ruim"<<endl<<"[3] - emergencia"<<endl;
                    cin >> estado; 
                    // 0 - ainda não consultado, 1 - moderado , 2 - ruim , 3 - emergência
                    p->setEstado(estado);
                    cout << "Digite o Sintoma do paciente: "<< endl;
                    cin >> sintoma;
                    p->setSintoma(sintoma);
                break;
                }
                else if (i == paciente.size()-1) 
                {
                    cout <<"Paciente nao encontrado"<<endl;
                }
                i++;
            }
        }
        break;

        case 3:
            i=0;
            if(paciente.empty()){cout << "Banco de dados vazio" << endl;}
            else
            {
                cout << "Digite o nome do paciente: ";
                cin >> nome;
                for(auto p : paciente) {
                    if(p->getNome2() == nome) {
                        cout << "Valor da cirurgia: ";
                        cin >> valor; 
                        // 0 - ainda não consultado, 1 - moderado , 2 - ruim , 3 - emergência
                        p->setValor(valor);
                        break;
                    }
                    else if(i == paciente.size()-1) 
                    {
                        cout <<"Paciente nao encontrado"<<endl;
                    }
                    i++;
                }
            }
            break;
        case 4:
            if(paciente.empty()){cout << "Banco de dados vazio" << endl;}
            else
            {
                cout << "No banco de dados do hospital contem "<< paciente.size()<<" pacientes"<<endl;
                for(auto p : paciente){
                    cout << "- "<< p->getNome2() <<endl;
                }
            }
            break;
        case 5:
            i=0;
            if(paciente.empty()){cout << "Banco de dados vazio"<< endl;}
            else
            {
                cout <<"Voceh quer consultar fixa de qual paciente? "<<endl;
                cin >> nome;
                for(auto x : paciente)
                {
                    if(x->getNome2() == nome)
                    {
                        x->Exibir();
                        break;
                    }
                    else if(i == paciente.size()-1)
                    {
                        cout << "Paciente nao encontrado" <<endl;
                    }
                    i++;
                }
                
            }
            break;
        case 6:
            i=0;
            if(paciente.empty()){cout << "BANCO VAZIO" <<endl;}
            else
            {
                cout << "Digite o nome do paciente que voceh quer remover" << endl;
                cin >> nome;
                for(auto p : paciente)
                {
                    if(p->getNome2() == nome)
                    {
                        paciente.erase(paciente.begin() + i);
                        cout<< "Paciente excluido do banco de dados"<<endl;
                        break;
                    }
                    else if (i == paciente.size() - 1){
                        cout << "Paciente nao encontrado"<< endl;
                    }
                    i++;
                }
            }
            break;
        default:
            break;
        }
    } while (v != 0);

    paciente.clear();
    return 0;
}