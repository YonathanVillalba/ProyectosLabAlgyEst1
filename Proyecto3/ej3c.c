/* a) Traducı al lenguaje C los programas 1.ac del pactico que se encuentra en este
enlace y Utilizar la funcion assert de C para asegurar que se cumpla la precondicion σ0.*/

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

int main(){
 int x, y;
 printf("ingresar valor para x\n");
 scanf("%d", &x);
 printf("ingresar valor para y\n");
 scanf("%d", &y);
 assert(x==2 && y==5);
 y = y+y;
  assert (x==2 && y==10);
 printf("el valor de y pasa a ser igual a %d\n", y);
 x=x+y;
  assert (x==12 && y==10);
 printf("el valor de x pasa a ser igual a %d\n", x);
return 0;
}

/*
ingresar valor para x
2
ingresar valor para y
5
el valor de y pasa a ser igual a 10
el valor de x pasa a ser igual a 12
*/

/*
ingresar valor para x
2
ingresar valor para y
1
ej3c: ej3c.c:11: main: Assertion `x==2 && y==5' failed.
Abortado (`core' generado)
*/