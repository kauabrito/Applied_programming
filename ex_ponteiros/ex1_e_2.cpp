#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Resistor {
    double resistencia = 100;
    string *ponteiro;
    int quant;
public:
    void setFaixa(int quant){
        this->quant = quant;
        SetFaixa();
    }
    double calculaTensao(double corrente);
    double calculaCorrente(double tensao);
    void setResistencia(double novaResistencia){this->resistencia = novaResistencia;}
    void SetFaixa();
    void calculaResistencia();
    int f1(string );
    int f2(string );
    int f3(string );
    int f4(string );
    float f5(string );
    int f6(string );
};

double Resistor::calculaTensao(double corrente){
    double tensao = corrente * resistencia;
    return tensao;
}

double Resistor::calculaCorrente(double tensao){
    double corrente = tensao / resistencia;
    return corrente;
}

void Resistor::SetFaixa(){
    ponteiro = new string[quant];
    for(int i = 0; i < quant; i++){
        cout << "Digite a cor da faixa " << i + 1 << endl;
        cin >> *(ponteiro+i);
    }
}

int Resistor::f1(string f){
    string f0 = f;
    if (f0 == "preto"){return 0;}
    else if (f0 == "marrom"){return 100;}
    else if (f0 == "vermelho"){return 200;}
    else if (f0 == "laranja"){return 300;}
    else if (f0 == "amarelo"){return 400;}
    else if (f0 == "verde"){return 500;}
    else if (f0 == "azul"){return 600;}
    else if (f0 == "violeta"){return 700;}
    else if (f0 == "cinza"){return 800;}
    else if (f0 == "branco"){return 900;}
    else if (f0 == "dourado"){return 0;}
    else if (f0 == "prata"){return 0;}
    else{return 0;}    
}

int Resistor::f2(string f){
    string f1 = f;
    if (f1 == "preto"){return 0;}
    else if (f1 == "marrom"){return 10;}
    else if (f1 == "vermelho"){return 20;}
    else if (f1 == "laranja"){return 30;}
    else if (f1 == "amarelo"){return 40;}
    else if (f1 == "verde"){return 50;}
    else if (f1 == "azul"){return 60;}
    else if (f1 == "violeta"){return 70;}
    else if (f1 == "cinza"){return 80;}
    else if (f1 == "branco"){return 90;}
    else if (f1 == "dourado"){return 0;}
    else if (f1 == "prata"){return 0;}
    else {return 0;}
}

int Resistor::f3(string f){
    string f2 = f;
    if (f2 == "preto"){return 0;}
    else if (f2 == "marrom"){return 1;}
    else if (f2 == "vermelho"){return 2;}
    else if (f2 == "laranja"){return 3;}
    else if (f2 == "amarelo"){return 4;}
    else if (f2 == "verde"){return 5;}
    else if (f2 == "azul"){return 6;}
    else if (f2 == "violeta"){return 7;}
    else if (f2 == "cinza"){return 8;}
    else if (f2 == "branco"){return 9;}
    else if (f2 == "dourado"){return 0;}
    else if (f2 == "prata"){return 0;}
    else {return 0;}
}

int Resistor::f4(string f){
    string f3 = f;
    if (f3 == "preto"){return 0;}
    else if (f3 == "marrom"){return 1;}
    else if (f3 == "vermelho"){return 2;}
    else if (f3 == "laranja"){return 3;}
    else if (f3 == "amarelo"){return 4;}
    else if (f3 == "verde"){return 5;}
    else if (f3 == "azul"){return 6;}
    else if (f3 == "violeta"){return 7;}
    else if (f3 == "cinza"){return 8;}
    else if (f3 == "branco"){return 9;}
    else if (f3 == "dourado"){return -1;}
    else if (f3 == "prata"){return -2;}
    else {return 0;}
}

float Resistor::f5(string f){
    string f4 = f;
    if (f4 == "preto"){return 0;}
    else if (f4== "marrom"){return 1;}
    else if (f4=="vermelho"){return 2;}
    else if (f4=="laranja"){return 0;}
    else if (f4=="amarelo"){return 0;}
    else if (f4=="verde"){return 0.5;}
    else if (f4=="azul"){return 0.25;}
    else if (f4=="violeta"){return 0.1;}
    else if (f4=="cinza"){return 0.05;}
    else if (f4=="branco"){return 0;}
    else if (f4=="dourado"){return 5;}
    else if (f4=="prata"){return 10;}
    else return 0;
}

int Resistor::f6(string f){
    string f5 = f;
    if (f5 == "preto"){return 0;}
    else if (f5 == "marrom"){return 100;}
    else if (f5 == "vermelho"){return 50;}
    else if (f5 == "laranja"){return 15;}
    else if (f5 == "amarelo"){return 25;}
    else if (f5 == "verde"){return 0;}
    else if (f5 == "azul"){return 10;}
    else if (f5 == "violeta"){return 5;}
    else if (f5 == "cinza"){return 0;}
    else if (f5 == "branco"){return 0;}
    else if (f5 == "dourado"){return 0;}
    else if (f5 == "prata"){return 0;}
    else {return 0;}
}


void Resistor::calculaResistencia(){
    if (quant == 3){
        this->resistencia = (f2(*(ponteiro)) + f3(*(ponteiro+1))) * (pow(10, f4(*(ponteiro + 2))));
        cout << resistencia << "[Ohms] +OU-20%";
    }
    else if (quant == 4){
        this->resistencia = (f2(*(ponteiro)) + f3(*(ponteiro+1))) * (pow(10, f4(*(ponteiro +2))));
        cout << resistencia << "[Ohms] +OU-" << f5(*(ponteiro + 3))<<"%";
    }
    else if (quant == 5){
        this->resistencia = (f1(*(ponteiro)) + f2(*(ponteiro +1)) + f3(*(ponteiro +2))) * (pow(10, f4(*(ponteiro+3))));
        cout << resistencia << "[Ohms] +OU-" << f5(*(ponteiro+4))<< "%";
    }
    else if (quant == 6){
        this->resistencia = (f1(*(ponteiro)) + f2(*(ponteiro+1)) + f3(*(ponteiro+2))) * (pow(10, f4(*(ponteiro+3))));
        cout << resistencia << "[Ohms] +OU-" << f5(*(ponteiro+4)) << "%" << f6(*(ponteiro+5)) << "PPM/C";
    }
    else {
        cout << "Invalido";
    }

    delete[] ponteiro;
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
    string verificacao;
    cout << "\n\n\nQuestao 2" << endl;
   do
    {
        cout << "Quantas faixas você deseja calcular? ";
        cin >> quant;
        objeto.setFaixa(quant);
        objeto.calculaResistencia();
        cout << "\nDeseja calcular outra resistencia?s-[sim] ou n-[nao] ";
        cin >> verificacao;
    }while(verificacao != "n");
    
    cout<< "Programa finalizado";
    return 0;
}