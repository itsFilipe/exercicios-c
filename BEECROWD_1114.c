#include <stdio.h>

int main() {

    int pass;
    int password = 2002;

    while(1) {
        scanf("%d", &pass);

        if(pass == password) {
            printf("Acesso Permitido\n");
            break;
        } else {
            printf("Senha Invalida\n");
        }
    }

    return 0;
}