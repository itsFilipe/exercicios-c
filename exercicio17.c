/* Calculando juros compostos */  
#include <stdio.h> 
#include <math.h> 

int main()  
{ 
  double quantia, principal = 1000.0;
  double taxa;
  int ano;

  printf("Ano");

  for(taxa = 0.10; taxa <= 0.50; taxa += 0.10)
  {
    printf("%15.0f%%", taxa * 100);
  }

  printf("\n");

  for (ano = 1 ; ano <= 10; ano++)
  {
    printf("%2d", ano);

    for (taxa = 0.10; taxa <= 0.50; taxa += 0.10)
    {
        quantia = principal * pow(1.0 + taxa, ano); //1000 × (1.05)^3 para 3 anos a 10% ao ano.
        printf("%15.2f", quantia);
    }

    printf("\n");

  }

  return 0;
}   

/* int ano; 
  double quantia, principal = 1000.0,  taxa = .05; 
  printf  ("%4s%21s\n",   "Ano",   "Saldo na conta"); 
  for  (ano = 1; ano <= 10; ano++)
    { 
        quantia = principal * pow(1.0 + taxa, ano); 
        printf("%4d%21.2f\n",  ano, quantia); 
    } 

  return 0; 
*/