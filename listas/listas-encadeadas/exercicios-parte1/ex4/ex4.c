#include<stdio.h>
#include"lista.h"


int main(){

    Lista l1 = lst_criar();
    Lista l2 = lst_criar();
    Lista l3 = lst_criar();
    
    l1 = lst_inserir(l1,0);
    l1 = lst_inserir(l1,1);
    l1 = lst_inserir(l1,2);
    l1 = lst_inserir(l1,3);

    l2 = lst_inserir(l2,4);
    l2 = lst_inserir(l2,5);
    l2 = lst_inserir(l2,6);
    l2 = lst_inserir(l2,7);

    printf("Lista 1:");
    lst_printa(l1);

    printf("\nLista 2:");
    lst_printa(l2);

    l3 = concatena_retorna_terceira(l1,l2);
    printf("\nListas concatenadas: ");
    lst_printa(l1);
    




}