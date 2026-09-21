#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

void erro_alocacao()
{
    printf("\nErro de alocacao de memoria.");
    system("pause");
    exit(1);
}

int ***cria_matriz(int l, int c, int p)
{
    int ***matriz;

    matriz = (int***)malloc(l * sizeof(int**));

    if (matriz == NULL)
    {
        erro_alocacao();
    }

    for (int i = 0; i < l; i++)
    {
        matriz[i] = (int**)malloc(c * sizeof(int*));

        if (matriz[i] == NULL)
        {
            erro_alocacao();
        }

        for (int j = 0; j < c; j++)
        {
            matriz[i][j] = (int*)malloc(p * sizeof(int));

            if (matriz[i][j] == NULL)
            {
                erro_alocacao();
            }
        }
    }

    return matriz;
}

void preenche_matriz(int ***m, int l, int c, int p)
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            for (int k = 0; k < p; k++)
            {
                printf("Digite um valor:");
                scanf("%d", &m[i][j][k]);
            }
        }
    }
}

void imprime_matriz(int ***m, int l, int c, int p)
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            for (int k = 0; k < p; k++)
            {
                printf("%d", m[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
