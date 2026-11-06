#include <stdio.h>
#include "heaps.h"

int main() {
    int cap;
    printf("Digite a capacidade da lista de prioridades: ");
    if (scanf("%d", &cap) != 1 || cap <= 0) {
        printf("Capacidade invalida.\n");
        return 1;
    }

    Heaps *h = hps_cria(cap);
    if (h == NULL) {
        printf("Erro ao criar o heap.\n");
        return 1;
    }

    int op;
    do {
        printf("\n1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Imprimir heap\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        if (scanf("%d", &op) != 1) break;

        if (op == 1) {
            int x;
            printf("Valor a inserir: ");
            scanf("%d", &x);
            if (hps_inserir(h, x))
                printf("Inserido: %d\n", x);
            else
                printf("Heap cheio.\n");
        } else if (op == 2) {
            int saida;
            if (hps_remover(h, &saida))
                printf("Removido: %d\n", saida);
            else
                printf("Heap vazio.\n");
        } else if (op == 3) {
            hps_imprime(h);
        } else if (op != 0) {
            printf("Opcao invalida.\n");
        }
    } while (op != 0);

    hps_libera(h);
    return 0;
}