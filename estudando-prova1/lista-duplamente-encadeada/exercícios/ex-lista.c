#include<stdio.h>
#include<stdlib.h>
#include"ex-lista.h"

struct lista{
    int dado;
    Lista* ant;
    Lista* prox;
};


Lista* l_cria(){
    return NULL;
}

Lista* l_insere_inicio(Lista* l, int dado );
 
Lista* l_insere_final(Lista* l, int dado){
    Lista* novo =(Lista*) malloc(sizeof(Lista));
    if(novo == NULL)return NULL;
    novo->dado = dado;
    novo->prox = NULL;
    Lista* ultimo = l_ultimo(l);
    if(ultimo == NULL){
        novo->ant = NULL;
        return novo;
    }

    ultimo->prox = novo;
    novo->ant = ultimo;
    return l;
}

Lista* l_insere_ordenado(Lista* l, int v);

Lista* l_insere_pos(Lista* l, int dado, int pos);

Lista* busca(Lista* l, int v){
    Lista* p =l;
    while(p != NULL && p->dado != v){
        p = p->prox;
    }
    return p;
}

Lista* l_ultimo(Lista* l){
    if(l == NULL)return l;
    Lista* p = l;
    while(p->prox != NULL){
        p = p->prox;
    }
    return p;
}

void l_imprime(Lista* l){
    for(Lista* p = l; p != NULL; p = p->prox){
        printf("%d",p->dado);
    }
}

Lista* l_revove_inicio(Lista *l);

Lista* l_revove_fim(Lista *l);

Lista* l_revove_dado(Lista* l, int v){
    if(l == NULL) return l;
    Lista* p = l_busca(l,v);

    if(p == NULL){
        return p;
    }
    if(l == p){
        l = p->prox;
    }else{
        p->ant->prox = p->prox;
    }
    if(p->prox != NULL){
        p->prox->ant = p->ant;
    }
    free(p);
    return l;
}

Lista* l_revove_pos(Lista *l);



Lista* l_remove_ant(Lista* l, int v){
    if(l == NULL)return l;
    
    Lista* p = l;
    Lista* no = l_busca(l,v);
    if(p->dado == v || no->ant == NULL || no == NULL){
        preintf("não será possivel a remoção");
        return l;
    }
    Lista* noR = no->ant; 
    return l_revove_dado(l,noR->dado);


}

void l_libera(Lista* l){
    Lista* p = l;
    while(p != NULL){
        Lista* t = p->prox;
        free(p);
        p = t;
    }
}
