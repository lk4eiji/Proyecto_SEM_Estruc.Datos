#include <stdio.h>
#include <stdlib.h>
#include "menu_civilizaciones.h"

int main(){

    Civilizaciones *civilizaciones = Civilizaciones_init();
    menu_civilizaciones(civilizaciones);

    civilizaciones = ListaLigadaDoble_free(civilizaciones);

    return EXIT_SUCCESS;
}