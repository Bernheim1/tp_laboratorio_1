#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"

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
            if(controller_loadFromText("data.csv",lista)==0)
            {
                flagCarga = 1;
            }
        break;
       case 2:
           //CARGAR LOS DATOS MODO BINARIO
            if(controller_loadFromBinary("data.bin",lista)==0)
            {
                flagCarga = 1;
            }
        break;
       case 3:
           //ALTA EMPLEADO
            if( flagCarga)
            {
                controller_addEmployee(lista);
            }
            else
            {
                printf("Debe cargar los empleados para poder dar de alta\n");
            }
        break;
       case 4:
           //MODIFICAR EMPLEADO
            if(flagCarga)
            {
                controller_editEmployee(lista);
            }
            else
            {
                printf("Debe haber cargado los empleados para poder modificarlos\n");
            }
        break;
       case 5:
           //BAJA EMPLEADO
           if(flagCarga)
           {
               controller_removeEmployee(lista);
           }
           else
           {
               printf("Debe haber cargado los empleados para poder dar de baja\n");
           }
        break;
       case 6:
           //LISTAR EMPLEADOS
            if(flagCarga)
            {
                controller_ListEmployee(lista);
            }
            else
            {
                printf("Debe haber cargado los empleados para poder listarlos\n");
            }
        break;
       case 7:
           //ORDENAR EMPLEADOS
            if(flagCarga)
            {
                controller_sortEmployee(lista);
            }
            else
            {
                printf("Debe haber cargado los empleados para poder ordenarlos\n");
            }
        break;
       case 8:
           //GUARDAR DATOS MODO TEXTO
           if(flagCarga)
           {
               controller_saveAsText("data.csv",lista);
           }
           else
           {
               printf("Debe haber cargado los empleados para poder guardarlos");
           }
        break;
       case 9:
           //GUARDAR DATOS MODO BINARIO
           if(flagCarga)
           {
               controller_saveAsBinary("data.bin",lista);
           }
           else
           {
               printf("Debe haber cargado los empleados para poder guardarlos");
           }
        break;
       case 10:
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
    printf("1- Cargar datos de los empleados (Modo texto)\n");
    printf("2- Cargar datos de los empleados (Modo binario)\n");
    printf("3- Alta de empleado\n");
    printf("4- Modificar datos de un empleado\n");
    printf("5- Baja de empleado\n");
    printf("6- Listar empleados\n");
    printf("7- Ordenar empleados\n");
    printf("8- Guardar los datos de los empleados (Modo texto)\n");
    printf("9- Guardar los datos de los empleados (Modo binario)\n");
    printf("10- Salir\n\n");

    printf("Indique la opcion: ");
    scanf("%d",&opcion);


    return opcion;
}





