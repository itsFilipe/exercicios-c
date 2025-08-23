#include <stdio.h>
#include <math.h>
 
int main() {
 
    double A, B, C, delta, raiz1, raiz2;
    
    scanf("%lf %lf %lf", &A, &B, &C);
    
    delta = pow(B, 2) - 4 * A * C;

    if(A == 0 || delta < 0)
    {
        printf("Impossivel calcular\n");
        return 0;
    };

    raiz1 = ((-1 * B) + sqrt(delta))/ (2 * A);
    raiz2 = ((-1 * B) - sqrt(delta))/ (2 * A);

    printf("R1 = %.5lf\n", raiz1);
    printf("R2 = %.5lf\n", raiz2);
 
    return 0;
}