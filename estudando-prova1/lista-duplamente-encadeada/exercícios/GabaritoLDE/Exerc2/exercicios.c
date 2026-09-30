#include <stdio.h>
#include <stdlib.h>
#include "exercicios.h"

/* função de criação: retorna uma lista vazia */
Lista2* lst_cria (void)
{
	return NULL;
}

/* função busca: busca um elemento na lista */
Lista2* lst_busca (Lista2* l, int v)
{
	Lista2* p;
	for (p=l; p!=NULL; p=p->prox)
		if (p->info == v)
			return p;
	return NULL; /* não achou o elemento */
}

/* inserção no início: retorna a lista atualizada */
Lista2* lst_insere (Lista2* l, int v)
{
	Lista2* novo = (Lista2*) malloc(sizeof(Lista2));
	novo->info = v;
	novo->prox = l;
	novo->ant = NULL;
	/* verifica se lista não estava vazia */
	if (l != NULL)
		l->ant = novo;
	return novo;
}

/* função imprime: imprime valores dos elementos */
void lst_imprime (Lista2* l)
{
	Lista2* p;
	for (p = l; p != NULL; p = p->prox)
		printf("\tinfo = %d\n", p->info);
}

Lista2* lst_retira (Lista2* l, int v)
{
	Lista2* p = lst_busca(l,v);
	if (p == NULL)
		return l; /* não achou o elemento: retorna lista inalterada */
	/* retira elemento do encadeamento */
	if (l == p) /* testa se é o primeiro elemento */
		l = p->prox;
	else
		p->ant->prox = p->prox;
	if (p->prox != NULL) /* testa se é o último elemento */
		p->prox->ant = p->ant;
	free(p);
	return l;
}

/* função retira: retira elemento anterior da lista */
Lista2* lst_retira_ant (Lista2* l, int v)
{
	Lista2* p = l; /* ponteiro para percorrer a lista */
	if (p==NULL || p->info==v) //lista estah vazia ou quer remover o nó anterior ao inicio
	{
		printf ("\nRemocao nao serah realizada, retorna lista original....");
		return l;
	}
	Lista2* ant = NULL;
	while (p!=NULL && p->info!=v)//procura elemento
	{
		ant=p;
		p=p->prox;
	}
	if (p!=NULL)//encontrou o valor v passado em p, logo remove o anterior a ele
	{
		printf ("\nVai remover o valor %d", ant->info);
		l=lst_retira(l, ant->info);//manda remover o anterior ao valor passado
   }
	return l;		
}
