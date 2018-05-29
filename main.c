#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "item.h"
#include "ST.h"

int main (int argc, char** argv) {
  

//char * parm1; //Parametro1 passado pelo usuario no terminal
no *lista = NULL;
Item *item = NULL;
Item *arvore = NULL;
des *desenho = NULL;
int numeroMaiores;//quantidade de palavras a serem exibidas (escolhido pelo usuario)
char palavra[50];

  while(!feof(stdin)){
     
    scanf("%s",palavra);

    if(!feof(stdin)){

      CriarItem(palavra,&item,0,1);//Cria arvore por ordem alfabetica
    }
 
  }
 
  percorreArv(&arvore, &item);//Cria arvore por ordem de quantidade
  maiores(&arvore,&lista);//Transforma em lista
  exibeItens(lista,numeroMaiores);//Imprime os mais frequentes

  //imprime(&arvore, NULL, desenho, NULL, (variavel com altura maxima para impressao da arvore aqui));
  
  /*lista = percorreArv(item,lista);
  exibeItens(lista);*/
  
}
