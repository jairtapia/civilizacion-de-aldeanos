#ifndef CIVILIZACION_H_INCLUDED
#define CIVILIZACION_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"lista_aldeanos.h"


struct civilizacion {
    char *nombre;
    AldeanosLista *aldeanosLista;
};

typedef struct civilizacion Civilizacion;

Civilizacion *civilizacion_init(char *nombre){
    Civilizacion *civilizacion = (Civilizacion*)malloc(sizeof(Civilizacion));
    if(civilizacion==NULL){
        puts("no se reservo memoria");
        return civilizacion;
    }
    civilizacion->nombre =strdup(nombre);
    civilizacion->aldeanosLista = AldeanosLista_init();
    return civilizacion;

}

Civilizacion *civilizacion_free(Civilizacion *civilizacion){
    if(civilizacion==NULL){
        puts("error civilizacion sin memoria");
        return civilizacion;
    }
    free(civilizacion->nombre);
    civilizacion->aldeanosLista = AldeanosLista_free(civilizacion->aldeanosLista);
    free(civilizacion);
    civilizacion = NULL;
    return civilizacion;
}





#endif // CIVILIZACION_H_INCLUDED
