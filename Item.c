#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "item.h"

void CriarItem(char palavra[50], struct no **raiz){

 if(*raiz == NULL){
 
  (*raiz) = (struct no*) malloc (sizeof(struct no));
   
   if(*raiz == NULL){
   
    printf("\n Erro! Heap Overflow! \n");
   }
   
   else{
   
   strcpy((*raiz)->palavra, palavra);
   (*raiz)->quantidade = 1;
   
   (*raiz)-> esq = NULL;
   (*raiz)-> dir = NULL;
   
   }
  
  if(strcmp((*raiz->palavra),palavra) == 0){ /* Compara a raiz com a palavra */
    
    (*raiz)->quantidade++; /* Incrementa a quantidade de palavras */ 
  } 
  
  if(strcmp((*raiz->palavra),palavra) < 0 || strcmp((*raiz)->prox->palavra,palavra) != 0 || (*raiz)->prox != NULL){ /* Verifica se a palavra eh maior que a raiz, entra no else se for menor */
  
   (*aux) =  (struct no*) malloc (sizeof(struct no));
 
   strcpy(aux-> palavra,palavra); 
   (*aux)->quantidade = 1;
   
   /*Comparar a proxima palavra do no*/
  } 
  
  else{
  
  
  
  }
  if() /* Chama a recursão*/
         
}
  
  
  
  
}


void RemoverItem(){

}
