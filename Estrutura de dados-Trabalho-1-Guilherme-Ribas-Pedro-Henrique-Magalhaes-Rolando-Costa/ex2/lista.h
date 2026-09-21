#ifndef _lista_
#define _lista_

struct lista{
    int linha;
    int coluna;
    int inf;
    struct lista *prox;
};

typedef struct lista Lista;

Lista *lst_cria();

Lista *lst_insere(Lista *l, int linha, int col, int v, int n_linhas, int n_colunas);

int lst_tamanho(Lista *l);

void lst_libera(Lista *l);

#endif