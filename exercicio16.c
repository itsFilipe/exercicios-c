#include <stdio.h>

int main() {
    int i, j;
    unsigned long long fatorial;  // tipo maior para armazenar grandes resultados

    printf("Numero\tFatorial\n");
    printf("------------------\n");

    for (i = 1; i <= 5; i++) {
        fatorial = 1;

        for (j = 1; j <= i; j++) {
            fatorial *= j;
        }

        printf("%d\t%llu\n", i, fatorial);
    }

    return 0;
}
