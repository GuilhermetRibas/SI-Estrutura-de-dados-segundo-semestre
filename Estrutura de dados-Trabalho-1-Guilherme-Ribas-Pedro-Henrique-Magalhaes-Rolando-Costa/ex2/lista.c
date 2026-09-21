#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista *lst_cria()
{
    return NULL;
}

Lista *lst_insere(Lista *l, int linha, int col, int v, int n_linhas, int n_colunas)
{ // no final
    if (v == 0)
        return l;
    if (linha >= n_linhas || col >= n_colunas || linha < 0 || col < 0)
        return l;
    Lista *novo = malloc(sizeof(Lista));
    if (novo == NULL)
        return NULL;

    novo->prox = NULL;
    novo->linha = linha;
    novo->coluna = col;
    novo->inf = v;
    if (l == NULL)
        return novo;

    Lista *p = l;
    while (p != NULL && p->prox != NULL)
    {
        p = p->prox;
    }
    p->prox = novo;
    return l;
}

int lst_tamanho(Lista *l)
{
    Lista *p = l;
    int cont = 0;
    while (p != NULL)
    {
        cont++;
        p = p->prox;
    }
    return cont;
}

void lst_libera(Lista *l)
{
    if (l == NULL)
        return;
    Lista *p = l;
    while (p != NULL)
    {
        Lista *t = p->prox;
        free(p);
        p = t;
    }
}
