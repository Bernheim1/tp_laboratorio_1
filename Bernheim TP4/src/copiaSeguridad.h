#include "LinkedList.h"
#ifndef COPIASEGURIDAD_H_INCLUDED
#define COPIASEGURIDAD_H_INCLUDED



#endif // COPIASEGURIDAD_H_INCLUDED


/** \brief llama a las funciones que permiten realizar una copia de seguridad del archivo cargado
 *
 * \param lista de la que se hace la copia de seguridad
 * \return retorna 0 si pudo ingresar una opcion valida, sino 0
 *
 */
int copiaSeguridad(LinkedList* pArrayListClientes);

/** \brief realiza un nuevo archivo, pide el nombre y le concatena ".csv"
 *
 * \param lista de la que se hace la copia de seguridad
 *
 */
void copiaSeguridadBin(LinkedList* pArrayListClientes);

/** \brief realiza un nuevo archivo, pide el nombre y le concatena ".bin"
 *
 * \param lista de la que se hace la copia de seguridad
 *
 */
void copiaSeguridadTxt(LinkedList* pArrayListClientes);
