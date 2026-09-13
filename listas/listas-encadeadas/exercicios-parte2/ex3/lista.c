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
        return l;

    novo->inf = v;

    // Lista vazia
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

    // Inserir no início
    if (anterior == NULL)
    {
        novo->prox = l;
        return novo;
    }

    // Inserir no meio ou final
    novo->prox = anterior->prox;
    anterior->prox = novo;

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

    Lista anterior = NULL;
    Lista p = l;
    while (p != NULL && p->inf < v)
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

Lista insere_final(Lista l, int v)
{
    Lista novo = malloc(sizeof(struct lista));
    if (novo == NULL)
        return NULL;
    novo->inf = v;
    novo->prox = NULL;

    if (l == NULL)
        return novo;

    Lista p = l;
    while (p->prox != NULL)
    {
        p = p->prox;
    }
    p->prox = novo;
    return l;
}

Lista merge(Lista l1, Lista l2)
{
    Lista resultante = lst_criar();
    Lista p_l1 = l1;
    Lista p_l2 = l2;
    // inseriri na lista nova,so que tem que ser e traz para frente
    while (p_l1 != NULL && p_l2 != NULL)
    {
        resultante = insere_final(resultante, p_l1->inf);
        p_l1 = p_l1->prox;

        resultante = insere_final(resultante, p_l2->inf);
        p_l2 = p_l2->prox;
    }

    while (p_l1 != NULL)
    {
        resultante = insere_final(resultante, p_l1->inf);
        p_l1 = p_l1->prox;
    }

    while (p_l1 != NULL)
    {
        resultante = insere_final(resultante, p_l1->inf);
        p_l1 = p_l1->prox;
    }

    return resultante;
}
