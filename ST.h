
#ifndef ST_H_
#define ST_H_

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

void apaga(des **desenho);
void desenhaArvore(des **desenho, Item *raiz, Item *Anterior, Item **ult, int verifica);
void imprime(Item **raiz, Item *AlAnt, des *desenho, Item *ultimoAltura, int vezes);
void insereOrdenado(no **Lista, char palavra[],int quantidade);
void maiores(Item **arvore, no **Lista);
void exibeItens(no *Lista, int vezes);
void desenha(des *desenho);

#endif
