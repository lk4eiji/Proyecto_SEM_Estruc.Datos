#ifndef ALDEANOS_LISTA_H
#define ALDEANOS_LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include "aldeano.h"
#define CAPACIDAD 3

struct aldeanos_lista
{
    Aldeano **aldeanos;
    size_t cantidad;
    size_t capacidad;
};
typedef struct aldeanos_lista AldeanosLista;

AldeanosLista *aldeanosLista_init(){
    AldeanosLista *aldeanosLista;
    aldeanosLista = (AldeanosLista*)malloc(sizeof(AldeanosLista));
    if(aldeanosLista != NULL){
        aldeanosLista->aldeanos = (Aldeano**)malloc(sizeof(Aldeano*)*CAPACIDAD);
        if(aldeanosLista->aldeanos == NULL){
            puts("Error al crear el arreglo");
            exit(1);
        }
        aldeanosLista->capacidad = CAPACIDAD;
        aldeanosLista->cantidad = 0;
    }
    return aldeanosLista; 
}

AldeanosLista *AldeanosLista_free(AldeanosLista *aldeanosLista){
    if(aldeanosLista != NULL){
        if(aldeanosLista->aldeanos != NULL){
            for (size_t i = 0; i < aldeanosLista->cantidad; i++)
            {
                Aldeano_free(aldeanosLista->aldeanos[i]);
                aldeanosLista->aldeanos[i] = NULL;
            }
            
        }
        free(aldeanosLista);
        aldeanosLista = NULL;
    }

    return aldeanosLista;
}

bool AldeanosLista_llena(AldeanosLista *aldeanosLista){
    if (aldeanosLista == NULL)
    {
        puts("No tiene memoria AldeanosLista");
        exit(1);
    }

    return aldeanosLista->cantidad == aldeanosLista->capacidad;
    
}

bool AldeanosLista_expandir(AldeanosLista *aldeanosLista){
    bool NO_ERROR = false;
    if (aldeanosLista != NULL){
        size_t nuevaCapacidad = aldeanosLista->capacidad + CAPACIDAD;
        Aldeano **temp_p = (Aldeano**)realloc(aldeanosLista->aldeanos,
                                    sizeof(Aldeano*)*nuevaCapacidad);
        if(temp_p != NULL){
            puts("Se expandio AldeanosLista");
            aldeanosLista->aldeanos = temp_p;
            aldeanosLista->capacidad = nuevaCapacidad;
            NO_ERROR = true;
        }else{
            puts("No fue posible expandir");
        }
    }
    return NO_ERROR;
}

bool AldeanosLista_agregar_final(AldeanosLista *aldeanosLista,
                                  Aldeano *aldeano)
{
    bool NO_ERROR = false;
    if (aldeanosLista != NULL)
    {
        if(AldeanosLista_llena(aldeanosLista)){
            AldeanosLista_expandir(aldeanosLista);
        }
        aldeanosLista->aldeanos[aldeanosLista->cantidad] = aldeano;
        aldeanosLista->cantidad++;
        NO_ERROR = true;
    }
    return NO_ERROR;
}

bool AldeanosLista_agregar_inicio(AldeanosLista *aldeanosLista,
                                  Aldeano *aldeano)
{
    bool NO_ERROR = false;
    if (aldeanosLista != NULL)
    {
        if(AldeanosLista_llena(aldeanosLista)){
            AldeanosLista_expandir(aldeanosLista);
        }
        for (size_t i = aldeanosLista->cantidad; i > 0; i--){
            aldeanosLista->aldeanos[i] = aldeanosLista->aldeanos[i-1];
        }
        aldeanosLista->aldeanos[0] = aldeano;
        aldeanosLista->cantidad++;
        NO_ERROR = true;
    }
    return NO_ERROR;
}

bool AldeanosLista_insertar(AldeanosLista *aldeanosLista,
                                  Aldeano *aldeano,
                                  size_t posicion)
{
    bool NO_ERROR = false;
    if (aldeanosLista != NULL)
    {
        if(AldeanosLista_llena(aldeanosLista)){
            AldeanosLista_expandir(aldeanosLista);
        }
        for (size_t i = aldeanosLista->cantidad; i > posicion; i--){
            aldeanosLista->aldeanos[i] = aldeanosLista->aldeanos[i-1];
        }
        aldeanosLista->aldeanos[posicion] = aldeano;
        aldeanosLista->cantidad++;
        NO_ERROR = true;
    }
    return NO_ERROR;
}

bool AldeanosLista_mostrar(AldeanosLista *aldeanosLista){
    bool NO_ERROR = false;
    if (aldeanosLista != NULL){
        printf("Cantidad: %zu, capacidad: %zu\n",aldeanosLista->cantidad,
                                               aldeanosLista->capacidad);
        for (size_t i = 0; i < aldeanosLista->cantidad; i++)
        {
            Aldeano_mostrar(aldeanosLista->aldeanos[i]);
        }
        printf("\n");
        NO_ERROR = true;
    }
    return NO_ERROR;
}

bool AldeanosLista_mostrar_tabla(AldeanosLista *aldeanosLista){
    bool NO_ERROR = false;
    if (aldeanosLista != NULL){
        printf("%-10s %4s %5s\n","Nombre", "Edad", "Salud");
        for (size_t i = 0; i < aldeanosLista->cantidad; i++)
        {
            Aldeano_mostrar_fila(aldeanosLista->aldeanos[i]);
        }
        printf("Cantidad: %zu, capacidad: %zu\n",aldeanosLista->cantidad,
                                               aldeanosLista->capacidad);
        NO_ERROR = true;
    }
    return NO_ERROR;
}

bool AldeanosLista_vacia(AldeanosLista *aldeanosLista){
    if (aldeanosLista == NULL){
        puts("No tiene memoria AldeanosLista");
        exit(1);
    }
    return aldeanosLista->cantidad == 0;
}

bool AldeanosLista_eliminar_final(AldeanosLista *aldeanosLista){
    bool NO_ERROR = false;
    if (aldeanosLista != NULL){
        if (!AldeanosLista_vacia(aldeanosLista)){
            size_t ultimaPosicion = aldeanosLista->cantidad-1;
            Aldeano_free(aldeanosLista->aldeanos[ultimaPosicion]);
            aldeanosLista->aldeanos[ultimaPosicion] = NULL;
            aldeanosLista->cantidad--;
            NO_ERROR = true;
        }
        
    }
    return NO_ERROR;
}

bool AldeanosLista_eliminar_inicio(AldeanosLista *aldeanosLista){
    bool NO_ERROR = false;
    if (aldeanosLista != NULL){
        if (!AldeanosLista_vacia(aldeanosLista)){
            aldeanosLista->aldeanos[0] = 
            Aldeano_free(aldeanosLista->aldeanos[0]);
            if (aldeanosLista->aldeanos[0] == NULL){
                for (size_t i = 0; i < aldeanosLista->cantidad; i++){
                    aldeanosLista->aldeanos[i] = aldeanosLista->aldeanos[i+1];
                }
                puts("Se liberó Aldeano");
                aldeanosLista->cantidad--;
                NO_ERROR = true;
            }else{
                puts("Error al liberar Aldeano");
            }
        }
        
    }
    return NO_ERROR;
}

bool AldeanosLista_eliminar(AldeanosLista *aldeanosLista, size_t posicion){
    bool NO_ERROR = false;
    if (posicion >= aldeanosLista->cantidad){
        return NO_ERROR;
    }
    if (aldeanosLista != NULL){
        if (!AldeanosLista_vacia(aldeanosLista)){
            aldeanosLista->aldeanos[posicion] = 
            Aldeano_free(aldeanosLista->aldeanos[posicion]);
            if (aldeanosLista->aldeanos[posicion] == NULL){
                for (size_t i = posicion; i < aldeanosLista->cantidad-1; i++){
                    aldeanosLista->aldeanos[i] = aldeanosLista->aldeanos[i+1];
                }
                puts("Se liberó Aldeano");
                aldeanosLista->cantidad--;
                NO_ERROR = true;
            }else{
                puts("Error al liberar Aldeano");
            }
        }
        
    }
    return NO_ERROR;
}

#endif