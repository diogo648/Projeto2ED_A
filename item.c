#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

void criarItem(char palavra[], Item **raiz, int lado, int altura) {

	if (*raiz == NULL) {

		Item *aux = (Item*)malloc(sizeof(Item));

		if (aux == NULL) {

			printf("\n Erro! Heap Overflow! \n");
		}
		else {
			strcpy(aux->palavra, palavra);
			aux->quantidade = 1;
			aux->esq = NULL;
			aux->dir = NULL;
			aux->lado = lado;
			aux->altura = altura;
			(*raiz) = aux;
		}
	}
	else if (strcmp(palavra, (*raiz)->palavra) == 0) { // Compara a raiz com a palavra 

		(*raiz)->quantidade++; // Incrementa a quantidade de palavras 
	}

	else if (strcmp(palavra, (*raiz)->palavra) < 0) { // Verifica se a palavra eh maior que a raiz, entra no else se for menor 

		altura = altura + 1;
		criarItem(palavra, &(*raiz)->esq, 1, altura);

		//Comparar a proxima palavra do no
	}
	else {
		altura = altura + 1;
		criarItem(palavra, &(*raiz)->dir, 2, altura);

	}
	
}

void imprimeLinha(Item *raiz,int espaco)
{
	int i;

	if (raiz->altura != 1)
	{
		for (i = 0; i < raiz->altura - 2; i++)
		{
			printf("  ");
		}
		printf("|-");
	}

	printf("%s", raiz->palavra);
	if (raiz->altura == 1)
	{
		printf(" (raiz)\n");
	}
	else
	{
		printf(" (altura %d)\n", raiz->altura);
	}




	/*
	if (raiz->altura != 1)
	{
		for (i = 0; i < raiz->altura-2; i++)
		{
			printf("| ");
		}
		printf("|-");
	}

	printf("%s", raiz->palavra);
	if (raiz->altura == 1)
	{
		printf(" (raiz)\n");
	}
	else
	{
		printf(" (altura %d)\n", raiz->altura);
	}*/
}

/*void imprimeNULL(int altura,int espaco)
{
	int i;

	if (altura != 1)
	{
		//for (i = 0; i < altura - 1; i++)
		//{
		//	printf("  ");
		//}
		//printf("|-");

		//for (i = 0; i < espaco; i++)
		//{
		//	printf("  ");
		//}
		for (i = 0; i < raiz->altura - 2; i++)
		{
			printf("  ");
		}
		printf("|-");
	}

	printf("NULL\n");
}*/

/*void imprime(Item **raiz, Item *AlAnt,int espaco)
{
	if (*raiz)
	{
		imprimeLinha(*raiz,espaco);
		
		espaco = espaco + 1;
		imprime(&(*raiz)->esq,(*raiz),espaco);	
		imprime(&(*raiz)->dir, (*raiz),espaco);
		espaco = espaco - 1;
	
	}
	else if(AlAnt->dir != NULL || AlAnt->esq != NULL)
	{	
		imprimeNULL(AlAnt->altura,espaco);
	}
}*/


void imprimirArv(struct item *raiz){
  
  if(raiz){

    imprimirArv(raiz->esq);
    printf("%d %s \n",raiz->quantidade,raiz->palavra);
    imprimirArv(raiz->dir);

  }
}


void removerItem() {

}

