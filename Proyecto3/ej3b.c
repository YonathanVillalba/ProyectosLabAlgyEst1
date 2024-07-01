/* a) Traducı al lenguaje C los programas 1.ab del pactico que se encuentra en este
enlace y Utilizar la funcion assert de C para asegurar que se cumpla la precondicion σ0.*/

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>


int main(){
int x, y;
printf("ingresar valor para x\n");
scanf("%d", &x);
printf("ingresar valor para y\n");
scanf("%d", &y);
assert(x==2 && y==5);
x=x+y;
assert(x == 7 && y == 5);
printf("el valor de x pasa a ser igual a %d\n", x);
y = y+y;
assert(y == 10 && x == 7);
printf("el valor de y pasa a ser igual a %d\n", y);
return 0;
}

/*
ingresar valor para x
2
ingresar valor para y
5
el valor de x pasa a ser igual a 7
el valor de y pasa a ser igual a 10
*/

/*
ingresar valor para x
3
ingresar valor para y
4
ej3b: ej3b.c:13: main: Assertion `x==2 && y==5' failed.
Abortado (`core' generado)
*/