#include <stdio.h>

int main() //REVISAO PROGRAMA C
{
    float numero;
    printf("Digite um numero \n");
    scanf("%f", &numero);
    printf("Numero digitado eh: %f \n", numero);
    if(numero < 0){printf("numero negativo");}
    else if (numero == 0){printf("numero nulo");}
    else if (numero > 0){printf("numero maior que zero");}
    else{printf("voceh digitou algo errado");}    
    return 0;
}