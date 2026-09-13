#ifndef _LISTA_
#define _LISTA_

typedef struct lista *Lista;

Lista lst_criar();

Lista lst_inserer_inicio(Lista l, int v);

Lista lst_insere_ordenado(Lista l, int v);

Lista lst_remove_inicio(Lista l);

Lista lst_remove_no(Lista l, int v);

void lst_imprimi(Lista l);

Lista lst_busca(Lista l, int v);

void lst_libera(Lista l);

Lista separa(Lista l, int n);


#endif