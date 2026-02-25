#include <stdio.h>

int main() {

    int x, y, hold;

    while(1) {

        scanf("%d %d", &x, &y);
        
        if (x <= 0 || y <= 0) {
            break;
        }

        if(x > y) {
            hold = x;
            x = y;
            y = hold;
        }

        int soma = 0; // Reinicia a soma para cada novo par de entradas

        for (int i = x; i <= y; i++) {
            printf("%d ", i);
            soma += i;
        }
        printf("Sum=%d\n", soma);
    }

    return 0;
}