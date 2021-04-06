/*
Autor:  Rubí E. Ramírez Milián
Compliador: gcc.exe (MinGW.org GCC-6.3.0-1) 6.3.0
Para compilar: gcc -o Calculadora Calculadora.c
Fecha:  Tue Apr 6 12:52:43 HAC 2021
Librerías: stdio (u otras)
Entradas, Salidas, Resumen:
*/
 
//Librerias
#include <stdio.h>
//Declaración e inicialización de funciones
float suma(float A, float B);
float resta(float A, float B);
float multiplicacion(float A, float B);
float division(float A, float B);

int main()
{
    float A, B;
    int X;
    float result;
    printf("Ingrese el primer numero:\n");//Pide el primer número
    scanf("%f", &A);
    printf("Ingrese el segundo numero:\n");//Pide el segundo número
    scanf("%f", &B);
    printf("Ingrese un digito del 0 al 4:\n");//Pide un dígito del 0 al 4 para ejecutar alguna función
    scanf("%d", &X);
    if (X == 1)
    {   //Si el usuario escoge 1 suma
        result = suma(A, B);
        printf("Usted escogio suma: %.2f", result);
    }
    else if (X == 2)
    { //Si el usuario escoge 2 resta
        result = resta(A, B);
        printf("Usted escogio resta: %.2f", result);
    }
    else if (X == 3)
    { //Si el usuario escoge 3 multiplica
        result = multiplicacion(A, B);
        printf("Usted escogio multiplicacion: %.2f", result);
    }
    else if (X == 4)
    { //Si el usuario escoge 4 divide
        result = division(A, B);
        printf("Usted escogio division: %f", result);
    }
    else if (X == 0)
    {
        printf("Usted escogio salir");
    }
    return 0;
}

float suma(float A, float B){
    //función suma los dos valores ingresados
    float result;
    result = A+B;
    return result;
}

float resta(float A, float B){
    //función resta los dos valores ingresados(el orden importa)
    float result; //variable local
    result = A - B;
    return result;
}

float multiplicacion(float A, float B){
    //función multiplicaa los dos valores ingresados
    float result; //variable local
    result = A*B;
    return result;
}

float division(float A, float B){
    //función divide los dos valores ingresados(el orden importa)
    float result; //variable local
    result = A/B;
    return result;
}
