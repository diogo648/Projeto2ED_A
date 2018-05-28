#ifndef ITEM_H_
#define ITEM_H_

struct item {
  char palavra[20]; /* string que contem a palavra do texto*/
  int quantidade;  /* Armazena a quantidade de vezes que a palavra aparece  */
  int lado;
  int altura;
  struct item *dir,*esq;
};

typedef struct item Item;

void criarItem(char palavra[], Item **raiz, int lado, int altura);
void imprimirArv(struct item *raiz);
void removerItem();

#endif
