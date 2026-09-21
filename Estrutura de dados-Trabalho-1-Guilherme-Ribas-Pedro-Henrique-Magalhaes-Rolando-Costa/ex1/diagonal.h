#ifndef _lista_ex1_
#define _lista_ex1_

struct diagonal
{
    int ordem;
    int *v;
};

typedef struct diagonal Diagonal;

Diagonal *dgl_cria(int ordem);

void dgl_preeche(Diagonal *d,int i, int inf);

void dgl_imprime(Diagonal *d);

int dgl_busca(Diagonal *d, int l, int col);

void dgl_desaloca(Diagonal *d);

#endif