#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "parser.h"
#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = 1;

    FILE* f = fopen(path,"r");

    if(f != NULL)
    {
        if(parser_EmployeeFromText(f,pArrayListEmployee))
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

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = 1;//error
    FILE* f;

    f = fopen(path, "rb");

    if(f != NULL)
    {
        if(!parser_EmployeeFromBinary(f, pArrayListEmployee))
        {
            todoOk = 0; //exito
            //printf("Archivo cargado con exito\n");
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

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 1;

    if(altaEmployee(pArrayListEmployee)==0)
    {
        todoOk = 0;
    }
    return todoOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 1;
    if(employeeMod(pArrayListEmployee)==0)
    {
        todoOk = 0;
    }
    return todoOk;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 1;
    if(bajaEmpleado(pArrayListEmployee)==0)
    {
        todoOk = 0;
    }
    return todoOk;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 1;
    system("cls");
    if(mostrarEmpleados(pArrayListEmployee)==0)
    {
        todoOk = 0;
    }
    return todoOk;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 1;
    system("cls");
    if(sortEmployee(pArrayListEmployee)==0)
    {
        todoOk = 0;
    }
    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk = 1;

	FILE* pFile;
	int auxId;
	char auxNombre[128];
	int auxHoras;
	int auxSueldo;
	Employee* auxEmployee;

	if(pArrayListEmployee != NULL && path != NULL)
	{
		pFile = fopen(path, "w");
		if(pFile != NULL)
		{
			todoOk = 0;
			fprintf(pFile, "id,nombre,horas trabajadas,sueldo\n");
			for(int i = 1; i < ll_len(pArrayListEmployee); i++)
			{
				auxEmployee = ll_get(pArrayListEmployee, i);
				if(!employee_getId(auxEmployee, &auxId) &&
				   !employee_getNombre(auxEmployee, auxNombre) &&
				   !employee_getHorasTrabajadas(auxEmployee, &auxHoras) &&
				   !employee_getSueldo(auxEmployee, &auxSueldo))
				{
					fprintf(pFile, "%d,%s,%d,%d\n", auxId, auxNombre, auxHoras, auxSueldo);
				}
			}
			fclose(pFile);
			printf("Se guardaron los datos en el archivo data.csv\n");
		}
	}

    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = 1;
    FILE* pFile;
    Employee* pEmployee;
    int tam;

    if(pArrayListEmployee != NULL && path != NULL)
    {
        pFile = fopen(path, "wb");
        tam = ll_len(pArrayListEmployee);
        for(int i = 0; i < tam; i++)
        {
            pEmployee = (Employee*) ll_get(pArrayListEmployee, i);
            fwrite(pEmployee, sizeof(Employee), 1, pFile);
        }
        fclose(pFile);
        printf("Se guardaron los datos en el archivo data.bin\n");
        todoOk = 0;
    }
    else
    {
        printf("No se pudo abrir el archivo\n");
    }

    return todoOk;

}
