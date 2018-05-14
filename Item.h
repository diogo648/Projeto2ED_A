
#ifndef ITEM_H_
#define ITEM_H_

struct tipoItem {
 char chave[50]; /* string que contem a palavra do texto*/
 int valor;  /* Armazena a quantidade de vezes que a palavra aparece  */
};

typedef struct tipoItem Item;


void CriarItem();
void RemoverItem();


#endif
