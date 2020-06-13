#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "validaciones.h"

int buscarLibre( int* indice, Employee** vec, int tam)
{
    *indice = -1;
    int todoOk = 0;

    if( vec != NULL && indice != NULL)
    {
        todoOk=1;
        for(int i=0; i < tam; i++)
        {
            if( *(vec + i) == NULL)
            {
                *indice = i;
                break;
            }
        }
    }

    return todoOk;
}

int mostrarEmpleados( LinkedList* lista)
{
    int todoOk = 1;
    int tam;

    if(lista != NULL)
    {
        todoOk = 0;
        printf("  ID      NOMBRE    HORAS TRABAJADAS  SUELDO\n");
        tam = ll_len(lista);

        for (int i=0; i<tam; i++)
        {
            mostrarEmpleado(lista, i);
        }
    }
    else
    {
        printf("No hay empleados que listar\n");
    }
    return todoOk;
}

void mostrarEmpleado( LinkedList* lista,int indice)
{
    Employee* employee = (Employee*) employee_new();

    employee = ll_get(lista, indice);
    printf("%4d  %12s  %8d         %d \n", employee->id, employee->nombre, employee->horasTrabajadas, employee->sueldo);

}

int employee_setId(Employee* employee,int id)
{
    int todoOk = 1;
    if(employee != NULL)
    {
        employee->id = id;
        todoOk=0;
    }
    return todoOk;
}

int employee_getId(Employee* employee,int* id)
{
    int todoOk = 1;

    if(employee != NULL && id != NULL)
    {
        *id = employee->id;
        todoOk = 0;
    }
    return todoOk;
}

int employee_setNombre(Employee* employee,char* name)
{
    int todoOk = 1;

    if(employee != NULL )
    {
        strcpy(employee->nombre,name);
        todoOk = 0;
    }
    return todoOk;
}

int employee_getNombre(Employee* employee,char* name)
{
    int todoOk = 1;

    if(employee != NULL && name != NULL)
    {
        strcpy(name,employee->nombre);
        todoOk = 0;
    }
    return todoOk;
}

int employee_setHorasTrabajadas(Employee* employee,int horasTrabajadas)
{
    int todoOk = 1;

    if(employee != NULL)
    {
        employee->horasTrabajadas = horasTrabajadas;
        todoOk = 0;
    }
    return todoOk;
}

int employee_getHorasTrabajadas(Employee* employee,int* horasTrabajadas)
{
    int todoOk = 1;

    if(employee != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = employee->horasTrabajadas;
        todoOk = 0;
    }
    return todoOk;
}

int employee_setSueldo(Employee* employee,int sueldo)
{
    int todoOk = 1;
    if(employee != NULL)
    {
        employee->sueldo = sueldo;
        todoOk=0;
    }
    return todoOk;
}

int employee_getSueldo(Employee* employee,int* sueldo)
{
    int todoOk = 1;

    if(employee != NULL && sueldo != NULL)
    {
        *sueldo = employee->sueldo;
        todoOk = 0;
    }
    return todoOk;
}

Employee* employee_new()
{
    Employee* newEmployee = (Employee*) malloc(sizeof(Employee));

    return newEmployee;
}

Employee* employee_newParamS(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
    return employee_newParametros(atoi(idStr),nombreStr,atoi(horasTrabajadasStr),atoi(sueldoStr));
}

Employee* employee_newParametros(int id,char* nombre,int horasTrabajadas,int sueldo)
{
    Employee* newEmployee = employee_new();

    if(newEmployee != NULL)
    {
        employee_setId(newEmployee,id);
        employee_setNombre(newEmployee,nombre);
        employee_setSueldo(newEmployee,sueldo);
        employee_setHorasTrabajadas(newEmployee,horasTrabajadas);
    }
    else
    {
        free(newEmployee);
        newEmployee = NULL;
    }
    return newEmployee;
}

int altaEmployee(LinkedList* lista)
{
    int todoOK = -1;
    char auxChar[128];
    int auxInt;
    int indice;

    Employee* auxEmployee;

    auxEmployee = (Employee*) employee_new();

    if(auxEmployee != NULL && lista != NULL)
    {

        system("cls");

        printf("***** ALTA EMPLEADO *****\n\n");

        while(todoOK==-1)
        {
            //ID
            if((utn_getEntero(&auxInt,2,"Ingrese el id: ","Error. Reingrese el id\n",1,10000000))==0)
            {
                if(findEmployeeById(lista,auxInt,&indice)==1)
                {
                    employee_setId(auxEmployee,auxInt);
                }
                else
                {
                    printf("El id ingresado ya existe\n");
                    todoOK=1;
                    break;
                }
            }
            else
            {
                printf("Se quedo sin intentos para ingresar el id\n");
                todoOK=1;
                break;
            }
            //NOMBRE
            if((utn_getCadena(auxChar,128,2,"Ingrese el nombre: ","Error. Reingrese el nombre\n"))==0)
            {
                employee_setNombre(auxEmployee,auxChar);
            }
            else
            {
                printf("Se quedo sin intentos para ingresar el nombre\n");
                todoOK=1;
                break;
            }
            //HORAS TRABAJADAS
            if((utn_getEntero(&auxInt,2,"Ingrese horas trabajadas: ","Error. Reingrese horas trabajadas\n",1,10000000))==0)
            {
                employee_setHorasTrabajadas(auxEmployee,auxInt);
            }
            else
            {
                printf("Se quedo sin intentos para ingresar las horas trabajadas\n");
                todoOK=1;
                break;
            }
            //SUELDO
            if((utn_getEntero(&auxInt,2,"Ingrese el sueldo: ","Error. Reingrese el sueldo\n",1,99999999))==0)
            {
                employee_setSueldo(auxEmployee,auxInt);
                todoOK=0;
            }
            else
            {
                printf("Se quedo sin intentos para ingresar el sueldo\n");
                todoOK=1;
                break;
            }

        }
        if(todoOK==0)
        {
            if(ll_add(lista,auxEmployee)==0)
            {
                printf("Alta exitosa\n");
            }
            else
            {
                printf("No se pudo realizar el alta\n");
            }
        }
        else if(todoOK == 1 || todoOK ==-1)
        {
            printf("Se cancelo el alta\n");
            free(auxEmployee);
        }



    }

    free(auxEmployee);


    return todoOK;
}

int employeeMod(LinkedList* lista)
{
    int todoOk = 1;
    int id;
    int indice;
    char seguir = 's';
    char confirma;


    mostrarEmpleados(lista);
    if(utn_getEntero(&id,2,"\nIngrese el id del empleado a modificar: ","Error. Reingrese el id\n",1,10000000)==0)
    {
        if(findEmployeeById(lista,id,&indice)==0)
        {
            do
            {
                switch(menuModEmployee())
                {
                case 1:
                    modificarId(lista,indice);
                    break;
                case 2:
                    modificarNombre(lista,indice);
                    break;
                case 3:
                    modificarHoras(lista,indice);
                    break;
                case 4:
                    modificarSueldo(lista,indice);
                    break;
                case 5:
                    printf("Confirma salida: ");
                    fflush(stdin);
                    scanf("%c",&confirma);
                    if(confirma=='s')
                    {
                        seguir='n';
                    }
                    break;
                }
                system("pause");
            }
            while(seguir=='s');
        }
        else
        {
            printf("No hay ningun empleado con el id: %d",id);
        }
    }
    else
    {
        printf("Se quedo sin intentos para ingresar un id valido\n");
    }




    return todoOk;
}

int menuModEmployee()
{
    int opcion;

    system("cls");
    printf("**** MODIFICAR EMPLEADO ****\n\n");
    printf("1. Modificar Id\n");
    printf("2. Modificar Nombre\n");
    printf("3. Modificar Horas trabajadas\n");
    printf("4. Modificar Sueldo\n");
    printf("5. Salir\n\n");

    utn_getEntero(&opcion,2,"Ingrese una opcion: ","Error. Reingrese opcion",1,5);

    return opcion;
}

int modificarId(LinkedList* lista, int indice)
{
    int todoOk = 1;
    int id;

    Employee* auxEmployee;

    auxEmployee = ll_get(lista,indice);

        if(utn_getEntero(&id,2,"Ingrese el nuevo ID: ","Error. Reingrese el nuevo ID\n",0,10000)==0)
        {
            if(findEmployeeById(lista,id,&indice)==1)
            {
                printf("Se modifico el id por: %d",id);
                auxEmployee->id = id;
                todoOk = 0;
            }
            else
            {
                printf("El id ingresada ya existe\n");
            }
        }
        else
        {
            printf("Se quedo sin intentos para ingresar el nuevo id\n");
        }



    return todoOk;
}

int modificarNombre(LinkedList* lista,int  indice)
{

    int todoOk = 1;
    char nuevoNombre[128];

    Employee* auxEmployee;
    auxEmployee = ll_get(lista, indice);

    if(utn_getCadena(nuevoNombre,128,2,"Ingrese el nuevo nombre: ", "Error. Reingrese el nuevo nombre\n")==0)
    {
        printf("El nombre %s se modifico por %s\n",auxEmployee->nombre,nuevoNombre);
        employee_setNombre(auxEmployee,nuevoNombre);
        todoOk = 0;
    }
    else
    {
        printf("Se quedo sin intentos para ingresar el nuevo nombre\n");
    }

    return todoOk;
}

int modificarHoras(LinkedList* lista,int  indice)
{

    int todoOk = 1;
    int horas;

    Employee* auxEmployee;
    auxEmployee = ll_get(lista,indice);

    if(utn_getEntero(&horas,2,"Ingrese nueva cantidad de horas: ","Error. Reingrese nueva cantidad de horas\n",1,10000000)==0)
    {
        printf("Se modificaron las horas trabajadas a: %d",horas);
        employee_setHorasTrabajadas(auxEmployee,horas);
        todoOk = 0;
    }
    else
    {
        printf("Se quedo sin intentos para ingresar las nuevas horas trabajadas\n");
    }

    return todoOk;
}

int modificarSueldo(LinkedList* lista,int  indice)
{

    int todoOk = 1;
    int sueldo;

    Employee* auxEmployee;
    auxEmployee = ll_get(lista,indice);

    if(utn_getEntero(&sueldo,2,"Ingrese nuevo sueldo: ","Error. Reingrese nuevo sueldo\n",1,10000000)==0)
    {
        printf("Se modifico el sueldo a: %d",sueldo);
        employee_setSueldo(auxEmployee,sueldo);
        todoOk = 0;
    }
    else
    {
        printf("Se quedo sin intentos para ingresar el nuevo sueldo\n");
    }

    return todoOk;
}

int bajaEmpleado(LinkedList* lista)
{
    int indice;
    int id;
    char confirma;
    int todoOk = 1;

    system("cls");
    printf("****BAJA EMPLEADO ****\n\n");

    if(utn_getEntero(&id,2,"Ingrese id del empleado: ","Error. Reingrese el id\n",1,10000)==0)
    {
        if(findEmployeeById(lista,id,&indice)==0)
        {

            system("cls");
            printf("****BAJA EMPLEADO ****\n\n");
            printf("  ID      NOMBRE    HORAS TRABAJADAS  SUELDO\n");
            mostrarEmpleado(lista,indice);

            printf("Confirma la baja? : ");
            fflush(stdin);
            scanf("%c",&confirma);

            if(confirma == 's')
            {
                if(ll_remove(lista,indice)==0)
                   {
                       printf("Se realizo al baja con exito\n");
                       todoOk = 0;
                   }
                   else
                    {
                        printf("No se pudo realizar la baja\n");
                    }
            }
            else
            {
                printf("Se cancelo la baja\n");
            }
        }
        else
        {
            printf("No hay ningun empleado con el id: %d",id);
        }
    }
    else
    {
        printf("Se quedo sin intentos para ingresar el id\n");
    }

    return todoOk;
}

int findEmployeeById(LinkedList* lista, int id,int* indice)
{
    int tam = ll_len(lista);
    int todoOk = 1;
    Employee* auxEmployee;
    *indice = -1;

    for(int i = 0; i < tam; i++)
    {
        auxEmployee = (Employee*) ll_get(lista,i);
        if(auxEmployee->id == id)
        {
            *indice = i;
            todoOk = 0;
            break;
        }
    }

    return todoOk;
}

int employee_CompararId(void * a, void* b)
{
    int retorno = 0;
    Employee* p1;
    Employee* p2;

    if(a != NULL && b != NULL)
    {
        p1 = (Employee*) a;
        p2 = (Employee*) b;

        if( p1->id > p2->id)
        {
            retorno = 1;
        }
        else if(p1->id < p2->id)
        {
            retorno = -1;
        }
        }



    return retorno;
}

int employee_CompararNombre(void * a, void* b)
{
    int retorno = 0;
    Employee* p1;
    Employee* p2;

    if(a != NULL && b != NULL)
    {
        p1 = (Employee*) a;
        p2 = (Employee*) b;

        retorno = strcmp(p1->nombre,p2->nombre);

    }


    return retorno;
}

int employee_CompararHoras(void * a, void* b)
{
    int retorno = 0;
    Employee* p1;
    Employee* p2;

    if(a != NULL && b != NULL)
    {
        p1 = (Employee*) a;
        p2 = (Employee*) b;

        if( p1->horasTrabajadas > p2->horasTrabajadas)
        {
            retorno = 1;
        }
        else if(p1->horasTrabajadas < p2->horasTrabajadas)
        {
            retorno = -1;
        }
        }


    return retorno;
}

int employee_CompararSueldo(void * a, void* b)
{
    int retorno = 0;
    Employee* p1;
    Employee* p2;

    if(a != NULL && b != NULL)
    {
        p1 = (Employee*) a;
        p2 = (Employee*) b;

        if( p1->sueldo > p2->sueldo)
        {
            retorno = 1;
        }
        else if(p1->sueldo < p2->sueldo)
        {
            retorno = -1;
        }
        }



    return retorno;
}

int menuSortEmployee()
{
    int opcion;

    system("cls");
    printf("**** ORDENAR EMPLEADOS ****\n\n");
    printf("1. Ordenar por Id\n");
    printf("2. Ordenar por Nombre\n");
    printf("3. Ordenar por Horas trabajadas\n");
    printf("4. Ordenar por Sueldo\n");


    utn_getEntero(&opcion,2,"Ingrese una opcion: ","Error. Reingrese opcion",1,4);

    return opcion;
}

int sortEmployee(LinkedList* lista)
{
    int todoOk = 1;
    int orden;

                switch(menuSortEmployee())
                {
                case 1:
                    if(utn_getEntero(&orden,2,"Ingrese 1 para orden ascendente o 0 para descendente: ","Error. Reingrese el orden\n",0,1)==0)
                    {
                        ll_sort(lista,employee_CompararId,orden);
                        printf("Se pudieron ordenar los empleados correctamente\n");
                        todoOk = 0;
                    }
                    else
                    {
                        printf("Se quedo sin intentos para elegir el orden\n");
                    }
                    break;
                case 2:
                    if(utn_getEntero(&orden,2,"Ingrese 1 para orden ascendente o 0 para descendente: ","Error. Reingrese el orden\n",0,1)==0)
                    {
                        ll_sort(lista,employee_CompararNombre,orden);
                        printf("Se pudieron ordenar los empleados correctamente\n");
                        todoOk = 0;
                    }
                    else
                    {
                        printf("Se quedo sin intentos para elegir el orden\n");
                    }
                    break;
                case 3:
                    if(utn_getEntero(&orden,2,"Ingrese 1 para orden ascendente o 0 para descendente: ","Error. Reingrese el orden\n",0,1)==0)
                    {
                        ll_sort(lista,employee_CompararHoras,orden);
                        printf("Se pudieron ordenar los empleados correctamente\n");
                        todoOk = 0;
                    }
                    else
                    {
                        printf("Se quedo sin intentos para elegir el orden\n");
                    }
                    break;
                case 4:
                    if(utn_getEntero(&orden,2,"Ingrese 1 para orden ascendente o 0 para descendente: ","Error. Reingrese el orden\n",0,1)==0)
                    {
                        ll_sort(lista,employee_CompararSueldo,orden);
                        printf("Se pudieron ordenar los empleados correctamente\n");
                        todoOk = 0;
                    }
                    else
                    {
                        printf("Se quedo sin intentos para elegir el orden\n");
                    }
                    break;
                }



    return todoOk;
}
