#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED



#endif // VALIDACIONES_H_INCLUDED


/** \brief pide un valor entero y valida el ingreso
 *
 * \param	puntero a entero en donde se va a guardar el dato
 * \param	reintentos que se le dan al usuario para ingresar de manera correcta
 * \param	mensaje a mostrar para ingresar el dato
 * \param	mensaje de error en caso de que se ingrese de manera erronea lo pedido
 * \param	minimo numero que se puede ingresar
 * \param	maximo numero que se puede ingresar
 *
 * \return	0 si logra tomar el dato, sino -1
 *
 */
int utn_getEntero(int* pEntero,int reintentos,char* msg,char*msgError,int minimo,int maximo);

/** \brief	pide un valor tipo float y valida el ingreso
 *
 * \param	puntero a flotante en donde se va a guardar el dato
 * \param	reintentos que se le dan al usuario para ingresar de manera correcta
 * \param	mensaje a mostrar para ingresar el dato
 * \param	mensaje de error en caso de que se ingrese de manera erronea lo pedido
 * \param	minimo numero que se puede ingresar
 * \param	maximo numero que se puede ingresar
 *
 * \return	0 si logra tomar el dato, sino -1
 *
 */
int utn_getFlotante(float*pFloat,int reintentos,char* msg,char*msgError,float minimo,float maximo);

/** \brief	toma la cadena que fue ingresada y le saca el '\n' al fgets
 *
 * \param	puntero a char en la que cargar la cadena ya validada}
 *
 * \return	0 si tuvo exito, sino -1
 *
 */
int getCadena(char* pAux,int limite);

/** \brief	llama a isInt y a isCadena para validar que sea un entero y pasa la cadana a integer
 *
 * \param	puntero a entero donde se va a cargar el numero validado
 *
 * \return	0 si logra validar, sino -1
 *
 */
int getInt(int* pAux);

/** \brief	recorre la cadena validando que cada posicion sea un numero entre 0 y 9
 *
 * \param	cadena donde se carga el numero validado
 *
 * \return	0 si logra validar, sino -1
 *
 */
int isInt(char *pAux);

/** \brief	valida que el parametro que se la pase sea flotante. Cuenta que solo haya un punto
 *
 * \param	cadena donde se carga el numero flotante validado
 *
 * \return	0 si la cadena es de numeros y tiene solo un punto, sino -1
 *
 */
int isFloat(char* pAux);

/** \brief	obtiene una cadena con getCadena y valida con isFloat, pasa esa cadena a flotante
 *
 * \param	puntero a variable tipo float donde se va a cagar el numero validado
 *
 * \return	0 si tuvo exito, sino -1
 *
 */
int getFloat(float*pAux);

/** \brief	valida que el usuario haya ingresado una cadena de caracteres
 *
 * \param	puntero a variable char en la que carga la cadena validada
 * \param	limite de caracteres que se pueden ingresar
 * \param	reintentos que se le dan al usuario para ingresar de manera correcta
 * \param	mensaje a mostrar para ingresar el dato
 * \param	mensaje de error en caso de que se ingrese de manera erronea lo pedido
 *
 * \return	0 si tuvo exito, sino -1
 *
 */
int utn_getCadena(char *pAux,int limite,int reintentos,char* msj,char*msjError);

/** \brief	recorre la cadena validando que cada posicion sea una letra
 *
 * \param	cadena donde se carga la letra validada
 *
 * \return	0 si logra validar, sino -1
 *
 */
int isLetras(char*pAux);

