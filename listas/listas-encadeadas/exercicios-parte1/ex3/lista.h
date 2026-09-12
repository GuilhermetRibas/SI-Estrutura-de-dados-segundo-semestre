#ifndef _LISTA_
#define _Lista_

typedef struct lista *Lista;

Lista lst_criar();

Lista lst_inserir(Lista l, int v);

void lst_printa(Lista l);

void lst_libera(Lista l);

Lista ultimo(Lista l);

#endif