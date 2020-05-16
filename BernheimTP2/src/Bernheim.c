/*
 * Bernheim.c
 *
 *  Created on: 14 may. 2020
 *      Author: Bernheim
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BernheimTP2.h"
#include "Validaciones.h"


int menuInformar()
{
    int opcion;

    system("cls");
    printf("**** MENU INFORMES ****\n\n");
    printf("1- Ordenar por apellido y sector\n");
    printf("2- Sueldos\n");
    printf("3- Volver al menu principal\n\n");
    printf("Indique la opcion: ");
    scanf("%d",&opcion);

    return opcion;

}
void informar(eEmpleado vec[],int tam)
{
    char seguir='s';
    char confirma;
    do
    {

        switch(menuInformar())
        {
        case 1:
            informarEmpleados(vec,tam);
            system("pause");
            break;
        case 2:
            informarSueldos(vec,tam);
            system("pause");
            break;
        case 3:
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
        fflush(stdin);
    }
    while(seguir=='s');
}
int mostrarMenu()
{
    int opcion;
    system("cls");
    printf("**** Menu de opciones ****\n\n");
    printf("1- Alta empleado\n");
    printf("2- Modificar empleado\n");
    printf("3- Baja empleado\n");
    printf("4- Informes\n");
    printf("5- Salir\n");
    printf("Indique la opcion: ");
    scanf("%d",&opcion);

    return opcion;
}
void inicializarEmpleados(eEmpleado vec[],int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}
int altaEmpleado(int idX,eEmpleado vec[], int tam)
{
    int todoOK = -1;
    int indice = buscarLibre(vec,tam);

    eEmpleado auxEmpleado;
    int auxInt;
    char auxChar[51];
    float auxFloat;

    system("cls");
    printf("***** ALTA EMPLEADO *****\n\n");

    if(indice == -1)
    {
        printf("Sistema completo\n\n");
    }
    else
    {
    	while(todoOK==-1)
    	{
    		//NOMBRE
    		if((utn_getCadena(auxChar, 51,2,"Ingrese nombre: ","Error. Reingrese el nombre\n"))==0)
    		{
    			strcpy(auxEmpleado.nombre,auxChar);
    		}
    		else
    		{
    			printf("Se quedo sin intentos para ingresar el nombre\n\n");
    			todoOK=0;
    			break;
    		}
    		//APELLIDO
    		if((utn_getCadena(auxChar,51,2,"Ingrese el apellido: ","Error. Reingrese el apellido\n"))==0)
    		{
    			strcpy(auxEmpleado.apellido,auxChar);
    		}
    		else
    		{
    			printf("Se quedo sin intentos para ingresar el apellido\n\n");
    			todoOK=0;
    			break;
    		}
    		//SECTOR
    		if((utn_getEntero(&auxInt,2,"Ingrese el sector: ","Error. Reingrese el sector\n",1,1000))==0)
    		{
    			auxEmpleado.sector=auxInt;
    		}
    		else
    		{
    			printf("Se quedo sin intentos para ingresar el sector\n");
    			todoOK=0;
    			break;
    		}
    		//SUELDO
    		if((utn_getFlotante(&auxFloat,2,"Ingrese el sueldo: ","Error. Reingrese el sueldo\n",1,999999999))==0)
    		{
    			auxEmpleado.sueldo=auxFloat;
    			todoOK=1;
    		}
    		else
    		{
    			printf("Se quedo sin intentos para ingresar el sueldo\n");
    			todoOK=0;
    			break;
    		}

    	}
        if(todoOK==1)
        {
        printf("\n\nEl id del nuevo empleado es: %d\n\n",idX);
        auxEmpleado.isEmpty = 0;
        auxEmpleado.id = idX;
        vec[indice] = auxEmpleado;
        }



    }


    return todoOK;
}
int buscarLibre(eEmpleado vec[],int tam)
{

    int indice = -1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;

}
int buscarEmpleado(int id, eEmpleado vec[], int tam)
{
    int indice = -1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].id == id && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;

}
void modificarEmpleado(eEmpleado vec[],int tam)
{
    int indice;
    int id;
    char confirma;
    float auxFloat;
    int auxInt;
    char auxChar[51];

    system("cls");
    printf("***** MODIFICAR EMPLEADO *****\n\n");

    mostrarEmpleados(vec,tam);

    if((utn_getEntero(&auxInt,2,"\nIngrese el id: ","Error. Reingrese el id\n",1,1000))==0)
    {
    	id=auxInt;
    }
    else
    {
    	printf("Se quedo sin intentos para ingresar el id\n\n");
    	id=-1;
    }

    indice = buscarEmpleado(id,vec,tam);

    if(indice== -1)
    {
    	if(id==-1)
    	{
    		printf("Se cancelo la operacion\n");
    	}
    	else
    	{
    		printf("No hay registro de algun empleado con el id: %d\n", id);
    	}

    }
    else
    {
        system("cls");
        printf("Id     Nombre   Apellido   Sector    Sueldo \n");
        mostrarEmpleado(vec[indice]);

        printf("\nConfirma modificar este empleado? : ");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma=='s')
        {
            switch(menuModificar())
            {
            case 'a':
            	//NOMBRE
        		if((utn_getCadena(auxChar, 51,2,"Ingrese el nuevo nombre: ","Error. Reingrese el nuevo nombre\n"))==0)
        		{
        			strcpy(vec[indice].nombre,auxChar);
        			printf("\n\nSe modifico el nombre con exito\n\n");
        		}
        		else
        		{
        			printf("Se quedo sin intentos para ingresar el nuevo nombre\n\n");

        		}
                break;
            case 'b':
            	//APELLIDO
        		if((utn_getCadena(auxChar,51,2,"Ingrese el nuevo apellido: ","Error. Reingrese nuevo apellido\n"))==0)
        		{
        			strcpy(vec[indice].apellido,auxChar);
        			printf("\n\nSe modifico el apellido con exito\n\n");
        		}
        		else
        		{
        			printf("Se quedo sin intentos para ingresar el apellido\n\n");
        		}
                break;
            case 'c':
        		if((utn_getEntero(&auxInt,2,"Ingrese el nuevo sector: ","Error. Reingrese el nuevo sector\n",1,1000))==0)
        		{
        			vec[indice].sector=auxInt;
        			printf("\n\nSe modifico el sector con exito\n\n");
        		}
        		else
        		{
        			printf("Se quedo sin intentos para ingresar el nuevo sector\n");
        		}
                break;
            case 'd':
        		if((utn_getFlotante(&auxFloat,2,"Ingrese el nuevo sueldo: ","Error. Reingrese el nuevo sueldo\n",1,999999999))==0)
        		{
        			vec[indice].sueldo=auxFloat;
        			printf("\n\nSe modifico el sueldo con exito\n\n");
        		}
        		else
        		{
        			printf("Se quedo sin intentos para ingresar el nuevo sueldo\n");
        		}
                break;
            default:
                printf("\n\nIngrese una opcion valida.");
            }
        }
        else
        {
            printf("\n\nSe cancelo la operacion\n\n");
        }

    }

}
void mostrarEmpleado(eEmpleado x)
{
    printf("%d   %10s   %10s      %d     %.2f   \n", x.id,x.nombre,x.apellido,x.sector,x.sueldo);

}
void mostrarEmpleados(eEmpleado vec[],int tam)
{
    int flag=0;
    system("cls");
    printf("\nListado de empleados\n");
    printf("Id      Nombre     Apellido   Sector    Sueldo \n");

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            mostrarEmpleado(vec[i]);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("\nNo hay empleados que listar\n\n");
    }

}
int menuModificar()
{
    char opcion;

    printf("\n\nQUE DESEA MODIFICAR?\n\n");
    printf("a-Nombre\n");
    printf("b-Apellido\n");
    printf("c-Sector\n");
    printf("d-Sueldo\n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%c",&opcion);

    return opcion;

}
void bajaEmpleado(eEmpleado vec[], int tam)
{
    int indice;
    int id;
    char confirma;
    int auxInt;

    system("cls");
    printf("****BAJA EMPLEADO****\n\n");

    mostrarEmpleados(vec,tam);

    if((utn_getEntero(&auxInt,2,"\nIngrese el id: ","Error. Reingrese el id\n",1,1000))==0)
    {
    	id=auxInt;
    }
    else
    {
    	printf("Se quedo sin intentos para ingresar el id\n\n");
    	id=-1;
    }

    indice = buscarEmpleado(id,vec,tam);

    if(indice== -1)
    {
    	if(id==-1)
    	{
    		printf("Se cancelo la operacion\n");
    	}
    	else
    	{
    		printf("No hay registro de algun empleado con el id: %d\n", id);
    	}
    }
    else
    {
        printf("Id     Nombre   Apellido   Sector    Sueldo \n");
        mostrarEmpleado(vec[indice]);
        printf("Confirma la baja? : ");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma=='s')
        {
            vec[indice].isEmpty=1;
            printf("Se ha realizado la baja con exito\n\n");
        }
        else
        {
            printf("Se cancelo la operacion\n\n");
        }

    }

}
void informarEmpleados(eEmpleado vec[], int tam)
{
    int orden;
    eEmpleado auxEmpleado;


    printf("Ingrese 0 para ordenar de manera descendente o 1 para ordenar de manera ascendente: ");
    scanf("%d",&orden);


        for(int i=0; i<tam-1; i++)
        {
        for(int j=i+1; j<tam; j++)
        {
            if(orden==1)
            {
                if(vec[i].isEmpty==0 && vec[i].sector>vec[j].sector)
                {
                    auxEmpleado=vec[i];
                    vec[i]=vec[j];
                    vec[j]=auxEmpleado;
                }
                else
                {
                    if(vec[i].sector==vec[j].sector && strcmp(vec[i].apellido,vec[j].apellido)>0)
                    {
                        auxEmpleado=vec[i];
                        vec[i]=vec[j];
                        vec[j]=auxEmpleado;
                    }
                }
            }
            else
            {
                if(vec[i].isEmpty==0 && vec[i].sector<vec[j].sector)
                {
                    auxEmpleado=vec[i];
                    vec[i]=vec[j];
                    vec[j]=auxEmpleado;
                }
                else
                {
                    if(vec[i].sector==vec[j].sector && strcmp(vec[i].apellido,vec[j].apellido)>0)
                    {
                        auxEmpleado=vec[i];
                        vec[i]=vec[j];
                        vec[j]=auxEmpleado;
                    }
                }
            }

        }
    }
    mostrarEmpleados(vec,tam);


}
void informarSueldos(eEmpleado vec[],int tam)
{
    float total = 0;
    int cantidadEmpleados = 0;
    float promedio;
    int empleadosEncimaPromedio = 0;

    for(int i=0; i<tam-1; i++)
    {
        if(vec[i].isEmpty==0)
        {
            total+=vec[i].sueldo;
            cantidadEmpleados++;
        }
    }

    promedio= total/cantidadEmpleados;

    for(int i=0; i<tam-1; i++)
    {
        if(vec[i].isEmpty==0 && vec[i].sueldo>promedio)
        {
            empleadosEncimaPromedio++;
        }
    }


    system("cls");
    printf("***** SUELDOS *****\n\n");
    printf("El total de los sueldos es: %.f\n",total);
    printf("El promedio de los sueldos es: %.f\n",promedio);
    printf("%d empleados superan el sueldo promedio\n\n",empleadosEncimaPromedio);

}


