#ifndef MENU_CIVILIZACIONES_H
#define MENU_CIVILIZACIONES_H

#include "civilizaciones.h"
#include "menu_aldeanos.h"


void menu_civilizaciones(Civilizaciones *civilizaciones)
{
    typedef enum
    {
        SALIR,
        INSERTAR_INICIO,INSERTAR_FINAL,
        MOSTRAR,
        ELIMINAR_INICIO,ELIMINAR_FINAL,
        BUSCAR
    }MENU_CIVILIZACIONES;

    int op;
    Civilizacion *civilizacion;
    char *nombre;

    do{
        puts("1. Insertar inicio");
        puts("2. Insertar final");
        puts("3. Mostrar");
        puts("4. Eliminar inicio");
        puts("5. Eliminar final");
        puts("6. Buscar civilizacion");
        puts("0. Salir");
        scanf("%i",&op);
        while(getchar() != '\n');

        switch(op)
        {
        case INSERTAR_INICIO:
            civilizacion = Civilizacion_capturar();
            if(civilizacion == NULL){
                puts("Error al crear Civilizaciones");
                continue;
            }
            if(Civilizaciones_insertar_inicio(civilizaciones,civilizacion)){
                puts("Se inserto Civilizaciones al inicio");
            }else puts("Error al insertar Civilizaciones al inicio");
            break;
        case INSERTAR_FINAL:
            civilizacion = Civilizacion_capturar();
            if(civilizacion == NULL){
                puts("Error al crear Civilizaciones");
                continue;
            }
            if(Civilizaciones_insertar_final(civilizaciones,civilizacion)){
                puts("Se insertó Civilizaciones al final");
            }else puts("Error al insertar Civilizaciones al final");
            break;
        case MOSTRAR:
            if(Civilizaciones_mostrar(civilizaciones)){
                puts("Se mostró Civilizaciones");
                puts("");
            }else{
                puts("Error al mostrat Civilizaciones");
                puts("");
            }
            break;
        case ELIMINAR_INICIO:
            if(Civilizaciones_eliminar_inicio(civilizaciones)){
                puts("Se eliminó Civilizaciones al incio");
            }else puts("Error al eliminar Civilizaciones al inicio");
            break;
        case ELIMINAR_FINAL:
            if(Civilizaciones_eliminar_final(civilizaciones)){
                puts("Se eliminó civilizaciones al final");
            }else puts("Error al eliminar Civilizaciones al final");
            break;
        case BUSCAR:
            nombre = leerCadena("Nombre de la civilización que deseas buscar: ");
            civilizacion = Civilizaciones_buscar(civilizaciones,nombre);
            if(civilizacion == NULL){
                printf("No se encontró la civilización: %s\n",nombre);
                continue;
            }
            menu_aldeanos(civilizacion->aldeanosLista, civilizacion->puerto);
            break;
        default:
            break;

        }

    }while(op != SALIR);
}



#endif