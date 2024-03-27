#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Resistor {
    double resistencia = 100;
    string *f;
    int quant;
public:
    void setFaixa(int quant){
        this->quant = quant;
        SetFaixa(quant);
    }
    double calculaTensao(double corrente);
    double calculaCorrente(double tensao);
    void setResistencia(double novaResistencia){this->resistencia = novaResistencia;}
    void SetFaixa(int quant);
    void calculaResistencia();
    int f1();
    int f2();
    int f3();
    int f4();
    float f5();
    int f6();
};

double Resistor::calculaTensao(double corrente){
    double tensao = corrente * resistencia;
    return tensao;
}

double Resistor::calculaCorrente(double tensao){
    double corrente = tensao / resistencia;
    return corrente;
}

void Resistor::SetFaixa(int quant){
    f = new string[quant];
    for(int i = 0; i < quant; i++){
        cout << "Digite a cor da faixa " << i + 1 << endl;
        cin >> f[i];
    }
}

int Resistor::f1(){
    if (f[0] == "preto"){return 0;}
    else if (f[0] == "marrom"){return 100;}
    else if (f[0] == "vermelho"){return 200;}
    else if (f[0] == "laranja"){return 300;}
    else if (f[0] == "amarelo"){return 400;}
    else if (f[0] == "verde"){return 500;}
    else if (f[0] == "azul"){return 600;}
    else if (f[0] == "violeta"){return 700;}
    else if (f[0] == "cinza"){return 800;}
    else if (f[0] == "branco"){return 900;}
    else if (f[0] == "dourado"){return 0;}
    else if (f[0] == "prata"){return 0;}
    else{return 0;}    
}

int Resistor::f2(){
    if (f[1] == "preto"){return 0;}
    else if (f[1] == "marrom"){return 10;}
    else if (f[1] == "vermelho"){return 20;}
    else if (f[1] == "laranja"){return 30;}
    else if (f[1] == "amarelo"){return 40;}
    else if (f[1] == "verde"){return 50;}
    else if (f[1] == "azul"){return 60;}
    else if (f[1] == "violeta"){return 70;}
    else if (f[1] == "cinza"){return 80;}
    else if (f[1] == "branco"){return 90;}
    else if (f[1] == "dourado"){return 0;}
    else if (f[1] == "prata"){return 0;}
    else {return 0;}
}

int Resistor::f3(){
    if (f[2] == "preto"){return 0;}
    else if (f[2] == "marrom"){return 1;}
    else if (f[2] == "vermelho"){return 2;}
    else if (f[2] == "laranja"){return 3;}
    else if (f[2] == "amarelo"){return 4;}
    else if (f[2] == "verde"){return 5;}
    else if (f[2] == "azul"){return 6;}
    else if (f[2] == "violeta"){return 7;}
    else if (f[2] == "cinza"){return 8;}
    else if (f[2] == "branco"){return 9;}
    else if (f[2] == "dourado"){return 0;}
    else if (f[2] == "prata"){return 0;}
    else {return 0;}
}

int Resistor::f4(){
    if (f[3] == "preto"){return 0;}
    else if (f[3] == "marrom"){return 1;}
    else if (f[3] == "vermelho"){return 2;}
    else if (f[3] == "laranja"){return 3;}
    else if (f[3] == "amarelo"){return 4;}
    else if (f[3] == "verde"){return 5;}
    else if (f[3] == "azul"){return 6;}
    else if (f[3] == "violeta"){return 7;}
    else if (f[3] == "cinza"){return 8;}
    else if (f[3] == "branco"){return 9;}
    else if (f[3] == "dourado"){return -1;}
    else if (f[3] == "prata"){return -2;}
    else {return 0;}
}

float Resistor::f5(){
    if (f[4]== "preto"){return 0;}
    else if (f[4]== "marrom"){return 1;}
    else if (f[4]=="vermelho"){return 2;}
    else if (f[4]=="laranja"){return 0;}
    else if (f[4]=="amarelo"){return 0;}
    else if (f[4]=="verde"){return 0.5;}
    else if (f[4]=="azul"){return 0.25;}
    else if (f[4]=="violeta"){return 0.1;}
    else if (f[4]=="cinza"){return 0.05;}
    else if (f[4]=="branco"){return 0;}
    else if (f[4]=="dourado"){return 5;}
    else if (f[4]=="prata"){return 10;}
    else return 0;
}

int Resistor::f6(){
    if (f[5] == "preto"){return 0;}
    else if (f[5] == "marrom"){return 100;}
    else if (f[5] == "vermelho"){return 50;}
    else if (f[5] == "laranja"){return 15;}
    else if (f[5] == "amarelo"){return 25;}
    else if (f[5] == "verde"){return 0;}
    else if (f[5] == "azul"){return 10;}
    else if (f[5] == "violeta"){return 5;}
    else if (f[5] == "cinza"){return 0;}
    else if (f[5] == "branco"){return 0;}
    else if (f[5] == "dourado"){return 0;}
    else if (f[5] == "prata"){return 0;}
    else {return 0;}
}


void Resistor::calculaResistencia(){
    if (quant == 3){
        this->resistencia = (f2() + f3()) * (pow(10, f4()));
        cout << resistencia << "[Ohms] +OU-20%";
    }
    else if (quant == 4){
        this->resistencia = (f2() + f3()) * (pow(10, f4()));
        cout << resistencia << "[Ohms] +OU-" << f5()<<"%";
    }
    else if (quant == 5){
        this->resistencia = (f1() + f2() + f3()) * (pow(10, f4()));
        cout << resistencia << "[Ohms] +OU-" << f5()<< "%";
    }
    else if (quant == 6){
        this->resistencia = (f1() + f2() + f3()) * (pow(10, f4()));
        cout << resistencia << "[Ohms] +OU-" << f5() << "%" << f6() << "PPM/C";
    }
    else {
        cout << "Invalido";
    }
    delete[] f;
}

int main(){
    Resistor objeto;
    float R;
    cout << "Tensao[V] para 100 Ohms e 2.5 A: " << objeto.calculaTensao(2.5) << endl;
    cout << "Digite uma RESISTENCA [Ohms]: ";
    cin >> R;
    objeto.setResistencia(R);
    cout << "Corrente para " << R << " ohms e 12 V: " << objeto.calculaCorrente(12) << "A";

    int quant;
    cout << "\n\n\nQuestao 2" << endl;
    cout << "Quantas faixas você deseja calcular? ";
    cin >> quant;
    objeto.setFaixa(quant);
    objeto.calculaResistencia();
    return 0;
}