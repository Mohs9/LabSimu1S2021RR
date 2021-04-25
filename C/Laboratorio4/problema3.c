/*
Autor:  Rubí E. Ramírez Milián
Compliador: gcc (Debian 8.3.0-6) 8.3.0
Para compilar: gcc -o problema3 problema3.c
Fecha:  Mon Apr 19 18:46:53 CST 2021
Librerías: stdio (u otras)
Entradas, Salidas, Resumen:
*/
 
//Librerias
#include <stdio.h>
#include <math.h>
//Declaración e inicialización de variables globales

//Llamamos a las funciones correspondientes.
float norma(float V[]);
void suma_vectores(float A[], float B[], int n);
float producto_escalar(float A[], float B[], int n);
void producto_vectorial(float A[], float B[], int n);


void main(){
    //Inicializamos los arreglos en los que vamos a guardar las coordenadas que ingrese el usuario.
    int n=3;
    float A[3];
    float B[3];
    

    //Solicita los valores a pares de las coordenadas de los dos vectores.
    for (int k; k < n; k++){
        printf("Ingrese las cordenadas %d  de los vectores A, B \n", k);
        scanf("%f, %f", &A[k], &B[k]);
    }
    //Imprime la norma de cada vector
    puts("Norma de A, Norma de B");
    printf("%f, %f \n", norma(A), norma(B));
    //Imprime la suma de los vectores
    puts("Suma Vectorial de A + B:");
    suma_vectores(A,B,n);
    //Imprime el producto escalar
    puts("Producto escalar:");
    printf("%f \n", producto_escalar(A,B,3));
    //Imprime el producto cruz
    puts("Producto vectorial:");
    producto_vectorial(A,B,3);

}


//Magnitud del vector
float norma(float V[]){
    float suma_cuadrados;
    //Se suma los cuadrados de las coordenadas
    suma_cuadrados = pow(V[0], 2) + pow(V[1], 2) + pow(V[2], 2);
    //Regresa la raiz cuadrada de lo anterior.
    return pow(suma_cuadrados, 0.5);
}

//Suma vectorial
void suma_vectores(float A[], float B[], int n){
    float S[n];

    //Con el for sumamos coordenada con coordenada.
    for(int i=0; i < n; i++){
        S[i]= A[i]+B[i];
    }
    //Imprimimos las coordenadas del nuevo vector
    for (int i=0; i < n; i++){
        printf("%f ", S[i]);
    }
    printf("\n");
}


//Producto escalar
float producto_escalar(float A[], float B[], int n){
    float suma_producto;
    //Con el for sumamos la multiplicación de coordenada con coordenada
    for(int i =0; i < n; i++){
        suma_producto += A[i]*B[i];
    }
    return suma_producto;
}

//Producto vectorial
void producto_vectorial(float A[], float B[], int n){
    float C[n];
    int p, q;
    //Dado que la posición de las coordenadas en la fórmula se repite cíclicamente se puede aprovechar esta propiedad y usar m\'odulos.
    for(int m = 0; m < n; m++){
        p = (m+1)%3;
        q = (m+2)%3;
        C[m]= A[p]*B[q]-A[q]*B[p];
    }
    //Imprime las coordenadas del nuevo vector.
    for (int i = 0; i < n; i++){
        printf("%f ", C[i]);
    }
    printf("\n");
}