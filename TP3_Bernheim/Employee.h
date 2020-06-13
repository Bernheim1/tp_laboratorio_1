#include "LinkedList.h"
#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;


/** \brief asigna espacio en la memoria dinamica para un employee
 *
 * \return puntero a Employee
 *
 */
Employee* employee_new();

/** \brief asigna un espacio en memoria dinamica para un employee asignandole los datos
 *
 * \param id a asignar
 * \param nombre a asignar
 * \param horas trabajadas a asignar
 * \param sueldo a asignar
 * \return puntero a employee con los datos setteados
 *
 */
Employee* employee_newParametros(int id,char* nombre,int horasTrabajadas,int sueldo);

/** \brief llama a employee_newParametros
 *
 * \param id a asignar de tipo cadena
 * \param nombre a asignar
 * \param horas trabajadas a asignar de tipo cadena
 * \param sueldo a asignar de tipo cadena
 *
 * \return llama a employee_newParametros convirtiendo los datos de cadena a entero
 *
 */
Employee* employee_newParamS(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr);

/** \brief asigna el id a un employee
 *
 * \param un employee
 * \param id a asignar
 * \return retorna 0 si se pudo asignar el id sino 1
 *
 */
int employee_setId(Employee* employee,int id);

/** \brief obtiene el id de un employee
 *
 * \param un employee
 * \param variable donde guardar el id obtenido
 * \return retorna 0 si se pudo obtener el id sino 1
 *
 */
int employee_getId(Employee* employee,int* id);

/** \brief asigna el nombre de un employee
 *
 * \param un employee
 * \param nombre a asignar
 * \return retorna 0 si se pudo asignar el nombre sino 1
 *
 */
int employee_setNombre(Employee* employee,char* nombre);

/** \brief obtiene el nombre de un employee
 *
 * \param un employee
 * \param variable donde guardar el nombre obtenido
 * \return retorna 0 si se pudo obtener el nombre sino 1
 *
 */
int employee_getNombre(Employee* employee,char* nombre);

/** \brief asigna las horas trabajadas a un employee
 *
 * \param un employee
 * \param horas trabajadas a asignar
 * \return retorna 0 si se pudo asignar las horas trabajadas o sino 1
 */
int employee_setHorasTrabajadas(Employee* employee,int horasTrabajadas);

/** \brief obtiene las horas trabajadas de um employee
 *
 * \param un employee
 * \param variable donde guardar las horas trabajadas obtenidas
 * \return retorna 0 si se pudo obtener las horas trabajadas sino 1
 *
 */
int employee_getHorasTrabajadas(Employee* employee,int* horasTrabajadas);

/** \brief asigna el sueldo a un employee
 *
 * \param el employee deseado
 * \param sueldo a asignar
 * \return retorna 0 si se pudo asignar el sueldo o 1 en caso de no haberlo podido asignar
 *
 */
int employee_setSueldo(Employee* employee,int sueldo);

/** \brief obtiene el sueldo de un employee
 *
 * \param un employee
 * \param variable donde guardar sueldo obtenido
 * \return retorna 0 si se pudo obtener el sueldo sino 1
 */
int employee_getSueldo(Employee* employee,int* sueldo);

/** \brief muestra a un employee
 *
 * \param lista
 * \param indice donde se encuentra el employee
 *
 */
void mostrarEmpleado( LinkedList* lista,int indice);

/** \brief muestra la lista de employees
 *
 * \param lista de employees
 * \return retorna 0 si se pudo mostrar la lista sino 1
 *
 */
int mostrarEmpleados( LinkedList* lista);

/** \brief da de alta un nuevo employee en la lista
 *
 * \param lista de employees
 * \return retorna 0 si se pudo realizar el alta sino 1
 *
 */
int altaEmployee(LinkedList* lista);

/** \brief llama a menuModEmployee y da a elegir
 *
 * \param lista de employee
 * \return retorna 0 si se pudo realizar el alta sino 1
 *
 */
int employeeMod(LinkedList* lista);

/** \brief muestra un menu de opciones a modificar de un employee
 *
 *
 * \return opcion elegida
 *
 */
int menuModEmployee();

/** \brief pide el ingreso de un nuevo id y lo guarda en el indice pasado por parametro
 *
 * \param lista de employee
 * \param indice del empleado en la lista
 *
 * \return retorna 0 si se pudo modificar el employee sino 1
 */
int modificarId(LinkedList* lista, int indice);

/** \brief pide el ingreso de un nuevo nombre y lo guarda en el indice pasado por parametro
 *
 * \param lista de employee
 * \param indice del empleado en la lista
 *
 * \return retorna 0 si se pudo modificar el employee sino 1
 *
 */
int modificarNombre(LinkedList* lista,int  indice);

/** \brief pide el ingreso de nueva cantidad de horas trabajadas y las guarda en el indice pasado por parametro
 *
 * \param lista de employee
 * \param indice del empleado en la lista
 *
 * \return retorna 0 si se pudo modificar el employee sino 1
 *
 */
int modificarHoras(LinkedList* lista,int  indice);

/** \brief pide el ingreso de un nuevo sueldo y lo guarda en el indice pasado por parametro
 *
 * \param lista de employee
 * \param indice del empleado en la lista
 *
 * \return retorna 0 si se pudo modificar el employee sino 1
 *
 */
int modificarSueldo(LinkedList* lista,int  indice);

/** \brief busca un employee por id y guarda la posicion en el int* pasado por parametro
 *
 * \param lista de employee
 * \param  id a buscar
 * \param  puntero a entero donde guardar la posicion del empleado con el id pasado
 * \return 0 si encontro un employee con ese id, sino 1
 *
 */
int findEmployeeById(LinkedList* lista, int id,int* indice);

/** \brief realiza la baja de un employee de la lista
 *
 * \param lista de employee
 * \return retorna 0 si se pudo realizar la baja sino 1
 *
 */
int bajaEmpleado(LinkedList* lista);

/** \brief compara el sueldo entre dos employees
 *
 * \param puntero a void
 * \param puntero a void
 * \return retorna 0 si los sueldos son iguales, 1 si el primero es mayor o -1 si el segundo es mayor
 *
 */
int employee_CompararSueldo(void * a, void* b);

/** \brief compara las horas trabajadas entre dos employee
 *
 * \param puntero a void
 * \param puntero a void
 * \return retorna 0 si los sueldos son iguales, 1 si el primero es mayor o -1 si el segundo es mayor
 *
 */
int employee_CompararHoras(void * a, void* b);

/** \brief compara los nombres de los employee
 *
 * \param puntero a void
 * \param puntero a void
 * \return retorna 0 si los sueldos son iguales, 1 si el primero es mayor o -1 si el segundo es mayor
 */
int employee_CompararNombre(void * a, void* b);

 /** \brief compara los id de dos employee
 *
 * \param puntero a void
 * \param puntero a void
 * \return retorna 0 si los sueldos son iguales, 1 si el primero es mayor o -1 si el segundo es mayor
 *
 */
int employee_CompararId(void * a, void* b);

/** \brief ordena la lista de employee segun la opcion elegida en el menuSortEmployee()
 *
 * \param lista de employee
 * \return retorna 0 si se pudo realizar el ordenamiento sino 1
 *
 */
int sortEmployee(LinkedList* lista);

/** \brief muestra un menu de opciones a ordenar de la lista
 *
 *
 * \return opcion elegida
 *
 */
int menuSortEmployee();


#endif // employee_H_INCLUDED
