#ifndef MENU_BATALLA_H
#define MENU_BATALLA_H
#include "batalla.h"
#include "utilidades.h"

typedef enum{
    SALIR_BATALLA,
    AGREGAR_BARCO_BATALLA,
    SACAR_BARCO_BATALLA,
    MOSTRAR_BARCOS_BATALLA
}MENU_BATALLA;

void menu_batalla(Batalla *batalla, Puerto *puerto){

    int op,seleccion;
    Barco *barco;

    do{
            puts("1. Agregar barco a la batalla");
            puts("2. Sacar un barco de la batalla");
            puts("3. Mostrar barcos en la batalla");
            puts("0. Salir de la batalla");
            scanf("%i",&op);
            switch(op){
            case AGREGAR_BARCO_BATALLA:
                barco = ColaBatalla_lugar(puerto);
                if (barco == NULL){
                    puts("Error al agregar barco a la batalla");
                    continue;
                }
                if(ColaBatalla_encolar(batalla,barco)){
                    if (seleccion == 1){
                        Puerto_eliminar_inicio(puerto);
                    }else Puerto_eliminar_final(puerto);
                    puts("Se agregó barco a la Batalla");
                }else{
                    puts("Error al agregar barco a la Batalla");
                    continue;
                }
                break;
            case SACAR_BARCO_BATALLA:
                barco = ColaBatalla_regresar(batalla);
                if(barco == NULL){
                    puts("Error al sacar Barco");
                    continue;
                }
                puts("A donde quieres regresar el barco: ");  
                puts("1. Inicio");
                puts("2. Final");
                scanf("%i",&seleccion);
                if(seleccion == 1){
                    Puerto_insertar_inicio(puerto,barco);
                    puts("Se regresó barco al inicio");
                    ColaBatalla_desencolar(batalla);
                }else{
                    Puerto_insertar_final(puerto,barco);
                    puts("Se regresó barco al final");
                    ColaBatalla_desencolar(batalla);
                }
                break;
            case MOSTRAR_BARCOS_BATALLA:
                if(ColaBatalla_mostrar(batalla)){
                    puts("Se mostró Batalla");
                    puts("");
                }else{
                    puts("Error al mostrar Batalla");
                    puts("");
                }
                break;

            }


    }while(op != SALIR_BATALLA);
}


#endif
