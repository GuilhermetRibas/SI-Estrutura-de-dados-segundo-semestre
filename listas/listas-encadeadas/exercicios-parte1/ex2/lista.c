#include<stdio.h>
#include<stdlib.h>
#include"lista.h"

struct lista
{
    int info;
    Lista prox;
};


Lista lst_cria(){
    return NULL;
}

Lista lst_insere(Lista l, int v){
    Lista nova = malloc(sizeof(struct lista));
    nova->info = v;
    nova->prox = l;
    return nova;
}

void lst_printa(Lista l){
    Lista p;
    for(p = l; p != NULL; p= p->prox){
        printf("%d", p->info);
    }
}

void lst_libera(Lista l){
    Lista p = l;
    while(p !=NULL){
       l = p->prox;
       free(p);
       p = l;
    }
}

int maiores(Lista l, int n){
    Lista p;
    int cont =0;
    for(p = l; p != NULL; p = p->prox){
        if(p->info > n){
            cont++;
        }
    }
    return cont;
}
