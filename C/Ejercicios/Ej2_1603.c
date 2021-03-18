/*
Autor:  Rubi E. Ramirez Milian
Compliador: gcc (Debian 6.3.0-18+deb9u1) 6.3.0 20170516
Para compilar: gcc -o Ej2_1603 Ej2_1603.c
Fecha:  Wed Mar 17 07:22:14 CST 2021
Librerias: stdio (u otras)
Entradas, Salidas, Resumen:Calcula la raiz cuadrada entera por defecto de un numero N positivo dado.
*/
 
//Librerias
#include <stdio.h>
//Declaracion e inicializacion de variables globales


int main(){
    float N; //Declarar variable tipo flotante o real
    int i=1; //Declarar variable tipo entero

    printf("Escriba un numero positivo \n"); 
    scanf("%f", &N); //Pedir un numero N y almacenarlo en la variable N.

    //entrar all ciclo hile mientra i cuadrado sea menor que el numero dado
    while(i*i<=N){
        i=i+1;
    }
    
    printf("La raiz es: %d \n", i-1); //Salir del ciclo while cuando sea mayor.
   
}




