#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "copiaSeguridad.h"
#include "LinkedList.h"
#include "Controller.h"
#include "validaciones.h"


void copiaSeguridadTxt(LinkedList* pArrayListClientes)
{
    FILE* pFile;
    char path[51];
    LinkedList* auxLinkedList;

    if(pArrayListClientes != NULL)
    {
        printf("Ingrese el nombre del nuevo archivo: ");
        scanf("%s",path);

        strcat(path,".csv");

        pFile = fopen(path, "w");

        if(pFile != NULL)
        {
            auxLinkedList = ll_clone(pArrayListClientes);

            if(auxLinkedList != NULL)
            {
                if(ll_containsAll(pArrayListClientes,auxLinkedList))
                {
                    if(!controller_saveAsText(path,auxLinkedList))
                    {
                        printf("Se hizo correctamente la copia de seguridad en %s\n",path);
                    }
                    else
                    {
                        printf("No se pudo hacer la copia de seguridad");
                    }

                }

            }
        }


    }


}

void copiaSeguridadBin(LinkedList* pArrayListClientes)
{
    FILE* pFile;
    char path[51];
    LinkedList* auxLinkedList;

    if(pArrayListClientes != NULL)
    {
        printf("Ingrese el nombre del nuevo archivo: ");
        scanf("%s",path);

        strcat(path,".bin");

        pFile = fopen(path, "wb");

        if(pFile != NULL)
        {
            auxLinkedList = ll_clone(pArrayListClientes);

            if(auxLinkedList != NULL)
            {
                if(ll_containsAll(pArrayListClientes,auxLinkedList))
                {
                    if(!controller_saveAsBinary(path,auxLinkedList))
                    {
                        printf("Se hizo correctamente la copia de seguridad en %s\n",path);
                    }
                    else
                    {
                        printf("No se pudo hacer la copia de seguridad");
                    }

                }

            }
        }


    }

}

int copiaSeguridad(LinkedList* pArrayListClientes)
{
    int opcion;
    int todoOk = 1;

    system("cls");
    printf("\t**** MENU DE OPCIONES COPIA DE SEGURIDAD ****\n\n");
    printf("1- Copia de seguridad (Modo texto)\n");
    printf("2- Copia de seguridad (Modo binario)\n");

    if(utn_getEntero(&opcion,2,"Ingrese 1 para guardar en texto o 2 para guardar en binario: ","Error. Reingrese opcion\n",1,2)==0)
    {
        todoOk = 0;
        switch(opcion)
        {
        case 1:
            copiaSeguridadTxt(pArrayListClientes);
            break;
        case 2:
            copiaSeguridadBin(pArrayListClientes);
            break;
        }
    }
    else
    {
        printf("Se quedo sin intentos para ingresar una opcion\n");
    }
    return todoOk;
}

