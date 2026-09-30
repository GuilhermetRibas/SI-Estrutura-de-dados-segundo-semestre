#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

struct lista
{
    int dado;
    Lista *prox;
    Lista *ant;
};

Lista *l_cria()
{
    return NULL;
}

Lista *l_insere_inicio(Lista *l, int dado)
{
    Lista *novo = malloc(sizeof(struct lista));
    if (novo == NULL)
        return NULL;
    Lista *p = l;
    novo->dado = dado;
    novo->ant = NULL;
    novo->prox = p;
    if (l != NULL)
    {
        p->ant = novo;
    }
    return novo;
}

Lista *l_insere_final(Lista *l, int dado)
{
    Lista *novo = malloc(sizeof(struct lista));
    if (novo == NULL)
        return NULL;
    novo->dado = dado;
    novo->prox = NULL;
    if (l == NULL)
    {
        novo->ant = NULL;
        l = novo;
    }
    else
    {
        Lista *p = l;
        while (p->prox != NULL)
        {
            p = p->prox;
        }
        p->prox = novo;
        novo->ant = p;
    }
    return l;
}

Lista *l_insere_ordenado(Lista *l, int v)
{ // ver dps
    Lista *novo = malloc(sizeof(struct lista));
    if (novo == NULL)
        return NULL;
    novo->dado = v;

    if (l == NULL)
    {
        novo->ant = NULL;
        novo->prox = l;
        l = novo;
    }
    else
    {

        Lista *p = l;
        while (p->prox != NULL && p->dado < v)
        {
            p = p->prox;
        }

        if (p->prox == NULL)
        {
        }

        Lista *anterior = p->ant;

        anterior->prox = novo;
        novo->prox = p;
        novo->ant = anterior;
        p->ant = novo;
    }
    return l;
}

Lista *l_insere_pos(Lista *l, int dado, int pos);

Lista *l_busca(Lista *l, int dado)
{
    for (Lista *p = l; p != NULL; p = p->prox)
    {
        printf("%d", p->dado);
    }
}

void l_imprime(Lista *l)
{
    if (l == NULL)
        return NULL;
    Lista *p = l;
    l = p->prox;
    free(p);
}

Lista *l_revove_inicio(Lista *l)
{
    

}

Lista *l_revove_fim(Lista *l);

Lista *l_revove_dado(Lista *l, int v)
{
    if (l == NULL)
        return l;
    Lista *p = l;
    while (p->prox != NULL && p->dado != v)
    {
        p = p->prox;
    }
    if (p == l)
    {
        l = p->prox;
    }
    else
    {
        p->ant->prox = p->prox;
    }
    if (p->prox != NULL)
    {
        p->prox->ant = p->ant;
    }
    free(p);
    return l;
}

Lista *l_revove_pos(Lista *l);

void l_libera(Lista *l)
{
    if (l == NULL)
        return l;
    Lista *p = l;
    while (p != NULL)
    {
        Lista *t = p->prox;
        free(p);
        p = t;
    }
}
