#ifndef ITEM_H_
#define ITEM_H_

typedef struct item Item;
typedef struct desenho des;
typedef struct item Item;
typedef struct tno no;

struct desenho
{
	char simbolo;
	des *prox;
};

struct tno
{
	char palavra[50];
	int quantidade;
	no *prox;
};

struct item {

  char palavra[50]; /* string que contem a palavra do texto*/
  int quantidade;  /* Armazena a quantidade de vezes que a palavra aparece  */
  int lado;
  int altura;
  Item *dir,*esq;
};

Item *buscaPalavra(Item **Arvore, char palavra[]);
void CriarItem(char palavra[], Item **raiz, int lado, int altura);
void CriaArvore(Item **Arvore, char palavra[], int lado, int altura, int quantidade);
void percorreArv(Item **Arvore, Item **Alfabetica);
void apaga(des **desenho);
void desenhaArvore(des **desenho, Item *raiz, Item *Anterior, Item **ult, int verifica);
void imprime(Item **raiz, Item *AlAnt, des *desenho, Item *ultimoAltura, int vezes);
void insereOrdenado(no **Lista, char palavra[],int quantidade);
void maiores(Item **arvore, no **Lista);
void exibeItens(no *Lista, int vezes);
void desenha(des *desenho);

#endif
