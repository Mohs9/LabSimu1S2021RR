/*
Autor:  Rubí E. Ramírez Milián
Compliador: gcc (Debian 8.3.0-6) 8.3.0
Para compilar: gcc -o problema5 problema5.c
Fecha:  Sat Apr 24 23:17:46 CST 2021
Librerías: stdio (u otras)
Entradas, Salidas, Resumen:
*/
 
//Librerias
#include <stdio.h>
//Declaración e inicialización de variables globales



long factorial(int n);

void main()
{
    //n valor de numero al que queremos ejecutar la funcion factorial
    int n;
    //solicita el valor de numero hasta que este sea mayor o igual a 0
    do
    {
        printf("Introducir un numero entero positivo: ");
        scanf("%d", &n);
    } while (n <= 1);
    puts("Factorial ! \n");

    //se realiza la ejecucion del factorial de n
    printf("%d", factorial(n));

    puts("\n");
}

//funcion factorial la cual se llama a si misma dependiendo del numero que ingresa en ella
long factorial(int n)
{
    //si el valor es 0 o 1 solo regresa 1
    if (n == 0 || n == 1)
        return 1;
    else
        //se utiliza el algoritmo de la funcion factorial
        return n*factorial(n-1);
        
        
}