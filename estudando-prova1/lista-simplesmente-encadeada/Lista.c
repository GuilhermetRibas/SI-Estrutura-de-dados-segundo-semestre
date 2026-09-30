#include<stdio.h>
#include<stdlib.h>
#include"Lista.h"

struct lista{
    int dado;
    Lista *prox;
};

Lista* l_cria(){
    return NULL;
}

Lista* l_insere_inicio(Lista* l, int dado ){
    Lista *novo = malloc(sizeof(struct lista));
    if(novo == NULL)return NULL;

    novo->prox = l;
    novo->dado = dado;
    return novo;
}

Lista* l_insere_final(Lista* l, int dado){
    Lista* novo  = malloc(sizeof(struct lista));
    if(novo == NULL)return NULL;
    novo->dado = dado;

    if(l == NULL){
    novo->prox = l;
    return novo;        
    }

    Lista* p = l;
    while(p->prox != NULL){
        p = p->prox;
    }
    p->prox = novo;
    novo->prox = NULL;
    return l;
}

Lista* l_insere_ordenado(Lista* l, int v){
    Lista* novo = malloc(sizeof(struct lista));
    if(novo == NULL)return NULL;
    novo->dado = v;

    Lista* ant = NULL;
    Lista*p = l;
    while (p!=NULL && p->dado < v)
    {
        ant = p;
        p= p->prox;
    }
    if(ant == NULL){
        novo->prox = l;
        return novo;
    }else{
        ant->prox = novo;
        novo->prox = p;
    }
    return l;
}

Lista* l_insere_pos(Lista* l, int dado, int pos);

Lista* l_busca(Lista* l, int dado){
    for(Lista* p = l; p != NULL; p = p->prox){
        if(p->dado == dado){
            return p;
        }
    }
    return NULL;
}

void l_imprime(Lista* l){
    for(Lista* p = l; p != NULL; p = p->prox){
        printf("%d",p->dado);
    }
}

Lista* l_revove_inicio(Lista *l){
    if(l == NULL)return NULL;
    Lista* p = l;
    l = p->prox;
    free(p); 
}

Lista* l_revove_fim(Lista* l){
    if(l == NULL)return l;
    Lista* ant = NULL;
    Lista* p = l;
    while ( p->prox != NULL)
    {   
        ant = p;
        p = p->prox;
    }
    if(ant == NULL){
        l = p->prox;
    }else{
        ant->prox = NULL;
    }
    free(p);
    return l;
}

Lista* l_revove_dado(Lista* l, int v){
    if(l == NULL){
        return l;
    }
    Lista* ant = NULL;
    Lista* p = l;
    while(p != NULL && p->dado != v){
        ant = p;
        p = p->prox;
    }
    if(ant == NULL){
        l = p->prox;
    }else{
        ant->prox = p->prox;
    }
    free(p);
    return l;
}

Lista* l_revove_pos(Lista *l){

}

void l_libera(Lista* l){
     if(l== NULL)return l;
    Lista *p = l;
    while(p != NULL){
        Lista *t = p->prox;
        free(p);
        p= t;
    }
}
