#include <stdio.h>

int main() {
    int j;
    int i = 1;
    for (j = 65; j >= 0; j -= 5) {
        printf("I=%d J=%d\n", i, j);
        i += 3;
    }

    return 0;
}