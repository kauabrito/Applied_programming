#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

int main(int argc, char *argv[])
{
    /*
    ofstream saida ("teste.txt");

    if(!saida){cout <<"O arquivo não pode ser aberto"; return 1;}
    saida << "Mateus" << endl;
    saida << 5 << endl;
    saida << 9.8 << endl;
    saida << "Salabino" << endl;
    saida << 12 << endl;
    saida << 10 << endl;
    saida.close();
    
    string nome;
    int idade;
    float cra;

    ifstream entrada ("teste.txt");
    if(!entrada){cout << "Erro!"; return 1;}
    
    entrada >> nome >> idade >> cra;
    cout << "Nome: " << nome << endl<< "Idade: "<< idade << endl<< "Cra: " << cra << endl;

    entrada >> nome >> idade >> cra;
    cout << "Nome: "<< nome << endl<< "Idade: "<< idade << endl << "Cra: " << cra << endl;
    


    //ou podemos fazer um for
    
    for (int i = 0; i<4; i++)
    {
        entrada >> nome >> idade >> cra;
        cout << "Nome: " << nome << endl<< "Idade: "<< idade << endl<< "Cra: " << cra << endl;
    }
    */

    if(argc!=4){
        cout << "Error!";
        return 1;
    }
    char nome[80];
    strcpy(nome, argv[1]);
    int p = atoi(argv[2]);
    float cra = atof(argv[3]);

    ofstream saida ("teste.txt", ios::app);
    if(!saida){cout << "Erro ao abrir o arquivo!"; return 1;}
    
    saida << nome << endl;
    saida << p <<endl<< " " << cra << endl;
    saida.close();5
    return 0;
    
}
