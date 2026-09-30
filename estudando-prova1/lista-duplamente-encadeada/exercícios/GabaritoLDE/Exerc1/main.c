#include <stdio.h>
#include <stdlib.h>
#include "exercicios.h"

int main()
{
	Lista2* l;
	printf ("\nCriando lista....");
	l = lst_cria();
	printf ("\nImprimindo lista....");
	lst_imprime (l);
	printf ("\nInserindo elementos na lista....");
	l = lst_insere (l, 10);
	printf ("\nImprimindo lista....");
	lst_imprime (l);
	l = lst_insere (l, 20);
	printf ("\nImprimindo lista....");
	lst_imprime (l);
	l = lst_insere (l, 30);
	printf ("\nImprimindo lista....");
	lst_imprime (l);
	l = lst_insere (l, 40);
	printf ("\nImprimindo lista....");
	lst_imprime (l);
	l = lst_insere (l, 50);
	printf ("\nImprimindo lista....");
	lst_imprime (l);
	system("PAUSE");
	return 1;
}