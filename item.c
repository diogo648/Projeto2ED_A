#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
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

		
	}
	else {
		altura = altura + 1;
		CriarItem(palavra, &(*raiz)->dir, 2, altura);

	}
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

Item *buscaPalavra(Item **Arvore, char palavra[])
{
	if(!(*Arvore))
	{
		return NULL;
	}
	else if(strcmp(palavra,(*Arvore)->palavra) == 0)
	{
		return *Arvore;
	}
	else if(strcmp(palavra,(*Arvore)->palavra) < 0)
	{
		return buscaPalavra(&(*Arvore)->esq,palavra);
	}
	else if(strcmp(palavra,(*Arvore)->palavra) > 0)
	{
		return buscaPalavra(&(*Arvore)->dir,palavra);	
	}
}

void desenha(des *desenho)
{
	if (desenho)
	{
		desenha(desenho->prox);
		printf(" ");
		printf("%c", desenho->simbolo);		
	}
}

void insereOrdenado(no **Lista, char palavra[],int quantidade)
{
	if (!(*Lista))
	{
		no *aux = (no*)malloc(sizeof(no));
		strcpy(aux->palavra, palavra);
		aux->quantidade = quantidade;
		aux->prox = NULL;
		(*Lista) = aux;
	}
	else
	{
		insereOrdenado(&(*Lista)->prox, palavra, quantidade);
	}

}

void exibeItens(no *Lista, int vezes)
{
	if (Lista != NULL && vezes > 0)
	{
		printf("%d %s\n",Lista->quantidade, Lista->palavra);
		exibeItens(Lista->prox, vezes - 1);
	}
}

void apaga(des **desenho)
{
	des *aux;
	if ((*desenho) != NULL && (*desenho)->simbolo == ' ')
	{
		apaga(&(*desenho)->prox);
		aux = (*desenho);
		(*desenho) = (*desenho)->prox;
		free(aux);
	}
	else if ((*desenho) != NULL && (*desenho)->simbolo == '|')
	{
		aux = (*desenho);
		(*desenho) = (*desenho)->prox;
		free(aux);
	}
}

void desenhaArvore(des **desenho, Item *raiz, Item *Anterior, Item **ult, int verifica)
{
	if (raiz->lado == 1 && Anterior->lado == 1)
	{
		des *aux = (des*)malloc(sizeof(des));
		aux->simbolo = '|';
		aux->prox = (*desenho);
		(*desenho) = aux;
		(*ult) = raiz;

	}
	else if (Anterior->lado == 2 && raiz->altura > (*ult)->altura)
	{
		des *aux = (des*)malloc(sizeof(des));
		aux->simbolo = ' ';
		aux->prox = (*desenho);
		(*desenho) = aux;
		(*ult) = raiz;

	}
	else if (Anterior->lado == 1 && raiz->altura > (*ult)->altura)
	{
		des *aux = (des*)malloc(sizeof(des));
		aux->simbolo = '|';
		aux->prox = (*desenho);
		(*desenho) = aux;
		(*ult) = raiz;

	}
	else if (raiz->lado == 2 && raiz->altura < (*ult)->altura)
	{
		apaga(desenho);
		(*ult) = raiz;
	}
	else
	{
		(*ult) = raiz;
	}
}



void imprime(Item **raiz, Item *AlAnt, des *desenho, Item *ultimoAltura, int vezes)
{
	if (*raiz)
	{
		if ((*raiz)->altura <= vezes)
		{
			if ((*raiz)->altura != 1)
			{
				printf(" |-");
			}
			else
			{
				printf(" ");
			}

			printf("%d %s",(*raiz)->quantidade, (*raiz)->palavra);
			if ((*raiz)->altura == 1)
			{
				printf(" (raiz)\n");
			}
			else
			{
				printf(" (altura %d)\n", (*raiz)->altura);
			}

			if ((*raiz)->esq != NULL && (*raiz)->esq->altura <= vezes)
			{
				desenhaArvore(&desenho, (*raiz)->esq, (*raiz), &ultimoAltura, 0);
				desenha(desenho);
			}
			else if ((*raiz)->dir != NULL && (*raiz)->dir->altura <= vezes)
			{
				desenhaArvore(&desenho, (*raiz)->dir, (*raiz), &ultimoAltura, 0);
				desenha(desenho);
			}
			else if((*raiz)->lado == 1)
			{
				desenha(desenho);
			}
			else if((*raiz)->lado == 2)
			{
				apaga(&desenho);
				desenha(desenho);
			}
		}
		imprime(&(*raiz)->esq, (*raiz), desenho, ultimoAltura, vezes);
		imprime(&(*raiz)->dir, (*raiz), desenho, ultimoAltura, vezes);

	}
	else if (AlAnt->dir != NULL || AlAnt->esq != NULL)
	{
		if (AlAnt->altura + 1 <= vezes)
		{
			printf(" ");
			printf("|-NULL");
			printf(" (altura %d)\n", ultimoAltura->altura);
			if (ultimoAltura->lado == 1 && ultimoAltura->altura > AlAnt->altura)
			{
				apaga(&desenho);
			}
			desenha(desenho);
		}
	}
}

void maiores(Item **arvore, no **Lista)
{
	if (*arvore)
	{
		maiores(&(*arvore)->dir,Lista);
		insereOrdenado(Lista, (*arvore)->palavra, (*arvore)->quantidade);
		maiores(&(*arvore)->esq, Lista);
	}
}
