/*
Autor:  Rubí E. Ramírez Milián
Compliador: gcc (Debian 8.3.0-6) 8.3.0
Para compilar: gcc -o Problema4 Problema4.c
Fecha:  Wed Apr 28 16:31:03 CST 2021
Librerías: stdio (u otras)
Entradas, Salidas, Resumen:
*/
 
//Librerias
#include <stdio.h>
#include <math.h>
//Declaración e inicialización de variables globales

void fancy_print(float A[3][3]);
void multiplicacion_escalar(float x, float A[3][3]);
void suma_matrices(float A[3][3], float B[3][3]);
void resta_matrices(float A[3][3], float B[3][3]);
void multiplicacion_matrices(float A[3][3], float B[3][3]);
float determinante(float A[3][3]);
float cofactor(float A[3][3], int i, int j);
void transpuesta(float A[3][3], float B[3][3]);
void inversa(float A[3][3]);
void reduccion_Gauss(float A[3][3]);
void reduccion_Gauss_Jordan(float A[3][3]);

void main() /* Rellenamos una matriz */
{
    int i, j;
    float x, A[3][3], B[3][3];
    float C[3][3];
    /* rellenamos las matrices */
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            printf("Ingrese a_%d %d y b_%d %d \n", (i+1), (j+1), (i+1), (j+1));
            scanf(" %f  %f", &A[i][j], &B[i][j]);
        }
    }
    puts("Ingrese un escalar");}
    scanf(" %f", &x);

    puts("Multiplicación por ecalar");
    multiplicacion_escalar(x, A);
    puts(" ");
    puts("Suma de A y B");
    suma_matrices(A,B);
    puts(" ");
    puts("Resta de A y B");
    resta_matrices(A,B);
    puts(" ");
    puts("Multiplicación de A por B");
    multiplicacion_matrices(A,B);
    puts(" ");
    puts("Transpuesta de A");
    transpuesta(A,C);
    fancy_print(C);
    puts(" ");
    puts("Determinante de A");
    printf("%f", determinante(A));
    puts(" ");
    puts("Inversa de A");
    inversa(A);
    puts(" ");
}


void fancy_print(float A[3][3]){
    /*visualizamos la matriz*/
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %s %f ", (j % 3 == 0 ? "\n " : "  "), A[i][j]);
        }
    }
}


void multiplicacion_escalar(float x, float A[3][3]){
    float C[3][3];
    // Recorremos la matriz
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            C[i][j]=x*A[i][j];
        }
    }
     /*visualizamos la matriz*/
    fancy_print(C);
     
}

void suma_matrices(float A[3][3], float B[3][3])
{
    float C[3][3];
    // Recorremos la matriz
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            C[i][j] = A[i][j]+ B[i][j];
        }
    }
    /*visualizamos la matriz*/
    fancy_print(C);
}

void resta_matrices(float A[3][3], float B[3][3])
{
    float C[3][3];
    // Recorremos la matriz
        for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    /*visualizamos la matriz*/
    fancy_print(C);
}

void multiplicacion_matrices(float A[3][3], float B[3][3]){

    float C[3][3];
    // Recorremos la matriz
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {   
            for(int k = 0; k<3; k++){
            C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
    /*visualizamos la matriz*/
    fancy_print(C);
}

void transpuesta(float A[3][3], float B[3][3])
{
    // Recorremos la matriz
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            B[i][j]=A[j][i];
        }
    }
    
}

float cofactor(float A[3][3], int i, int j)
{
    //Para calcular cofactores necesitamos calcular (-1)^{i+j}det(A), los indices se corren en módulo y ya se toma en cuenta el signo
    float C_ij;
    int p, q, r, s;
    p= (1+i)%3;
    q= (1+j)%3;
    r= (2+i)%3;
    s=(2+j)%3;
    C_ij = A[p][q]*A[r][s]-A[p][s]*A[r][q];

    return C_ij;
}

float determinante(float A[3][3]){
    //Para una matriz de 3x3 se calcula como la sumatoria de las componentes de alguna fila o columan multiplicadas por sus cofactor respectivo.
    float det;
    for(int column =0; column < 3; column ++){
        det += A[0][column]*cofactor(A,0,column);
        //printf("%f", det);
    }

    return det;

}

void inversa(float A[3][3]){
    float C[3][3];
    //Para la inversa necesitamos una matriz adjunta que es la transpuesta de la matriz de cofactores
    //Recorremos la matriz para que C[3][3] se vuelva la matriz de cofactores
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            C[i][j] = cofactor(A, i, j);
        }
    }
    //Luego C debe volverse la matriz transpuesta para ser la adjunta para eso llamamos a la función tanspuesta
    float B[3][3];//matriz adjunta
    transpuesta(C,B);
    float determinante_inverso= pow(determinante(A),-1);
    //inversa es entonces la multiplicación de la matriz adjunta por el determinante;
    multiplicacion_escalar(determinante_inverso, B);

}
