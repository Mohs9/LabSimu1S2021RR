unset label
set terminal 'epslatex'
set output 'pv.tex'
set xrange [40:200]
set yrange [5:90]
set title "Presi\\'on vrs. Volumen"
set xlabel "V [in$^{3}$]"
set ylabel "P [lb/in$^{3}$]"
set grid
unset key
a=1.5
b=30435.58
f(x)= b*x**(-a)
fit f(x) 'datos.dat' using 1:3 via a, b
plot f(x), 'datos.dat' using 1:3:2:4 with xyerrorbars pt 3
set output