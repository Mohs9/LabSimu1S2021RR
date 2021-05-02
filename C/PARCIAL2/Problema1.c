/*
Autor:  Rubí E. Ramírez Milián
Compliador: gcc (Debian 8.3.0-6) 8.3.0
Para compilar: gcc -o Problema1 Problema1.c -lm
Fecha:  Fri Apr 30 17:40:36 CST 2021
Librerías: stdio (u otras)
Entradas, Salidas, Resumen: Minimo Cuadrados de presión-volumen
*/
 
//Librerias
#include <stdio.h>
//#include <stdlib.h>
#include <math.h>
//Declaración e inicialización de variables globales

float volumen[] = {54.3,61.8,72.4,88.7,118.6,194};
float presion[] = {61.2,49.2,37.6,28.4,19.2,10.2};
float yerror= 0.2;
float xerror = 0.1;
int n = sizeof(volumen) / sizeof(volumen[0]);




float sumatoria_xy(float x[], float y[]);
float sumatoria_datos(float x[]);

int main()
{
    //valores de cada parte de la ecuacion lineal
    int Deltax=0;
    int Deltay=0;
    float a=0;
    float ln_b=0;
    float r=0;
    float ln_volumen[n];
    float ln_presion[n];
    float ln_volumen_error[n];
    float a_error=0;
    float ln_b_error=0;
    float b;
    float incerteza_ln_presion;
    float desviacion;

    //Ahora debemos volver la función lineal para usar mínimos cuadrados, usamos logaritmos para ello

    //Recorremos el arreglo
    for (int i = 0; i < n; i++)
    {
        ln_volumen[i] = log(volumen[i]);
        ln_presion[i] = log(presion[i]);
    }

    Deltax = n * sumatoria_xy(ln_volumen, ln_volumen) - sumatoria_datos(ln_volumen) * sumatoria_datos(ln_volumen);
    Deltay = n * sumatoria_xy(ln_presion, ln_presion) - sumatoria_datos(ln_presion) * sumatoria_datos(ln_presion);
    a=(n * sumatoria_xy(ln_volumen,ln_presion) - sumatoria_datos(ln_volumen) * sumatoria_datos(ln_presion))/Deltax;
    ln_b=(sumatoria_datos(ln_presion)-a*sumatoria_datos(ln_volumen))/n;
    b = pow(2.71828, ln_b);

        //Incerteza en las nuevas variables x y y, debe ser la desviaviación estándar
    for (int i = 0; i < n; i++)
    {
        ln_volumen_error[i] = xerror/(volumen[i]);
        incerteza_ln_presion += pow((ln_presion[i] - ln_b - a * ln_volumen[i]),2)/n;
        
    }

    desviacion = sqrt(incerteza_ln_presion);
    ln_b_error= desviacion*sqrt(sumatoria_xy(ln_volumen,ln_volumen)/Deltax);
    a_error = sqrt(n) * desviacion/ (sqrt(Deltax));

    //se obtiene el coeficiente de correlacion
    r = (n * sumatoria_xy(ln_volumen, ln_presion)-sumatoria_datos(ln_volumen) * sumatoria_datos(ln_presion)) / sqrt(Deltax*Deltay);
    
    printf("ln P = %f ln V+ %f\n", a, ln_b);
    printf("b= %f +/- %f\n", b, ln_b_error * exp(ln_b));
    printf("a= %f +/- %f\n", a, a_error);
    printf("El valor de P cuando V=100 in^{3}=%f lb/in^{3} \n", b*pow(100,a));
    //el coeficiente de determinacion es el cuadrado de r
    //printf("Coeficciente de determinacion: %f\n", r*r);

    /* se crea y se abre el archivo datln.txt en modo escritura 
     * para almacenar los valores de x y y que están declarados en los arreglos ln_volumen y ln_presion y sus incertezas*/
    FILE *archivoPuntos =fopen("datosln.dat", "w");

    /*Guardar los puntos x,y en el archivo de texto creado y abierto previamente*/
    for (int i = 0; i <n; i++)
    {
        fprintf(archivoPuntos,"%f,   %f,  %f,  %f \n", ln_volumen[i], ln_volumen_error[i], ln_presion[i], desviacion);
    }

    fclose(archivoPuntos);
    FILE *gnu_config1 = popen("gnuplot -persist", "w");
    fprintf(gnu_config1, "unset label\n");
    fprintf(gnu_config1, "set terminal 'epslatex'\n");
    fprintf(gnu_config1, "set output 'pv.tex'\n");
    fprintf(gnu_config1, "set xrange [40:200]\n");
    fprintf(gnu_config1, "set yrange [5:90]\n");
    fprintf(gnu_config1, "set title 'Presion vrs. Volumen'\n");
    fprintf(gnu_config1, "set xlabel ' V[in$ ^ {3} $]'\n");
    fprintf(gnu_config1, "set ylabel 'P[lb / in$ ^ {3} $]'\n");
    fprintf(gnu_config1, "unset key\n");
    fprintf(gnu_config1, "set grid\n");
    fprintf(gnu_config1, "unset key\n");
    fprintf(gnu_config1, "a=%f\n", a);
    fprintf(gnu_config1, "b=%f\n", b);
    fprintf(gnu_config1, "f(x)=b*x**a\n");
    fprintf(gnu_config1, "unset key\n");
    fprintf(gnu_config1, "plot f(x), 'datos.dat' using 1:3:2:4 with xyerrorbars pt 3\n");
    fprintf(gnu_config1, "set output\n");

    FILE *gnu_config = popen("gnuplot -persist", "w");
    fprintf(gnu_config, "unset label\n");
    fprintf(gnu_config, "set terminal 'epslatex'\n");
    fprintf(gnu_config, "set output 'pvln.tex'\n");
    fprintf(gnu_config, "set xrange [2:7]\n");
    fprintf(gnu_config, "set yrange [2:7]\n");
    fprintf(gnu_config, "set title 'Presion vrs. Volumen (lineal)'\n");
    fprintf(gnu_config, "set xlabel 'ln V[in$ ^ {3} $]'\n");
    fprintf(gnu_config, "set ylabel 'ln P[lb / in$ ^ {3} $]'\n");
    fprintf(gnu_config, "set grid\n");
    fprintf(gnu_config, "unset key\n");
    fprintf(gnu_config, "set grid\n");
    fprintf(gnu_config, "unset key\n");
    fprintf(gnu_config, "a=%f\n", a);
    fprintf(gnu_config, "b=%f\n", ln_b);
    fprintf(gnu_config, "f(x)=a*x+b\n");
    fprintf(gnu_config, "unset key\n");
    fprintf(gnu_config, "set datafile separator comma\n");
    fprintf(gnu_config, "plot f(x), 'datosln.dat' using 1:3:2:4 with xyerrorbars pt 3\n");
    fprintf(gnu_config, "set output\n");


    pclose(gnu_config1);
    pclose(gnu_config);
    return 0;
}

   


float sumatoria_datos(float x[])
{
    float valor= 0;
    for (int i = 0; i < n; i++)
    {
        valor += x[i];
    }
    return valor;
}

//se realiza la suma de dos vectores, multiplicando cada uno de sus valores  de forma consecurtiva
float sumatoria_xy(float x[], float y[])
{
    float valor = 0;
    for (int i = 0; i < n; i++)
    {
        valor += x[i] * y[i];
    }
    return valor;
}



