/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "LinkedList.h"
#include "Controller.h"
#include "copiaSeguridad.h"
#include "clientes.h"

int menuPrincipal();


int main()
{
    LinkedList* lista = ll_newLinkedList();
    char seguir = 's';
    char confirma;
    int flagCarga = 0;

    do
    {
        switch(menuPrincipal())
        {
       case 1:
           //CARGAR LOS DATOS MODO TEXTO
            if(controller_loadFromText("clientes.csv",lista)==0)
            {
                flagCarga = 1;
            }
        break;
       case 2:
           //CARGAR LOS DATOS MODO BINARIO
            if(controller_loadFromBinary("clientes.bin",lista)==0)
            {
                flagCarga = 1;
            }
        break;
       case 3:
           //ALTA CLIENTE
            if( flagCarga)
            {
                controller_addCliente(lista);
            }
            else
            {
                printf("Debe cargar los clientes para poder dar de alta\n");
            }
        break;
       case 4:
           //MODIFICAR CLIENTE
            if(flagCarga)
            {
                controller_editCliente(lista);
            }
            else
            {
                printf("Debe haber cargado los clientes para poder modificarlos\n");
            }
        break;
       case 5:
           //BAJA CLIENTE
           if(flagCarga)
           {
               controller_removeCliente(lista);
           }
           else
           {
               printf("Debe haber cargado los clientes para poder dar de baja\n");
           }
        break;
       case 6:
           //LISTAR CLIENTES
            if(flagCarga)
            {
                controller_ListClientes(lista);
            }
            else
            {
                printf("Debe haber cargado los clientes para poder listarlos\n");
            }
        break;
       case 7:
           //ORDENAR CLIENTES
            if(flagCarga)
            {
                controller_sortClientes(lista);
            }
            else
            {
                printf("Debe haber cargado los clientes para poder ordenarlos\n");
            }
        break;
       case 8:
           //COPIA DE SEGURIDAD
           if(flagCarga)
           {
               copiaSeguridad(lista);
           }
           else
           {
               printf("Debe haber cargado los clientes para poder hacer una copia de seguridad\n");
           }
        break;
       case 9:
           //MOVER CLIENTE
           if(flagCarga)
           {
                moverCliente(lista);
           }
           else
           {
               printf("Debe haber cargado los clientes para poder moverlos de lugar en la lista\n");
           }
        break;
       case 10:
           //GUARDAR DATOS MODO TEXTO
           if(flagCarga)
           {
               controller_saveAsText("clientes.csv",lista);
           }
           else
           {
               printf("Debe haber cargado los clientes para poder guardarlos\n");
           }
        break;
       case 11:
           //GUARDAR DATOS MODO BINARIO
           if(flagCarga)
           {
               controller_saveAsBinary("clientes.bin",lista);
           }
           else
           {
               printf("Debe haber cargado los clientes para poder guardarlos\n");
           }
        break;
       case 12:
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
        printf("Ingrese una opcion valida\n");
        }
        system("pause");
    }while(seguir=='s');

    ll_deleteLinkedList(lista);
    return 0;
}


int menuPrincipal()
{
    int opcion;
    system("cls");
    printf("\t**** MENU DE OPCIONES ****\n\n");
    printf("1- Cargar datos de los clientes (Modo texto)\n");
    printf("2- Cargar datos de los clientes (Modo binario)\n");
    printf("3- Alta de cliente\n");
    printf("4- Modificar datos de un cliente\n");
    printf("5- Baja de cliente\n");
    printf("6- Listar clientes\n");
    printf("7- Ordenar clientes\n");
    printf("8- Hacer copia de seguridad\n");
    printf("9- Mover cliente de lugar en la lista\n");
    printf("10- Guardar los datos de los clientes (Modo texto)\n");
    printf("11- Guardar los datos de los clientes (Modo binario)\n");
    printf("12- Salir\n\n");

    printf("Indique la opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);


    return opcion;
}


