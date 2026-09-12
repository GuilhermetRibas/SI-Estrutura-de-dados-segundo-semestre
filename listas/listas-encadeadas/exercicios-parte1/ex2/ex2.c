#include<stdio.h>
#include"lista.h"

int main(){

    Lista l = lst_cria();
    for(int i =0; i < 10; i++){
        l = lst_insere(l, i);
    }
    lst_printa(l);
    int quat_maior_n = maiores(l,4);
    printf("\nMaiores que 4: %d", quat_maior_n );
    lst_libera(l);

}