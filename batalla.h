#ifndef BATALLA_H
#define BATALLA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "barco.h"
#include "puerto.h"
#include "utilidades.h"

struct noddo_doble
{
    Barco *dato;
    struct noddo_doble *siguiente;
    struct noddo_doble *anterior;
};
typedef struct noddo_doble NoddoDoble;

NoddoDoble *NodoDDoble_init(Barco *dato){
    NoddoDoble *noddo_doble = (NoddoDoble*)malloc(sizeof(NoddoDoble));

    if(noddo_doble == NULL){
        puts("No se pudo reservar memoria para Nodo");
        return NULL;
    }

    noddo_doble->dato = dato;
    noddo_doble->siguiente = NULL;
    noddo_doble->anterior = NULL;

    return noddo_doble;
}
struct llistaligadadoble{
    NoddoDoble *inicio;
    NoddoDoble *final;
    size_t cantidad;
};
typedef struct llistaligadadoble ColaInt;

ColaInt *ColaInt_init()
{
    ColaInt *colaInt = (ColaInt*)malloc(sizeof(ColaInt));

    if (colaInt == NULL){
        puts("No se reservó memoria para ColaBarcos");
        return NULL;
    }

    colaInt->inicio = NULL;
    colaInt-> final = NULL;
    colaInt->cantidad = 0;

    return colaInt;
}

bool ColaInt_vacia(ColaInt *colaInt)
{
    if(colaInt == NULL){
        puts("ListaLigada no tiene memoria");
        exit(1);
    }
    return colaInt->cantidad == 0;
}

bool ColaInt_encolar(ColaInt *colaInt,Barco *dato)
{
    if (colaInt == NULL){
        puts("Cola no tiene memoria");
        return false;
    }
    if (dato->combustible == 0){
        puts("El barco no tiene combustible");
        return false;
    }

    NoddoDoble *nuevo = NodoDDoble_init(dato);
    if (nuevo == NULL){
        puts("ListaLigada no puedo crear un nuevo Nodo");
        return false;
    }
    if(ColaInt_vacia(colaInt)){
        puts("Modifica la velocidad del barco");
        dato->velocidad = leerFloat("Velocidad: ");
        colaInt->inicio = nuevo;
        colaInt->final = nuevo;
        colaInt->cantidad++;
        return true;
    }
    puts("Modifica la velocidad del barco");
    dato->velocidad = leerFloat("Velocidad: ");
    nuevo->anterior = colaInt->final;
    colaInt->final->siguiente = nuevo;
    colaInt->final = nuevo;
    colaInt->cantidad++;
    return true;
}

bool ColaInt_mostrar(ColaInt *colaInt)
{
    if(colaInt == NULL){
        puts("ListaLigada no tiene memoria");
        return false;
    }

    NoddoDoble *temp = colaInt->inicio;

    while(temp != NULL){
        printf("%-4s %12s %10s %8s\n","Id", "Combustible", "Velocidad", "Armadura");
        if(!Barco_mostrar(temp->dato)){
            puts("Error al mostrar Barco");
        }
        puts("Se mostró Barco");
        puts("-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.");
        temp = temp->siguiente;
    }
    printf("cantidad %zu\n",colaInt->cantidad);
    return true;
}

bool ColaInt_desencolar(ColaInt *colaInt)
{
    if(colaInt == NULL){
        puts("ListaLigada no tiene memoria");
        return false;
    }

    if(ColaInt_vacia(colaInt)){
        puts("ListaLigada esta vacia");
        return false;
    }

    NoddoDoble *temp = colaInt->inicio;
    if(temp->siguiente != NULL){
        temp->siguiente->anterior = NULL;
    }
    else{
        colaInt->final = NULL;
    }

    colaInt->inicio = temp->siguiente;
    colaInt->cantidad--;
    return true;
}

ColaInt *ColaInt_free(ColaInt *colaInt)
{
    if(colaInt == NULL){
        puts("ListaLigada no tiene memoria");
        return NULL;
    }

    while(!ColaInt_vacia(colaInt)){
        ColaInt_desencolar(colaInt);
    }
    free(colaInt);
    colaInt = NULL;
    return colaInt;
}

Barco *ColaInt_tomar(ColaInt *colaInt){
    if (colaInt == NULL){
        puts("Cola no tiene memoria");
        return NULL;
    }
    if(ColaInt_vacia(colaInt)){
        puts("ColaInt está vacia");
        return NULL;
    }
    if (colaInt->inicio->dato->armadura == 0){
        puts("El barco no tiene armadura suficiente, no puede regresar");
        ColaInt_desencolar(colaInt);
        return NULL;
    }
    
    puts("Modifica la armadura del barco");
    colaInt->inicio->dato->armadura = leerFloat("Armadura: ");
    if (colaInt->inicio->dato->armadura == 0){
        puts("El barco no tiene armadura suficiente, no puede regresar");
        ColaInt_desencolar(colaInt);
        return NULL;
    }
    puts("Modifica el combustible del barco");
    colaInt->inicio->dato->combustible = leerFloat("Combustible: ");
    colaInt->inicio->dato->velocidad = 0;
    return colaInt->inicio->dato;

}

typedef ColaInt Batalla;
#define ColaBatalla_init ColaInt_init
#define ColaBatalla_vacia ColaInt_vacia
#define ColaBatalla_encolar ColaInt_encolar
#define ColaBatalla_mostrar ColaInt_mostrar
#define ColaBatalla_desencolar ColaInt_desencolar
#define ColaBatalla_free ColaInt_free
#define ColaBatalla_tomar ColaInt_tomar

Barco *ColaBatalla_lugar(Puerto *puerto){
    int seleccion;
    Nodo_Doble *temp = puerto->inicio;
    if (temp->dato == 0){
        puts("No hay barcos por agregar");
        return NULL;
    }
    puts("Desde donde deseas agregar el barco: ");  
    puts("1. Inicio");
    puts("2. Final");
    seleccion = leerInt("Lugar: ");
    if(seleccion == 1){
        if (temp->dato->combustible == 0){
            puts("Barco sin combustible");
            Puerto_eliminar_inicio(puerto);
            return NULL;
        }
        Puerto_eliminar_inicio(puerto);
        return temp->dato;
    }else if(seleccion == 2){
        Nodo_Doble *temp = puerto->final;
        if (temp->dato->combustible == 0){
            Puerto_eliminar_final(puerto);
            puts("Barco sin combustible");
            return NULL;
        }
        Puerto_eliminar_final(puerto);
        return temp->dato;
    }
    return NULL;
}

#endif
