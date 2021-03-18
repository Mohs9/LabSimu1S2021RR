/*
Autor:  Rubi E. Ramirez Milian
Compliador: gcc (Debian 6.3.0-18+deb9u1) 6.3.0 20170516
Para compilar: gcc -o Ej4_1603 Ej4_1603.c
Fecha:  Wed Mar 17 14:50:18 CST 2021
Librerias: stdio (u otras)
Entradas, Salidas, Resumen: lee dos números enteros para generar un rango y muestra todos los números primos en ese rango.
*/
 
//Librerias
#include <stdio.h>
//Declaracion e inicializacion de variables globales


int main(){
    int N1, N2; //Declarar variables enteras
    
    
    printf("Ingrese dos números enteros positivos: \n"); // Lee dos numeros positivos.
    scanf("%d, %d", &N1, &N2);
   
        
    while(N1<=N2){
        int i=1; //Declarar variable tipo entero
        //entrar al ciclo while mientras i cuadrado sea menor que el número dado
        while(i*i<=N1){
            i++;
        }
        /*Primero sacamos la raíz cuadrada para hacer más corto el proceso se buscar primos por el criterio de buscar si es congruente con cero en módulo raíz cuadrada del número.  */

        int j=2, primo=1; //inicializamos las variables con las que vamos a comprobar si es primo o no
        //Con este ciclo while, mientras j sea menor que la raíz cuadrada entera del número y el flag primo sea igual a 1.    
        while(j<i && primo==1){
        //Si k es congruente con j el flag primo cambia a 0. Si no j aumenta 1
            if(N1%j==0){
               primo=0;
            }else{
               j++;
            }
        }
        //Si el flag primo no cambia a 0 es por que sí es primo y lo imprime.
        if(primo==1){
            printf("%d, \n", N1);
        }
        //Aumenta el N1 en 1.
        N1++;
    }
}
