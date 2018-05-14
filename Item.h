
#ifndef ITEM_H_
#define ITEM_H_

typedef struct tipoItem Item;

struct tipoItem {
 char palavra[]; /* string que contem a palavra do texto*/
 int quantidade;  /* Armazena a quantidade de vezes que a palavra aparece  */
 struct Item *dir,*esq;
};

void CriarItem();
void RemoverItem();

#endif
