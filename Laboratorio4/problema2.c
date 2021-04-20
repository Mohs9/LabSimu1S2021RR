/*
Autor:  Rub\'i E. Ram\'irez Mili\'an
Compliador: gcc (Debian 8.3.0-6) 8.3.0
Para compilar: gcc -o problema2 problema2.c
Fecha:  Sun Apr 18 00:18:31 CST 2021
Librerías: stdio (u otras)
Entradas, Salidas, Resumen:
*/
 
//Librerias
#include <stdio.h>
//Declaraci\'on e inicializaci\'on de variables globales

void print_ascendentemente(int a[], int n);

void insertion_sort(int A[], int n);

void main()
{
    int n = 5;
    int A[5];
    for(int k; k < n; k++){
        puts("Ingrese un entero");
        scanf("%d", &A[k]);

    }
    puts("vector inicial");
    print_ascendentemente(A, n);

    insertion_sort(A, 5);
    puts("\nvector ordenado");
    print_ascendentemente(A,n);
}

//Imprime los valores ascendentemente
void print_ascendentemente(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", a[i]);
    }
    printf("\n");
}

/*ordenamiento por insercion*/

void insertion_sort(int A[], int n){
    int i, j;
    int aux;
    for (i = 1; i < n; i++)
    /* indice j explora la sublista que va del valor que tiene la posicion i al valor inicial buscando la posicion correcta del elemento destino, lo asigna a a[j] */
    {
        j = i;
        aux = A[i];
        /* se localiza el punto de inserción explorando hacia abajo */
        while (j > 0 && aux < A[j - 1])
        {
            /* desplazar elementos hacia arriba para hacer espacio */
            A[j] = A[j - 1];
            j--;
        }
        /*Cambia el valor de la posicion j al valor de auxiliar*/
        A[j] = aux;
    }
}