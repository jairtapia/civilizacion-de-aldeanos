#ifndef LISTA_ALDEANOS_H_INCLUDED
#define LISTA_ALDEANOS_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"aldeano.h"
#define CAPACIDAD 3

struct lista_aldeanos{
Aldeano **aldeanos;
size_t cantidad;
size_t capacidad;
};

typedef struct lista_aldeanos AldeanosLista;
/*metodo que inicializa la lista de los aldeanos
creando espacio de memoria adecuada a un aldeano*/
AldeanosLista *AldeanosLista_init(){
AldeanosLista *aldeanosLista;
aldeanosLista = (AldeanosLista*)malloc(sizeof(AldeanosLista));
if(aldeanosLista!=NULL){
    aldeanosLista->aldeanos = (Aldeano**)malloc(sizeof(Aldeano*)*CAPACIDAD);
    if(aldeanosLista->aldeanos == NULL){
        puts("error al crear el arreglo");
        exit(1);
    }
    aldeanosLista->cantidad = 0;
    aldeanosLista->capacidad = CAPACIDAD;
}
return aldeanosLista;
}

/*metodo de la lista que se encarga de liberar la memoria
igualmente mandando a llamar un metodo del aldeano que igual libera
memoria*/
AldeanosLista *AldeanosLista_free(AldeanosLista *aldeanosLista){
    if(aldeanosLista!=NULL){
        if(aldeanosLista->aldeanos!=NULL){
            for(size_t i = 0; i<aldeanosLista->cantidad;i++){
                Aldeano_free(aldeanosLista->aldeanos[i]);
                aldeanosLista->aldeanos[i] = NULL;
            }
            free(aldeanosLista->aldeanos);
            aldeanosLista->aldeanos = NULL;
        }
        free(aldeanosLista);
        aldeanosLista = NULL;
    }
return aldeanosLista;
}


/*metodo de la lista que se encarga de verificar
si la lista esta llena o no*/
bool AldeanosLista_llena(AldeanosLista *aldeanosLista){
    if(aldeanosLista==NULL){
        puts("no tieme memoria para la lista");
        exit(1);
    }
    return aldeanosLista->cantidad == aldeanosLista->capacidad;
}

/*metodo de la lista que se encarga de verificar si la lista esa vacia
o no*/
bool AldeanosLista_vacia(AldeanosLista *aldeanosLista){
    if(aldeanosLista == NULL){
        puts("no tiene memoria aldeanos lista");
        exit(1);
    }
    return aldeanosLista->cantidad == 0;
}


/*metodo de la lista que expande dicha lista si esta en su capacidad maxima*/
bool AldeanosLista_expandir(AldeanosLista *aldeanosLista){
    bool NO_ERROR = false;
    if(aldeanosLista!=NULL){
        size_t nuevacapacidad = aldeanosLista->capacidad +CAPACIDAD;
        Aldeano **aldeanoAUX = (Aldeano**)realloc(aldeanosLista->aldeanos,sizeof(Aldeano*)*nuevacapacidad);
        if(aldeanoAUX!=NULL){
            puts("se expandio la aldeanos lista");
            aldeanosLista->aldeanos = aldeanoAUX;
            aldeanosLista->capacidad = nuevacapacidad;
            NO_ERROR = true;
        }
        else{
            puts("no se logro expandir la lista");
        }
    }
return NO_ERROR;
}


/*metodo de la lista que se encarga de agregar un aldeano siempre
al final de la lista*/
bool AldeanosLista_agreagar_final(AldeanosLista *aldeanosLista, Aldeano *aldeano){
        bool NO_ERROR = false;
        if(aldeanosLista!=NULL){
            if(AldeanosLista_llena(aldeanosLista)){
                AldeanosLista_expandir(aldeanosLista);
            }
            aldeanosLista->aldeanos[aldeanosLista->cantidad] = aldeano;
            aldeanosLista->cantidad++;
            NO_ERROR = true;
        }
        return NO_ERROR;
}

/*metodo de la lista que se encarga de agregar un aldeano siempre
al inicio de la lista*/
bool AldeanosLista_agregar_inicio(AldeanosLista* aldeanosLista, Aldeano *aldeano){
    bool NO_ERROR = false;
    if(aldeanosLista!=NULL){
        if(AldeanosLista_llena(aldeanosLista)){
            AldeanosLista_expandir(aldeanosLista);
        }
        for(size_t i = aldeanosLista->cantidad;i>0;i--){
            aldeanosLista->aldeanos[i] = aldeanosLista->aldeanos[i-1];
        }
        aldeanosLista->aldeanos[0] = aldeano;
        aldeanosLista->cantidad++;
        NO_ERROR = true;
    }
    return NO_ERROR;
}

bool AldeanosLista_insertar(AldeanosLista * aldeanosLista, Aldeano *aldeano, size_t pos){
    bool NO_ERROR = false;
    if(pos<0 || pos>aldeanosLista->cantidad){
        return NO_ERROR;
    }
    if(aldeanosLista != NULL){
        if(AldeanosLista_llena(aldeanosLista)){
            AldeanosLista_expandir(aldeanosLista);
        }
        for(size_t i = aldeanosLista->cantidad;i>pos;i--){
            aldeanosLista->aldeanos[i] = aldeanosLista->aldeanos[i-1];
        }
        aldeanosLista->aldeanos[pos] = aldeano;
        aldeanosLista->cantidad++;
        NO_ERROR = true;
    }
return NO_ERROR;
}

/*metodo de la lista que se encarga de mostrarle al usuario los datos
contenidos en dicha lista de en forma de una lista*/
bool AldeanosLista_mostrar(AldeanosLista *aldeanosLista){
    bool NO_ERROR = false;
        if(aldeanosLista != NULL){
            printf("cantidad| %zu, capacidad| %zu \n",aldeanosLista->cantidad,aldeanosLista->capacidad);
        for(size_t i = 0;i<aldeanosLista->cantidad;i++){
            Aldeano_mostrar(aldeanosLista->aldeanos[i]);
            }
        NO_ERROR = true;
        }
return NO_ERROR;
}

/*metodo de la lista que se encarga de mostrarle al usuario los datos
contenidos en dicha lista en forma de una tabla*/
bool AldeanosLista_mostrar_fila(AldeanosLista *aldeanosLista){
    bool NO_ERROR = false;
    if(!AldeanosLista_vacia(aldeanosLista)){
        if(aldeanosLista != NULL){
                printf("%-10s %8s %10s\n","nombre","edad","salud");
                printf("------------------------------\n");
                for(size_t i = 0;i<aldeanosLista->cantidad;i++){
                Aldeano_mostrar_fila(aldeanosLista->aldeanos[i]);
                }
                printf("------------------------------\n");
                printf("cantidad| %zu, capacidad| %zu \n",aldeanosLista->cantidad,aldeanosLista->capacidad);
            NO_ERROR = true;
        }
    }
return NO_ERROR;
}


/*metodo de la lista que se encarga de eleminar un elemento de dicha lista
de acuerdo a la posicion ingresada por el usuario*/
bool AldeanosLista_eliminar_pos(AldeanosLista *aldeanosLista,size_t pos){
    bool NO_ERROR = false;
    if(pos<0 || pos>aldeanosLista->cantidad){
        return NO_ERROR;
    }
    if(aldeanosLista != NULL){
        if(!AldeanosLista_vacia(aldeanosLista))
            aldeanosLista->aldeanos[pos] =  Aldeano_free(aldeanosLista->aldeanos[pos]);
            if(aldeanosLista->aldeanos[pos] == NULL){
                for(size_t i = pos; i<aldeanosLista->cantidad;i++){
                    aldeanosLista->aldeanos[i] = aldeanosLista->aldeanos[i+1];
                }
            puts("se libero al aldeano");
            aldeanosLista->cantidad--;
            NO_ERROR = true;
            }
            else{
                puts("error al liberar el aldeano");
            }
        }
    return NO_ERROR;
}

bool AldeanosLista_elimina_inicio(AldeanosLista *aldeanosLista){
    bool NO_ERROR = false;
    if(aldeanosLista != NULL){
        aldeanosLista->aldeanos[0] = Aldeano_free(aldeanosLista->aldeanos[0]);
        if(aldeanosLista->aldeanos[0]==NULL){
            for(size_t i = 0; i<aldeanosLista->cantidad;i++){
                aldeanosLista->aldeanos[i] = aldeanosLista->aldeanos[i+1];
            }
            puts("se elimino al aldeano");
            aldeanosLista->cantidad--;
            NO_ERROR = true;
        }
        else{
            puts("error al liberar aldeano");
        }
    }
    return NO_ERROR;

}


bool AldeanosLista_eliminar_final(AldeanosLista *aldeanosLista){
    bool NO_ERROR = false;
    if(aldeanosLista != NULL){
        if(!AldeanosLista_vacia(aldeanosLista)){
            size_t ultimapos = aldeanosLista->cantidad-1;
            Aldeano_free(aldeanosLista->aldeanos[ultimapos]);
            aldeanosLista->aldeanos[ultimapos] = NULL;
            aldeanosLista->cantidad--;
            NO_ERROR = true;
        }
    }
return NO_ERROR;
}
#endif // LISTA_ALDEANOS_H_INCLUDED
