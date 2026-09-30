#include <stdio.h>
#include <stdlib.h>
#include "exercicios.h"

int main()
{
	Lista2* l;
	printf ("\nCriando lista....");
	l = lst_cria();
	printf ("\nInserindo elementos na lista....");
	l = lst_insere (l, 50);
	l = lst_insere (l, 40);
	l = lst_insere (l, 30);
	l = lst_insere (l, 20);
	l = lst_insere (l, 10);
	printf ("\nImprimindo lista original....\n");
		lst_imprime (l);	
	while (1)//coloquei um laco infinito para testar remocao com varios valores
	{
		int x;
		printf ("\nInforme o valor: ");
		scanf ("%d", &x);
		printf ("\nTentando remover o elemento anterior ao elemento %d: ", x);
		l = lst_retira_ant (l, x);
		printf ("\nImprimindo lista novamente apos a remocao (se ocorreu)....\n");
		lst_imprime (l);
	} //while
	system("PAUSE");
	return 1;
}
