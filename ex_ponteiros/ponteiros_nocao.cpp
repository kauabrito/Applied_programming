#include <iostream>
#include <vector>
using namespace std;

int main()
{   int op;
    int i =0;
    int numero;
    vector<int>v;
    
    do
    {
        cout << "[1] - Adicionar"<<endl<<"[2] - Excluir"<<endl<<"[3] - imprimir lista"<<endl<<"[0] - sair"<<endl;
        cin >> op;
        switch(op)
        {
            case 1:
                    
                    cout <<"Digite um numero inteiro para cadastrar: ";
                    cin >>numero;
                    v.push_back(numero);
                break;

            case 2:
                    i =0;
                    if(v.empty()){cout << "VECTOR VAZIO"<<endl;}
                    else
                    {
                        cout << "Qual numero voceh quer apagar?"<<endl;
                        cin >> numero;
                        for(auto x : v)
                        {
                            if(x == numero){v.erase(v.begin() + i); break;}
                            else if(i == v.size()-1) {cout << "Valor nao encontrado"<<endl;}
                            i++;
                        }
                    }
                break;

            case 3:
                    if(v.empty()){cout << "VECTOR VAZIO" <<endl;}
                    else
                    {
                        for(auto x:v){

                        cout <<x<<endl;
                    }
                    }
                    
                break;

            default:
                    if(op !=0){cout << "Opcao invalida"<<endl;}
                break;

        }
    }while(op !=0);
    return 0;
}