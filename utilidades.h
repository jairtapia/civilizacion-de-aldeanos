#ifndef UTILIDADES_H_INCLUDED
#define UTILIDADES_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char cadena[100];
char *leerCadena(char *msg){
    char *temp;
    printf("%s\n",msg);
    temp = fgets(cadena, sizeof(cadena),stdin);
    if(temp!=NULL){
        cadena[strlen(cadena)-1] = '\0';
    }
    return cadena;
}

int leerInt(char *msg){
    int entero;
    printf("%s\n",msg);
    scanf("%i",&entero);
    fflush(stdin);

return entero;
}


int leersize_t(char *msg){
    size_t st;
    printf("%s\n",msg);
    scanf("%zu",&st);
    fflush(stdin);

return st;
}


#endif // UTILIDADES_H_INCLUDED
