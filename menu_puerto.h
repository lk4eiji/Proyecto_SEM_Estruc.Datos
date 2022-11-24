#ifndef MENU_PUERTO_H
#define MENU_PUERTO_H
#include <stdio.h>
#include <stdlib.h>
#include "puerto.h"
#include "menu_guerreros.h"
#include "menu_batalla.h"

typedef enum{
    SALIR_PUERTO,
    AGREGAR_BARCO, MOSTRAR_BARCOS,
    BUSCAR_BARCO,BATALLA
}MENU_PUERTO;

void menu_puerto(Puerto *puerto, Batalla *batalla){
    int opc;
    size_t id;
    Barco *barco;
    do
    {
        puts("1. Agregar Barco");
        puts("2. Mostrar");
        puts("3. Buscar Barco");
        puts("4. Batalla");
        puts("0. Salir");
        scanf("%i",&opc);
        while(getchar() != '\n');
        switch (opc)
        {
        case AGREGAR_BARCO:
            barco = Barco_capturar();
            if(barco == NULL){
                puts("Error al crear Barco");
                continue;
            }
            if(Puerto_insertar_final(puerto,barco)){
                puts("Se agregó Barco");
            }else puts("Error al agregar Barco");
            break;
        case MOSTRAR_BARCOS:
            if(Puerto_mostrar(puerto)){
                puts("Se mostró Puerto");
                puts("");
            }else{
                puts("Error al mostrar Puerto");
                puts("");
            }
            break;
        case BUSCAR_BARCO:
            id = leerSize_t("Inserte el ID del barco a buscar: ");
            barco = Puerto_buscar(puerto, id);
            if(barco == NULL){
                printf("No se encontró el barco con ID: %zu\n",id);
                continue;
            }
            menu_guerreros(barco->guerreros);
            break;
        case BATALLA:
            if (puerto->cantidad != 0 || batalla->cantidad != 0){
                menu_batalla(batalla, puerto);
            }else puts("No hay barcos disponibles");
            break;
        case SALIR_PUERTO:
            puts("Saliendo...");
            break;
        default:
            puts("Opción no valida");
            break;
        }
    } while (opc != SALIR_PUERTO);
    

}

#endif