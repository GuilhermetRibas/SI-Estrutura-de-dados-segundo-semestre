#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "lista.h"

struct lista
{
    int inf;
    struct lista *prox;
};

Lista lst_criar()
{
    return NULL;
}

Lista lst_inserer_inicio(Lista l, int v)
{
    Lista novo = malloc(sizeof(struct lista));
    if (novo == NULL)
        return NULL;

    novo->inf = v;
    novo->prox = l;
    return novo;
}

Lista lst_insere_ordenado(Lista l, int v)
{
    Lista novo = malloc(sizeof(struct lista));
    if (novo == NULL)
        return NULL;

    novo->inf = v;

    if (l == NULL)
    {
        novo->prox = l;
        return novo;
    }
    Lista anterior = NULL;
    Lista p = l;
    while (p != NULL && p->inf < v)
    {
        anterior = p;
        p = p->prox;
    }
    if (anterior == NULL)
    {
        novo->prox = p;
        return novo;
    }
    else
    {
        novo->prox = anterior->prox;
        anterior->prox = novo;
    }
    return l;
}

Lista lst_remove_inicio(Lista l)
{

    if (l == NULL)
        return NULL;
    Lista p = l;
    p = l->prox;
    free(l);
    return p;
}

Lista lst_remove_no(Lista l, int v)
{
    if (l == NULL)
        return false;
    Lista anterior = NULL;
    Lista p = l;
    while (p != NULL && p->inf != v)
    {
        anterior = p;
        p = p->prox;
    }
    if (anterior == NULL)
    {
        l = p->prox;
    }
    else
    {
        anterior->prox = p->prox;
    }
    free(p);
    return l;
}

void lst_imprimi(Lista l)
{
    Lista p;
    for (p = l; p != NULL; p = p->prox)
    {
        printf("%d", p->inf);
    }
}

Lista lst_busca(Lista l, int v)
{
    if (l == NULL)
        return NULL;
    Lista p;
    for (p = l; p != NULL; p = p->prox)
    {
        if (p->inf == v)
        {
            return p;
        }
    }
    return NULL;
}

void lst_libera(Lista l)
{

    Lista atual = l;
    Lista prox;
    while (atual != NULL)
    {
        prox = atual->prox;
        free(atual);
        atual = prox;
    }
}

Lista inverte(Lista l)
{
    if (l == NULL)
    {
        return l;
    }
    Lista antecessor = NULL;
    Lista atual = l;
    Lista proximo;
    while (atual != NULL)
    {
        proximo = atual->prox;
        atual->prox = antecessor;
        antecessor = atual;
        atual = proximo;
    }
    return antecessor;
}

Lista insere_final(Lista l, int v)
{
    Lista novo = malloc(sizeof(struct lista));
    if (novo == NULL)
        return NULL;

    novo->inf = v;
    novo->prox = NULL;
    if (l == NULL)
    {
        return novo;
    }
    Lista p = l;
    while (p->prox != NULL)
    {
        p = p->prox;
    }
    p->prox = novo;
    return l;
}

int igual(Lista l1, Lista l2)
{

    Lista pl1 = l1;
    Lista pl2 = l2;

    while (pl1 != NULL && pl2 != NULL)
    {
        if (pl1->inf != pl2->inf)
        {
            return 0;
        }
        pl1 = pl1->prox;
        pl2 = pl2->prox;
    }
    if (pl1 == NULL && pl2 == NULL)
    {
        return 1;
    }
    return 0;
}

Lista copia(Lista l)
{
    Lista cpy = lst_criar();
    if (l == NULL)
    {
        return cpy;
    }
    Lista pl = l;
    while (pl != NULL)
    {
        cpy = insere_final(cpy, pl->inf);
        pl = pl->prox;
    }
    return cpy;
}