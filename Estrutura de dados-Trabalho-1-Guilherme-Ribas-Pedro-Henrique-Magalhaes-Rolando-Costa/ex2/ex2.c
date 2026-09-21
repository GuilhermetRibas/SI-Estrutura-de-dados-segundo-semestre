#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "esparsa.h"

int main()
{
    Lista *l = lst_cria();
    Esparsa *e;
    int n_colunas, n_linhas;
    int opcao;
    int linha, coluna, v;
    int linha_soma;

    printf("Digite o numero de linhas da matriz: ");
    scanf("%d", &n_linhas);

    printf("Digite o numero de colunas da matriz: ");
    scanf("%d", &n_colunas);

    do
    {
        printf("\n======== MENU =======\n");
        printf("1 - Inserir valor\n");
        printf("2 - Imprimir matriz\n");
        printf("3 - Somar uma linha\n");
        printf("4 - Percentual de valores validos\n");
        printf("5 - Buscar elemento\n");
        printf("6 - Sair\n");
        printf("=====================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o valor: ");
            scanf("%d", &v);

            printf("Digite a linha do valor: ");
            scanf("%d", &linha);

            printf("Digite a coluna do valor: ");
            scanf("%d", &coluna);

            l = lst_insere(l, linha, coluna, v, n_linhas, n_colunas);

            break;

        case 2:
        {
            e = esp_cria(n_linhas, n_colunas, l);
            esp_imprime(e);
        }
        break;

        case 3:
            printf("Digite a linha que deseja somar: ");
            scanf("%d", &linha_soma);

            {
                Esparsa *e = esp_cria(n_linhas, n_colunas, l);

                printf("Somatorio da linha: %d\n",
                       esp_soma_linha(e, linha_soma));
            }
            break;

        case 4:
        {
            Esparsa *e = esp_cria(n_linhas, n_colunas, l);

            printf("Percentual de valores validos: %.2f%%\n",
                   esp_percentual_validos(e));
        }
        break;
        case 5:
            printf("Digite a linha: ");
            scanf("%d", &linha);

            printf("Digite a coluna: ");
            scanf("%d", &coluna);

            printf("Valor da posicao [%d][%d]: %d\n",
                   linha, coluna, esp_busca(e, linha, coluna));

            break;

        case 6:
            esp_libera(e);
            printf("Encerrando\n");
            break;

        default:
            printf("Opcao invalida\n");
        }

    } while (opcao != 6);

    return 0;
}