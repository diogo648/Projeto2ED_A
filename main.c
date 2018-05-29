#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "item.h"
#include "ST.h"

int main (int argc, char** argv) {

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
int flagW=0; //Flag utilizada para verificar se o comando -w foi passado pelo usuario
int flagR=0; //Flag utilizada para verificar se o comando -r foi passado pelo usuario
int flagS=0; //Flag utilizada para verificar se o comando -s foi passado pelo usuario
FILE *fp;

  for (int i=1; i< argc; i++) {

    if(strncmp(argv[i],"-n",2) == 0){ //Delimitar o resultado de busca

      n = strtok(argv[i],"-n");
      numeroMaiores = atoi(n);
    }

    if(strncmp(argv[i],"-r",2) == 0){ //Carregar informacoes da tabela de simbolos de um arquivo
      
      flagR = 1; //Comando passado pelo usuario
      fileIn = strtok(argv[i],"-r");
    }

    if(strncmp(argv[i],"-w",2) == 0){ //Salvar informacoes da tabela de simbolos em um arquivo

       flagW = 1; //Comando passado pelo usuario
       fileOut = strtok(argv[i],"-w");
    }

     if(strncmp(argv[i],"-s",2) == 0){ //Buscar palavra especifica
       
       flagS = 1; //Comando passado pelo usuario
       word = strtok(argv[i],"-s");
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

  if(flagR == 1 && flagW == 1 || flagR == 0 && flagW == 1){ //Se o usuario passou os dois comandos -r e -w, o -w tem a prioridade
    
    fp=fopen(fileOut,"w");
    fprintf(fp, "Teste!!!!!");//Escreve o conteudo da lista no arquivo recem criado
    fclose(fp);
  }

  if(flagR == 1 && flagW == 0){
    
    fp=fopen(fileIn,"r");
    fclose(fp);
  }

  if(flagS == 1){ //Buscar palavra

  }


  //imprime(&arvore, NULL, desenho, NULL, (variavel com altura maxima para impressao da arvore aqui));
  
}
