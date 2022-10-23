#ifndef ALDEANO_H_INCLUDED
#define ALDEANO_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"utilidades.h"


struct aldeano{
    char *nombre;
    int edad;
    int salud;
};

typedef struct aldeano Aldeano;

Aldeano *Aldeano_init(char *nombre,int edad, int salud){
    Aldeano *aldeano = (Aldeano*)malloc(sizeof(Aldeano));
    if(aldeano !=NULL){
        aldeano->nombre = strdup(nombre);
        aldeano->edad = edad;
        aldeano->salud = salud;
}
 return aldeano;
}

Aldeano *Aldeano_free(Aldeano *aldeano){
    if(aldeano!=NULL){
            free(aldeano->nombre);
            aldeano->nombre = NULL;
            free(aldeano);
            aldeano = NULL;
    }
    return aldeano;

}

Aldeano *Aldeano_capturar(){
    char *nombre = leerCadena("escribe el nombre del aldeano");
    int edad = leerInt("escribe la edad del aldeano");
    int salud = leerInt("escribe la salud del aldeano");
    Aldeano *aldeano = Aldeano_init(nombre,edad,salud);
return aldeano;
}

bool Aldeano_mostrar(Aldeano *aldeano){
    bool NO_ERROR = false;
    if(aldeano!=NULL){
        printf("nombre: %s\n",aldeano->nombre);
        printf("edad: %i\n",aldeano->edad);
        printf("salud: %i\n",aldeano->salud);
        NO_ERROR = true;
    }
return NO_ERROR;
}


bool Aldeano_mostrar_fila(Aldeano *aldeano){
    bool NO_ERROR = false;
    if(aldeano!=NULL){
        printf("|%-10s |%6i |%8i|\n",aldeano->nombre,aldeano->edad,aldeano->salud);
        NO_ERROR = true;
    }
return NO_ERROR;
}

#endif // ALDEANO_H_INCLUDED
