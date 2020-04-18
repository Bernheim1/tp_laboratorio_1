#ifndef TP1BERNHEIM_H_INCLUDED
#define TP1BERNHEIM_H_INCLUDED



#endif // TP1BERNHEIM_H_INCLUDED


/** \brief muestra un menu de opciones
 *
 * \param int a Primer operando
 * \param int b  Segundo operando
 * \param int flag1  Flag para validar el ingreso del primer operando
 * \param int flag2  Flag para validar el ingreso del segundo operando
 * \return  La opcion elegida por el usuario como numero entero
 *
 */

int mostrarMenu(int a,int b,int flag1,int flag2);

/** \brief Recibe dos operandos y los suma
 *
 * \param int a primer operando a sumar
 * \param int b segundo operando a sumar
 * \return La suma de los dos operandos
 *
 */

int sumar(int a, int b);

/** \brief Recibe dos operandos y los resta
 *
 * \param int a primer operando a restar
 * \param int b segundo operando a restar
 * \return La resta del primer operando menos el segundo
 *
 */

int restar(int a,int b);

/** \brief Recibe dos operandos y los divide
 *
 * \param int a dividendo de la operacion
 * \param int b divisor de la operacion
 * \return La division del primer operando sobre el segundo
 *
 */

int dividir(int a, int b);

/** \brief Recibe dos operandos y los multiplica
 *
 * \param int a primer operando a ser multiplicado
 * \param int b segundo operando a ser multiplicado
 * \return La multiplicacion del primer operando por el segundo
 *
 */

int multiplicar(int a, int b);

/** \brief Recibe un operando y calcula el factorial
 *
 * \param int a numero utilizar
 * \return  El resultado del factorial del operando
 *
 */

int factorial(int a);

/** \brief Establece el valor de una variable a 0
 *
 * \param int* p variable a resetear
 *
 */
void reset(int* p);
