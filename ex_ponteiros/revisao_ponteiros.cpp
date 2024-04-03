#include <iostream>

using namespace std;
//int *funcao(void);
//int exemplo(int ,int );
int main()
{   /*
    int *p; // o tipo do ponteiro deve ser o mesmo tipo da variável que ele "apontará"
    int numero;
    p = &numero; // p é um ponteiro que recebe o endereço do número.
    cout << "Digite o numero: ";
    cin >> numero;

    cout << p << endl; // mostrará o endereço do número.
    cout << *p << endl; //mostrará o conteúdo do local que o ponteiro recebeu.
    */

    /*
    //CONEXÃO ENTRE PONTEIRO E ARRAY
    int *ponteiro;
    int array[5] = {25, 34, 52, 74, 60};
    for (int i = 0; i<5; i++)
    {
        cout << *(array + i) << endl; // isso é igual a ----- cout << array[i] << endl;
    }
    
    cout << endl;

    ponteiro = array; //array é um ponteiro;
    for(int i = 0; i<5; i++)
    {
        cout << *(ponteiro + i) << endl;
        // ou poderia fazer

        //cout << *ponteiro << endl;
        //ponteiro++;

    }
    */

    /*
    //FUNÇÕES QUE RETORNAM UM PONTEIRO

    // int *funcao(void);
    int *ponteiro;

    ponteiro = funcao();
    
    for(int i = 0; i<5 ;i++)
    {
        cout << *(ponteiro + i) << endl;
    }
    */

    /*
    //Ponteiro para função
    int (*ponteiro)(int, int);
    ponteiro = &exemplo;
    cout << "Resultado do produto" << (*ponteiro)(3, 4);
    */
    
    /*
    //ALOCAÇÃO DINÂMICA
    //O operador new devolve um ponteiro para o dado alocado

    int *array = new int[5]; // aloca memória para um array de 10 inteiros no heap
    //se for --> int *array = new int; ou seje só um espaço...
    if (array == NULL) //verifica se foi possível fazer a alocação desejada
    {   
        return -1;
    }

    for(int i=0; i<5 ; i++)
    {
        cout <<"Digite o número "<< i+1 <<" :";
        cin >> *(array + i);
    }
    for(int i=0; i<5 ; i++)
    {
        cout <<"Número "<< i+1 <<" : "<< *(array + i) << endl;
    }

    delete[] array; // libera a memória alocada para o array de inteiros
    //... delete array;
    */
    

    
    return 0;

}

/*
int exemplo(int x , int y)
{
    return x*y;
}
*/

/*
int *funcao (){
    //sabendo que um array é um ponteiro;
    static int array[5]; //o static é usado para a array não ser apagada, ou seja, a array não ser uma variável local.
    for(int i = 0; i<5; i++)
    {
        cout << "Digite o número " << i+1 << " da array: ";
        cin >> *(array + i); // ou cin >> array[i];
    }
    return array;
}
*/