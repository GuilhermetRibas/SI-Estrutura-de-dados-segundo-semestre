#include<stdio.h>
#include<stdlib.h>
#include"matriz.h"

int main(){

int linhas, colunas, profundidade;

printf("Digite o numero de linhas: ");
scanf("%d", &linhas);

printf("Digite o numero de colunas: ");
scanf("%d", &colunas);

printf("Digite a profundidade: ");
scanf("%d", &profundidade);

int ***matriz = cria_matriz(linhas, colunas, profundidade);

preenche_matriz(matriz, linhas, colunas, profundidade);

imprime_matriz(matriz,linhas, colunas, profundidade );

}