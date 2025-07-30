#include <stdio.h>

#define MAX 10

int main()
{
    int i, j;
    int n[MAX] = {10,9,8,7,6,5,4,3,2,1};

    printf("%s%13s%17s\n", "Elemento", "Valor", "Histograma");

    for(i = 0; i < MAX; i++)
    {
        printf("%7d%13d        ", i, n[i]);

        for(j = 0; j < n[i]; j++)
        {
            printf("%c", '*');
        }
        
        printf("\n");
    }
    
    return 0;
}