#include<stdio.h>
#include<stdlib.h>

float* aloca_vetor(int n);
void le_vetor(int n, float *vet);
float calcula_media(int n, float *vet);
float verifica_maior_que_media(int n, float *vet);

int main(){
    int n;
    float *vet;
    printf("digite o tamanho do vetor: ");
    scanf("%d", &n);
    vet = aloca_vetor(n);
    le_vetor(n, vet);
  printf("Percentual de valores maiores que a media do vetor: %2.f",  verifica_maior_que_media(n, vet));




}

float* aloca_vetor(int n){
    return (float*)malloc(n*sizeof(float));
}
void le_vetor(int n, float *vet){
    for(int i = 0; i < n; i++){
        printf("Digite um valor: ");
        scanf("%d", &vet[i]);
    }
}

float calcula_media(int n, float *vet){
    float somatorio = 0;
    float media;
    for(int i = 0; i < n; i++){
        somatorio+= vet[i];   }
    media = somatorio/n;
    return media;
}

float verifica_maior_que_media(int n, float *vet){
    int cont = 0;
    float porcentagem;
    float media_valores = calcula_media(n, vet);
    for(int i = 0; i < n; i++){
        if(vet[i] > media_valores){
            cont++;
        }
    }
    //percentual
    // n = 100% 
    // cont = ?%
   porcentagem = cont * 100 / n;
   return porcentagem;

}




