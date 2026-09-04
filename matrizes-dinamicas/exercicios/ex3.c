#include <stdio.h>
#include <stdlib.h>

int **aloca_matriz(int m, int n);
void desaloca_matriz(int m, int **mat);
void preenche_matriz(int m, int n, int **mat);
void mostra_matriz(int n, int m, int **mat);

int main()
{
    int n, m;
    int **mat;
    printf("Digite o numero de linhas:");
    scanf("%d", &m);
    printf("Digite o numero de linhas: ");
    scanf("%d", &n);
    mat = aloca_matriz(m, n);
    preenche_matriz(m, n, mat);
    mostra_matriz(n, m, mat);
    desaloca_matriz(m, mat);
}

int **aloca_matriz(int m, int n)
{
    int **mat;
    mat = (int **)malloc(m * sizeof(int));
    if (mat == NULL)
    {
        printf("Erro ao alocarmemória");
        system("pause");
        exit(1);
    }
    for (int i = 0; i < m; i++)
    {
        mat[i] = (int *)malloc(n * sizeof(int));
        if (mat[i] == NULL)
        {
            printf("Erro ao alocar mamória");
            system("pause");
            exit(1);
        }
    }
    return mat;
}
void desaloca_matriz(int m, int **mat)
{
    for (int i = 0; i < m; i++)
    {
        free(mat[i]);
    }
    free(mat);
}
void preenche_matriz(int m, int n, int **mat)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Digite um valor: ");
            scanf("%d", &mat[i][j]);
        }
    }
}
void mostra_matriz(int n, int m, int **mat)
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
