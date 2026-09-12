#ifndef _LISTA_H
#define _LISTA_H

typedef struct lista *Lista;

Lista cria_lista();

Lista insere_lista(Lista l,int v);

void printa_lista(Lista l);

void libera_lista(Lista l);

int comprimento(Lista l);

#endif