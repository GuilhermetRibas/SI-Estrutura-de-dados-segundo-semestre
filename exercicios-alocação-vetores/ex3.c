#include <stdio.h>
#include <stdlib.h>

void inverte(int n, int *vet);

int main()
{

    int *vet;
    int n;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    vet = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {

        printf("Digite um valor: ");
        scanf("%d", &vet[i]);
    }

    inverte(n, vet);

    printf("Vetor invertido: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d", vet[i]);
    }

    free(vet);
}

void inverte(int n, int *vet)
{
    // 1 2 3 4
    // 4  3 2 1
    int aux;
    int j = n - 1;

    for (int i = 0; i < n / 2; i++)
    {
        aux = vet[i];
        vet[i] = vet[j];
        vet[j] = aux;
        j--;
    }
}
