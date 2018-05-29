#ifndef ITEM_H_
#define ITEM_H_

typedef struct item Item;

struct item {

  char palavra[50]; /* string que contem a palavra do texto*/
  int quantidade;  /* Armazena a quantidade de vezes que a palavra aparece  */
  int lado;
  int altura;
  Item *dir,*esq;
};

void CriarItem(char palavra[], Item **raiz, int lado, int altura);
void CriaArvore(Item **Arvore, char palavra[], int lado, int altura, int quantidade);
void percorreArv(Item **Arvore, Item **Alfabetica);
/*
no *percorreArv(struct item *raiz, no *lista);
void exibeItens(no *itens);
no *insereOrdenado(no *lista, no *novaLista);
no *insereItem(char palavra[20], int quantidade);*/
void removerItem();

#endif
