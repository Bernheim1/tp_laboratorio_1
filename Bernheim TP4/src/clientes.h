#include "LinkedList.h"
#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    char calle[51];
    int numeroCalle;
    float dinero;
}eCliente;


/** \brief asigna espacio en la memoria dinamica para un cliente
 *
 * \return puntero a eCliente
 *
 */
eCliente* cliente_new();

/** \brief asigna un espacio en memoria dinamica para un cliente asignandole los datos
 *
 * \param id a asignar
 * \param nombre a asignar
 * \param horas trabajadas a asignar
 * \param sueldo a asignar
 * \return puntero a cliente con los datos setteados
 *
 */
eCliente* cliente_newParametros(int id,char* nombre,char* apellido,char* calle,int numeroCalle,float dinero);

/** \brief llama a cliente_newParametros
 *
 * \param id a asignar de tipo cadena
 * \param nombre a asignar
 * \param horas trabajadas a asignar de tipo cadena
 * \param sueldo a asignar de tipo cadena
 *
 * \return llama a cliente_newParametros convirtiendo los datos de cadena a entero
 *
 */
eCliente* cliente_newParamS(char* idStr, char* nombreStr, char* apellidoStr,char* calleStr,char* numeroCalle, char* dineroStr);

/** \brief asigna el id a un cliente
 *
 * \param un cliente
 * \param id a asignar
 * \return retorna 0 si se pudo asignar el id sino 1
 *
 */
int cliente_setId(eCliente* cliente,int id);

/** \brief obtiene el id de un cliente
 *
 * \param un cliente
 * \param variable donde guardar el id obtenido
 * \return retorna 0 si se pudo obtener el id sino 1
 *
 */
int cliente_getId(eCliente* cliente,int* id);

/** \brief asigna el nombre de un cliente
 *
 * \param un cliente
 * \param nombre a asignar
 * \return retorna 0 si se pudo asignar el nombre sino 1
 *
 */
int cliente_setNombre(eCliente* cliente,char* nombre);

/** \brief obtiene el nombre de un cliente
 *
 * \param un cliente
 * \param variable donde guardar el nombre obtenido
 * \return retorna 0 si se pudo obtener el nombre, sino 1
 *
 */
int cliente_getNombre(eCliente* cliente,char* nombre);

/** \brief asigna el apellido de un cliente
 *
 * \param un cliente
 * \param apellido a asignar
 * \return retorna 0 si se pudo asignar el apellido, sino 1
 *
 */
int cliente_setApellido(eCliente* cliente,char* apellido);

/** \brief obtiene el apellido de un cliente
 *
 * \param un cliente
 * \param variable donde guardar el apellido obtenido
 * \return retorna 0 si se pudo obtener el apellido, sino 1
 *
 */
int cliente_getApellido(eCliente* cliente,char* apellido);

/** \brief asigna la calle de un cliente
 *
 * \param un cliente
 * \param calle a asignar
 * \return retorna 0 si se pudo asignar la calle, sino 1
 *
 */
int cliente_setCalle(eCliente* cliente,char* calle);

/** \brief obtiene la calle de un cliente
 *
 * \param un cliente
 * \param variable donde guardar la calle obtenida
 * \return retorna 0 si se pudo obtener la calle, sino 1
 *
 */
int cliente_getCalle(eCliente* cliente,char* calle);

/** \brief obtiene el numero de la calle de un cliente
 *
 * \param un cliente
 * \param variable donde guardar el numero de la calle obtenido
 * \return retorna 0 si se pudo asignar el numero de la calle, sino 1
 *
 */
int cliente_setNumeroCalle(eCliente* cliente,int numeroCalle);

/** \brief obtiene el numero de la calle de un cliente
 *
 * \param un cliente
 * \param variable donde guardar el numero de la calle obtenido
 * \return retorna 0 si se pudo obtener el numero de la calle, sino 1
 *
 */
int cliente_getNumeroCalle(eCliente* cliente,int* numeroCalle);

/** \brief obtiene el dinero en cuenta de un cliente
 *
 * \param un cliente
 * \param variable donde guardar el dinero en cuenta obtenido
 * \return retorna 0 si se pudo asignar el dinero en cuenta, sino 1
 *
 */
int cliente_setDinero(eCliente* cliente,float dinero);

/** \brief obtiene el dinero en cuenta de un cliente
 *
 * \param un cliente
 * \param variable donde guardar el dinero en cuenta obtenido
 * \return retorna 0 si se pudo asignar el dinero en cuenta, sino 1
 *
 */
int cliente_getDinero(eCliente* cliente,float* dinero);

/** \brief establece el primer id en 1001 y lee el ultimo id asignado en el archivo "proximoId.bin"
 *
 * \param puntero a int donde se va a asignar el siguiente id
 * \return retorna 0 si se pudo abrir el archivo, sino -1
 *
 */
int obtenerId(int* id);

/** \brief actualiza el siguiente id a asignar y lo guarda en el archivo "proximoId.bin"
 *
 * \param valor del ultimo id asignado
 * \return retorna 0 si se pudo abrir el archivo, sino -1
 *
 */
int actualizarId(int id);

/** \brief saca a un cliente de la lista y lo ubica en otro indice
 *
 * \param lista donde sacar y reubicar al cliente
 *
 */
void moverCliente(LinkedList* pArrayListCliente);

/** \brief muestra a un cliente
 *
 * \param lista
 * \param indice donde se encuentra el cliente
 *
 */
void mostrarCliente( LinkedList* lista,int indice);

/** \brief muestra la lista de clientes
 *
 * \param lista de clientes
 * \return retorna 0 si se pudo mostrar la lista sino 1
 *
 */
int mostrarClientes( LinkedList* lista);

/** \brief da de alta un nuevo cliente en la lista
 *
 * \param lista de clientes
 * \return retorna 0 si se pudo realizar el alta sino 1
 *
 */
int altaCliente(LinkedList* lista);

/** \brief llama a menuModEmployee y da a elegir
 *
 * \param lista de cliente
 * \return retorna 0 si se pudo realizar el alta sino 1
 *
 */
int clienteMod(LinkedList* lista);

/** \brief muestra un menu de opciones a modificar de un cliente
 *
 *
 * \return opcion elegida
 *
 */
int menuModCliente();

/** \brief pide el ingreso de un nuevo nombre y lo guarda en el indice pasado por parametro
 *
 * \param lista de cliente
 * \param indice del empleado en la lista
 *
 * \return retorna 0 si se pudo modificar el cliente sino 1
 *
 */
int modificarNombre(LinkedList* lista,int  indice);
int modificarApellido(LinkedList* lista,int  indice);
int modificarCalle(LinkedList* lista,int  indice);
int modificarDinero(LinkedList* lista,int  indice);
int modificarNumeroCalle(LinkedList* lista,int  indice);

/** \brief busca un cliente por id y guarda la posicion en el int* pasado por parametro
 *
 * \param lista de cliente
 * \param  id a buscar
 * \param  puntero a entero donde guardar la posicion del empleado con el id pasado
 * \return 0 si encontro un cliente con ese id, sino 1
 *
 */
int findClienteById(LinkedList* lista, int id,int* indice);

/** \brief realiza la baja de un cliente de la lista
 *
 * \param lista de cliente
 * \return retorna 0 si se pudo realizar la baja sino 1
 *
 */
int bajaCliente(LinkedList* lista);

 /** \brief compara los id de dos clientes
 *
 * \param puntero a void
 * \param puntero a void
 * \return retorna 0 si los id son iguales, 1 si el primero es mayor o -1 si el segundo es mayor
 *
 */
int cliente_ComparaId(void * a, void* b);

/** \brief compara los nombres de los clientes
 *
 * \param puntero a void
 * \param puntero a void
 * \return retorna 0 si los nombres son iguales, 1 si el primero esta antes en el ascii o -1 si el segundo esta despues en el ascii
 */
int cliente_ComparaNombre(void * a, void* b);

/** \brief compara los apellidos de los clientes
 *
 * \param puntero a void
 * \param puntero a void
 * \return retorna 0 si los apellidos son iguales, 1 si el primero esta antes en el ascii o -1 si el segundo esta despues en el ascii
 */
int cliente_ComparaApellido(void * a, void* b);

/** \brief compara las calles de los clientes
 *
 * \param puntero a void
 * \param puntero a void
 * \return retorna 0 si las calles son iguales, 1 si el primero esta antes en el ascii o -1 si el segundo esta despues en el ascii
 */
int cliente_ComparaCalle(void * a, void* b);

/** \brief compara los numeros de las calles de los clientes
 *
 * \param puntero a void
 * \param puntero a void
 * \return retorna 0 si los los numeros de las calles son iguales, 1 si el primero es mayor o -1 si el segundo es mayor
 */
int cliente_ComparaNumeroCalle(void * a, void* b);

/** \brief compara el dinero en cuenta de los clientes
 *
 * \param puntero a void
 * \param puntero a void
 * \return retorna 0 si el dinero en cuenta de los clientes son iguales, 1 si el primero es mayor o -1 si el segundo es mayor
 */
int cliente_ComparaDinero(void * a, void* b);


/** \brief ordena la lista de clientes segun la opcion elegida en el menuSortEmployee()
 *
 * \param lista de clientes
 * \return retorna 0 si se pudo realizar el ordenamiento sino 1
 *
 */
int sortClientes(LinkedList* lista);

/** \brief muestra un menu de opciones a ordenar de la lista
 *
 *
 * \return opcion elegida
 *
 */
int menuSortClientes();




#endif // employee_H_INCLUDED
