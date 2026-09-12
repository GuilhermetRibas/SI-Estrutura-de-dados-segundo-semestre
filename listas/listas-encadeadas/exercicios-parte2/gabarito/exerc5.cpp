#include <stdio.h>
#include <stdlib.h>

struct lista
{
	int info;
	struct lista* prox;
};
typedef struct lista Lista;

Lista* lst_cria (void)
{
	return NULL;
}

/* inserção no início: retorna a lista atualizada */
Lista* lst_insere (Lista* l, int i)
{
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = i;
	novo->prox = l;
	return novo;
}

/* função imprime: imprime valores dos elementos */
void lst_imprime (Lista* l)
{
	Lista* p;
	for (p = l; p != NULL; p = p->prox)
		printf("\n\tinfo = %d\n", p->info);
}

/*a função igual percorre ambas as listas ao mesmo tempo, comparando os elementos em cada posição. Se todas as posições 
tiverem elementos iguais e ambas as listas chegarem ao fim ao mesmo tempo, as listas são consideradas iguais. Caso contrário, elas são consideradas 
diferentes*/
int igual(Lista* l1, Lista* l2){
	while (l1 != NULL && l2 != NULL) 
	{
        if (l1->info != l2->info) 
            return 0; // Elementos são diferentes
        l1 = l1->prox;
        l2 = l2->prox;
    }
    // Se ambos os ponteiros chegaram ao final das listas, elas são iguais
    return (l1 == NULL && l2 == NULL);
}

int main (void){
	Lista* l; /* declara uma lista não iniciada */
	Lista* l2;
	l = lst_cria(); /* inicia lista vazia */
	l2 = lst_cria();
	l = lst_insere(l, 1);
	l = lst_insere(l, 2);
	printf ("\nLista 1:\n"); 
	lst_imprime(l);	
	l2 = lst_insere(l2, 1);
	l2 = lst_insere(l2, 2);
	printf ("\nLista 2:\n"); 
	lst_imprime(l2);
	int i=igual(l,l2);
	if (i == 1)
		printf ("\nListas iguais\n");
	else
		printf ("\nListas diferentes\n");
	system("pause");
	return 0;
}
