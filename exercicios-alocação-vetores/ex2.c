#include <stdio.h>
#include <stdlib.h>

int negativos(int n, float *vet)
{
    int cont = 0;
    for (int i = 0; i < n; i++)
    {
        if (vet[i] < 0)
        {
            cont++;
        }
    }

    return cont;
}

int main()
{

    float *vet;
    int n;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    vet = (float *)malloc(n * sizeof(float));

    for (int i = 0; i < n; i++)
    {
        printf("Digite uma valor: ");
        scanf("%f", &vet[i]);
    }

    printf("A quantia de números negativos: %d", negativos(n, vet));

    free(vet);
}