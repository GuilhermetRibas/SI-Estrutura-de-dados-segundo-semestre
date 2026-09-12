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
	printf("\n\t %d", p->info);
}

Lista* separa (Lista* l, int n){
	Lista* p = l;
	Lista* l2= NULL;
	for (p=l; p!=NULL; p=p->prox){
		if (p->info==n){
			l2=p->prox;
			p->prox=NULL;
		}
	}
	return l2;
}

int main (void){
	Lista* l; /* declara uma lista não iniciada */
	Lista* l2 = NULL;
	l = lst_cria(); /* inicia lista vazia */
	int separador;
	l = lst_insere(l, 8);
	l = lst_insere(l, 7);
	l = lst_insere(l, 6);
	l = lst_insere(l, 5);
	l = lst_insere(l, 4);
	l = lst_insere(l, 3);
	l = lst_insere(l, 2);
	l = lst_insere(l, 1);
	lst_imprime(l); 
	printf ("\nDigite o separador: ");
	scanf ("%d", &separador);	
	printf ("\nSeparando no %d", separador);
	l2=separa(l,separador);
	printf ("\nLista 1:");
	lst_imprime(l);
	printf ("\nLista 2:");
	lst_imprime(l2);
	system("pause");
	return 0;
}
