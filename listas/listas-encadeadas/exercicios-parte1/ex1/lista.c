#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"lista.h"


struct lista
{
    int info;
    Lista prox;
};

Lista cria_lista(){
    return NULL;
}

Lista insere_lista(Lista l, int v){
    Lista novo_no = malloc(sizeof(struct lista));
    novo_no->info = v;
    novo_no->prox = l;
    return novo_no;
}

void printa_lista(Lista l){
    Lista p;
    for(p =l; p != NULL; p = p->prox){
        printf("%d", p->info);
    }
}   

void libera_lista(Lista l){
    Lista p = l;
    while(p != NULL){
        l = p->prox;
        free(p);
        p = l;
    }
    
    
}
int comprimento(Lista l){
    int tam = 0;
    Lista p;
    for(p = l; p != NULL; p = p->prox){
        tam++;
    }
    return tam;
}
