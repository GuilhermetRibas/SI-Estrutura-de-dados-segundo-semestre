#include<stdio.h>
#include<stdlib.h>

void printa_vetor_contrario(int n, int *vet);

int main(){

    int n = 10;
    int *vet;

    vet = (int*)malloc(10*sizeof(int));
    for(int i = 0; i < 10; i++){
        printf("Digite um valor: ");
        scanf("%d", &vet[i]);
    }
    printa_vetor_contrario(n, vet);

}

void printa_vetor_contrario(int n, int *vet){

    for(int i = n - 1; i >= 0;i--){
        printf("%d ", vet[i]);
    }
}
