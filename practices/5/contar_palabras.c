#include <ctype.h>
#include <stdio.h>
int main (void){
    char frase[1000]=" ";
    int i;
    printf("escribe tu frase ciudadano\n");
    for (i=1; frase[i-1]!='\0';i++){
     scanf("%c",&frase[i]);
    if (frase[i]=='\n'){break;};
    };
    int pos=1,contador=0,relleno=0;
    while (frase[pos-1]!='\0'){
       frase[pos]= toupper(frase[pos]);
      if (frase[pos]>='A' && frase[pos]<='Z'){
           relleno*=1;
      }
      else if ((frase[pos]=='\0')&&((frase[pos+1]>='A') && (frase[pos+1]<='Z'))|| ((frase[pos-1]>='A' && frase[pos-1]<='Z')) ){
        contador+=1;
      };
            pos++;
    };
      printf("Tu frase tiene: %i palabra(s)\n",contador);
};
