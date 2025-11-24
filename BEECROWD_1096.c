#include <stdio.h>

int main() {

    for ( int i = 1; i <= 9 ; i+=2) {
            for ( int j = 7; j >= 5; j -= 1) {
            printf("I=%d ", i);
            printf("J=%d\n", j);
            }
    }

    return 0;
}