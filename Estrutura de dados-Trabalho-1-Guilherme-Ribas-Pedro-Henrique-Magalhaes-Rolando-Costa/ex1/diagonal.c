#include <stdio.h>
#include <stdlib.h>
#include "diagonal.h"

Diagonal *dgl_cria(int ordem)
{
    Diagonal *nova = malloc(sizeof(Diagonal));
    if (nova == NULL)
        return NULL;
    nova->ordem = ordem;
    nova->v = malloc(ordem * sizeof(int));
    if (nova->v == NULL)
        return NULL;
    for (int i = 0; i < ordem; i++)
    {
        nova->v[i] = 0;
    }
    return nova;
}

void dgl_preeche(Diagonal *d, int i, int inf)
{
    d->v[i] = inf;
}

void dgl_imprime(Diagonal *d)
{

    for (int i = 0; i < d->ordem; i++)
    {
        if (i > 0)
        {
            for (int j = 0; j < i; j++)
            {
                printf(" 0 ");
            }
        }
        printf(" %d ", d->v[i]);
        for (int k = i + 1; k < d->ordem; k++)
        {
            printf(" 0 ");
        }
        printf("\n");
    }
}

int dgl_busca(Diagonal *d, int l, int col)
{
    if(l >= d->ordem || col >= d->ordem || l < 0 || col < 0){
        return -1;
    }
    if (l == col)
    {
        return d->v[l];
    }
    return 0;
}

void dgl_desaloca(Diagonal *d)
{
    free(d->v);
    free(d);
}
