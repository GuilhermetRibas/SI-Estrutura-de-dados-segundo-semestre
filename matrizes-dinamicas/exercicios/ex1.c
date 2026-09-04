#include <stdio.h>
#include <stdlib.h>

void imprime_matriz(int m, int n, int *mat);

void aloca_matriz(int *mat, int m, int n);

int main()
{

    int n, m;
    int *mat;

    printf("Digite quntas lihas:");
    scanf("%d", &m);

    printf("Digite quntas colunas:");
    scanf("%d", &n);

    aloca_matriz(mat, m, n);

    printf("Digite sua matriz: \n");

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Digite um valor: ");
            scanf("%d", &mat[i * n + j]);
        }
    }

    imprime_matriz(m, n, mat);
    free(mat);
}

void aloca_matriz(int *mat, int m, int n)
{
    mat = (int *)malloc(n * m * sizeof(int));
    if(mat == NULL){
        printf("Erro ao alocar memória");
        system("pause");
		exit(1);
    }
}

void imprime_matriz(int m, int n, int *mat)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d", mat[i * n + j]);
        }
        printf("\n");
    }
}
