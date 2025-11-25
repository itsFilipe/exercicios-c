#include <stdio.h>

int main() {

    int n, x, y;
    int soma = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        
        if(x < y) {
            for(int j = x + 1; j < y; j++) {
                if( j % 2 != 0) {
                    soma += j;
                }
            }
            printf("%d\n", soma);
            
            soma = 0;

        } else if(x > y) {
            for(int j = x - 1; j > y; j--) {
                if( j % 2 != 0) {
                    soma += j;
                }
            }
            printf("%d\n", soma);

            soma = 0;

        } else {
            printf("%d\n", soma);
        }
    }

    return 0;
}