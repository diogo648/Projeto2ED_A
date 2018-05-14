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
        
}
  
  
  
  
}


void RemoverItem(){

}
