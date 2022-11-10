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
        puts("Error civilización sin memoria");
        return civilizacion;
    }
    free(civilizacion->nombre);
    civilizacion->aldeanosLista =AldeanosLista_free(civilizacion->aldeanosLista);
    free(civilizacion);
    civilizacion = NULL;
    return civilizacion;
}

Civilizacion *Civilizacion_capturar(){
    char *nombre = leerCadena("Nombre civilización: ");

    Civilizacion *civilizacion = Civilizacion_init(nombre);

    return civilizacion;
}

bool Civilizacion_mostrar(Civilizacion *civilizacion)
{
    if(civilizacion == NULL){
        puts("Civilización no tiene memoria");
        return false;
    }
    printf("Nombre de la civilización: %s\n",civilizacion->nombre);
    if(AldeanosLista_mostrar_tabla(civilizacion->aldeanosLista)){
        puts("Se mostró AldeanosLista");
    }else
    {
        puts("error al mostrar Aldeanos");
        return false;
    }
    return true;
}


#endif