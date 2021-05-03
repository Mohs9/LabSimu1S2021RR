/*
Autor:  Rubí E. Ramírez Milián
Compliador: gcc (Debian 8.3.0-6) 8.3.0
Para compilar: gcc -o Problema2 Problema2.c
Fecha:  Fri Apr 30 17:40:43 CST 2021
Librerías: stdio, math (u otras)
Entradas, Salidas, Resumen: Métos de Newton-Ramphson
*/
 
//Librerias
#include <stdio.h>
#include <math.h>
//Declaración e inicialización de variables globales
#define PI 3.14159265358979323846

float funcion(float x);
float valor_absoluto(float x);

int main(){
    //Definimos las variables que serán el intervalo
    float xa =2;
    float xp;
    float xanterior;
    float xb=4;
    float error=100;
    //Biseccionamos el intervalo
    xp= (xa+xb)/2;
    //Entramos al ciclo while
    while (error >0.001)
    {   //Si ambas imágenes tiene el mismo signo xa se vuelve el punto más cercano a la raíz
        if(funcion(xa)*funcion(xp)>0){
            xa=xp;
        }
        //Si la imágenes  de xa y xp tienen signo distinto xp se aproxima más a la raíz que xp
        else if(funcion(xa)*funcion(xp)<0){
            xb=xp;
        }
        //Si la imagen de xp es cero se encontró la raíz
        else{
            break;
        }
        //Se usa la otra variable para almacenar la primera bisección
        xanterior = xp;
        //Se le asigna el nuevo valor
        xp=(xa+xb)/2;
        //Se evalua el error
        error =100*valor_absoluto(xp-xanterior)/xp;
    
    }
    printf("xp=%f \n", xp);

    FILE *gnu = popen("gnuplot -persist", "w");
    fprintf(gnu, "unset label\n");
    fprintf(gnu, "set terminal 'epslatex'\n");
    fprintf(gnu, "set output 'funcion.tex'\n");
    fprintf(gnu, "set xrange [-4:4]\n");
    fprintf(gnu, "set yrange [-1:1]\n");
    fprintf(gnu, "set title ''\n");
    fprintf(gnu, "set xlabel 'x'\n");
    fprintf(gnu, "set ylabel 'sin(x)/x'\n");
    fprintf(gnu, "set grid\n");
    fprintf(gnu, "unset key\n");
    fprintf(gnu, "set grid\n");
    fprintf(gnu, "unset key\n");
    fprintf(gnu, "f(x)=sin(x)/x\n");
    fprintf(gnu, "plot f(x)\n");
    fprintf(gnu, "set output\n");

    pclose(gnu);
    return 0;
}


float funcion(float x){
    return sin(x)/x;
}



float valor_absoluto(float x){
    if(x>=0){
        return x;
    }else if(x<0){
        return -x;
    }
}