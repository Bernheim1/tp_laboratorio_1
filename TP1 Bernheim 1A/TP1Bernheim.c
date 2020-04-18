#include <stdio.h>
#include <stdlib.h>
#include "TP1Bernheim.h"



int mostrarMenu(int a,int b,int flag1,int flag2)
{

    int opcion;
    system("cls");
    printf("**** MENU DE OPCIONES ****\n");
    if(flag1&&flag2)
    {
        printf("Los numeros cargados actualmente son: A %d B: %d\n\n",a,b);
    }
    else if(flag2==0 && flag1)
    {
        printf("Los numeros cargados actualmente son: A: %d B: y\n\n",a);
    }
    else if(flag2 && flag1==0)
    {
        printf("Los numeros cargados actualmente son: A: x B: %d\n\n",b);
    }
    else
    {
        printf("Los numeros cargados actualmente son: A: x B: y\n\n");
    }


    printf("1-Ingresar primer operando\n");
    printf("2-Ingresar segundo operando\n");
    printf("3-Calcular las operaciones\n");
    printf("4-Mostrar resultados\n");
    printf("5-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;


}

int sumar(int a, int b)
{
    return a+b;
}
int restar(int a, int b)
{
    return a-b;
}

int dividir(int a, int b)
{
    if(b!=0)
    {
       return a/b;
    }
    else
    {
        return 0;
    }
}
int multiplicar(int a, int b)
{
    return a*b;
}

int factorial(int a)
{
    int fact=0;

    if(a>=0)
    {
        if(a==1||a==0)
        {
            fact=1;
        }
        else
        {
            fact=a*factorial(a-1);
        }

    }


    return fact;
}

void reset(int* p)
{
    *p=0;
}
