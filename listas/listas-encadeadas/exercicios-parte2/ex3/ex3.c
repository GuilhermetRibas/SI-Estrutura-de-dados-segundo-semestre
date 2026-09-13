#include<stdio.h>
#include "lista.h"

int main(){

Lista l1;
l1 = lst_criar();
l1 = lst_insere_ordenado(l1, 5);
l1 = lst_insere_ordenado(l1, 4);
l1 = lst_insere_ordenado(l1, 3);
l1 = lst_insere_ordenado(l1, 2);
lst_imprimi(l1);
printf("\n");

Lista l2;
l2 = lst_criar();
l2 = lst_insere_ordenado(l2, 6);
l2 = lst_insere_ordenado(l2, 7);
l2 = lst_insere_ordenado(l2, 8);
l2 = lst_insere_ordenado(l2, 9);
lst_imprimi(l2);
printf("\n");
Lista l_merge = merge(l1, l2);
lst_imprimi(l_merge);

}