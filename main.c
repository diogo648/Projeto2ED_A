#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "item.h"

int main (int argc, char** argv) {
  
  Item *item; 

  int i;
  char palavra[20];
             
 for (i=1; i< argc; i++) {
     printf("\narg%d=%s", i, argv[i]);
 }
  
  
  /*switch (argv[i]){
      
       case "-n":
       case "-w":
       case: "-r":
       case: "pMAX":
      
      
      
  }*/
  
while(!feof(stdin)){
     
  scanf("%s",palavra);

  if(!feof(stdin)){
   
    //printf("%s \n", palavra);
    criarItem(palavra,&item,0,1);
  }
 
}

imprimirArv(item);
  
}
