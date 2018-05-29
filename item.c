#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

void CriarItem(char palavra[], Item **raiz, int lado, int altura) {

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
		CriarItem(palavra, &(*raiz)->esq, 1, altura);

		//Comparar a proxima palavra do no
	}
	else {
		altura = altura + 1;
		CriarItem(palavra, &(*raiz)->dir, 2, altura);

	}// Chama a recursão
	 /**/
}

void CriaArvore(Item **Arvore, char palavra[], int lado, int altura, int quantidade)
{
	if (*Arvore == NULL) {

		Item *aux = (Item*)malloc(sizeof(Item));

		if (aux == NULL) {

			printf("\n Erro! Heap Overflow! \n");
		}
		else {
			strcpy(aux->palavra, palavra);
			aux->quantidade = quantidade;
			aux->esq = NULL;
			aux->dir = NULL;
			aux->lado = lado;
			aux->altura = altura;
			*Arvore = aux;
		}
	}
	else if (quantidade < (*Arvore)->quantidade) { // Verifica se a palavra eh maior que a raiz, entra no else se for menor 

		altura = altura + 1;
		CriaArvore(&(*Arvore)->esq, palavra, 1, altura, quantidade);

		//Comparar a proxima palavra do no
	}
	else if (quantidade >(*Arvore)->quantidade) {
		altura = altura + 1;
		CriaArvore(&(*Arvore)->dir, palavra, 2, altura, quantidade);

	}
	else
	{
		if (strcmp(palavra, (*Arvore)->palavra) > 0)
		{
			altura = altura + 1;
			CriaArvore(&(*Arvore)->esq, palavra, 1, altura, quantidade);
		}
		else if (strcmp(palavra, (*Arvore)->palavra) < 0)
		{
			altura = altura + 1;
			CriaArvore(&(*Arvore)->dir, palavra, 2, altura, quantidade);
		}
	}
}

void percorreArv(Item **Arvore, Item **Alfabetica)
{
	if (*Alfabetica)
	{
		CriaArvore(Arvore, (*Alfabetica)->palavra, 0, 1, (*Alfabetica)->quantidade);
		percorreArv(Arvore, &(*Alfabetica)->esq);
		percorreArv(Arvore, &(*Alfabetica)->dir);
	}
}

/*
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
	}
}*/

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
}


no *insereItem(char palavra[20], int quantidade)
{
	no *item = (no*)malloc(sizeof(no));

        strcpy(item->palavra, palavra);
	item->quantidade = quantidade;
	item->prox = NULL;

	return item;

}

no *insereOrdenado(no *lista, no *novaLista)
{
	no *temp = NULL, *temp1 = lista;
    

	if (temp1 == NULL)
	{
		lista = novaLista;//Se a lista está vazia, os novos dados são a lista
	}
	else
	{
		while (temp1 != NULL && novaLista->quantidade > temp1->quantidade)//Encontra a posição correta na lista
		{

                        
			temp = temp1; 
			temp1 = temp1->prox;
		}

		if (temp == NULL)//Insere na posição correta
		{
			novaLista->prox = lista;
			lista = novaLista;
		}
		else
		{

			novaLista->prox = temp1;
			temp->prox = novaLista;
		}
	}

	return lista;//Retorna a lista ordenada
}



no *percorreArv(struct item *raiz, no *lista){ //RAIZ -> ESQ -> DIR

no *aux = NULL;

  if(raiz){

    aux = insereItem(raiz->palavra,raiz->quantidade);
    lista = insereOrdenado(lista,aux);    
    percorreArv(raiz->esq,lista);
    percorreArv(raiz->dir,lista);
    
   }
    
  return lista;
}


void exibeItens(no *itens){

  while(itens){
    
    printf("%d %s \n",itens->quantidade,itens->palavra);
    itens = itens->prox;
  }


}*/

void removerItem() {

}
