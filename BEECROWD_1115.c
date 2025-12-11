#include <stdio.h>

int main () {

    int x,y;

    while (1)
    {   
        scanf("%d %d", &x, &y);
        
        if(x > 0) {
            if(y > 0) {
                printf("primeiro\n");
            } else {
                printf("quarto\n");
            }
        } else if (x < 0) {
            if(y > 0) {
                printf("segundo\n");
            } else {
                printf("terceiro\n");
            }
        } else {
             break;
        }
    }
    
    return 0;
}