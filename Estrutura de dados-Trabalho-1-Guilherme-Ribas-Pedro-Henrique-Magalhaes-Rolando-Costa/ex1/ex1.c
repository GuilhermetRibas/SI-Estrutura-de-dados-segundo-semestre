#include <stdio.h>
#include <stdlib.h>
#include "diagonal.h"

int main()
{
    int ordem;
    int opcao;
    int valor;
    int col, l;

    printf("Digite a ordem da matriz quadrada: ");
    scanf("%d", &ordem);

    Diagonal *d = dgl_cria(ordem);

    do
    {
        printf("\n======== MENU ======\n");
        printf("1 - Preencher diagonal\n");
        printf("2 - Imprimir matriz\n");
        printf("3 - Pesquisar valor\n");
        printf("4 - Sair\n");
        printf("================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            for (int i = 0; i < ordem; i++)
            {
                printf("Digite o %d valor da diagonal: ", i);
                scanf("%d", &valor);

                dgl_preeche(d, i, valor);
            }
            break;

        case 2:
            printf("\nMatriz:\n");
            dgl_imprime(d);
            break;

        case 3:
            printf("\nDigite a coluna para a pesquisa: ");
            scanf("%d", &col);

            printf("Digite a linha para a pesquisa: ");
            scanf("%d", &l);

            printf("Valor da posicao %dX%d: %d\n", l, col, dgl_busca(d, l, col));
            break;

        case 4:
            printf("Encerrando\n");
            break;

        default:
            printf("Opcao invalida\n");
        }

    } while (opcao != 4);

    dgl_desaloca(d);

    return 0;
}