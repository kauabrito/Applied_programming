#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{   
    int i;
    int numero1, op;
    string v;
    vector<int>numero;

    do{
        cout << "[1] - Inserir"<<endl<<"[2] - Buscar"<<endl<<"[3] - Remover"<<endl<<"[4] - Quantidade"<<endl<<"[5] - listar"<<endl<<"[-1] - Sair"<<endl;
        cin >>op;

        switch(op)
        {   
            case 1:
                do{
                    cout << "Digite um numero: ";
                    cin >> numero1;
                    numero.push_back(numero1);
                    cout << "Adicionar? [n] - Nao ou [s]-Sim "<<endl;
                    cin >> v;
                }while(v != "n");
            break;

            case 2:
                do{
                i=0;
                if(numero.empty()){cout<< "BANCO VAZIO"<<endl; break;}
                else
                {
                    cout << "Qual numero voceh quer verificar se esta no vector? ";
                    cin >> numero1;
                        for(auto x:numero)
                    {
                        if(x == numero1){
                        cout << "Valor encontrado"<<endl;
                        break;
                    }
                        if(i == numero.size()-1){cout <<"valor nao encontrado"<<endl;}
                        i++;
                    }
                    cout << "Buscar?[n] - Nao ou [s]-Sim"<<endl;
                    cin >> v;
                }
        }while(v != "n");
            break;
        case 3:
        do{
            i = 0;
            if(numero.empty()){cout<< "BANCO VAZIO"<<endl; break;}
            else
            {
                cout <<"Qual o numero que deseja apagar? ";
                cin >> numero1;
                for(auto y:numero)
                {   //numero.erase(numero.begin() + i)
                    if(y == numero1){numero.erase(numero.begin() + i); break;}
                    if(i == numero.size()-1){cout << "O numero nao esta no banco de dados, por isso nao eh possivel deletar" << endl;}
                    i++;
                }
            }
            cout << "Remover?[n] - Nao ou [s]-Sim"<<endl;
            cin >> v;
        }while(v != "n");
            break;
        
        case 4:
            if(numero.empty()){cout << "BANCO VAZIO" << endl;}
            else
            {
                cout << "Quantidade de numeros cadastrados eh: "<< numero.size() <<endl;
            }
        break;
        case 5:
            if(numero.empty()){cout << "BANCO VAZIO" << endl;}
            else
            {
                for(auto w :numero){
                    cout << w << endl;
                }
            }
        break;
            default:
            if(op == -1){cout << "Saindo do programa..."; numero.clear(); break;}
            cout << "Opcao invalida";
            break;
    }

    }while(op != -1);
    
    return 0;
}