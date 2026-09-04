#include <stdio.h>
#include <stdlib.h>

int **soma_matriz(int m, int n, int **mat1, int **mat2);

int **aloca_matriz(int m, int n);

void libera_matriz(int m, int **mat);

void preenche_matriz(int m, int n, int **mat);

void printa_matriz(int m, int nn, int **mat);

int main()
{
    int m, n;
    int **mat1, **mat2, **mat3;

    printf("digite a quantia de linhas: ");
    scanf("%d", &m);
    printf("digite a quantia de colunas: ");
    scanf("%d", &n);

    mat1 = aloca_matriz(m, n);
    mat2 = aloca_matriz(m, n);
    printf("Digite os valores da primeira matriz: \n");
    preenche_matriz(m, n, mat1);
    printf("\nDigite os valores da segunda matriz: \n");
    preenche_matriz(m, n, mat2);
    mat3 = soma_matriz(m, n, mat1, mat2);
    printa_matriz(m, n, mat3);

    libera_matriz(m,mat1);
    libera_matriz(m,mat2);
    libera_matriz(m,mat3);
}

int **aloca_matriz(int m, int n)
{
    int **mat;
    mat = (int **)malloc(m * sizeof(int));
    if (mat == NULL)
    {
        printf("erro ao alocar memória");
        system("pause");
        exit(1);
    }
    for (int i = 0; i < m; i++)
    {
        mat[i] = (int *)malloc(n * sizeof(int));
        if (mat == NULL)
        {
            printf("erro ao alocar memoria");
            system("pause");
            exit(1);
        }
    }
    return mat;
}

void libera_matriz(int m, int **mat)
{   
    for(int i =0; i< m; i++){
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
            printf("Digite um valor");
            scanf("%d", &mat[i][j]);
        }
    }
}

void printa_matriz(int m, int n, int **mat)
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

int **soma_matriz(int m, int n, int **mat1, int **mat2)
{
    int **mat3;
    mat3 = aloca_matriz(m, n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat3[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return mat3;
}
