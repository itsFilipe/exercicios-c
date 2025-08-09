#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A, B, C, maiorAB, maior;

    scanf("%d" "%d" "%d", &A, &B, &C);

    maiorAB = (A + B + abs(A-B)) / 2;

    if(maiorAB < C)
    {
        maior = C;
        printf("%d eh o maior\n", maior);
    } 
    else
    {
        printf("%d eh o maior\n", maiorAB);
    }
    
    return 0;
}