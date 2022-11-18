#ifndef MENU_GUERREROS_H
#define MENU_GUERREROS_H
#include <stdio.h>
#include <stdlib.h>
#include "barco.h"

typedef enum{
    SALIR_GUERREROS,
    AGREGAR_GUERRERO, ELIMINAR_GUERRERO,
    MOSTRAR_ULTIMO, MOSTRAR_GUERREROS
}MENU_GUERREROS;

void menu_guerreros(PilaGuerreros *guerreros){
    int opc;
    Guerrero *guerrero;
    size_t *dato;
    do
    {
        puts("1. Agregar Guerrero");
        puts("2. Eliminar Guerrero");
        puts("3. Mostrar último guerrero");
        puts("4. Mostrar todos los guerreros");
        puts("0. Salir");
        scanf("%i",&opc);
        while(getchar() != '\n');
        switch (opc)
        {
        case AGREGAR_GUERRERO:
            guerrero = Guerrero_capturar();
            if(guerrero == NULL){
                puts("Error al Crear Guerrero");
                continue;
            }
            if(PilaGuerreros_apilar(guerreros,guerrero)){
                puts("Se agregó Guerrero");
            }else puts("Error al agregar Guerrero");
            break;
        case ELIMINAR_GUERRERO:
            if(PilaGuerreros_desapilar(guerreros)){
                puts("Se desapilo guerrero al final");
            }else puts("Error desapilar guerrero");
            break;
        case MOSTRAR_ULTIMO:
            dato = PilaGuerreros_tope(guerreros);
            if (dato == NULL)
            {
                puts("No hay guerreros");
                continue;
            }
            printf("[Id Guerrero: %zu]\n",*dato);
            break;
        case MOSTRAR_GUERREROS:
            if(PilaGuerreros_mostrar(guerreros)){
                puts("Se mostró Guerreros");
                puts("");
            }else{
                puts("Error al mostrar Guerreros");
                puts("");
            }
            break;
        case SALIR_GUERREROS:
            puts("Saliendo...");
            break;
        default:
            puts("Opción no valida");
            break;
        }
    } while (opc != SALIR_GUERREROS);
    

}

#endif