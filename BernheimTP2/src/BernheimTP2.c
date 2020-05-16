/*
 ============================================================================
 Name        : BernheimTP2.c
 Author      : Bernheim
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BernheimTP2.h"
#include "Validaciones.h"

#define TAM 5


int main()
{
	setbuf(stdout,NULL);
    char seguir='s';
    char confirma;
    int proximoId=1;
    eEmpleado listaEmpleados[TAM];
    int flagAlta=0;

    inicializarEmpleados(listaEmpleados,TAM);

    do
    {

        switch(mostrarMenu())
        {
        case 1:
            //ALTA
            if(altaEmpleado(proximoId,listaEmpleados,TAM))
            {
                proximoId++;
                flagAlta=1;
            }
            break;
        case 2:
            //MODIFICAR
            if(flagAlta)
            {
                modificarEmpleado(listaEmpleados,TAM);
            }
            else
            {
                printf("\n\nPrimero debe ingresar empleados para poder modificarlos\n\n");
            }
            break;
        case 3:
            //BAJA
            if(flagAlta)
            {
                bajaEmpleado(listaEmpleados,TAM);
            }
            else
            {
                printf("\n\nPrimero debe ingresar empleados para poder dar de baja\n\n");
            }
            break;
        case 4:
            //INFORMAR
            if(flagAlta)
            {
                informar(listaEmpleados,TAM);
            }
            else
            {
                printf("\n\nPrimero debe ingresar empleados para poder listarlos\n\n");
            }
            break;
        case 5:
            //SALIR
            printf("Confirma salida: ");
            fflush(stdin);
            scanf("%c",&confirma);
            if(confirma=='s')
            {
                seguir='n';
            }
            break;
        default:
            printf("Ingrese una opcion valida. \n\n");
        }
        system("pause");
        fflush(stdin);
    }
    while(seguir=='s');


    return 0;
}

