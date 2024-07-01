/* a) Traducı al lenguaje C los programas 1.a del pactico que se encuentra en este
enlace y Utilizar la funcion assert de C para asegurar que se cumpla la precondicion σ0.*/

#include <stdio.h>
#include <stdbool.h>
#include <assert.h> 

int main(){
int x;
printf("ingrese un valor para x\n");
scanf("%d",&x);
assert(x==1);
x=5;
assert (x==5);
printf("el valor de x es %d\n", x);
return 0;
}

/*
ingrese un valor para x
1
el valor de x es 5
*/
/*
ingrese un valor para x
6
ej3: ej3.c:9: main: Assertion `x==1' failed.
Abortado (`core' generado)

*/
