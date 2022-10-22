#ifndef UTILIDADES_H
#define UTILIDADES_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char cadena[100];

char *leerCadena(char *mensaje){
    char *temp;
    printf("%s",mensaje);
    temp = fgets(cadena,sizeof(cadena),stdin);
    if(temp != NULL){
        cadena[strlen(cadena)-1] = '\0';
    }
    return cadena;
}

int leerInt(char *mensaje){
    int entero;
    printf("%s", mensaje);
    scanf("%i", &entero);
    return entero;
}

int leerSize_t(char *mensaje){
    size_t st;
    printf("%s", mensaje);
    scanf("%zu", &st);
    return st;
}

#endif