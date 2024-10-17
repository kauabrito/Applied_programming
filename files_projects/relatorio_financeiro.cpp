#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class Relatorio {
private:
    string Name_bank;
    double Credito_consumido = 0;
    vector<pair<string, double>> entradas_mensais;

public:
    Relatorio(string Name_bank) {
        this->Name_bank = Name_bank;
    }

    string getName_bank() { return Name_bank; }
    double getCredito_consumido() { return Credito_consumido; }
    void addEntradaMensal(string nome_mes, double valor) {
        entradas_mensais.push_back(make_pair(nome_mes, valor));
        Credito_consumido += valor;
    }

    void descricao_mensais();
    void escreverRelatorioMensal(fstream& arquivo);
};

void Relatorio::descricao_mensais() {
    int op;
    string nome_mes;
    double valor;
    do {
        cout << "Digite o nome do Mes (ou 'sair' para terminar): ";
        cin >> nome_mes;
        if (nome_mes == "sair") {
            break;
        }
        cout << "Digite o valor da Fatura: ";
        cin >> valor;
        addEntradaMensal(nome_mes, valor);
    } while (true);
}

void Relatorio::escreverRelatorioMensal(fstream& arquivo) {
    arquivo << "Banco: " << Name_bank << endl;
    for (const auto& entrada : entradas_mensais) {
        arquivo << "Mes: " << entrada.first << " Valor da Fatura: " << entrada.second << endl;
    }
    arquivo << "Valor total consumido: " << Credito_consumido << endl;
}

class Bolso : public Relatorio {
protected:
    double entrada_mensal;
    double entrada_periodo;

public:
    Bolso(string Name_bank, double entrada_mensal, double entrada_periodo)
        : Relatorio(Name_bank) {
        this->entrada_mensal = entrada_mensal;
        this->entrada_periodo = entrada_periodo;
    }

    double getEntrada_Mensal() { return entrada_mensal; }
    double getEntrada_periodo() { return entrada_periodo; }
};

class Planilha : public Bolso {
private:
    double saldo_mensal;

public:
    Planilha(string Name_bank, double entrada_mensal, double entrada_periodo, double saldo_mensal)
        : Bolso(Name_bank, entrada_mensal, entrada_periodo) {
        this->saldo_mensal = saldo_mensal;
    }

    double getSaldo_mensal() { return saldo_mensal; }

    void calcularSaldoMensal() {
        saldo_mensal = entrada_mensal - getCredito_consumido();
    }

    void gerarRelatorio(fstream& arquivo) {
        calcularSaldoMensal();
        escreverRelatorioMensal(arquivo);
        arquivo << "Saldo Mensal: " << saldo_mensal << endl;
        arquivo << "---------------------------" << endl;
    }
};

int main() {
    vector<Planilha*> planilhas;
    double total_faturas = 0;
    double total_entrada_periodo = 0;
    string nomeBanco;
    double entrada_mensal;
    double entrada_periodo;
    int op, quant;
    do
    {
        cout << "Escreva o nome do BANCO: ";
        cin.ignore();
        getline(cin, nomeBanco);
        cout <<"Digite a entrada MENSAL: ";
        cin >> entrada_mensal;
        cout << "Digite a quantidade de meses para que determinemos o valor da Entra_Periodo: ";
        cin>> quant;
        entrada_periodo = quant*entrada_mensal;
        planilhas.push_back(new Planilha(nomeBanco, entrada_mensal, entrada_periodo, 0.0));
        cout << "Cadastrar mais 1 banco? [1] - sim ou [0] - nao";
        cin >> op;
    }while(op ==1);

    for (auto planilha : planilhas) {
        cout << "---BANCO---"<<endl;
        cout << planilha->getName_bank();
        cout << "-----------"<<endl;
        planilha->descricao_mensais();
    }

    fstream arquivo;
    arquivo.open("relatorio_final.txt", ios::out);
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }

    for (auto planilha : planilhas) {
        planilha->gerarRelatorio(arquivo);
        total_faturas += planilha->getCredito_consumido();
        total_entrada_periodo += planilha->getEntrada_periodo();
    }

    double saldo_final = total_entrada_periodo - total_faturas;
    arquivo << "Fatura Total de Todos os Bancos: " << total_faturas << endl;
    arquivo << "Entrada Total do Periodo: " << total_entrada_periodo << endl;
    arquivo << "Saldo Final após o Periodo: " << saldo_final << endl;

    arquivo.close();

    cout << "Relatorio gerado com sucesso!" << endl;

    return 0;
}
