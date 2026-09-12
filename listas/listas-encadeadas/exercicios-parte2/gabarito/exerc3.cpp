#include <stdio.h>
#include <stdlib.h>

struct Lista{
   int info;
   struct Lista* prox;
};

Lista* criar(void){
   return NULL;
}

bool vazia(Lista* lista){
     return (lista == NULL);
}

Lista* inserirInicio(Lista* lista, int elemento){
   Lista* novoNo = (Lista*) malloc(sizeof(Lista));
   novoNo->info = elemento;
   novoNo->prox = lista;
   return novoNo;
}

Lista* ultimo (Lista* l)
{
	Lista* p=l;
	if (p!=NULL)
		while (p->prox!=NULL)
			p=p->prox;
	return p;
}

/* inserção no fim: retorna a lista atualizada */
Lista* inserirFim (Lista* l, int i)
{
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = i;
	novo->prox=NULL;
	Lista* ult = ultimo (l);
	if (ult==NULL)//lista vazia
		l=novo;
	else //ha elementos na lista
		ult->prox=novo;
	return l;
}

void imprimir(Lista* l){
	Lista* p;
	for (p=l; p!=NULL; p=p->prox)
		printf ("\n%d", p->info);
}

Lista* merge(Lista* l1, Lista* l2){
	Lista* resultante = criar();
	Lista* tl1 = l1;
	Lista* tl2 = l2;
	while (!(vazia(tl1) && vazia(tl2)))//eqnto as 2 listas nao ficarem vazias
	{
		if (!vazia(tl1)){
	    	resultante = inserirFim(resultante, tl1->info);
		    tl1 = tl1->prox;
		}
		if (!vazia(tl2)){
			resultante = inserirFim(resultante, tl2->info);
			tl2 = tl2->prox;
		}
	}
	return resultante;
}

int main(){
    printf("\nLista 1: ");
	Lista* l1 = criar();
    l1 = inserirInicio(l1, 9);	
    l1 = inserirInicio(l1, 7);
    l1 = inserirInicio(l1, 5);
    l1 = inserirInicio(l1, 3);
    l1 = inserirInicio(l1, 1);
    imprimir(l1);
    printf("\nLista 2: ");
    Lista* l2 = criar();
    l2 = inserirInicio(l2, 6);
    l2 = inserirInicio(l2, 4);
    l2 = inserirInicio(l2, 2);
    imprimir(l2);
    printf("\nLista 3: ");
    Lista* l3 = merge(l1, l2);
    imprimir(l3);
    system ("pause");
}

   