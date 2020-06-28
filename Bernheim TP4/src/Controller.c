#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "parser.h"
#include "Controller.h"


/** \brief Carga los datos de los clientes desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListClientes LinkedList*
 * \return retorna 0 si pudo abrir el archivo y cargar, sino 1
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListClientes)
{
    int todoOk = 1;

    FILE* f = fopen(path,"r");

    if(f != NULL)
    {
        if(parser_ClientesFromText(f,pArrayListClientes))
        {
            todoOk = 0;
            printf("Se cargaron los datos\n");
        }
    }
    else
    {
        printf("No se pudo abrir el archivo\n");
    }

    fclose(f);

    return todoOk;
}

/** \brief Carga los datos de los clientes desde el archivo clientes.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListClientes LinkedList*
 * \return retorna 0 si pudo abrir el archivo y cargar, sino 1
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListClientes)
{
    int todoOk = 1;
    FILE* f;

    f = fopen(path, "rb");

    if(f != NULL)
    {
        if(!parser_ClientesFromBinary(f, pArrayListClientes))
        {
            todoOk = 0;
            printf("Se cargaron los datos del archivo clientes.bin\n");
        }
        else
        {
            printf("No se pudo leer el archivo correctamente\n");
        }
    }
    else
    {
        printf("No se pudo abrir el archivo\n");
    }
    fclose(f);
    return todoOk;

}

/** \brief Alta de clientes
 *
 * \param path char*
 * \param pArrayListClientes LinkedList*
 * \return int
 *
 */
int controller_addCliente(LinkedList* pArrayListClientes)
{
    int todoOk = 1;

    if(altaCliente(pArrayListClientes)==0)
    {
        todoOk = 0;
    }
    return todoOk;
}

/** \brief Modificar datos del cliente
 *
 * \param path char*
 * \param pArrayListClientes LinkedList*
 * \return retorna 0 si pudo editar, sino 1
 *
 */
int controller_editCliente(LinkedList* pArrayListClientes)
{
    int todoOk = 1;
    if(clienteMod(pArrayListClientes)==0)
    {
        todoOk = 0;
    }
    return todoOk;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListClientes LinkedList*
 * \return retorna 0 si pudo dar de baja, sino 1
 *
 */
int controller_removeCliente(LinkedList* pArrayListClientes)
{
    int todoOk = 1;
    if(bajaCliente(pArrayListClientes)==0)
    {
        todoOk = 0;
    }
    return todoOk;
}

/** \brief Listar clientes
 *
 * \param path char*
 * \param pArrayListClientes LinkedList*
 * \return retorna 0 si pudo mostrar, sino 1
 *
 */
int controller_ListClientes(LinkedList* pArrayListClientes)
{
    int todoOk = 1;
    system("cls");
    if(mostrarClientes(pArrayListClientes)==0)
    {
        todoOk = 0;
    }
    return todoOk;
}

/** \brief Ordenar clientes
 *
 * \param path char*
 * \param pArrayListClientes LinkedList*
 * \return retorna 0 si pudo ordenar, sino 1
 *
 */
int controller_sortClientes(LinkedList* pArrayListClientes)
{
    int todoOk = 1;
    system("cls");
    if(sortClientes(pArrayListClientes)==0)
    {
        todoOk = 0;
    }
    return todoOk;
}

/** \brief Guarda los datos de los clientes en el archivo clientes.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListClientes LinkedList*
 * \return retorna 0 si pudo abrir el archivo, sino 1
 *
 */

int controller_saveAsText(char* path , LinkedList* pArrayListClientes)
{
	int todoOk = 1;

	FILE* pFile;
	int auxId;
	char auxNombre[51];
	char auxApellido[51];
	char auxCalle[51];
	float auxDinero;
	int auxNumeroCalle;
	eCliente* auxCliente;

	if(pArrayListClientes != NULL && path != NULL)
	{
		pFile = fopen(path, "w");
		if(pFile != NULL)
		{
			todoOk = 0;
			fprintf(pFile, "id,nombre,apellido,calle,numero calle,sueldo\n");
			for(int i = 1; i < ll_len(pArrayListClientes); i++)
			{
				auxCliente = ll_get(pArrayListClientes, i);
				if(!cliente_getId(auxCliente, &auxId) &&
				   !cliente_getNombre(auxCliente, auxNombre) &&
                   !cliente_getApellido(auxCliente,auxApellido) &&
				   !cliente_getCalle(auxCliente, auxCalle) &&
                   !cliente_getNumeroCalle(auxCliente,&auxNumeroCalle) &&
				   !cliente_getDinero(auxCliente, &auxDinero))
				{
					fprintf(pFile, "%d,%s,%s,%s,%d,%.2f\n", auxId, auxNombre, auxApellido,auxCalle,auxNumeroCalle, auxDinero);
				}
			}
			fclose(pFile);
			printf("Se guardaron los datos en el archivo\n");
		}
	}

    return todoOk;
}

/** \brief Guarda los datos de los clientes en el archivo clientes.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListClientes LinkedList*
 * \return retorna 0 si pudo abrir el archivo, sino 1
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListClientes)
{
    int todoOk = 1;
    FILE* pFile;
    eCliente* auxCliente;
    int tam;

    if(pArrayListClientes != NULL && path != NULL)
    {
        pFile = fopen(path, "wb");
        tam = ll_len(pArrayListClientes);
        for(int i = 0; i < tam; i++)
        {
            auxCliente = (eCliente*) ll_get(pArrayListClientes, i);
            fwrite(auxCliente, sizeof(eCliente), 1, pFile);
        }
        fclose(pFile);
        printf("Se guardaron los datos en el archivo clientes.bin\n");
        todoOk = 0;
    }
    else
    {
        printf("No se pudo abrir el archivo\n");
    }

    return todoOk;

}




