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
    if (l == NULL)
        return NULL;
    Lista novo = malloc(sizeof(struct lista));
    if (novo == NULL)
        return NULL;
    novo->inf = v;
    Lista anterior = NULL;
    Lista p = l;
    while (p->inf != v && p != NULL)
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

Lista retira_n(Lista l, int n){
    if(l != NULL){

        if(l->inf == n){
            Lista t = l;
            l = l->prox;
            free(t);
            l = retira_n(l,n);
        }else{
            l->prox = retira_n(l->prox,n);
        }
    }
    return l;
    
}