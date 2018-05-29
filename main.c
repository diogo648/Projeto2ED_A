#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "item.h"

int main (int argc, char** argv) {
  
no *lista;
Item *item; 
//char * parm1; //Parametro1 passado pelo usuario no terminal
char palavra[20];
  
  while(!feof(stdin)){
     
    scanf("%s",palavra);

    if(!feof(stdin)){

      criarItem(palavra,&item,0,1);
    }
 
  }
 
  lista = percorreArv(item,lista);
  exibeItens(lista);
  
}
