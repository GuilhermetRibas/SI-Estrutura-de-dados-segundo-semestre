#include<stdio.h>
#include"lista.h"

int main(){

Lista l1;
l1 = lst_criar();
l1 = lst_insere_ordenado(l1, 5);
l1 = lst_insere_ordenado(l1, 4);
l1 = lst_insere_ordenado(l1, 3);
l1 = lst_insere_ordenado(l1, 2);
lst_imprimi(l1);
printf("\n");

Lista cpyl1 = copia(l1);
lst_imprimi(cpyl1);



}