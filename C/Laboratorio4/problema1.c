/*
Autor:  Rubí E. Ramírez Milián
Compliador:
Para compilar: gcc -o problema1 problema1.c
Fecha:  Sat Apr 17 17:38:09 CST 2021
Librerías: stdio (u otras)
Entradas, Salidas, Resumen:
*/
 
//Librerias
#include <stdio.h>
//Declaración e inicialización de variables globales

void print_ascendentemente(int a[], int n);
void print_descendentemente(int a[], int n);
void selection_sort(int P[], int n);

    void main()
{   char caracter;
    int n = 10;
    int P[] = {16, 20, 12, 6, 8, 2, 14, 4, 10, 18};
    
    selection_sort(P, n);

    do{
        puts("Escoja a o d");
        caracter = getchar();
    }while((caracter)!='a' && (caracter)!='d');

    if(caracter=='a'){
        puts("vector ordenado ascendentemente");
        print_ascendentemente(P, n);
    }

    if (caracter =='d')
    {
        puts("vector ordenado descendentemente");
        print_descendentemente(P, n);
    }
}
    



void selection_sort(int P[], int n){

    int min, i, j;
    //se utiliza el primer espacio del vector para comparar el resto de los valores
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        //se busca en la sublista generada la posicion del menor valor
        for (j = i + 1; j < n; j++)
        {
            if (P[j] < P[min])
                min = j;
        }
        //se realiza el cambio del menor elemento por el seleccionado de pivote, solo si este es mayor
        if (i != min)
        {
            int aux = P[i];
            P[i] = P[min];
            P[min] = aux;
        }
    }


}

void print_ascendentemente(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", a[i]);
    }
}

void print_descendentemente(int a[], int n)
{
    for (int i = n-1; i >=0; i--)
    {
        printf("%d  ", a[i]);
    }
}