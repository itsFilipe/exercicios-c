#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(){

    char nome[20];
    int notaLab=0, notaProvaParcial=0, notaExameFinal=0;
    float media=0;

    printf("Digite seu nome: \n");
    gets(nome);

    printf("Digite sua nota do lab: \n");
    scanf("%i", &notaLab);

    printf("Digite sua nota da prova parcial: \n");
    scanf("%i", &notaProvaParcial);

    printf("Digite sua nota do exame final: \n");
    scanf("%i", &notaExameFinal);

    media = (notaLab * 0.2) + (notaProvaParcial * 0.3) + (notaExameFinal * 0.5);

    printf("Seu nome e %s\n", nome);
    printf("sua nota do lab: %i\n", notaLab);
    printf("sua da prova parcial: %i\n", notaProvaParcial);
    printf("sua nota do exame final: %i\n", notaExameFinal);
    printf("E a sua media: %.2f\n", media);

    getch();
    return 0;

}
