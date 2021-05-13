/*
Autor:  Rubí E. Ramírez Milián
Compliador: gcc (Debian 8.3.0-6) 8.3.0
Para compilar: gcc -o segundo_orden segundo_orden.c
Fecha:  Wed May 12 22:12:27 CST 2021
Librerías: stdio (u otras)
Entradas, Salidas, Resumen:Runge-kutta para solucionar edos de segundo orden.
*/
 
//Librerias
#include <stdio.h>
#include <math.h>
//Declaración e inicialización de variables globales



//funciones utiles
float f(float t, float v, float y, float TSFC, float E0, float CD, float A, float m0, float mf0);
float f2(float t, float v, float y, float TSFC, float E0, float CD, float A, float m0, float mf0);
float mf(float t, float TSFC,float E0, float mf0);
float Fa(float t, float y, float v, float CD, float A);
float mc(float t, float y, float v, float TSFC, float E0, float m0,float mf0);
float gravedad(float t, float y, float v);
float rho(float t, float y, float v);

void main()
{   
    //Se usara el metodo de Runge-Kutta de cuarto orden para solucionar la EDO de segundo orden
    //Como la ecuacion es de segundo orden se soluciona como un sistema de ecuaciones par v(t) que es la derivada de y respecto a t
    //y para y(t) 

     /*PRIMER COHETE*/////////////////////////////////////////////////////////////////////////////////

    //Para el primer cohete se tiene las siguiente condiciones iniciales:
    float w1 = 0.65, u1=0;
    float y1=0.65, v1= 0, t1 = 0, h = 0.01;
    float k1, k2, k3,k4;
    float l1,l2,l3,l4;
    float te;//tiempo en que se agota el combustible
    float tiempo_suelo;//tiempo en el que cae al suelo
    float hmax;
    FILE *pf1 = fopen("cohete1.dat", "wt");
    float TSFC1 = 3.248 * pow(10, -4);
    float E01 =3*pow(10,7);
    float CD1 = 61.27;
    float A1 =201.6;
    float m01 = 1.1 * pow(10, 5);
    float mf01 = 1.5 * pow(10,6);
    //mientras el combustible no sea cero  es decir mf!=0 se sigue encontrando valores



    while(mf(t1,TSFC1, E01, mf01)>=0){
        //solucion del sistema de ecuaciones para resolver la edo
        l1 = h * f(t1, v1, y1,TSFC1, E01,CD1,A1,m01, mf01);
        k1 = h *v1;
        l2 = h * f(t1 + h / 2, v1 + l1 / 2, y1 + k1 / 2, TSFC1, E01, CD1, A1, m01,mf01);
        k2 = h * (v1 + l1 / 2);
        l3 = h * f(t1 + h / 2, v1 + l2 / 2, y1 + k2 / 2, TSFC1, E01, CD1, A1, m01, mf01);
        k3 = h*(v1+l2/2);
        l4 = h * f(t1 + h, v1 + l3, y1 + k3, TSFC1, E01, CD1, A1, m01,mf01);
        k4 = h*(v1+l3);
        w1+= (k1+2*k2+2*k3+k4)/6;
        u1+= (l1+2*l2+2*l3+l4)/6;
        t1+=h;
        y1=w1;
        v1=u1;
        fprintf(pf1, "%.2f\t%f\t%f\n", t1, y1, v1);
        //La altura máxima e produce cuando la derivada es cero es decir cuando v(t) es cero;
        if(mf(t1,TSFC1, E01, mf01)<=0){
            te= t1;
            hmax= y1;
            //Aproximadamente el doble que lo que le toma llegar a la altura máx
            tiempo_suelo=2*t1;

        }
        // cuando v(t) es menor que cero  y y(t)=0 deja de tabular valores
        if (round(v1)<0 && round(y1)==0){
            break;
        }
    }
    //Cerrar archivo
    fclose(pf1);

  

    puts("Cohete Ah Mun");
    puts("Especificaciones del Cohete:");
    printf("Empuje del cohete %.2f\n", E01);
    printf("Consumo Especifico del empuje %f\n", TSFC1);
    printf("Coeficiente de Forma %.2f\n", CD1);
    printf("Sección transversal %.2f\n", A1);
    printf("Masa del propulsor %.2f\n", m01);
    printf("Altura máxima alcanzada %.2f\n",  hmax);
    printf("Tiempoo cuando se agota el compustible %.2fmin\n", te/60);
    printf("Tiempo cuando ocurre el impacto en el suelo %.2fmin\n", tiempo_suelo/60);



    //GRAFICAS
    //Se genera un archivo.tex para compilarlo depues en latex

    FILE *gnu1 = popen("gnuplot -persist", "w");
    fprintf(gnu1, "unset label\n");
    fprintf(gnu1, "set terminal 'epslatex'\n");
    fprintf(gnu1, "set output 'cohete1.tex'\n");
    fprintf(gnu1, "set title 'Ah Mun'\n");
    fprintf(gnu1, "set xlabel 't[s]'\n");
    fprintf(gnu1, "set ylabel 'Velocidad[m/s]'\n");
    fprintf(gnu1, "set grid\n");
    fprintf(gnu1, "plot 'cohete1.dat' using 1:3 title 'Velocidad'pt 3\n");
    fprintf(gnu1, "set output\n");

    pclose(gnu1);
    //altura vrs tiempo
    FILE *gnu1_altura = popen("gnuplot -persist", "w");
    fprintf(gnu1_altura, "unset label\n");
    fprintf(gnu1_altura, "set terminal 'epslatex'\n");
    fprintf(gnu1_altura, "set output 'cohete1_altura.tex'\n");
    fprintf(gnu1_altura, "set title 'Ah Mun'\n");
    fprintf(gnu1_altura, "set xlabel 't[s]'\n");
    fprintf(gnu1_altura, "set ylabel 'Altura[m]'\n");
    fprintf(gnu1_altura, "set grid\n");
    fprintf(gnu1_altura, "plot 'cohete1.dat' using 1:2  title 'Altura' pt 4\n");
    fprintf(gnu1_altura, "set output\n");

    // velocidad vrs altura
    FILE *gnu1_vel = popen("gnuplot -persist", "w");
    fprintf(gnu1_vel, "unset label\n");
    fprintf(gnu1_vel, "set terminal 'epslatex'\n");
    fprintf(gnu1_vel, "set output 'cohete1_vel.tex'\n");
    fprintf(gnu1_vel, "set title 'Ah Mun'\n");
    fprintf(gnu1_vel, "set xlabel 'Altura[m]'\n");
    fprintf(gnu1_vel, "set ylabel 'Velocidad[m/s]'\n");
    fprintf(gnu1_vel, "set grid\n");
    fprintf(gnu1_vel, "unset key\n");
    fprintf(gnu1_vel, "plot 'cohete1.dat' using 2:3  pt 4\n");
    fprintf(gnu1_vel, "set output\n");

    pclose(gnu1_vel);

    //Cohete 2//////////////////////////////////////////////////////////////////

    //Para el segundo cohete se tiene las siguiente condiciones iniciales:
    float w2 = 0.65, u2 = 0;
    float y2 = 0.65, v2 = 0, t2 = 0;
    float k1_2, k2_2, k3_2, k4_2;
    float l1_2, l2_2, l3_2, l4_2;
    float te2;           //tiempo en que se agota el combustible
    float tiempo_suelo2; //tiempo en el que cae al suelo
    float hmax2;
    FILE *pf2 = fopen("cohete2.dat", "wt");
    float TSFC2 = 2.248 * pow(10, -4);
    float E02 = 2.7 * pow(10, 7);
    float CD2 = 61.27;
    float A2 = 201.6;
    float m02 = 1.1 * pow(10, 5);
    float mf02= 1.5*pow(10,6);
    //mientras el combustible no sea cero  es decir mf!=0 se sigue encontrando valores,
    while (mf(t2, TSFC2, E02, mf02)> 0)
    {
        //solucion del sistema de ecuaciones para resolver la edo
        l1_2 = h * f(t2, v2, y2, TSFC2, E02, CD2, A2, m02,mf02);
        k1_2 = h * v2;
        l2_2 = h * f(t2 + h / 2, v2 + l1_2 / 2, y2 + k1_2 / 2, TSFC2, E02, CD2, A2, m02,mf02);
        k2_2 = h * (v2 + l2_2 / 2);
        l3_2 = h * f(t2 + h / 2, v2 + l2_2 / 2, y2 + k2_2 / 2, TSFC2, E02, CD2, A2, m02,mf02);
        k3_2 = h * (v2 + l2_2 / 2);
        l4_2 = h * f(t2 + h, v2 + l3_2, y2 + k3_2, TSFC2, E02, CD2, A2, m02,mf02);
        k4_2 = h * (v2 + l3_2);
        w2 += (k1_2 + 2 * k2_2 + 2 * k3_2 + k4_2) / 6;
        u2 += (l1_2 + 2 * l2_2 + 2 * l3_2 + l4_2) / 6;
        t2 += h;
        y2 = w2;
        v2 = u2;
        fprintf(pf2, "%.2f\t%f\t%f\n", t2, y2, v2);
        if (mf(t2,TSFC2, E02,mf02)<= 0)
        {
            te2 = t2;
            hmax2=y2;
            //Aproximadamente el tiempo en el suelo es el doble que le toma llegar a la altura maxima
            tiempo_suelo2=2*t2;
        }

        //La altura máxima e produce cuando la derivada es cero es decir cuando v(t) es cero;
    
        // cuando v(t) es menor que cero  y y(t)=0 deja de tabular valores
        if (round(v2) < 0 && round(y2) == 0)
        {
            break;
        }
    }
    //Cerrar archivo
    fclose(pf2);
    puts("Cohete Ah Kin");
    puts("Especificaciones del Cohete:");
    printf("Empuje del cohete %.2f\n", E02);
    printf("Consumo Especifico del empuje %f\n", TSFC2);
    printf("Coeficiente de Forma %.2f\n", CD2);
    printf("Sección transversal %.2f\n", A2);
    printf("Masa del propulsor %.2f\n", m02);
    printf("Altura máxima alcanzada %.2f\n", hmax2);
    printf("Tiempoo cuando se agota el compustible %.2f min \n", te2 / 60);
    printf("Tiempo cuando ocurre el impacto en el suelo %.2fmin \n", tiempo_suelo2 / 60);

    //GRAFICAS
    //Se genera un archivo.tex para compilarlo depues en latex
    //Grafica de velocidad
    FILE *gnu2 = popen("gnuplot -persist", "w");
    fprintf(gnu2, "unset label\n");
    fprintf(gnu2, "set terminal 'epslatex'\n");
    fprintf(gnu2, "set output 'cohete2.tex'\n");
    fprintf(gnu2, "set title 'Ahau Kin'\n");
    fprintf(gnu2, "set xlabel 't[s]'\n");
    fprintf(gnu2, "set ylabel 'Velocidad[m/s]'\n");
    fprintf(gnu2, "set grid\n");
    fprintf(gnu2, "plot 'cohete2.dat' using 1:3 title 'Velocidad'pt 3\n");
    fprintf(gnu2, "set output\n");
    //Cerramos el ejecutor
    pclose(gnu2);
    //grafica de altura
    FILE *gnu2_altura = popen("gnuplot -persist", "w");
    fprintf(gnu2_altura, "unset label\n");
    fprintf(gnu2_altura, "set terminal 'epslatex'\n");
    fprintf(gnu2_altura, "set output 'cohete2_altura.tex'\n");
    fprintf(gnu2_altura, "set title 'Ahau Hin'\n");
    fprintf(gnu2_altura, "set xlabel 't[s]'\n");
    fprintf(gnu2_altura, "set ylabel 'Altura[m]'\n");
    fprintf(gnu2_altura, "set grid\n");
    fprintf(gnu2_altura, "plot 'cohete2.dat' using 1:2 pt 3\n");
    fprintf(gnu2_altura, "set output\n");

    pclose(gnu2_altura);

    // velocidad vrs altura
    FILE *gnu2_vel = popen("gnuplot -persist", "w");
    fprintf(gnu2_vel, "unset label\n");
    fprintf(gnu2_vel, "set terminal 'epslatex'\n");
    fprintf(gnu2_vel, "set output 'cohete2_vel.tex'\n");
    fprintf(gnu2_vel, "set title 'Ahau Kin'\n");
    fprintf(gnu2_vel, "set xlabel 'Altura[m]'\n");
    fprintf(gnu2_vel, "set ylabel 'Velocidad[m/s]'\n");
    fprintf(gnu2_vel, "set grid\n");
    fprintf(gnu2_vel, "unset key\n");
    fprintf(gnu2_vel, "plot 'cohete2.dat' using 2:3 pt 3\n");
    fprintf(gnu2_vel, "set output\n");

    pclose(gnu2_vel);
    //Cohete 3//////////////////////////////////////////////////////////////////

    //Para el tercer cohete se tiene las siguiente condiciones iniciales:
    float w3 =0.65, u3 = 0;
    float y3 = 0.65, v3 = 0, t3 = 0;
    float k1_3, k2_3, k3_3, k4_3;
    float l1_3, l2_3, l3_3, l4_3;
    float te3;           //tiempo en que se agota el combustible
    float tiempo_suelo3; //tiempo en el que cae al suelo
    float hmax3;
    FILE *pf3 = fopen("cohete3.dat", "wt");
    float TSFC3 = 2.248 * pow(10, -4);
    float E03 = 2.7 * pow(10, 7);
    float CD3 = 61.27;
    float A3 = 201.6;
    float m03 = 1.1 * pow(10, 5);
    float mf03= 2.1*pow(10,6);
    //mientras el combustible no sea cero  es decir mf!=0 se sigue encontrando valores,
    while (mf(t3, TSFC3, E03,mf03)>= 0)
    {
        //solucion del sistema de ecuaciones para resolver la edo
        l1_3 = h * f(t3, v3, y3, TSFC3, E03, CD3, A3, m03,mf03);
        k1_3 = h * v3;
        l2_3 = h * f(t3 + h / 2, v3 + l1_2 / 2, y3 + k1_3 / 2, TSFC3, E03, CD3, A3, m03, mf03);
        k2_3 = h * (v3 + l2_3 / 2);
        l3_3 = h * f(t3 + h / 2, v3 + l2_3 / 2, y3 + k2_3 / 2, TSFC3, E03, CD2, A3, m03, mf03);
        k3_3 = h * (v2 + l2_3 / 2);
        l4_3 = h * f(t3 + h, v3 + l3_3, y3 + k3_3, TSFC2, E03, CD3, A3, m03, mf03);
        k4_3 = h * (v3 + l3_3);
        w3 += (k1_3 + 2 * k2_3 + 2 * k3_3 + k4_3) / 6;
        u3 += (l1_3 + 2 * l2_3 + 2 * l3_3 + l4_3) / 6;
        t3 += h;
        y3 = w3;
        v3 = u3;
        fprintf(pf3, "%.2f\t%f\t%f\n", t3, y3, v3);
        if (mf(t3, TSFC3, E03, mf03)<= 0)
        {
            te3= t3;
            hmax3 = y3;
            //Aproximadamente el doble que lo que le toma llegar a la altura máx
            tiempo_suelo3 = 2 * t3;
        }

        //La altura máxima e produce cuando la derivada es cero es decir cuando v(t) es cero;
        
        // cuando v(t) es menor que cero  y y(t)=0 deja de tabular valores
        if (round(v3) < 0 && round(y3) == 0)
        {
            break;
        }
    }
    //Cerrar archivo
    fclose(pf3);
    puts("Cohete Chac");
    puts("Especificaciones del Cohete:");
    printf("Empuje del cohete %.2f\n", E03);
    printf("Consumo Especifico del empuje %f\n", TSFC3);
    printf("Coeficiente de Forma %.2f\n", CD3);
    printf("Sección transversal %.2f\n", A3);
    printf("Masa del propulsor %.2f\n", m03);
    printf("Altura máxima alcanzada %.2f\n", hmax3);
    printf("Tiempoo cuando se agota el compustible %.2f min \n", te3 / 60);
    printf("Tiempo cuando ocurre el impacto en el suelo %.2f min\n", tiempo_suelo3 / 60);

    //GRAFICAS
    //Se genera un archivo.tex para compilarlo depues en latex

    FILE *gnu3 = popen("gnuplot -persist", "w");
    fprintf(gnu3, "unset label\n");
    fprintf(gnu3, "set terminal 'epslatex'\n");
    fprintf(gnu3, "set output 'cohete3.tex'\n");
    fprintf(gnu3, "set title 'Chac'\n");
    fprintf(gnu3, "set xlabel 't[s]'\n");
    fprintf(gnu3, "set ylabel 'Velocidad[m/s]'\n");
    fprintf(gnu3, "set grid\n");
    fprintf(gnu3, "plot 'cohete3.dat' using 1:3 title 'Velocidad'pt 3\n");
    fprintf(gnu3, "set output\n");

    pclose(gnu3);

    FILE *gnu3_altura = popen("gnuplot -persist", "w");
    fprintf(gnu3_altura, "unset label\n");
    fprintf(gnu3_altura, "set terminal 'epslatex'\n");
    fprintf(gnu3_altura, "set output 'cohete3_altura.tex'\n");
    fprintf(gnu3_altura, "set title 'Chac'\n");
    fprintf(gnu3_altura, "set xlabel 't[s]'\n");
    fprintf(gnu3_altura, "set ylabel 'Altura[m]'\n");
    fprintf(gnu3_altura, "set grid\n");
    fprintf(gnu3_altura, "plot 'cohete3.dat' using 1:2  title 'Altura' pt 4\n");
    fprintf(gnu3_altura, "set output\n");

    pclose(gnu3_altura);

    // velocidad vrs altura
    FILE *gnu3_vel = popen("gnuplot -persist", "w");
    fprintf(gnu3_vel, "unset label\n");
    fprintf(gnu3_vel, "set terminal 'epslatex'\n");
    fprintf(gnu3_vel, "set output 'cohete3_vel.tex'\n");
    fprintf(gnu3_vel, "set title 'Chac'\n");
    fprintf(gnu3_vel, "set xlabel 'Altura[m]'\n");
    fprintf(gnu3_vel, "set ylabel 'Velocidad[m/s]'\n");
    fprintf(gnu3_vel, "set grid\n");
    fprintf(gnu3_vel, "unset key\n");
    fprintf(gnu3_vel, "plot 'cohete3.dat' using 2:3  pt 4\n");
    fprintf(gnu3_vel, "set output\n");

    pclose(gnu3_vel);
}
// Masa del propulsor
//Se resulve anlítcamente la edo dm/dt=constante
float mf(float t, float TSFC, float E0,float mf0){
    float res;
    res= -TSFC*E0*t+mf0;
    return res;
}

float mc(float t, float y, float v, float TSFC, float E0, float m0, float mf0)
{
    float res;
    res= m0+mf(t,TSFC, E0, mf0);
    return res;
}

float rho(float t, float y, float v){
//definimos  adentro las constantes porque me dio problema  definirlas arriba
    float L=6.5*pow(10,-3);
    float T0= 288.15;
    float P0= 101325;
    float g0= 9.81;
    float R= 287.06;
    float res;
    //la altura maxima opara la densidad.
    float hmax=T0/L;
    //Escribimos por a parte lo del parentesis
    float parentesis= 1- L*y/T0;
    if (y <= hmax){
        res=P0*pow(parentesis,g0/(R*L))/(R*T0);
    }else if (y>hmax){
        res=0;
    }
    return res;
}
//La funcion F_a para el primer cohete
float Fa(float t, float y, float v, float CD, float A){
    float res;
    res = 0.5*(rho(t,y,v))*A*v*fabs(v);
    return res;
}
//funcion de gravedad 
float gravedad(float t, float y, float v){
    float  G= 6.693 * pow(10, -11);
    float RT = 6.3789 * pow(10, 6);
    float MT= 5.9736 * pow(10, 24);
    float denominador = pow(RT+y,2);
    float res=0;
    res = G*MT/denominador;
    return res;
}
//La funcion que está del lado derecho de la ecuacion
float f(float t, float v, float y, float TSFC, float E0, float CD, float A, float m0, float mf0)
{
    float res;
    res = (E0/mc(t,y,v,TSFC,E0,m0, mf0)-Fa(t,y,v, CD, A)/mc(t,y,v,TSFC,E0, m0, mf0)-gravedad(t,y,v));
    return res;
}

float f2(float t, float v, float y, float TSFC, float E0, float CD, float A, float m0, float mf0){
     float res;
    res = -Fa(t, y, v, CD, A) / mc(t, y, v, TSFC, E0, m0, mf0) -gravedad(t, y, v);
    return res;
}
