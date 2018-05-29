
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ST.h"
#include "item.h"

/*
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
}*/
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
/*
no *percorreArv(struct item *raiz, no *lista){ //RAIZ -> ESQ -> DIR

no *aux = NULL;

  if(raiz){

    aux = insereItem(raiz->palavra,raiz->quantidade);
    lista = insereOrdenado(lista,aux);    
    percorreArv(raiz->esq,lista);
    percorreArv(raiz->dir,lista);
    
   }
    
  return lista;
}*/

/*
void exibeItens(no *itens){

  while(itens){
    
    printf("%d %s \n",itens->quantidade,itens->palavra);
    itens = itens->prox;
  }


}*/

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

			printf("%s", (*raiz)->palavra);
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
			else if ((*raiz)->lado == 1 && (*raiz)->dir == NULL && (*raiz)->esq == NULL)
			{
				desenha(desenho);
			}
			else if ((*raiz)->lado == 2 && (*raiz)->esq == NULL && (*raiz)->dir == NULL)
			{
				apaga(&desenho);
				desenha(desenho);
			}
			else if((*raiz)->lado == 1)
			{
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
