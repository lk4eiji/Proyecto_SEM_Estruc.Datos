#ifndef PUERTO_H
#define PUERTO_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "barco.h"

struct nodoDoble
{
    Barco *dato;
    struct nodoDoble *siguiente;
    struct nodoDoble *anterior;
};
typedef struct nodoDoble Nodo_Doble;

Nodo_Doble *Nodo_Doble_init(Barco *dato){
    Nodo_Doble *nodo_doble = (Nodo_Doble*)malloc(sizeof(Nodo_Doble));

    if(nodo_doble == NULL){
        puts("No se pudo reservar memoria para Nodo");
        return NULL;
    }

    nodo_doble->dato = dato;
    nodo_doble->siguiente = NULL;
    nodo_doble->anterior = NULL;

    return nodo_doble;
}
struct listaligada_doble{
    Nodo_Doble *inicio;
    Nodo_Doble *final;
    size_t cantidad;
};
typedef struct listaligada_doble ListaLigada_Doble;

ListaLigada_Doble *ListaLigada_Doble_init()
{
    ListaLigada_Doble *listaLigada_Doble = (ListaLigada_Doble*)malloc(sizeof(ListaLigada_Doble));

    if (listaLigada_Doble == NULL){
        puts("No se reservó memoria para ListaLigada_Doble");
        return NULL;
    }

    listaLigada_Doble->inicio = NULL;
    listaLigada_Doble-> final = NULL;
    listaLigada_Doble->cantidad = 0;

    return listaLigada_Doble;
}

bool ListaLigada_Doble_vacia(ListaLigada_Doble *listaLigada_Doble)
{
    if(listaLigada_Doble == NULL){
        puts("ListaLigada no tiene memoria");
        exit(1);
    }
    return listaLigada_Doble->cantidad == 0;
}

bool ListaLigada_Doble_insertar_inicio(ListaLigada_Doble *listaLigada_Doble,Barco *dato)
{
    if (listaLigada_Doble == NULL){
        puts("ListaLigada no tiene memoria");
        return false;
    }

    Nodo_Doble *nuevo = Nodo_Doble_init(dato);
    if (nuevo == NULL){
        puts("ListaLigada no puedo crear un nuevo Nodo");
        return false;
    }
    if(ListaLigada_Doble_vacia(listaLigada_Doble)){
        listaLigada_Doble->inicio = nuevo;
        listaLigada_Doble->final = nuevo;
        listaLigada_Doble->cantidad++;
        return true;
    }

    nuevo->siguiente = listaLigada_Doble->inicio;
    listaLigada_Doble->inicio->anterior = nuevo;
    listaLigada_Doble->inicio = nuevo;
    listaLigada_Doble->cantidad++;
    return true;
}

bool ListaLigada_Doble_insertar_final(ListaLigada_Doble *listaLigada_Doble,Barco *dato)
{
    if (listaLigada_Doble == NULL){
        puts("ListaLigada no tiene memoria");
        return false;
    }

    Nodo_Doble *nuevo = Nodo_Doble_init(dato);
    if (nuevo == NULL){
        puts("ListaLigada no puedo crear un nuevo Nodo");
        return false;
    }
    if(ListaLigada_Doble_vacia(listaLigada_Doble)){
        listaLigada_Doble->inicio = nuevo;
        listaLigada_Doble->final = nuevo;
        listaLigada_Doble->cantidad++;
        return true;
    }

    nuevo->anterior = listaLigada_Doble->final;
    listaLigada_Doble->final->siguiente = nuevo;
    listaLigada_Doble->final = nuevo;
    listaLigada_Doble->cantidad++;
    return true;
}

bool ListaLigada_Doble_mostrar(ListaLigada_Doble *listaLigada_Doble)
{
    if(listaLigada_Doble == NULL){
        puts("ListaLigada no tiene memoria");
        return false;
    }

    Nodo_Doble *temp = listaLigada_Doble->inicio;

    while(temp != NULL){
        printf("%-4s %12s %10s %8s\n","Id", "Combustible", "Velocidad", "Armadura");
        if(!Barco_mostrar(temp->dato)){
            puts("Error al mostrar Barco");
        }
        puts("Se mostró Barco");
        puts("-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.");
        temp = temp->siguiente;
    }
    printf("cantidad de barcos: %zu\n",listaLigada_Doble->cantidad);
    return true;
}

bool ListaLigada_Doble_eliminar_inicio(ListaLigada_Doble *listaLigada_Doble)
{
    if(listaLigada_Doble == NULL){
        puts("ListaLigada no tiene memoria");
        return false;
    }

    if(ListaLigada_Doble_vacia(listaLigada_Doble)){
        puts("ListaLigada esta vacia");
        return false;
    }

    Nodo_Doble *temp = listaLigada_Doble->inicio;
    if(temp->siguiente != NULL){
        temp->siguiente->anterior = NULL;
    }
    else{
        listaLigada_Doble->final = NULL;
    }

    listaLigada_Doble->inicio = temp->siguiente;
    listaLigada_Doble->cantidad--;
    return true;
}

bool ListaLigada_Doble_eliminar_final(ListaLigada_Doble *listaLigada_Doble)
{
    if(listaLigada_Doble == NULL){
        puts("ListaLigada no tiene memoria");
        return false;
    }

    if(ListaLigada_Doble_vacia(listaLigada_Doble)){
        puts("ListaLigada esta vacia");
        return false;
    }

    Nodo_Doble *temp = listaLigada_Doble->final;
    if(temp->anterior != NULL){
        temp->anterior->siguiente = NULL;
    }
    else{
        listaLigada_Doble->inicio = NULL;
    }

    listaLigada_Doble->final = temp->anterior;
    listaLigada_Doble->cantidad--;
    return true;
}

ListaLigada_Doble *ListaLigada_Doble_free(ListaLigada_Doble *listaLigada_Doble)
{
    if(listaLigada_Doble == NULL){
        puts("ListaLigada no tiene memoria");
        return NULL;
    }

    while(!ListaLigada_Doble_vacia(listaLigada_Doble)){
        ListaLigada_Doble_eliminar_inicio(listaLigada_Doble);
    }
    free(listaLigada_Doble);
    listaLigada_Doble = NULL;
    return listaLigada_Doble;
}

typedef ListaLigada_Doble Puerto;
#define Puerto_init ListaLigada_Doble_init
#define Puerto_insertar_inicio ListaLigada_Doble_insertar_inicio
#define Puerto_insertar_final ListaLigada_Doble_insertar_final
#define Puerto_mostrar ListaLigada_Doble_mostrar
#define Puerto_free ListaLigada_Doble_free
#define Puerto_eliminar_inicio ListaLigada_Doble_eliminar_inicio
#define Puerto_eliminar_final ListaLigada_Doble_eliminar_final


Barco *Puerto_buscar(Puerto *puerto,size_t id)
{
    if(puerto == NULL){
        puts("Puerto no tiene memoria");
        return NULL;
    }
    Nodo_Doble *temp = puerto->inicio;

    while(temp != NULL){
        if(id == temp->dato->id){
            return temp->dato;
        }
        temp = temp->siguiente;
    }
    return NULL;

}

#endif
