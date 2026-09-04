#include <stdio.h>
#include <stdlib.h>

void imprime_metriz(int m, int n, int **mat);

void aloca_matriz(int m, int n, int **mat);

int main()
{

    int m, n;
    int **mat;

    printf("Digite quntas lihas:");
    scanf("%d", &m);

    printf("Digite quntas colunas:");
    scanf("%d", &n);
    mat = (int **)malloc(m * sizeof(int));

    for (int i = 0; i < m; i++)
    {
        mat[i] = (int *)malloc(n * sizeof(int));
    }
    if (mat == NULL)
    {
        printf("Erro ao alocar memória");
        system("pause");
        exit(1);
    }
    printf("Digite a matriz\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Digite um valor: ");
            scanf("%d", &mat[i][j]);
        }
    }
    imprime_metriz(m, n, mat);

    for (int i = 0; i < m; i++)
    {
        free(mat[i]);
    }
    free(mat);
}
void imprime_metriz(int m, int n, int **mat)
{

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d", mat[i][j]);
        }
        printf("\n");
    }
}
