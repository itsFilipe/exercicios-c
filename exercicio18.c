/* Calculando juros compostos */  
#include <stdio.h> 
#include <math.h> 

int main()  
{ 
  double quantia, capital;
  double taxa = 0.1599;
  int ano;  

  printf("Digite o seu capital: ");
  scanf("%lf", &capital); 

  printf("Ano\t 15,99%%");

  printf("\n");

  for (ano = 1 ; ano <= 10; ano++)
  {
    printf("%2d", ano);

    quantia = capital * pow(1.0 + taxa, ano); //1000 × (1.1599)^3 para 3 anos a 10% ao ano.
    printf("%13.2f", quantia);
    
    printf("\n");
  }

  return 0;
}   

