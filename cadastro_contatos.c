//Objetivo: Criar uma agenda simples para salvar contatos de amigos/família

#include <stdio.h>
#include <string.h>
#include <strings.h>

#define MAX 5

struct Contato
{
    char nome[50];
    char telefone[15];    // Ex: "(11)99999-9999"
    int idade;
    char email[50];
};

int main()
{
    struct Contato contatos[MAX];

    int opcao, sentinela, total_numeros = 0, encontrado, opcao_filtro, encontrou_filtro;
    char busca_nome[50];

    do
    {
        printf("==========================================\n");
        printf("                MINHA AGENDA              \n");
        printf("==========================================\n");
        printf("1 - Adicionar contato\n");
        printf("2 - Ver todos os contatos\n");
        printf("3 - Buscar por nome\n");
        printf("4 - Contar contatos\n");
        printf("5 - Filtrar por idade\n");
        printf("6 - Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%i", &opcao);
        getchar(); // limpa o \n do buffer

        switch (opcao)
        {
        case 1:
            do
            {   
                if (total_numeros>=MAX)
                {
                    printf("O valor maximo de contatos foi atingido (5)\n");
                    break;
                }

                printf("\nNome: ");
                fgets(contatos[total_numeros].nome, sizeof(contatos[total_numeros].nome), stdin);
                contatos[total_numeros].nome[strcspn(contatos[total_numeros].nome, "\n")] = 0;  // remove o \n

                if (strlen(contatos[total_numeros].nome) == 0)
                {
                    printf("Nome nao pode ficar em branco. tente novamente. \n");
                    break;
                }
                
                printf("Telefone: ");
                fgets(contatos[total_numeros].telefone, sizeof(contatos[total_numeros].telefone), stdin);
                contatos[total_numeros].telefone[strcspn(contatos[total_numeros].telefone, "\n")] = 0;  // remove o \n

                printf("Idade: ");
                scanf("%i", &contatos[total_numeros].idade);

                if (contatos[total_numeros].idade > 120 || contatos[total_numeros].idade < 1 )
                {
                    printf("Idade deve ser maior que 1 e menor que 120");
                    break;
                }
                
                getchar(); // limpa o \n após scanf

                printf("Email: ");
                fgets(contatos[total_numeros].email, sizeof(contatos[total_numeros].email), stdin);
                contatos[total_numeros].email[strcspn(contatos[total_numeros].email, "\n")] = 0;  // remove o \n

                total_numeros++;

                printf("\nDeseja continuar? SIM(1) / NAO(2)\n");
                scanf("%i", &sentinela);
                getchar(); // limpa o \n após scanf

            } while (sentinela == 1);

            break;

        case 2:
            if (total_numeros == 0) {
                printf("Nenhum contato cadastrado ainda.\n");
            break;
            }

            for (int i = 0; i < total_numeros; i++)
            {
                printf("\nNome: %s\n", contatos[i].nome);
                printf("Telefone: %s\n", contatos[i].telefone);
                printf("Idade: %i\n", contatos[i].idade);
                printf("Email: %s\n", contatos[i].email);
            }

            break;

        case 3:
            if (total_numeros == 0) {
                printf("Nenhum contato cadastrado ainda.\n");
            break;
            }

            printf("\nBusque por um nome: ");
            fgets(busca_nome, sizeof(busca_nome), stdin);
            busca_nome[strcspn(busca_nome, "\n")] = 0;  // remove o \n

            encontrado = 0;

            for (int i = 0; i < total_numeros; i++)
            {
                if (strcasecmp(contatos[i].nome, busca_nome) == 0) 
                {   
                    printf("Nome: %s\n", contatos[i].nome);
                    printf("Telefone: %s\n", contatos[i].telefone);
                    printf("Idade: %i\n", contatos[i].idade);
                    printf("Email: %s\n\n", contatos[i].email);
                    encontrado = 1;
                    break;
                }
            }

            if (!encontrado)
                {
                    printf("\nNenhum nome foi encontrado");
                }
            break;

        case 4:
            if (total_numeros == 0)
            {
                printf("\nVoce nao possui nenhum contato.");
            }
            else if(total_numeros == 1)
            {
                printf("\nVoce possui %i contato!", total_numeros);
            }
            else
            {
                printf("\nVoce possui %i contatos!", total_numeros);
            }
            
            break;

        case 5:
            if (total_numeros == 0)
            {
                printf("Nenhum contato cadastrado ainda.\n");
            break;
            }

            printf("\n===== FILTRAR POR IDADE =====");
            printf("1 - Mostrar apenas MAIORES de 18 anos\n");
            printf("2 - Mostrar apenas MENORES de 18 anos\n");
            printf("Escolha uma opcao: ");
            scanf("%d", &opcao_filtro);

            printf("\n===== RESULTADO DO FILTRO =====");
            switch (opcao_filtro)
            {
            case 1:
                encontrou_filtro = 0;
                printf("\nContatos maiores de 18 anos");
                for (int i = 0; i < total_numeros; i++)
                {
                    if (contatos[i].idade >= 18)
                    {
                        printf("%s - %i anos - %s - %s\n", contatos[i].nome, contatos[i].idade, contatos[i].telefone, contatos[i].email);
                        encontrou_filtro = 1;
                    }
                }

                if (encontrou_filtro == 0)
                {
                    printf("\nNenhum contato maior que 18 anos encontrado\n");
                }
                
                break;

            case 2:
                encontrou_filtro = 0;
                printf("\nContatos menores de 18 anos");
                for (int i = 0; i < total_numeros; i++)
                {
                    if (contatos[i].idade < 18)
                    {
                        printf("%s - %i anos - %s - %s\n", contatos[i].nome, contatos[i].idade, contatos[i].telefone, contatos[i].email);
                        encontrou_filtro = 1;
                    }
                }

                if (encontrou_filtro == 0)
                {
                    printf("\nNenhum contato com menor de 18 anos encontrado\n");
                }

                break;
            
            default:
                printf("\nNenhuma das opcoes foram inseridas");

                break;
            }

            break;

        case 6:
            printf("\nSaindo do sistema...\n");

            break;
        
        default:
            printf("\nNenhuma das opcoes foram inseridas");

            break;
        }
        
    } while (opcao !=6);

    return 0;

}