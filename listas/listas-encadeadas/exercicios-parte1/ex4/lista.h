#ifndef _LISTA_
#define _LISTA_

typedef struct lista *Lista;

Lista lst_criar();

Lista lst_inserir(Lista l, int v);

void lst_printa(Lista l);

void lst_libera(Lista l);

Lista ultimo(Lista l);

Lista concatena(Lista l1, Lista l2);

Lista concatena_retorna_terceira(Lista l1, Lista l2);

#endif