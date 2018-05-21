#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (int argc, char** argv) {
  
  
  int i=0;
  char palavra[20];
             
 for (i=1; i< argc; i++) {
     printf("\narg%d=%s", i, argv[i]);
 }
  
  while(!feof(stdin)){
     

    
    scanf("%s",palavra);

    if(!feof(stdin)){
    	printf("%s \n",palavra);
    }
 
  }
  
}
