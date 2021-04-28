/*
Autor:  Rubí E. Ramírez Milián
Compliador: gcc (Debian 8.3.0-6) 8.3.0
Para compilar: gcc -o Problema6 Problema6.c -lm
Fecha:  Wed Apr 28 10:25:07 CST 2021
Librerías: stdio (u otras)
Entradas, Salidas, Resumen:
*/
 
//Librerias
#include <stdio.h>
#include <math.h>
//Declaración e inicialización de variables globales


float serie1(float n);
float serie2(float n);
float serie3(float n);
float serie4(float n);

void main(){
    int n;

    do{
        puts("Ingrese un número entero mayor 1");
        scanf("%d", &n);
    }while(n<=1);

    printf("Serie 1 hasta %d \n", n);
    printf("%f \n", serie1(n));
    printf("Serie 2 hasta %d \n" , n);
    printf("%f \n", serie2(n));
    printf("Serie 3 hasta %d \n" , n);
    printf("%f \n", serie3(n));
    printf("Serie 4 hasta %d \n", n);
    printf("%f \n", serie4(n));
}

// Serie 1 k^{2}(k-3)
float serie1(float n){
    float sumatoria;
    for(int k =1; k<=n; k++){
        sumatoria+= k*k*(k-3);
    }
    return sumatoria;
}

// Serie 2 Sumatoria de números de Fibonacci
float serie2(float n)
{
    float sumatoria;
    float aureo = (1+pow(5,0.5))/2;
    float aureo_conjugado = (1-pow(5,0.5))/2;
    float p = 1/pow(5, 0.5);
     for (int k = 1; k <= n; k++)
    {
        sumatoria += p*pow(aureo, k)-p*pow(aureo_conjugado, k);
    }
    return sumatoria;
}

// Serie 3 (3/(k-1))
float serie3(float n)
{
    float sumatoria;
    for (int k = 2; k <= n; k++){
        sumatoria += 3*pow(k-1,-1);
    }
    return sumatoria;
}

// Serie 3 Sumatoria de la sucesión de Bode
float serie4(float n)
{
    float sumatoria;
    for (int k = 2; k <= n; k++)
    {
        sumatoria += 0.1*(3*pow(2,k-2)+4);
    }
    return sumatoria;
}