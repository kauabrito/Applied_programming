#include <stdio.h>

int int_power(int x, int n) {
    int resultado = 1;
    for (int i = 0; i < n; i++) {
        resultado *= x;
    }
    return resultado;
}

int main() {
    int x, n;
    printf("Digite dois numeros inteiros positivos (x e n): ");
    scanf("%d %d", &x, &n);
    printf("%d elevado a %d e: %d\n", x, n, int_power(x, n));
    return 0;
}