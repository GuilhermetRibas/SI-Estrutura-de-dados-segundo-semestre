#ifndef  _lista_
#define _lista_

typedef struct lista Lista;

Lista* l_cria();

Lista* l_insere_inicio(Lista* l, int dado );

Lista* l_insere_final(Lista* l, int dado);

Lista* l_insere_ordenado(Lista* l, int v);

Lista* l_insere_pos(Lista* l, int dado, int pos);

Lista* l_busca(Lista* l, int dado);

void l_imprime(Lista* l);

Lista* l_revove_inicio(Lista *l);

Lista* l_revove_fim(Lista *l);

Lista* l_revove_dado(Lista* l, int v);

Lista* l_revove_pos(Lista *l);

void l_libera(Lista* l);




#endif