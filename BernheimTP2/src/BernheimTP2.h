/*
 * BernheimTP2.h
 *
 *  Created on: 14 may. 2020
 *      Author: Bernheim
 */

#ifndef BERNHEIMTP2_H_
#define BERNHEIMTP2_H_

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float sueldo;
    int sector;
    int isEmpty;

} eEmpleado;


#endif /* BERNHEIMTP2_H_ */


/** \brief llama al menu de opciones y a la funcion elegida por el usuario
 *
 * \param vector de eEmpleado para pasar como parametro a las funciones a llamar
 * \param tamanio del vector para pasar como parametro a las funciones a llamar
 *
 */
void informar(eEmpleado vec[],int tam);

/** \brief menu que mostra las opciones a informar y retorna la elegida
 *
 * \return opcion ingresada por el usuario
 *
 */
int menuInformar();

/** \brief menu principal de opciones
 *
 * \return opcion ingresada por el usuario
 *
 */
int mostrarMenu();

/** \brief le da valor 1 a todos los empleados del vector que se le pasa por parametro
 *
 * \param vector de eEmpleado a recorrer
 * \param tamanio del vector de empleados
 *
 */
void inicializarEmpleados(eEmpleado vec[],int tam);

/** \brief busca un espacio vacio en un vector de eEmpleado y le carga los datos si el usuario ingresa
 *  bien todos los campos
 *
 * \param id a asignarle al nuevo empleado
 * \param vector de eEmpleado a utilizar para cargar el nuevo empleado
 * \param tamanio del vector de eEmpleado para recorrer
 *
 * \return 1 si pudo cargar los datos, -1 si no lo pudo hacer
 *
 */
int altaEmpleado(int idX,eEmpleado vec[], int tam);

/** \brief busca en un vector de eEmpleados si hay un espacio con isEmpety=1
 *
 * \param vector de eEmpleado a recorrer
 * \param tamanio del vector a recorrer
 *
 * \return -1 si no encuentra espacio vacio,sino el indice del espacio vacio
 *
 */
int buscarLibre(eEmpleado vec[],int tam);

/** \brief busca el id de un empleado en un vector de eEmpleado
 *
 * \param	id pasado por parametro a buscar
 * \param	vector de eEmpleado a recorrer
 * \param	tamanio del vector a recorrer
 *
 * \return	-1 si no encuentra el id en el vector, sino la posicion del id en el vector
 *
 */
int buscarEmpleado(int id, eEmpleado vec[], int tam);

/** \brief	muestra todos los datos de un empleado
 *
 * \param	vector de eEmpleado a mostrar
 *
 *
 */
void mostrarEmpleado(eEmpleado x);

/** \brief	muestra por pantalla todos los empleados del vector que se le pase
 *
 * \param	vector de eEmpleado a recorrer
 * \param	tamanio del vector a recorrer
 *
 *
 */
void mostrarEmpleados(eEmpleado vec[],int tam);

/** \brief	pide id de un empleado para modificar uno de sus campos
 *
 * \param	vector de eEmpleado a recorrer
 * \param	tamanio del vector a recorrer
 *
 *
 */
void modificarEmpleado(eEmpleado vec[],int tam);

/** \brief	muestra el menu de opciones a modificar
 *
 * \return opcion elegida por el usuario
 *
 */
int menuModificar();

/** \brief	pide el id de un empleado para realizar la baja logica del empleado en el vector
 *
 * \param	vector de eEmpleado en el que se busca el id
 * \param	tamanio del vector a recorrer
 *
 *
 */
void bajaEmpleado(eEmpleado vec[], int tam);

/** \brief	ordena los empleados del vector por apellido y sector
 *
 * \param	vector de eEmpleado a recorrer
 * \param	tamanio del vector a recorrer
 *
 *
 */
void informarEmpleados(eEmpleado vec[], int tam);

/** \brief	muestra por pantalla el total de los sueldos, el promedio y los empleados por encima del promedio
 *
 * \param	vector de eEmpleado a recorrer
 * \param	tamanio del vector a recorrer
 *
 *
 */
void informarSueldos(eEmpleado vec[],int tam);

