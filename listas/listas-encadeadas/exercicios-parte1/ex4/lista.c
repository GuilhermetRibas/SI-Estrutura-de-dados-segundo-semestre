#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista
{
    int info;
    Lista prox;
};

Lista lst_criar()
{
    return NULL;
}

Lista lst_inserir(Lista l, int v)
{
    Lista nova = malloc(sizeof(struct lista));
    nova->info = v;
    nova->prox = l;
    return nova;
}

void lst_printa(Lista l)
{
    Lista p;
    for (p = l; p != NULL; p = p->prox)
    {
        printf("%d", p->info);
    }
}

void lst_libera(Lista l)
{
    Lista p = l;
    while (p != NULL)
    {
        l = p->prox;
        free(p);
        p = l;
    }
}

Lista ultimo(Lista l)
{
    Lista p = l;
    int cont = 0;
    if (p != NULL)
    {
        while (p != NULL && p->prox != NULL)
        {
            p = p->prox;
        }
    }
    return p;
}

Lista concatena(Lista l1, Lista l2){
    if(l1 == NULL){
        return l2;
    }
    Lista ult_pont_l1 = ultimo(l1);
    ult_pont_l1->prox = l2;
    return l1;
}

Lista concatena_retorna_terceira(Lista l1, Lista l2){
    Lista nova_l1 = lst_criar();

    Lista nova_l2 = lst_criar();

    Lista p_l1 = l1;
    while (p_l1 != NULL)
    {
        nova_l1 = lst_inserir(nova_l1, p_l1->info);
        p_l1 = p_l1->prox;
    }
    
    Lista p_l2 = l2;
    while (p_l2 != NULL)
    {
       nova_l2 = lst_inserir(nova_l2, p_l2->info);
        p_l2 = p_l2->prox;
    }

    Lista ultimo_ponteiro_noval1 =ultimo(nova_l1);
    ultimo_ponteiro_noval1->prox = nova_l2;
    return nova_l1;

}

