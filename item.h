#ifndef ITEM_H_
#define ITEM_H_

struct item {

  char palavra[20]; /* string que contem a palavra do texto*/
  int quantidade;  /* Armazena a quantidade de vezes que a palavra aparece  */
  int lado;
  int altura;
  struct item *dir,*esq;
};

struct tno {

  char palavra[20];
  int quantidade;
  struct tno *prox;
};

typedef struct tno no;

typedef struct item Item;

void criarItem(char palavra[], Item **raiz, int lado, int altura);
no *percorreArv(struct item *raiz, no *lista);
void exibeItens(no *itens);
no *insereOrdenado(no *lista, no *novaLista);
no *insereItem(char palavra[20], int quantidade);
void removerItem();

#endif
