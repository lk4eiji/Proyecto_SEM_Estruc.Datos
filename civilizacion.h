#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include <stdio.h>
#include <stdlib.h>
#include "aldeanos_lista.h"
#include "puerto.h"
#include "batalla.h"

struct civilizacion
{
    char *nombre;
    AldeanosLista *aldeanosLista;
    Puerto *puerto;
    Batalla *batalla;
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
    civilizacion->puerto = Puerto_init();
    civilizacion->batalla = ColaBatalla_init();

    return civilizacion;
}

Civilizacion *Civilizacion_free(Civilizacion *civilizacion){
    if (civilizacion == NULL){
        puts("Error civilización sin memoria");
        return civilizacion;
    }
    free(civilizacion->nombre);
    civilizacion->aldeanosLista =AldeanosLista_free(civilizacion->aldeanosLista);
    civilizacion->puerto = Puerto_free(civilizacion->puerto);
    civilizacion->batalla = ColaBatalla_free(civilizacion->batalla);
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

bool Civilizacion_respaldar(Civilizacion *civilizacion, FILE *archivo){
    if (civilizacion == NULL){
        puts("Civilización no tiene memoria");
        return false;
    }
    if (archivo == NULL){
        puts("Archivo nulo");
        return false;
    }
    
    fprintf(archivo,"%s\n",civilizacion->nombre);
    char nombre_archivo[100];
    strcpy(nombre_archivo, civilizacion->nombre);
    strcat(nombre_archivo, ".txt");
    AldeanosLista_respaldar(civilizacion->aldeanosLista, nombre_archivo);
    return true;
}

Civilizacion *Civilizacion_recuperar(FILE *archivo){
    if (archivo == NULL){
        puts("Archivo nulo");
        return NULL;
    }

    char buffer[100];
    fgets(buffer,100,archivo);
    buffer[strlen(buffer)-1] = '\0';
    if (feof(archivo)) return NULL;
    
    Civilizacion *civilizacion = Civilizacion_init(buffer);
    char nombre_archivo[100];
    strcpy(nombre_archivo, civilizacion->nombre);
    strcat(nombre_archivo, ".txt");
    AldeanosLista_recuperar(civilizacion->aldeanosLista,nombre_archivo);
    return civilizacion;
}

#endif