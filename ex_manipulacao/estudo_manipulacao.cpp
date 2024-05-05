#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    //ofstream(sai do programa e vai para arquivo), ifstream(sai do arquivo e entra o programa) , fstream

    //ofstream arquivo;

    //arquivo.open("arquivo1.txt", ios::app); //ios::app é usado para quando formos colocar alguma coisa no arquivo, o programa não sobreescrever ao que estava antes.


    /*arquivo << "Arquivo Cauã Chaves Brito\n";
        arquivo << "Arquivo Sabino\n";
            arquivo << "Arquivo Davi Maracaj\n";
                arquivo << "Arquivo Lucas Hart\n";
                    arquivo << "Arquivo Ademar\n";
                        arquivo << "Arquivo Protasio\n";*/


    //-------Ler o conteúdo de um arquivo (ifstream)

    ifstream arquivoE;
    string linha;
    arquivoE.open("arquivo1.txt");
    if(arquivoE.is_open())
    {
        while(getline(arquivoE, linha)) //verifica se tem alguma coisa na linha e imprime
        {   
            cout<< linha << endl;
        }
    }
    else
    {
        cout << "Nao foi possivel abrir o arquivo"<<endl;
    }
    arquivoE.close();
    
    return 0;
}