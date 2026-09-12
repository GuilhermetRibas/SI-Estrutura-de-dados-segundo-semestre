#include <stdio.h>
#include <stdlib.h>

struct lista{
	int info;
	struct lista* prox;
};
typedef struct lista Lista;

Lista* ultimo (Lista* l)
{
	Lista* p=l;
	if (p!=NULL)
		while (p->prox!=l)
			p=p->prox;
	return p;
}

void lst_imprime (Lista* l)
{
	Lista* p = l;
    if (l==NULL)
    	printf ("\nLista vazia\n");
	if (p!=NULL)
		do{
			printf ("\t%d", p->info);
			p=p->prox;
		}while (p!=l);
	if (l!=NULL)
		printf ("\n\tO primeiro no eh %d, o ultimo eh %d e o proximo do ultimo eh %d\n", l->info, ultimo(l)->info, ultimo(l)->prox->info);	
}

Lista* lst_insere (Lista* l, int i)
{
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	Lista* ult=ultimo (l);
	novo->info = i;
	if (ult==NULL) //lista vazia
		novo->prox = novo;
	else//lista nao vazia
	{
		novo->prox=l;
		ult->prox=novo;
	}
	return novo;
}

Lista* retira (Lista* l, int v)
{
	if (l == NULL) {//lista vazia
        return l;
    }
	Lista* p =l;
    Lista* ant = NULL;
    while (p->info != v) //procura elemento
	{
        if (p->prox == l) // O elemento não foi encontrado na lista
            return l;
        ant = p;
        p = p->prox;
    }
    //encontrou elemento a ser removido
    if (ant == NULL)  // Se o elemento a ser removido é o primeiro nó
	{
        Lista* ult = ultimo (l);
        if (ult==l)//soh tem um no
	        l=NULL;
	    else//tem mais de um no
	    {
	    	l=l->prox;
        	ult->prox = l;
		}
    } 
	else //se o elemento a ser removido eh no meio ou fim
        ant->prox = p->prox;
    free(p);
    return l;
}	
		
main()
{
	Lista* l=NULL;
	l=lst_insere (l, 1);
	l=lst_insere (l, 2);
	l=lst_insere (l, 3);
	l=lst_insere (l, 4);
   	l=lst_insere (l, 5);
   	printf ("\nLista: ");
    lst_imprime (l);	
	int elemento;
	while (1)//laco infinito para testar multiplas remocoes
	{
		printf ("\nDigite o elemento a retirar: ");
		scanf ("%d", &elemento);
		l =  retira (l, elemento);	
		lst_imprime (l);	
	}	
}

