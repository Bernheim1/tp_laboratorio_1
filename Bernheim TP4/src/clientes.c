#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "validaciones.h"


int mostrarClientes( LinkedList* lista)
{
    int todoOk = 1;
    int tam;

    if(lista != NULL)
    {
        todoOk = 0;
        printf("  ID   NOMBRE             APELLIDO                  CALLE              NUMERO CALLE        DINERO EN CUENTA \n");
        tam = ll_len(lista);

        for (int i=0; i<tam; i++)
        {
            mostrarCliente(lista, i);
        }
    }
    else
    {
        printf("No hay clientes que listar\n");
    }
    return todoOk;
}

void mostrarCliente( LinkedList* lista,int indice)
{
    eCliente* cliente;

    cliente = ll_get(lista, indice);
    printf("%4d  %-16s    %-20s    %-20s    %-10d          $%0.2f  \n", cliente->id, cliente->nombre,cliente->apellido, cliente->calle,cliente->numeroCalle, cliente->dinero);

}

int cliente_setId(eCliente* cliente,int id)
{
    int todoOk = 1;
    if(cliente != NULL)
    {
        cliente->id = id;
        todoOk=0;
    }
    return todoOk;
}

int cliente_getId(eCliente* cliente,int* id)
{
    int todoOk = 1;

    if(cliente != NULL && id != NULL)
    {
        *id = cliente->id;
        todoOk = 0;
    }
    return todoOk;
}

int cliente_setNombre(eCliente* cliente,char* nombre)
{
    int todoOk = 1;

    if(cliente != NULL )
    {
        strcpy(cliente->nombre,nombre);
        todoOk = 0;
    }
    return todoOk;
}

int cliente_getNombre(eCliente* cliente,char* nombre)
{
    int todoOk = 1;

    if(cliente != NULL && nombre != NULL)
    {
        strcpy(nombre,cliente->nombre);
        todoOk = 0;
    }
    return todoOk;
}

int cliente_setApellido(eCliente* cliente,char* apellido)
{
    int todoOk = 1;

    if(cliente != NULL )
    {
        strcpy(cliente->apellido,apellido);
        todoOk = 0;
    }
    return todoOk;
}

int cliente_getApellido(eCliente* cliente,char* apellido)
{
    int todoOk = 1;

    if(cliente != NULL && apellido != NULL)
    {
        strcpy(apellido,cliente->apellido);
        todoOk = 0;
    }
    return todoOk;
}

int cliente_setCalle(eCliente* cliente,char* calle)
{
    int todoOk = 1;

    if(cliente != NULL )
    {
        strcpy(cliente->calle,calle);
        todoOk = 0;
    }
    return todoOk;
}

int cliente_getCalle(eCliente* cliente,char* calle)
{
    int todoOk = 1;

    if(cliente != NULL && calle != NULL)
    {
        strcpy(calle,cliente->calle);
        todoOk = 0;
    }
    return todoOk;
}

int cliente_setNumeroCalle(eCliente* cliente,int numeroCalle)
{
    int todoOk = 1;
    if(cliente != NULL)
    {
        cliente->numeroCalle = numeroCalle;
        todoOk=0;
    }
    return todoOk;
}

int cliente_getNumeroCalle(eCliente* cliente,int* numeroCalle)
{
    int todoOk = 1;

    if(cliente != NULL && numeroCalle != NULL)
    {
        *numeroCalle = cliente->numeroCalle;
        todoOk = 0;
    }
    return todoOk;
}

int cliente_setDinero(eCliente* cliente,float dinero)
{
    int todoOk = 1;

    if(cliente != NULL)
    {
        cliente->dinero = dinero;
        todoOk = 0;
    }
    return todoOk;
}

int cliente_getDinero(eCliente* cliente,float* dinero)
{
    int todoOk = 1;

    if(cliente != NULL && dinero != NULL)
    {
        *dinero = cliente->dinero;
        todoOk = 0;
    }
    return todoOk;
}

eCliente* cliente_new()
{
    eCliente* newCliente = (eCliente*) malloc(sizeof(eCliente));

    return newCliente;
}

eCliente* cliente_newParamS(char* idStr, char* nombreStr, char* apellidoStr,char* calleStr,char* numeroCalle, char* dineroStr)
{
    return cliente_newParametros(atoi(idStr),nombreStr,apellidoStr,calleStr,atoi(numeroCalle),atof(dineroStr));
}

eCliente* cliente_newParametros(int id,char* nombre,char* apellido,char* calle,int numeroCalle,float dinero)
{
    eCliente* newCliente = cliente_new();

    if(newCliente != NULL)
    {
        cliente_setId(newCliente,id);
        cliente_setNombre(newCliente,nombre);
        cliente_setApellido(newCliente,apellido);
        cliente_setCalle(newCliente,calle);
        cliente_setNumeroCalle(newCliente,numeroCalle);
        cliente_setDinero(newCliente,dinero);
    }
    else
    {
        free(newCliente);
        newCliente = NULL;
    }
    return newCliente;
}

int obtenerId(int* id)
{
    int todoOk = -1;
    *id = 1001;

    FILE* f;

    f=fopen("proximoId.bin","rb");

    if(f != NULL)
    {
        fread(id,sizeof(int),1,f);

        fclose(f);
        todoOk = 0;
    }
    return todoOk;
}

int actualizarId(int id)
{
    int todoOk = -1;
    id++;

    FILE* f = fopen("proximoId.bin","wb");

    if( f != NULL )
    {
        fwrite(&id,sizeof(int),1,f);

        fclose(f);
        todoOk = 0;
    }
    return todoOk;
}

int altaCliente(LinkedList* lista)
{
    int todoOK = -1;
    char auxChar[128];
    float auxFloat;
    int auxInt;

    eCliente* auxCliente;

    auxCliente = (eCliente*) cliente_new();

    if(auxCliente != NULL && lista != NULL)
    {

        system("cls");

        printf("***** ALTA CLIENTE *****\n\n");

        while(todoOK==-1)
        {
            //NOMBRE
            if((utn_getCadena(auxChar,128,2,"Ingrese nombre: ","Error. Reingrese nombre\n"))==0)
            {
                cliente_setNombre(auxCliente,auxChar);
            }
            else
            {
                printf("Se quedo sin intentos para ingresar el nombre\n");
                todoOK=1;
                break;
            }
            //APELLIDO
            if((utn_getCadena(auxChar,128,2,"\nIngrese apellido: ","Error. Reingrese apellido\n"))==0)
            {
                cliente_setApellido(auxCliente,auxChar);
            }
            else
            {
                printf("Se quedo sin intentos para ingresar el apellido\n");
                todoOK=1;
                break;
            }
            //CALLE
            printf("\nIngrese calle: ");
            scanf("%s",auxChar);
            cliente_setCalle(auxCliente,auxChar);
            //NUMERO CALLE
            if((utn_getEntero(&auxInt,2,"\nIngrese numeracion: ","Error. Reingrese numeracion\n",0,10000000))==0)
            {
                cliente_setNumeroCalle(auxCliente,auxInt);
            }
            else
            {
                printf("Se quedo sin intentos para ingresar la numeracion\n");
                todoOK=1;
                break;
            }
            //DINERO
            if((utn_getFlotante(&auxFloat,2,"\nIngrese el dinero en cuenta: ","Error. Reingrese el dinero en cuenta\n",1,10000000))==0)
            {
                cliente_setDinero(auxCliente,auxFloat);
                todoOK = 0;
            }
            else
            {
                printf("Se quedo sin intentos para ingresar el dinero en cuenta\n");
                todoOK=1;
                break;
            }

        }
        if(todoOK==0)
        {
            obtenerId(&auxInt);
            cliente_setId(auxCliente,auxInt);
            actualizarId(auxInt);
            if(ll_add(lista,auxCliente)==0)
            {
                printf("El id del nuevo clientes es: %d\n",auxInt);
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
            free(auxCliente);
        }

    }

    return todoOK;
}

int clienteMod(LinkedList* lista)
{
    int todoOk = 1;
    int id;
    int indice;
    char seguir = 's';
    char confirma;

    system("cls");
    mostrarClientes(lista);
    if(utn_getEntero(&id,2,"\nIngrese el id del cliente a modificar: ","Error. Reingrese el id\n",1,10000000)==0)
    {
        todoOk = 0;
        if(findClienteById(lista,id,&indice)==0)
        {
            do
            {
                switch(menuModCliente())
                {
                case 1:
                    modificarNombre(lista,indice);
                    system("pause");
                    break;
                case 2:
                    modificarApellido(lista,indice);
                    system("pause");
                    break;
                case 3:
                    modificarCalle(lista,indice);
                    system("pause");
                    break;
                case 4:
                    modificarNumeroCalle(lista,indice);
                    system("pause");
                    break;
                case 5:
                    modificarDinero(lista,indice);
                    system("pause");
                    break;
                case 6:
                    printf("Confirma salida: ");
                    fflush(stdin);
                    scanf("%c",&confirma);
                    if(confirma=='s')
                    {
                        seguir='n';
                    }
                    break;
                }
            }
            while(seguir=='s');
        }
        else
        {
            printf("No hay ningun cliente con el id: %d",id);
        }
    }
    else
    {
        printf("Se quedo sin intentos para ingresar un id valido\n");
    }




    return todoOk;
}

int menuModCliente()
{
    int opcion;

    system("cls");
    printf("**** MODIFICAR CLIENTE ****\n\n");
    printf("1. Modificar Nombre\n");
    printf("2. Modificar Apellido\n");
    printf("3. Modificar Calle\n");
    printf("4. Modificar Numero de Calle\n");
    printf("5. Modificar Dinero en cuenta\n");
    printf("6. Salir\n\n");

    utn_getEntero(&opcion,2,"Ingrese una opcion: ","Error. Reingrese opcion",1,6);

    return opcion;
}


int modificarNombre(LinkedList* lista,int  indice)
{
    int todoOk = 1;
    char nuevoNombre[128];

    eCliente* auxCliente;
    auxCliente = ll_get(lista, indice);

    if(utn_getCadena(nuevoNombre,128,2,"Ingrese el nuevo nombre: ", "Error. Reingrese el nuevo nombre\n")==0)
    {
        printf("El nombre %s se modifico por %s\n",auxCliente->nombre,nuevoNombre);
        cliente_setNombre(auxCliente,nuevoNombre);
        todoOk = 0;
    }
    else
    {
        printf("Se quedo sin intentos para ingresar el nuevo nombre\n");
    }

    return todoOk;
}

int modificarApellido(LinkedList* lista,int  indice)
{

    int todoOk = 1;
    char nuevoApellido[128];

    eCliente* auxCliente;
    auxCliente = ll_get(lista, indice);

    if(utn_getCadena(nuevoApellido,128,2,"Ingrese el nuevo apellido: ", "Error. Reingrese el nuevo apellido\n")==0)
    {
        printf("El apellido %s se modifico por %s\n",auxCliente->apellido,nuevoApellido);
        cliente_setApellido(auxCliente,nuevoApellido);
        todoOk = 0;
    }
    else
    {
        printf("Se quedo sin intentos para ingresar el nuevo apellido\n");
    }

    return todoOk;
}

int modificarCalle(LinkedList* lista,int  indice)
{
    int todoOk = 1;
    char nuevaCalle[51];

    eCliente* auxCliente;
    auxCliente = ll_get(lista, indice);

    if(utn_getCadena(nuevaCalle,51,2,"Ingrese la nueva calle: ", "Error. Reingrese la nueva calle\n")==0)
    {
        printf("La calle %s se modifico por %s\n",auxCliente->calle,nuevaCalle);
        cliente_setCalle(auxCliente,nuevaCalle);
        todoOk = 0;
    }
    else
    {
        printf("Se quedo sin intentos para ingresar la nueva calle\n");
    }

    return todoOk;
}

int modificarNumeroCalle(LinkedList* lista,int  indice)
{
    int todoOk = 1;
    int nuevoNumeroCalle;

    eCliente* auxCliente;
    auxCliente = ll_get(lista,indice);

    if(utn_getEntero(&nuevoNumeroCalle,2,"Ingrese nuevo numero de calle: ","Error. Reingrese nuevo numero de calle\n",1,10000000)==0)
    {
        printf("Se modifico el numero de la calle a: %d\n",nuevoNumeroCalle);
        cliente_setNumeroCalle(auxCliente,nuevoNumeroCalle);
        todoOk = 0;
    }
    else
    {
        printf("Se quedo sin intentos para ingresar el numero numero de calle\n");
    }

    return todoOk;
}

int modificarDinero(LinkedList* lista,int  indice)
{

    int todoOk = 1;
    float dinero;

    eCliente* auxCliente;
    auxCliente = ll_get(lista,indice);

    if(utn_getFlotante(&dinero,2,"Ingrese nueva cantidad de dinero en cuenta: ","Error. Reingrese la nueva cantidad de dinero en cuenta\n",1,10000000)==0)
    {
        printf("Se modifico el dinero en cuenta a: %.2f\n",dinero);
        cliente_setDinero(auxCliente,dinero);
        todoOk = 0;
    }
    else
    {
        printf("Se quedo sin intentos para ingresar la nueva cantidad de dinero en cuenta\n");
    }

    return todoOk;
}

int bajaCliente(LinkedList* lista)
{
    int indice;
    int id;
    char confirma;
    int todoOk = 1;

    system("cls");
    printf("****BAJA CLIENTE ****\n\n");

    mostrarClientes(lista);
    if(utn_getEntero(&id,2,"Ingrese id del cliente: ","Error. Reingrese el id\n",1,10000)==0)
    {
        if(findClienteById(lista,id,&indice)==0)
        {

            system("cls");
            printf("****BAJA CLIENTE ****\n\n");
            printf("  ID   NOMBRE             APELLIDO                  CALLE              NUMERO CALLE        DINERO EN CUENTA \n");
            mostrarCliente(lista,indice);

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
            printf("No hay ningun cliente con el id: %d",id);
        }
    }
    else
    {
        printf("Se quedo sin intentos para ingresar el id\n");
    }

    return todoOk;
}

int findClienteById(LinkedList* lista, int id,int* indice)
{
    int tam = ll_len(lista);
    int todoOk = 1;
    eCliente* auxCliente;
    *indice = -1;

    for(int i = 0; i < tam; i++)
    {
        auxCliente = (eCliente*) ll_get(lista,i);
        if(auxCliente->id == id)
        {
            *indice = i;
            todoOk = 0;
            break;
        }
    }

    return todoOk;
}

int cliente_ComparaId(void * a, void* b)
{
    int retorno = 0;
    eCliente* p1;
    eCliente* p2;

    if(a != NULL && b != NULL)
    {
        p1 = (eCliente*) a;
        p2 = (eCliente*) b;

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

int cliente_ComparaNombre(void * a, void* b)
{
    int retorno = 0;
    eCliente* p1;
    eCliente* p2;

    if(a != NULL && b != NULL)
    {
        p1 = (eCliente*) a;
        p2 = (eCliente*) b;

        retorno = strcmp(p1->nombre,p2->nombre);

    }


    return retorno;
}

int cliente_ComparaApellido(void * a, void* b)
{
    int retorno = 0;
    eCliente* p1;
    eCliente* p2;

    if(a != NULL && b != NULL)
    {
        p1 = (eCliente*) a;
        p2 = (eCliente*) b;

        retorno = strcmp(p1->apellido,p2->apellido);

    }


    return retorno;
}

int cliente_ComparaCalle(void * a, void* b)
{
    int retorno = 0;
    eCliente* p1;
    eCliente* p2;

    if(a != NULL && b != NULL)
    {
        p1 = (eCliente*) a;
        p2 = (eCliente*) b;

        retorno = strcmp(p1->calle,p2->calle);

    }


    return retorno;
}

int cliente_ComparaNumeroCalle(void * a, void* b)
{
    int retorno = 0;
    eCliente* p1;
    eCliente* p2;

    if(a != NULL && b != NULL)
    {
        p1 = (eCliente*) a;
        p2 = (eCliente*) b;

        if( p1->numeroCalle > p2->numeroCalle)
        {
            retorno = 1;
        }
        else if(p1->numeroCalle < p2->numeroCalle)
        {
            retorno = -1;
        }
    }



    return retorno;
}

int cliente_ComparaDinero(void * a, void* b)
{
    int retorno = 0;
    eCliente* p1;
    eCliente* p2;

    if(a != NULL && b != NULL)
    {
        p1 = (eCliente*) a;
        p2 = (eCliente*) b;

        if( p1->dinero > p2->dinero)
        {
            retorno = 1;
        }
        else if(p1->dinero < p2->dinero)
        {
            retorno = -1;
        }
    }


    return retorno;
}

int menuSortClientes()
{
    int opcion;

    system("cls");
    printf("**** ORDENAR CLIENTES ****\n\n");
    printf("1. Ordenar por Id\n");
    printf("2. Ordenar por Nombre\n");
    printf("3. Ordenar por Apellido\n");
    printf("4. Ordenar por Calle\n");
    printf("5. Ordenar por Numero de Calle\n");
    printf("6. Ordenar por Dinero en Cuenta\n");


    utn_getEntero(&opcion,2,"Ingrese una opcion: ","Error. Reingrese opcion",1,5);

    return opcion;
}

int sortClientes(LinkedList* lista)
{
    int todoOk = 1;
    int orden;

    switch(menuSortClientes())
    {
    case 1:
        if(utn_getEntero(&orden,2,"Ingrese 1 para orden ascendente o 0 para descendente: ","Error. Reingrese el orden\n",0,1)==0)
        {
            ll_sort(lista,cliente_ComparaId,orden);
            printf("Se pudieron ordenar los clientes correctamente\n");
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
            ll_sort(lista,cliente_ComparaNombre,orden);
            printf("Se pudieron ordenar los clientes correctamente\n");
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
            ll_sort(lista,cliente_ComparaApellido,orden);
            printf("Se pudieron ordenar los clientes correctamente\n");
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
            ll_sort(lista,cliente_ComparaCalle,orden);
            printf("Se pudieron ordenar los clientes correctamente\n");
            todoOk = 0;
        }
        else
        {
            printf("Se quedo sin intentos para elegir el orden\n");
        }
        break;
    case 5:
        if(utn_getEntero(&orden,2,"Ingrese 1 para orden ascendente o 0 para descendente: ","Error. Reingrese el orden\n",0,1)==0)
        {
            ll_sort(lista,cliente_ComparaNumeroCalle,orden);
            printf("Se pudieron ordenar los clientes correctamente\n");
            todoOk = 0;
        }
        else
        {
            printf("Se quedo sin intentos para elegir el orden\n");
        }
        break;
    case 6:
        if(utn_getEntero(&orden,2,"Ingrese 1 para orden ascendente o 0 para descendente: ","Error. Reingrese el orden\n",0,1)==0)
        {
            ll_sort(lista,cliente_ComparaDinero,orden);
            printf("Se pudieron ordenar los clientes correctamente\n");
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

void moverCliente(LinkedList* pArrayListCliente)
{
    int id;
    int indice;
    int nuevoIndice;
    eCliente* auxCliente;

    if(pArrayListCliente!=NULL)
    {
        printf("\nIngrese id del cliente a mover: ");
        scanf("%d",&id);

        findClienteById(pArrayListCliente,id,&indice);
        if(indice != -1)
        {
            auxCliente = ll_pop(pArrayListCliente,indice);
            if(utn_getEntero(&nuevoIndice,2,"\nIngrese el nuevo indice a colocar el cliente: ","Error. Reingrese el nuevo indice\n",0,ll_len(pArrayListCliente)-1)==0)
            {
                if(auxCliente!=NULL)
                {
                    if(ll_push(pArrayListCliente,nuevoIndice,auxCliente)==0)
                    {
                        printf("Cliente desplazado del indice %d al nuevo indice %d\n\n",id,nuevoIndice);
                    }
                }
            }
            else
            {
                printf("Se quedo sin intentos para ingresar un indice valido\n");
            }

        }
        else
        {
            printf("\nNo hay ningun cliente cargado con el id ingresado\n");
        }
    }

}




