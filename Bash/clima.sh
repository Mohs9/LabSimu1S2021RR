#!/bin/bash
curl wttr.in/Guatemala > lab3
lectura=$(head -7 lab3)
echo $lectura
rm lab3