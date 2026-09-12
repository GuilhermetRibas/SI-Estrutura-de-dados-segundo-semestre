#ifndef _LISTA_
#define _LISTA_

typedef struct lista *Lista;

Lista lst_cria();

Lista lst_insere(Lista l, int v);

void lst_printa(Lista l);

void lst_libera(Lista l);

int maiores(Lista l, int n);

#endif