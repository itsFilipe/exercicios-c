#include <stdio.h>
#include <string.h>

#define MAX 50

struct Aluno
{
    char nome[50];
    int idade;
    int matricula;
    float nota_final;
};

int main()
{
    int sentinela, opcao, total_alunos = 0;
    int pesquisa_matricula;

    struct Aluno aluno[MAX];

    do
    {
        printf("===== MENU ======\n");
        printf("1 - Cadastrar aluno\n");
        printf("2 - Listar alunos\n");
        printf("3 - Buscar por matricula\n");
        printf("4 - Sair\n\n");
        printf("Escolha uma opcao: \n");
        scanf("%i", &opcao);
        getchar(); // limpa o \n após scanf

        switch (opcao)
        {
        case 1:
            do
            {   
                if (total_alunos >= MAX)

                printf("\nNome: ");
                fgets(aluno[total_alunos].nome, sizeof(aluno[total_alunos].nome), stdin);
                aluno[total_alunos].nome[strcspn(aluno[total_alunos].nome, "\n")] = 0;  // remove o \n

                printf("Idade: ");
                scanf("%i", &aluno[total_alunos].idade);

                printf("Matricula: ");
                scanf("%i", &aluno[total_alunos].matricula);

                printf("Nota final: ");
                scanf("%f", &aluno[total_alunos].nota_final);
                if((aluno[total_alunos].nota_final > 10) || (aluno[total_alunos].nota_final < 0) )
                {
                    printf("A nota deve estar entre 10 e 0.\n");
                    break;
                }

                total_alunos++;

                {
                    printf("O valor maximo foi excedido");
                    break;
                }
                
                printf("\nDeseja continuar? SIM(1) | NAO(2)\n");
                scanf("%i", &sentinela);
                getchar(); // limpa o \n após scanf
            } while (sentinela != 2);
            break;
    
        case 2:
            if (total_alunos == 0)
                printf("Nenhum aluno cadastrado\n");
                
            for (int i = 0; i < total_alunos; i++)
            {   
                printf("====== Aluno %i ======\n", i + 1);
                printf("Nome: %s\n", aluno[i].nome);
                printf("Idade: %i\n", aluno[i].idade);
                printf("Matricula: %i\n", aluno[i].matricula);
                printf("Nota final: %.2f\n\n", aluno[i].nota_final);
            }
            break;

        case 3:
            printf("Digite a matricula desejada: ");
            scanf("%i", &pesquisa_matricula);

            int encontrado = 0;

            for ( int i = 0; i < total_alunos; i++)
            {
                if(aluno[i].matricula == pesquisa_matricula)
                {
                    printf("Nome: %s\n", aluno[i].nome);
                    printf("Idade: %i\n", aluno[i].idade);
                    printf("Matricula: %i\n", aluno[i].matricula);
                    printf("Nota final: %.2f\n\n", aluno[i].nota_final);
                    encontrado = 1;
                    break;
                } 
            }
                if(encontrado == 1)
                    printf("Esse numero de matricula nao foi encontrado\n");
            break;

        case 4:
            printf("Saindo do sistema...\n");
            break;
        
        default:
            printf("Opcao invalida! Tente novamente.\n");
        break;
        }
    } while (opcao != 4);
}


