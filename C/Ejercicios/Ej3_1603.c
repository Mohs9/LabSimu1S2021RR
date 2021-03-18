/*
Autor:  Rubi E. Ramirez Milian
Compliador: gcc (Debian 6.3.0-18+deb9u1) 6.3.0 20170516
Para compilar: gcc -o Ej3_1603 Ej3_1603.c
Fecha:  Wed Mar 17 08:05:14 CST 2021
Librerias: stdio (u otras)
Entradas, Salidas, Resumen: lea un numero mayor que 1 y determine si es
primo.
*/
 
//Librerias
#include <stdio.h>
//Declaracion e inicializacion de variables globales


int main(){
    int  N; //Declarar variable tipo entero positivo
    int i=1; //Declarar variable tipo entero
    printf("Escriba un número entero positivo mayor que 1 \n");
    scanf("%d", &N); //Pedir un numero N y almacenarlo en la variable N.
    
    //entrar al ciclo while mientras i cuadrado sea menor que el número dado
    while(i*i<=N){
         i++;
    }
/*    
Primero scamos la raíz cuadrada para hacer más corto el proceso se buscar primos por el criterio de buscar si es congruente con cero en módulo raíz cuadrada del número. 
*/

 
    int j=2, primo=1; //inicializamos las variables con las que vamos a comprobar si es primo o no
//Con este ciclo while, mientras j sea menor que la raíz cuadrada entera del número y el flag primo sea igual a 1.    
    while(j<i && primo==1){
        //Si N es congruente con j el flag primo cambia a 0. Si no j aumenta 1
        if(N%j==0){
            primo=0;
        }else{
            j++;
        }
    }
//Cuando se sale del ciclo while compara si  el flag primo es igual a cero, si sí lo es es porque era congruente a 0 mod algun j por lo que no es primo. Si no entonces sí lo es.     
    if(primo==0){
       printf("No es primo \n");
    }else{
       printf("Es primo\n");
    }
}
