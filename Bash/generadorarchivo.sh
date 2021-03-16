#!/bin/bash

#Autor: Rubi Ramirez
#Tipo: Script de Bash
#Ejecutar: ./generadorarchivo.sh
#Resumen:  Generador automatico de comentaios para script de C.

#bienvenida
echo "* * * * Generador de Archivos de C * * * *"
#obtener y validar el nombre del archivo
read -p "Ingrese el nombre del archivo: " nombre
fnombre=$nombre".c"
if [ -z $nombre ]; then
    echo "No ingreso un nombre valido"
    exit 2
fi
#obtener informacion del sistema
autor="Rubi E. Ramirez Milian"
fecha=$(date)
version=$(gcc --version | head -n 1)
#crear nuestro contenido
echo "/*" > $fnombre
echo "Autor: " $autor >> $fnombre
echo "Compliador:" $version >> $fnombre
echo Para compilar: gcc -o $nombre $fnombre >> $fnombre
echo "Fecha: " $fecha >> $fnombre
echo "Librerias: stdio (u otras)" >> $fnombre
echo "Entradas, Salidas, Resumen:" >> $fnombre
echo "*/" >> $fnombre
echo " " >> $fnombre
echo "//Librerias" >> $fnombre
echo "#include <stdio.h>" >> $fnombre
echo "//Declaracion e inicializacion de variables globales" >> $nombre

