#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include "item.h"

int main (int argc, char** argv) {

no *lista = NULL;
Item *item = NULL;
Item *arvore = NULL;
des *desenho = NULL;
int limite;//quantidade de palavras a serem exibidas (escolhido pelo usuario)
int count = 0;
char quantidade[10];
char palavra[50];
char *n;
char fileIn[50];
char fileOut[50];
char word[50];
int flagN=0; //Flag utilizada para verificar se o comando -n foi passado pelo usuario
int flagW=0; //Flag utilizada para verificar se o comando -w foi passado pelo usuario
int flagR=0; //Flag utilizada para verificar se o comando -r foi passado pelo usuario
int flagS=0; //Flag utilizada para verificar se o comando -s foi passado pelo usuario
int flagP=0; //Flag utilizada para verificar se o comando -p foi passado pelo usuario
FILE *fp;

  for (int i=1; i< argc; i++) {

    if(strncmp(argv[i],"-n",2) == 0){ //Delimitar o resultado de busca
	
      flagN = 1; //Comando passado pelo usuario
      n = strtok(argv[i],"-n");
      limite = atoi(n);
    }

    if(strncmp(argv[i],"-r",2) == 0){ //Carregar informacoes da tabela de simbolos de um arquivo
      
      flagR = 1; //Comando passado pelo usuario
      strcpy(fileIn,&argv[i][2]);
      //fileIn = strtok(argv[i],"-r");
    }

    if(strncmp(argv[i],"-w",2) == 0){ //Salvar informacoes da tabela de simbolos em um arquivo

       flagW = 1; //Comando passado pelo usuario
       strcpy(fileOut,&argv[i][2]);
       //fileOut = strtok(argv[i],"-w");
    }

     if(strncmp(argv[i],"-s",2) == 0){ //Buscar palavra especifica
       
       flagS = 1; //Comando passado pelo usuario
       //word = strtok(argv[i],"-s");
	strcpy(word,&argv[i][2]);
    }
     if(strncmp(argv[i],"-p",2) == 0){ //Desenha arvore
       
       flagP = 1; //Comando passado pelo usuario
       n = strtok(argv[i],"-p");
       limite = atoi(n);
    }
  }


  while(!feof(stdin)){
     
    scanf("%s",palavra);

    if(!feof(stdin)){

      CriarItem(palavra,&item,0,1);//Cria arvore por ordem alfabetica
    }
  }

  if(flagN == 1){

     percorreArv(&arvore, &item);//Cria arvore por ordem de quantidade
     maiores(&arvore,&lista);//Transforma em lista
     exibeItens(lista,limite);//Imprime os mais frequentes
  }
  if(flagR == 1 && flagW == 1 || flagR == 0 && flagW == 1){ //Se o usuario passou os dois comandos -r e -w, o -w tem a prioridade
    
    fp=fopen(fileOut,"w");
    while(lista && count <= limite)
    {
        fprintf(fp, "%d %s\n",lista->quantidade, lista->palavra);//Escreve o conteudo da lista no arquivo recem criado
        lista = lista->prox;
	count++;
    }
    fclose(fp);
  }

  if(flagR == 1 && flagW == 0){
    fp = fopen(fileIn,"r");
    while((fscanf(fp,"%s %s",quantidade, palavra)) != EOF)
    {
       //fscanf(fp,"%[^\n]",palavra);
       printf("%s %s\n",quantidade,palavra);
       //count++;
    }
    fclose(fp);
  }

  if(flagS == 1){ //Buscar palavra
	
	struct timeval tempo;
	double inicio, fim;

	gettimeofday(&tempo,NULL);
	inicio = (tempo.tv_sec/1000000) + tempo.tv_usec;

	Item *aux = buscaPalavra(&item, word);

	gettimeofday(&tempo,NULL);
	fim = (tempo.tv_sec/1000000) + tempo.tv_usec;
	
	if (aux)
	{
		printf("Encontrado: %s - Frequencia = %d - Altura = %d - Tempo = %.2lf microssegundo(s)\n",aux->palavra,aux->quantidade,aux->altura,fim - inicio);
	}
	else
	{
		printf("Nao encontrado\n");
	}
  }
  
  if(flagP == 1){
    
    percorreArv(&arvore, &item);//Cria arvore por ordem de quantidade
    imprime(&item, NULL, desenho, NULL, limite);//Imprime tabela de simbolos em formato de arvore
  }
  
}
