#!/bin/bash

#Autor: Rubi Ramirez
#Tipo: Script de Bash
#Ejecutar: ./generadorarchivo.sh
#Resumen:  Generador automatico de comentaios para script de C.

#bienvenida
echo "* * * * Generador de Archivos de C * * * *"
#obtener y validar el nombre del archivo
read -p "Ingrese el nombre del archivo: " nombre
fnombre=$nombre".gp"
if [ -z $nombre ]; then
    echo "No ingreso un nombre valido"
    exit 2
fi
#obtener informacion del sistema
autor="Rubí E. Ramírez Milián"
fecha=$(date)
version=$(gcc --version | head -n 1)
#crear nuestro contenido
echo "set title" > $fnombre
echo "Autor: " $autor >> $fnombre
echo "Compliador:" $version >> $fnombre
echo Para compilar: gcc -o $nombre $fnombre >> $fnombre
echo "Fecha: " $fecha >> $fnombre
echo "*/" >> $fnombre



