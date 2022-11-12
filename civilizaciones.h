#ifndef CIVILIZACIONES_H
#define CIVILIZACIONES_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "civilizacion.h"

struct nodo_doble
{
    Civilizacion *dato;
    struct nodo_doble *siguiente;
    struct nodo_doble *anterior;
};
typedef struct nodo_doble NodoDoble;

NodoDoble *NodoDoble_init(Civilizacion *dato)
{
    NodoDoble *nodo_doble = (NodoDoble*)malloc(sizeof(NodoDoble));

    if(nodo_doble == NULL){
        puts("No se pudo reservar memoria para Nodo");
        return NULL;
    }

    nodo_doble->dato = dato;
    nodo_doble->siguiente = NULL;
    nodo_doble->anterior = NULL;

    return nodo_doble;
}

struct listaligadadoble
{
    NodoDoble *inicio;
    NodoDoble *final;
    size_t cantidad;
};
typedef struct listaligadadoble ListaLigadaDoble;

ListaLigadaDoble *ListaLigadaDoble_init()
{
    ListaLigadaDoble *listaLigadaDoble = (ListaLigadaDoble*)malloc(sizeof(ListaLigadaDoble));

    if (listaLigadaDoble == NULL){
        puts("No se reservó memoria para ListaLigadaDoble");
        return NULL;
    }

    listaLigadaDoble->inicio = NULL;
    listaLigadaDoble-> final = NULL;
    listaLigadaDoble->cantidad = 0;

    return listaLigadaDoble;
}

bool ListaLigadaDoble_vacia(ListaLigadaDoble *listaLigadaDoble)
{
    if(listaLigadaDoble == NULL){
        puts("ListaLigada no tiene memoria");
        exit(1);
    }
    return listaLigadaDoble->cantidad == 0;
}

bool ListaLigadaDoble_insertar_inicio(ListaLigadaDoble *listaLigadaDoble,Civilizacion *dato)
{
    if (listaLigadaDoble == NULL){
        puts("ListaLigada no tiene memoria");
        return false;
    }

    NodoDoble *nuevo = NodoDoble_init(dato);
    if (nuevo == NULL){
        puts("ListaLigada no puedo crear un nuevo Nodo");
        return false;
    }
    if(ListaLigadaDoble_vacia(listaLigadaDoble)){
        listaLigadaDoble->inicio = nuevo;
        listaLigadaDoble->final = nuevo;
        listaLigadaDoble->cantidad++;
        return true;
    }

    nuevo->siguiente = listaLigadaDoble->inicio;
    listaLigadaDoble->inicio->anterior = nuevo;
    listaLigadaDoble->inicio = nuevo;
    listaLigadaDoble->cantidad++;
    return true;
}

bool ListaLigadaDoble_insertar_final(ListaLigadaDoble *listaLigadaDoble,Civilizacion *dato)
{
    if (listaLigadaDoble == NULL){
        puts("ListaLigada no tiene memoria");
        return false;
    }

    NodoDoble *nuevo = NodoDoble_init(dato);
    if (nuevo == NULL){
        puts("ListaLigada no puedo crear un nuevo Nodo");
        return false;
    }
    if(ListaLigadaDoble_vacia(listaLigadaDoble)){
        listaLigadaDoble->inicio = nuevo;
        listaLigadaDoble->final = nuevo;
        listaLigadaDoble->cantidad++;
        return true;
    }

    nuevo->anterior = listaLigadaDoble->final;
    listaLigadaDoble->final->siguiente = nuevo;
    listaLigadaDoble->final = nuevo;
    listaLigadaDoble->cantidad++;
    return true;
}

bool ListaLigadaDoble_mostrar(ListaLigadaDoble *listaLigadaDoble)
{
    if(listaLigadaDoble == NULL){
        puts("ListaLigada no tiene memoria");
        return false;
    }

    printf("cantidad %zu\n",listaLigadaDoble->cantidad);
    NodoDoble *temp = listaLigadaDoble->inicio;

    while(temp != NULL){
        if(Civilizacion_mostrar(temp->dato)){
            puts("Se mostró Civilizaciones");
            puts("-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.");
        }else puts("Error al mostrar Civilizacion");
        temp = temp->siguiente;
    }

    return true;
}

bool ListaLigadaDoble_eliminar_inicio(ListaLigadaDoble *listaLigadaDoble)
{
    if(listaLigadaDoble == NULL){
        puts("ListaLigada no tiene memoria");
        return false;
    }

    if(ListaLigadaDoble_vacia(listaLigadaDoble)){
        puts("ListaLigada esta vacia");
        return false;
    }

    NodoDoble *temp = listaLigadaDoble->inicio;
    if(temp->siguiente != NULL){
        temp->siguiente->anterior = NULL;
    }
    else{
        listaLigadaDoble->final = NULL;
    }

    listaLigadaDoble->inicio = temp->siguiente;
    listaLigadaDoble->cantidad--;
    Civilizacion_free(temp->dato);
    free(temp);
    temp = NULL;
    return true;
}

bool ListaLigadaDoble_eliminar_final(ListaLigadaDoble *listaLigadaDoble)
{
    if(listaLigadaDoble == NULL){
        puts("ListaLigada no tiene memoria");
        return false;
    }

    if(ListaLigadaDoble_vacia(listaLigadaDoble)){
        puts("ListaLigada esta vacia");
        return false;
    }

    NodoDoble *temp = listaLigadaDoble->final;
    if(temp->anterior != NULL){
        temp->anterior->siguiente = NULL;
    }
    else{
        listaLigadaDoble->inicio = NULL;
    }

    listaLigadaDoble->final = temp->anterior;
    listaLigadaDoble->cantidad--;
    Civilizacion_free(temp->dato);
    free(temp);
    temp = NULL;
    return true;
}

ListaLigadaDoble *ListaLigadaDoble_free(ListaLigadaDoble *listaLigadaDoble)
{
    if(listaLigadaDoble == NULL){
        puts("ListaLigada no tiene memoria");
        return NULL;
    }

    while(!ListaLigadaDoble_vacia(listaLigadaDoble)){
        ListaLigadaDoble_eliminar_inicio(listaLigadaDoble);
    }
    free(listaLigadaDoble);
    listaLigadaDoble = NULL;
    return listaLigadaDoble;
}

typedef ListaLigadaDoble Civilizaciones;
#define Civilizaciones_init ListaLigadaDoble_init
#define Civilizaciones_insertar_inicio ListaLigadaDoble_insertar_inicio
#define Civilizaciones_insertar_final ListaLigadaDoble_insertar_final
#define Civilizaciones_mostrar ListaLigadaDoble_mostrar
#define Civilizaciones_free ListaLigadaDoble_free
#define Civilizaciones_eliminar_inicio ListaLigadaDoble_eliminar_inicio
#define Civilizaciones_eliminar_final ListaLigadaDoble_eliminar_final

Civilizacion *Civilizaciones_buscar(Civilizaciones *civilizaciones,char *nombre)
{
    if(civilizaciones == NULL){
        puts("Civilizaciones no tiene memoria");
        return NULL;
    }
    NodoDoble *temp = civilizaciones->inicio;

    while(temp != NULL){
        if(strcmp(nombre, temp->dato->nombre) == 0){
            return temp->dato;
        }
        temp = temp->siguiente;
    }
    return NULL;

}


#endif
