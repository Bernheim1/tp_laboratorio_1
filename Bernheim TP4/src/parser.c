#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListClientes LinkedList*
 * \return int
 *
 */
int parser_ClientesFromText(FILE* pFile, LinkedList* pArrayListClientes)
{
    int todoOk = 0;
    int cant;
    eCliente* auxCliente;
    if (pFile == NULL || pArrayListClientes == NULL)
    {
        return todoOk;
    }
    else
    {
        ll_clear(pArrayListClientes);

        char buffer[6][128];

        fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",buffer[0], buffer[1], buffer[2], buffer[3],buffer[4],buffer[5]);

        while(!feof(pFile))
        {


            cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0], buffer[1], buffer[2], buffer[3],buffer[4],buffer[5]);
            if (cant == 6)
            {
                auxCliente = cliente_newParamS(buffer[0], buffer[1], buffer[2], buffer[3],buffer[4],buffer[5]);

                if (auxCliente != NULL)
                {

                    ll_add(pArrayListClientes, auxCliente);
                    todoOk = 1;

                }
            }

        }

    }



    return todoOk;

}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListClientes LinkedList*
 * \return int
 *
 */
int parser_ClientesFromBinary(FILE* pFile , LinkedList* pArrayListClientes)
{
    int todoOk = 1;
    eCliente* auxCliente;

    if(pFile != NULL && pArrayListClientes != NULL)
    {
        ll_clear(pArrayListClientes);
        do
        {
            auxCliente = cliente_new();
            if(fread(auxCliente, sizeof(eCliente), 1, pFile) == 1)
            {
                ll_add(pArrayListClientes, auxCliente);
                todoOk = 0;
            }
        }while(!feof(pFile));
    }


    return todoOk;
}

