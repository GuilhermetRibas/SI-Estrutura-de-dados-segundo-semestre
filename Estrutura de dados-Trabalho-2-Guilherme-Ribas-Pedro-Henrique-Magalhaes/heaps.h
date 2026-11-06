
#ifndef _heaps_
#define _heaps_

typedef struct heaps Heaps;


Heaps* hps_cria(int capacidade);

int hps_inserir(Heaps* h,int x);

int hps_remover(Heaps* h, int *saida);

void hps_imprime(Heaps* h);

void hps_libera(Heaps* h);

#endif