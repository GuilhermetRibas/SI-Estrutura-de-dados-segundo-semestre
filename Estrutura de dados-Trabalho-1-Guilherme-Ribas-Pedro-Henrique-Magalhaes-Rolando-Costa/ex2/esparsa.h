#ifndef _esparsa_
#define _esparsa_
#include "lista.h"

struct esparsa
{
    int linha;
    int colunas;
    struct lista *prim;
};

typedef struct esparsa Esparsa;

Esparsa *esp_cria(int linha, int col, Lista *l);

void esp_imprime(Esparsa *e);

int esp_busca(Esparsa *e, int linha, int coluna);

void esp_libera(Esparsa *e);

int esp_soma_linha(Esparsa *e, int linha_soma);

float esp_percentual_validos(Esparsa *e);

#endif