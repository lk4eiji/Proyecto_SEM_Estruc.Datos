#ifndef GUERRERO_H
#define GUERRERO_H
#include "utilidades.h"

struct guerrero{
    size_t id;
    int salud;
    float fuerza;
    float escudo;
    char *tipo;
};
typedef struct guerrero Guerrero;


Guerrero *Guerrero_init(size_t id, int salud, float fuerza,
                        float escudo, char *tipo)
{
    Guerrero *guerrero = (Guerrero*)malloc(sizeof(Guerrero));
    if(guerrero != NULL){
        guerrero->id = id;
        guerrero->salud = salud;
        guerrero->fuerza = fuerza;
        guerrero->escudo = escudo;
        guerrero->tipo = strdup(tipo);
    } 

    return guerrero;
} 

Guerrero *Guerrero_free(Guerrero *guerrero){
    if(guerrero != NULL){
        free(guerrero->tipo);
        guerrero->tipo = NULL;
        free(guerrero);
        guerrero = NULL;
    }
    return guerrero;
}

bool Guerrero_mostrar(Guerrero *guerrero){
    bool NO_ERROR = false;
    if(guerrero != NULL){
        printf("Id Guerrero: %zu\n", guerrero->id);
        printf("Salud: %i\n", guerrero->salud);
        printf("Fuerza: %.2f\n", guerrero->fuerza);
        printf("Escudo: %.2f\n", guerrero->escudo);
        printf("Tipo: %s\n", guerrero->tipo);
        puts("-.-.-.-.-.-.-.-.-.-.-.-.-.-.-");
        NO_ERROR = true;
    }
    return NO_ERROR;
}

Guerrero *Guerrero_capturar(){
    size_t id = leerSize_t("Id del guerrero: "); 
    int salud = leerInt("Salud (0-100): ");
    float fuerza = leerFloat("Fuerza (0.0 - 60.0): "), escudo = leerFloat("Escudo (0.0 - 30.0): ");
    while(getchar() != '\n');
    puts("Tipos a elegir: (Lancero, Arquero, Paladín, Granadero)");
    char *tipo = leerCadena("Tipo: ");

    Guerrero *guerrero = Guerrero_init(id, salud, fuerza, escudo, tipo);

    return guerrero;
}


#endif 