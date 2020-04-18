#include <stdio.h>
#include <stdlib.h>
#include "TP1Bernheim.h"



int main()
{
    char seguir = 's';
    int num1;
    int num2;
    int flag1=0;
    int flag2=0;
    int flagOperaciones=0;
    int resultadoSuma;
    int resultadoResta;
    int resultadoDivision;
    int resultadoMultiplicacion;
    int resultadoFactorialA;
    int resultadoFactorialB;




    do
    {
        switch(mostrarMenu(num1,num2,flag1,flag2))
        {
        case 1:
            system("cls");
            printf("Ingrese el primer operando: ");         //Pido primer operando y lo guardo en la variable num1
            scanf("%d",&num1);
            flag1=1;
            break;
        case 2:
            system("cls");
            printf("Ingrese el segundo operando: ");        // Pido el segundo operando y lo guardo en la variable num2
            scanf("%d",&num2);
            flag2=1;
            break;
        case 3:
            if(flag1 && flag2)
            {
                resultadoSuma=sumar(num1,num2);
                resultadoResta=restar(num1,num2);
                resultadoDivision=dividir(num1,num2);
                resultadoMultiplicacion=multiplicar(num1,num2);     //Realizo las operanciones, validando que se hayan ingresado los dos operando
                resultadoFactorialA=factorial(num1);
                resultadoFactorialB=factorial(num2);
                flagOperaciones=1;
                system("cls");
                printf("Se realizaron los calculos\n\n");
            }
            else
            {
                system("cls");
                printf("Debe ingresar los dos operandos para poder realizar las operaciones\n\n");
            }
            system("pause");
            break;
        case 4:
            if(flagOperaciones)
            {
                system("cls");
                printf("El resultado de %d+%d es: %d\n",num1,num2,resultadoSuma);
                printf("El resultado de %d-%d es: %d\n",num1,num2,resultadoResta);
                if(num2 != 0)
                {
                    printf("El resultado de %d/%d es: %d\n",num1,num2,resultadoDivision);       //Muestro los resultados y reseteo las variables
                }
                else
                {
                    printf("No es posible dividir por cero\n");
                }
                printf("El resultado de %d*%d es: %d\n",num1,num2,resultadoMultiplicacion);
                printf("El factorial de %d es: %d y el factorial de %d es: %d\n\n",num1,resultadoFactorialA,num2,resultadoFactorialB);
                reset(&num1);
                reset(&num2);
                reset(&flag1);
                reset(&flag2);
                reset(&flagOperaciones);
            }
            else
            {
                system("cls");
                printf("Debe realizar las operaciones primero para poder mostrar los resultados\n\n");
            }
            system("pause");
            break;
        case 5:
            seguir='n';     //Igual la variable seguir a un valor que no sea 's' para cerrar el programa
            break;
        default:
            system("cls");
            printf("El numero ingresado no es una opcion valida\n\n");      //Muestro mensaje si no se ingresa uno de las posibles opciones
            system("pause");
        }
        fflush(stdin);
    }
    while(seguir=='s');

    return 0;
}
