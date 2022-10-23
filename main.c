#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"aldeano.h"
#include"lista_aldeanos.h"
#include"menu_aldeanos.h"
#include"civilizacion.h"

int main(){
    Civilizacion *civilizacion = civilizacion_init("campesinos");
    menu_aldeanos(civilizacion->aldeanosLista);
    civilizacion = civilizacion_free(civilizacion);
    if(civilizacion==NULL){
        puts("se libero la memoria");
    }
return 0;
}
