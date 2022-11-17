#ifndef BARCO_H
#define BARCO_H
#include "pilaguerreros.h"

struct barco{
    size_t id;
    float combustible;
    float velocidad;
    float armadura;
    PilaGuerreros *guerreros;
};
typedef struct barco Barco;


Barco *Barco_init(size_t id, float combustible,
                     float velocidad, float armadura)
{
    Barco *barco = (Barco*)malloc(sizeof(Barco));
    if (barco == NULL)
    {
        puts("Error al reservar memoria para Barco");
        return barco;
    }
    barco->id = id;
    barco->combustible = combustible;
    barco->velocidad = velocidad;
    barco->armadura = armadura;
    barco->guerreros = PilaGuerreros_init();

    return barco;
} 

Barco *Barco_free(Barco *barco){
    if (barco == NULL){
        puts("Error Barco sin memoria");
        return barco;
    }
    barco->guerreros = PilaGuerreros_free(barco->guerreros);
    free(barco);
    barco = NULL;
    return barco;
}

bool Barco_mostrar(Barco *barco){
    if(barco == NULL){
        puts("Barco no tiene memoria");
        return false;
    }
    printf("Id del Barco: %zu\n", barco->id);
    printf("Combustible: %.2f\n", barco->combustible);
    printf("Velocidad: %.2f\n", barco->velocidad);
    printf("Armadura: %.2f\n", barco->armadura);
    puts("");
    if(Pila_mostrar(barco->guerreros)){
        puts("Se mostró Guerreros");
    }else
    {
        puts("error al mostrar Guerreros");
        return false;
    }
    return true;
}

Barco *Barco_capturar(){
    size_t id = leerSize_t("Id del Barco: "); 
    float combustible = leerFloat("Combustible: "),
          velocidad = leerFloat("Velocidad: "),
          armadura = leerFloat("Armadura: ");
    Barco *barco = Barco_init(id,combustible,velocidad,armadura);
    
    return barco;
}


#endif 