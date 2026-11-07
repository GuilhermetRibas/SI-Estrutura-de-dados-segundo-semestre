#include <stdio.h>
#include <stdlib.h>
#include "heaps.h"

struct heaps
{
    int *dados;
    int n;
    int cap;
};

Heaps *hps_cria(int capacidade)
{
    Heaps *h = malloc(sizeof(Heaps));
    if (h == NULL)
        return NULL;
    h->n = 0;
    h->cap = capacidade;
    h->dados = malloc(capacidade * sizeof(int));
    if (h->dados == NULL)
    {
        free(h);
        return NULL;
    }
    return h;
}

static void upheap(Heaps *h, int i)
{
    while (i > 0)
    {
        int pai = (i - 1) / 2;
        if (h->dados[i] <= h->dados[pai])
            break;
        int tmp = h->dados[i];
        h->dados[i] = h->dados[pai];
        h->dados[pai] = tmp;
        i = pai;
    }
}

int hps_inserir(Heaps *h, int x)
{
    if (h->n == h->cap)
        return 0;
    h->dados[h->n] = x;
    upheap(h, h->n);
    h->n++;
    return 1;
}

static void downheap(Heaps *h, int i)
{
    for (;;)
    {
        int esq = 2 * i + 1, dir = 2 * i + 2, maior = i;
        if (esq < h->n && h->dados[esq] > h->dados[maior])
            maior = esq;
        if (dir < h->n && h->dados[dir] > h->dados[maior])
            maior = dir;
        if (maior == i)
            break;
        int tmp = h->dados[i];
        h->dados[i] = h->dados[maior];
        h->dados[maior] = tmp;
        i = maior;
    }
}

int hps_remover(Heaps *h, int *saida)
{
    if (h->n == 0)
        return 0;
    *saida = h->dados[0];
    h->dados[0] = h->dados[h->n - 1];
    h->n--;
    downheap(h, 0);
    return 1;
}
void hps_imprime(Heaps *h)
{
    if (h == NULL)
        return;
    if (h->n == 0)
    {
        printf("Heap vazio.\n");
        return;
    }
    for (int i = 0; i < h->n; i++)
    {
        int esq = 2 * i + 1, dir = 2 * i + 2;
        printf("No %d: filho esq: ", h->dados[i]);
        if (esq < h->n) printf("%d", h->dados[esq]); else printf("vazio");
        printf(", filho dir: ");
        if (dir < h->n) printf("%d", h->dados[dir]); else printf("vazio");
        printf("\n");
    }
}

void hps_libera(Heaps *h)
{
    if (h != NULL)
    {
        free(h->dados);
        free(h);
    }
}
