#ifndef PILAGUERREROS_H
#define PILAGUERREROS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "guerrero.h"

struct nodo{
    Guerrero *dato;
    struct nodo *siguiente;
};
typedef struct nodo Nodo;

Nodo *Nodo_init(Guerrero *dato){
    Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));

    if(nodo == NULL){
        puts("No se pudo reservar memoria para Nodo");
        return NULL;
    }

    nodo->dato = dato;
    nodo->siguiente = NULL;

    return nodo;
}

struct listaligada{
    Nodo *raiz;
    size_t cantidad;
};
typedef struct listaligada Pila;

Pila *Pila_init(){
    Pila *pila = (Pila*)malloc(sizeof(Pila));

    if (pila == NULL){
        puts("No se reservó memoria para Pila");
        return NULL;
    }

    pila->raiz = NULL;
    pila->cantidad = 0;

    return pila;
}

bool Pila_vacia(Pila *pila){
    if(pila == NULL){
        puts("Pila no tiene memoria");
        exit(1);
    }
    return pila->cantidad == 0;
}

bool Pila_apilar(Pila *pila, Guerrero *dato){
    if (pila == NULL){
        puts("Pila no tiene memoria");
        return false;
    }

    Nodo *nuevo = Nodo_init(dato);
    if (nuevo == NULL){
        puts("Pila no puedo crear un nuevo Nodo");
        return false;
    }
    
    nuevo->siguiente = pila->raiz;
    pila->raiz = nuevo;
    pila->cantidad++;
    return true;
}

bool Pila_mostrar(Pila *pila){
    if(pila == NULL){
        puts("ListaLigada no tiene memoria");
        return false;
    }

    Nodo *temp = pila->raiz;

    while(temp != NULL){
        printf("Id Guerrero: %zu\n", temp->dato->id);
        printf("Salud: %i\n", temp->dato->salud);
        printf("Fuerza: %.2f\n", temp->dato->fuerza);
        printf("Escudo: %.2f\n", temp->dato->escudo);
        printf("Tipo: %s\n", temp->dato->tipo);
        temp = temp->siguiente;
    }
    printf("cantidad de Guerreros: %zu\n",pila->cantidad);
    puts("");
    return true;
}

bool Pila_desapilar(Pila *pila){
    if(pila == NULL){
        puts("Pila no tiene memoria");
        return false;
    }

    if(Pila_vacia(pila)){
        puts("Pila esta vacía");
        return false;
    }

    Nodo *temp = pila->raiz;
    pila->raiz = temp->siguiente;
    free(temp);
    temp = NULL;
    pila->cantidad--;
    return true;
}

Pila *Pila_free(Pila *pila){
    if(pila == NULL){
        puts("Pila no tiene memoria");
        return NULL;
    }

    while(!Pila_vacia(pila)){
        Pila_desapilar(pila);
    }
    free(pila);
    pila = NULL;
    return pila;
}

bool *Pila_tope(Pila *pila){
    if (pila == NULL){
        puts("Pila no tiene memoria");
        return false;
    }

    if (Pila_vacia(pila)){
        puts("Pila está vacía");
        return false;
    }
    
    printf("Id Guerrero: %zu\n", pila->raiz->dato->id);
    printf("Salud: %i\n", pila->raiz->dato->salud);
    printf("Fuerza: %.2f\n", pila->raiz->dato->fuerza);
    printf("Escudo: %.2f\n", pila->raiz->dato->escudo);
    printf("Tipo: %s\n", pila->raiz->dato->tipo);
    return true;
}

typedef Pila PilaGuerreros;
#define PilaGuerreros_init Pila_init
#define PilaGuerreros_apilar Pila_apilar
#define PilaGuerreros_mostrar Pila_mostrar
#define PilaGuerreros_desapilar Pila_desapilar
#define PilaGuerreros_free Pila_free
#define PilaGuerreros_tope Pila_tope

#endif