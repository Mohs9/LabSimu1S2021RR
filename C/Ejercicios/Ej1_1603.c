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
//Declaracion de variables globales
int main(){
    float x=0, max, min, media=0; //Declarar las variables de tipo flotante
    int  n=0;  //Declara la variable de tipo entero.
    printf("Ingresa un numero real \n"); 
    scanf("%f", &x); //Lee el primer número con el que se inicializará el conjunto.
    max=x;  //Le asigna valor de x a las variables min y max que usara para comparar.
    min=x; 
    
    //Ejecuta las instrucciones y luego evalúa la condición
    do{
       printf("Ingrese un numero real \n");
       scanf("%f", &x);
    //Si x es un número positivo entonces lo agrega a la sumatoria de media.
    //Si es positivo o cero, incrementa en 1 la variable n.
           if(x>=0){
               n++;
               media+= x;
               //Si el nuevo numero es mayor que el anterior lo guarda en la variable máximo.
               //Si es menor que el anterior minimo lo guarda como nuevo mínimo.
               if(x>=max){
                   max=x;
               }else if(x<min){
                   min=x;
               }
            }
     }while(x>=0);
        
     //Si n no aumentó es porque los numéros eran negativos e imprime la media, el maximo y el mínimo de los números dados.
     if(n==0){
         printf("los valores eran negativo");
     }else{
         printf("media: %.2f,maximo: %f, minimo: %f", media/n, max, min);
     }
    
}
