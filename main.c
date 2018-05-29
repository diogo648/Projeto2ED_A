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
char *n;
char *fileIn;
char *fileOut;
char *word;

  for (int i=1; i< argc; i++) {

    if(strncmp(argv[i],"-n",2) == 0){ //Delimitar o resultado de busca

      n = strtok(argv[i],"-n");
      numeroMaiores = atoi(n);
    }

    if(strncmp(argv[i],"-r",2) == 0){ //Carregar informacoes da tabela de simbolos de um arquivo

      fileIn = strtok(argv[i],"-r");
      printf("%s ",fileIn);
    }

    if(strncmp(argv[i],"-w",2) == 0){ //Salvar informacoes da tabela de simbolos em um arquivo

       fileOut = strtok(argv[i],"-w");
       printf("%s ",fileOut);
    }

     if(strncmp(argv[i],"-s",2) == 0){ //Buscar palavra especifica

       word = strtok(argv[i],"-s");
       printf("%s ",word);
    }

  }

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
