#include<stdio.h>
#include<stdlib.h>
#include"lista.h"

int main(){

    Lista l = cria_lista();
    for(int i =10; i > 0; i--){
      l = insere_lista(l,i);
    }
    printa_lista(l);    
    int quant_nos = comprimento(l);
    printf("\nNos: %d", quant_nos);
    libera_lista(l);
    
    
}


