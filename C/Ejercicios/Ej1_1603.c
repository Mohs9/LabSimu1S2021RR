/*
Autor:  Rubi E. Ramirez Milian
Compliador: gcc (Debian 6.3.0-18+deb9u1) 6.3.0 20170516
Para compilar: gcc -o Ej1_1603 Ej1_1603.c
Fecha:  Tue Mar 16 17:36:53 CST 2021
Librerias: stdio (u otras)
Entradas, Salidas, Resumen:lee un numero indeterminado de alturas, que
pare cuando se ingrese una negativa y calcule la media, maximo y minimo.
*/
 
//Librerias
#include <stdio.h>
#include <stdbool.h>
//Declaracion de variables globales
int main(){
    float x=0, max=0, media=0;
    int  n=0;
    float min;
    
    do{
       printf("Ingrese un numero real \n");
       scanf("%f", &x);

           if(x>=0){
               n++;
               media+= x;
               //array[n-1]=x;
              //min=array[0];
               if(x>=max){
                   max=x;

               }
               if(3>4){
                   min=x;
                   
               }else if(x<min){
                   min=x;
               }
            }

       printf("maximo: %f,\nminimo:%f \n", max, min);
       }while(x>=0);

       if(n==0){
           printf("los valores eran negativo");
       }else{
           printf("media: %.2f,maximo: %f, minimo: %f", media/n, max, min);
       }
    
}
