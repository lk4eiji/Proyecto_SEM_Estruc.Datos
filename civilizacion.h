#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include <stdio.h>
#include <stdlib.h>
#include "aldeanos_lista.h"

struct civilizacion
{
    char *nombre;
    AldeanosLista *aldeanosLista;
};
typedef struct civilizacion Civilizacion;

Civilizacion *Civilizacion_init(char *nombre){
    Civilizacion *civilizacion = (Civilizacion*)malloc(sizeof(Civilizacion));
    if (civilizacion == NULL)
    {
        puts("Error al reservar memoria");
        return civilizacion;
    }
    civilizacion->nombre = strdup(nombre);
    civilizacion->aldeanosLista = aldeanosLista_init();

    return civilizacion;
}

Civilizacion *Civilizacion_free(Civilizacion *civilizacion){
    if (civilizacion == NULL){
        puts("Error civilizacion sin memoria");
        return civilizacion;
    }
    free(civilizacion->nombre);
    civilizacion->aldeanosLista =AldeanosLista_free(civilizacion->aldeanosLista);
    free(civilizacion);
    civilizacion = NULL;
    return civilizacion;
}


#endif