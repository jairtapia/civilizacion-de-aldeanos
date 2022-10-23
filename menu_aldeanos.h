#ifndef MENU_ALDEANOS_H_INCLUDED
#define MENU_ALDEANOS_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include"lista_aldeanos.h"

typedef enum{salir,agregar_inicio, agregar_final, insertar, mostrar, mostrar_tabla,eliminar_inicio,eliminar_final,eliminar};

void menu_aldeanos(AldeanosLista *aldeanosLista){
    system("color 04");
    int opc, cantidad, agregar;
    Aldeano *aldeano;
    size_t posicion;
    do{
    printf("|--------------------------------|\n");
    printf("|--------------menu--------------|\n");
    printf("|-------1_agreagr inicio---------|\n");
    printf("|-------2_agreagar final---------|\n");
    printf("|----------3_insertar------------|\n");
    printf("|----------4_mostrar-------------|\n");
    printf("|-------5_mostrar tabla----------|\n");
    printf("|------6_eliminar inicio---------|\n");
    printf("|------7_eliminar final----------|\n");
    printf("|------8_eliminar posicion-------|\n");
    printf("|-----------0_salir--------------|\n");
    printf("|--------------------------------|\n");
    scanf("%i",&opc);
    fflush(stdin);
    system("cls");
    switch(opc){
    case agregar_inicio:
        printf("|---------------------------------------|\n");
        printf("|--------------agregar inicio-----------|\n");
        printf("|---------------------------------------|\n");
        do{
        aldeano = Aldeano_capturar();
        if(aldeano == NULL){
            puts("no se creo el aldeano");
            continue;
        }
        else{
            puts("si se creo un aldeano");
        }
        if(AldeanosLista_agregar_inicio(aldeanosLista,aldeano)){
        puts("se agrego al inicio correctamente");
        }
        printf("¿quieres agregar otro aldeano en  el inicio?\n1= si 2 = no\n");
        scanf("%i",&agregar);
        fflush(stdin);
        system("cls");
        }while(agregar!=2);
        break;
    case agregar_final:
        printf("|---------------------------------------|\n");
        printf("|---------------agreagar final----------|\n");
        printf("|---------------------------------------|\n");
        do{
            aldeano = Aldeano_capturar();
            if(aldeano == NULL){
                puts("no se creo el aldeano");
                continue;
            }
            else{
                puts("si se creo un aldeano");
            }
            if(AldeanosLista_agreagar_final(aldeanosLista, aldeano)){
                puts("se agrego correctamente al final");
            }
        printf("¿quieres agregar otro aldeano en  el inicio?\n1= si 2 = no\n");
        scanf("%i",&agregar);
        fflush(stdin);
        system("cls");
        }while(agregar!=2);
        break;
    case insertar:
        printf("|---------------------------------------|\n");
        printf("|----------------insertar---------------|\n");
        printf("|---------------------------------------|\n");
        aldeano = Aldeano_capturar();
        if(aldeano == NULL){
            puts("no se creo el aldeano");
            continue;
        }
        else{
            puts("si se creo un aldeano");
        }
        posicion = leersize_t("posicion");
        if(AldeanosLista_insertar(aldeanosLista,aldeano,posicion)){
        printf("se inserto correctamente en la posicion: %zu\n",posicion);
        }
        else{
            puts("error al insertar");
        }
        system("pause");
        system("cls");
        break;
    case mostrar:
        printf("|---------------------------------------|\n");
        printf("|-----------------mostrar---------------|\n");
        printf("|---------------------------------------|\n");
        if(AldeanosLista_mostrar(aldeanosLista)){
            puts("se mostro la lista");
        }
        else{
            puts("no se pudo mostrar la lista");
        }
        system("pause");
        system("cls");
        break;
    case mostrar_tabla:
        printf("|-----------------------------|\n");
        printf("|--------mostrar tabla--------|\n");
        printf("|-----------------------------|\n");
        if(AldeanosLista_mostrar_fila(aldeanosLista)){
            puts("se mostro la lista");
        }
        else{
            puts("no se pudo mostrar la lista");
        }
        system("pause");
        system("cls");
        break;
    case eliminar_inicio:
        printf("|---------------------------------------|\n");
        printf("|------------eliminar inicio------------|\n");
        printf("|---------------------------------------|\n");
        if(AldeanosLista_elimina_inicio(aldeanosLista)){
            puts("se elimino al aldeanoal inicio");
        }
        else{
            puts("error al eliminar al inicio");
        }
        system("pause");
        system("cls");
        break;
    case eliminar_final:
        printf("|---------------------------------------|\n");
        printf("|--------------eliminar final-----------|\n");
        printf("|---------------------------------------|\n");
        if(AldeanosLista_eliminar_final(aldeanosLista)){
            puts("se libero al aldeano al final");
        }
        else{
            puts("error al eliminar al final");
        }
        system("pause");
        system("cls");
        break;
    case eliminar:
        printf("|---------------------------------------|\n");
        printf("|------------------eliminar-------------|\n");
        printf("|---------------------------------------|\n");
        posicion = leersize_t("posicion");
        if(AldeanosLista_eliminar_pos(aldeanosLista,posicion)){
            puts("se elimino al aldeano");
        }
        else{
            puts("no se logro eliminar la posicion");
        }
        system("pause");
        system("cls");
        break;
    case salir:
        puts("saliendo del menu");
        break;
    default:
        puts("opcion incorrecta");
    }
    }while(opc!=0);
}



#endif // MENU_ALDEANOS_H_INCLUDED
