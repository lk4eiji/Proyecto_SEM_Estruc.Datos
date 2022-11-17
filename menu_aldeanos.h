#ifndef MENU_ALDEANOS_H
#define MENU_ALDEANOS_H
#include <stdio.h>
#include <stdlib.h>
#include "aldeanos_lista.h"
#include "menu_puerto.h"

typedef enum{
    SALIR,
    AGREGAR_INICIO, AGREGAR_FINAL, INSERTAR,
    MOSTRAR, MOSTRAR_TABLA,
    ELIMINAR_INICIO, ELIMINAR_FINAL, ELIMINAR,
    PUERTO
}MENU_ALDEANOS;

void menu_aldeanos(AldeanosLista *aldeanosLista, Puerto *puerto){
    int opc;
    Aldeano *aldeano;
    size_t posicion;
    do
    {
        puts("1. Agregar Inicio");
        puts("2. Agregar Final");
        puts("3. Insertar");
        puts("4. Mostrar");
        puts("5. Mostrar Tabla");
        puts("6. Eliminar Inicio");
        puts("7. Eliminar Final");
        puts("8. Eliminar");
        puts("9. Puerto");
        puts("0. Salir");
        scanf("%i",&opc);
        while(getchar() != '\n');
        switch (opc)
        {
        case AGREGAR_INICIO:
            aldeano = Aldeano_capturar();
            if (aldeano == NULL)
            {
                puts("Error al inicializar Aldeano");
                continue;
            }else puts("Se inicializó Aldeano");
            if (AldeanosLista_agregar_inicio(aldeanosLista, aldeano))
            {
                puts("Se agregó Aldeano al inicio");
            }else puts("Error al agregar Aldeano al inicio");
            break;
        case AGREGAR_FINAL:
            aldeano = Aldeano_capturar();
            if (aldeano == NULL)
            {
                puts("Error al inicializar Aldeano");
                continue;
            }else puts("Se inicializó Aldeano");
            if (AldeanosLista_agregar_final(aldeanosLista, aldeano))
            {
                puts("Se agregó Aldeano al final");
            }else puts("Error al agregar Aldeano al final");
            break;
        case INSERTAR:
            posicion = leerSize_t("Posición: ");
            while(getchar() != '\n');
            aldeano = Aldeano_capturar();
            if (aldeano == NULL){
                puts("Error al inicializar Aldeano");
                continue;
            }else puts("Se inicializó Aldeano");
            if (AldeanosLista_insertar(aldeanosLista, aldeano, posicion)){
              puts("Se insertó Aldeano");  
            }else puts("Error al insertar Aldeano");
            break;
        case MOSTRAR:
            if (AldeanosLista_mostrar(aldeanosLista)){
                puts("Se mostró AldeanosLista");
            }else puts("Error al mostrar Aldeanoslista");
            break;
        case MOSTRAR_TABLA:
            AldeanosLista_mostrar_tabla(aldeanosLista);
            break;
        case ELIMINAR_INICIO:
            if (AldeanosLista_eliminar_inicio(aldeanosLista)){
                puts("Se eliminó aldeano al inicio");
            }else puts("Error al eliminar Aldeano al incio");
            break;
        case ELIMINAR_FINAL:
            if (AldeanosLista_eliminar_final(aldeanosLista)){
                puts("Se eliminó aldeano al final");
            }else puts("Error al eliminar Aldeano al final");
            break;
        case ELIMINAR:
            posicion = leerSize_t("Posición: ");
            while(getchar() != '\n');
            if (AldeanosLista_eliminar(aldeanosLista, posicion)){
                puts("Se eliminó Aldeano");
            }else puts("Error al eliminar Aldeano");
            break;
        case PUERTO:
            menu_puerto(puerto);
            break;
        case SALIR:
            puts("Saliendo...");
            break;
        default:
            puts("Opción no valida");
            break;
        }
    } while (opc != SALIR);
    

}

#endif