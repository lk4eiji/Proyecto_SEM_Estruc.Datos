#ifndef ALDEANO_H
#define ALDEANO_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utilidades.h"

struct aldeano
{
    char *nombre;
    int edad;
    int salud;
};
typedef struct aldeano Aldeano;

Aldeano *Aldeano_init(char *nombre, int edad, int salud)
{
    Aldeano *aldeano = (Aldeano*)malloc(sizeof(Aldeano));
    if(aldeano != NULL){
        aldeano->nombre = strdup(nombre);
        aldeano->edad = edad;
        aldeano->salud = salud;
    } 

    return aldeano;
} 

Aldeano *Aldeano_free(Aldeano *aldeano)
{
    if(aldeano != NULL){
        free(aldeano->nombre);
        aldeano->nombre = NULL;
        free(aldeano);
        aldeano = NULL;
    }
    return aldeano;
}

bool Aldeano_mostrar(Aldeano *aldeano){
    bool NO_ERROR = false;
    if(aldeano != NULL){
        printf("Nombre: %s\n", aldeano->nombre);
        printf("Edad: %i\n", aldeano->edad);
        printf("Salud: %i\n", aldeano->salud);
        puts("-.-.-.-.-.-.-.-.-.-.-.-.-.-.-");
        NO_ERROR = true;
    }
    return NO_ERROR;
}


bool Aldeano_mostrar_fila(Aldeano *aldeano){
    bool NO_ERROR = false;
    if(aldeano != NULL){
        printf("%-10s %4i %5i \n",aldeano->nombre, aldeano->edad, aldeano->salud); 
        NO_ERROR = true;
    }
    return NO_ERROR;
}

Aldeano *Aldeano_capturar(){
    char *nombre = leerCadena("Nombre: ");
    int edad = leerInt("Edad: "), salud = leerInt("Salud: ");

    Aldeano *aldeano = Aldeano_init(nombre, edad, salud);

    return aldeano;
}

#endif