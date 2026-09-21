#include <stdio.h>
#include <stdlib.h>
#include "esparsa.h"
#include "lista.h"

Esparsa *esp_cria(int linha, int col, Lista *l)
{
    Esparsa *nova = malloc(sizeof(Esparsa));
    if (nova == NULL)
        return NULL;

    nova->linha = linha;
    nova->colunas = col;
    nova->prim = l;

    return nova;
}

int esp_busca(Esparsa *e, int linha, int coluna)
{
    if(linha >= e->linha || linha < 0 ||  coluna >= e->colunas || coluna < 0 ){
        return -1;
    }
    Lista *p = e->prim;
    while (p != NULL)
    {
        if (p->linha == linha && p->coluna == coluna)
        {
            return p->inf;
        }
        p = p->prox;
    }
    return 0;
}

void esp_imprime(Esparsa *e)
{
    for (int i = 0; i < e->linha; i++)
    {
        for (int j = 0; j < e->colunas; j++)
        {
            printf(" %d ", esp_busca(e, i, j));
        }
        printf("\n");
    }
}

void esp_libera(Esparsa *e)
{
    lst_libera(e->prim);
    free(e);
}

int esp_soma_linha(Esparsa *e, int linha_soma)
{
    if (linha_soma >= e->linha  || linha_soma < 0)
        return 0;
    Lista *p = e->prim;
    int cont = 0;
    while (p != NULL)
    {
        if (linha_soma == p->linha)
        {
            cont += p->inf;
        }
        p = p->prox;
    }
    return cont;
}

float esp_percentual_validos(Esparsa *e)
{
    if(e == NULL) return 0;
    float total = e->colunas * e->linha;
    float total_valido = lst_tamanho(e->prim);
    float pctg_valida = (100.0 * total_valido) / total;
    return pctg_valida;
}
