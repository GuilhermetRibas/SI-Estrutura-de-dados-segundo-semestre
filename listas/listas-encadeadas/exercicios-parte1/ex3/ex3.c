#include<stdio.h>
#include"lista.h"

int main(){

    Lista l = lst_criar();
    for(int i =0; i < 10; i++){
        l = lst_inserir(l, i);
    }
    lst_printa(l);
    Lista lst_ultimo = ultimo(l);
    lst_libera(l);
}