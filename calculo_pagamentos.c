/*Calculando o pagamento semanal. Uma empresa 
paga a seus funcionários como gerentes (que recebem 
um salário semanal fixo), trabalhadores por hora (que 
recebem um salário fixo por hora até as 40 primeiras 
horas de trabalho e ‘hora e meia’ — ou seja, 1,5 vez 
o salário por hora — para horas extras trabalhadas), 
trabalhadores comissionados (que recebem R$ 250,00 
mais 5,7 por cento de suas vendas brutas semanais) ou 
trabalhadores por unidade (que recebem um valor fixo 
para cada um dos itens que eles produzem — cada tra
balhador por unidade nessa empresa trabalha apenas em 
um tipo de item). Escreva um programa que calcule o 
pagamento semanal de cada empregado. Você não sabe 
o número de empregados com antecedência. Cada tipo 
de empregado tem seu próprio código de pagamento: ge
rentes têm código 1, trabalhadores por hora têm código 
2, trabalhadores comissionados têm código 3 e trabalha
dores por unidade têm código 4. Use um switch para 
calcular o pagamento de cada empregado com base no 
seu código de pagamento. Dentro do switch, peça ao 
usuário (ou seja, o funcionário administrativo da folha 
de pagamento) que informe os fatos apropriados que seu 
programa precisa para calcular o pagamento de cada em
pregado com base no código.*/

#include <stdio.h>

int main(){

    int opcao, itens;
    float salarioFixo, salarioVariavel, horasTrabalhadas, totalSalario, totalVendas, valorItem;

    do
    {
        printf("=== SISTEMA DE CALCULO DE PAGAMENTOS ===\n");
        printf("1 - GERENTES\n");
        printf("2 - TRABALHADOR POR HORA\n");
        printf("3 - TRABALHADOR POR COMISSAO\n");
        printf("4 - TRABALHADORES POR UNIDADE\n");
        printf("5 - SAIR\n");
        printf("Digite uma opcao: \n");
        scanf("%i", &opcao);

        switch (opcao)
        {
        case 1:
            printf("SELECIONADO - GERENTE\n");
            printf("Salario semanal fixo: \n");
            scanf("%f", &salarioFixo);

            printf("O salario semanal e %.2f\n", salarioFixo);
            break;

        case 2:
            printf("SELECIONADO - TRABALHADOR POR HORA\n");
            printf("Valor hora: \n");
            scanf("%f", &salarioVariavel);

            printf("Horas trabalhadas: \n");
            scanf("%f", &horasTrabalhadas);
            if (horasTrabalhadas <= 40)
            {
                totalSalario = salarioVariavel * horasTrabalhadas;
            } 
            else 
            {
                totalSalario = (salarioVariavel * 40) + (salarioVariavel * 1.5) * (horasTrabalhadas - 40);
            }

            printf("O salario semanal e %.2f\n", totalSalario);
            break;

        case 3:
            printf("SELECIONADO - TRABALHADOR POR COMISSAO\n");

            salarioFixo = 250;
        
            printf("Total vendas da semana: \n");
            scanf("%f", &totalVendas);

            totalSalario = salarioFixo + (totalVendas * 0.057);
        
            printf("O salario semanal e %.2f\n", totalSalario);
            break;

        case 4:
            printf("SELECIONADO - TRABALHADOR POR ITEM\n");
            printf("Total itens produzidos: \n");
            scanf("%i", &itens);

            printf("Valor item: \n");
            scanf("%f", &valorItem);

            totalSalario = itens * valorItem;

            printf("O salario semanal e %.2f\n", totalSalario);
            break;

        case 5:
            printf("Saindo do sistema...\n");
            break;
        
        default:
            printf("Nenhuma opcao foi selecionada...\n");
            break;
        }

    } while (opcao!=5);
    
    return 0;
}


