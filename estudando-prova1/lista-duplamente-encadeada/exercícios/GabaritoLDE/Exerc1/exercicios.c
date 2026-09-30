#include <stdio.h>
#include <stdlib.h>
#include "exercicios.h"

/* função de criação: retorna uma lista vazia */
Lista2* lst_cria (void)
{
	return NULL;
}

Lista2* ultimo (Lista2* l)
{
	Lista2* p=l;
	if (p!=NULL)
		while (p->prox!=NULL)
			p=p->prox;
	return p;
}

/* inserção no fim: retorna a lista atualizada */
Lista2* lst_insere (Lista2* l, int i)
{
	Lista2* novo = (Lista2*) malloc(sizeof(Lista2));
	novo->info = i;
	novo->prox=NULL;
	Lista2* ult = ultimo (l);
	if (ult==NULL)//lista vazia
		l=novo;
	else //ha elementos na lista
		ult->prox=novo;
	novo->ant=ult;
	return l;
}

/* função imprime: imprime valores dos elementos */
void lst_imprime (Lista2* l)
{
	Lista2* p;
	for (p = l; p != NULL; p = p->prox)
	printf("\n\tinfo = %d\n", p->info);
}