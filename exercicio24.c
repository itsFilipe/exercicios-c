#include <stdio.h>

int main()
{
    printf("A\tA+2\tA+4\tA+6\n");

    for (int i = 3; i <= 15; i += 3)
    {
        printf("%i\t%i\t%i\t%i", i, i + 2, i + 4, i + 6);
        printf("\n");
    }
    
    return 0;
}