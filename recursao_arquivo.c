#include <stdio.h>
int recursao(int n);

int main() {

    FILE *resultado = fopen("resultadoRecursao.txt", "w");

    int fatorial;

    fatorial = recursao(5);

    if(resultado) {
        fprintf(resultado, "Resultado: %d\n", fatorial);

        fclose(resultado);
        printf("O resultado foi salvo em arquivo\n");
    } else {
        printf("ERRO: nao foi possivel abrir o arquivo.\n");
    }

    return 0;
}

int recursao(int n) {
    if(n == 0) {
        return 1;
    }

    return n * recursao(n - 1);
}

