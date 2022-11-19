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
    printf("%-4zu %12.2f %10.2f %8.2f \n",barco->id,barco->combustible,barco->velocidad,barco->armadura); 
    puts("");
    puts("Guerreros: ");
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
    float combustible = leerFloat("Combustible (0.0 - 100.0): "),
          velocidad = leerFloat("Velocidad (0.0 - 14.0): "),
          armadura = leerFloat("Armadura (0.0 - 100.0): ");
    Barco *barco = Barco_init(id,combustible,velocidad,armadura);
    
    return barco;
}


#endif 