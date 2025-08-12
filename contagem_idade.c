#include <stdio.h>
 
int main() {

    int idade, contagem[3] = {0};
    int vetor[3] = {365, 30, 1};
    
    scanf("%d", &idade);
    
    for(int i = 0 ; i < 3 ; i++)
    {
        contagem[i] = idade / vetor[i];
        idade = idade % vetor[i];
    }
    
    printf("%d ano(s)\n", contagem[0]);
    printf("%d mes(es)\n", contagem[1]);
    printf("%d dia(s)\n", contagem[2]);
 
    return 0;
}