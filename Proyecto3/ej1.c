/* 1. Entrada/Salida Hace un programa en C, que solicite el ingreso de los valores de las variables
x,y,z, e imprima el resultado de las siguiente expresiones. Complet´a los resultados de la
tablas para los dos estados dados. */


#include <stdio.h>
#include <stdbool.h>

int main(){
int x, y, z, b, w;
printf("introducir valor para x\n");
scanf("%d", &x);
printf("introducir valor para y\n");
scanf("%d", &y);
printf("introducir valor para z\n");
scanf("%d", &z);
printf("introducir valor para b\n");
scanf("%d", &b);
printf("introducir valor para w\n");
scanf("%d", &w);
printf("el valor de la primera expresion es %d\n", x+y+1);
printf("el valor de la segunda expresion es %d\n", z*z+y*45-15*x);
printf("el valor de la tercera expresion es %d\n", y-2 == (x*3+1) %5);
printf("el valor de la cuarta expresion es %d\n", y/2*x); 
printf("el valor de la quinta expresion es %d\n", y < x*z);
return 0;

}

/*
introducir valor para x
7
introducir valor para y
3
introducir valor para z
5
el valor de la primera expresion es 11
el valor de la segunda expresion es 55
el valor de la tercera expresion es 0
el valor de la cuarta expresion es 7
el valor de la quinta expresion es 1 */
/* 
introducir valor para x
1           
introducir valor para y
10
introducir valor para z
8
el valor de la primera expresion es 12
el valor de la segunda expresion es 499
el valor de la tercera expresion es 0
el valor de la cuarta expresion es 5
el valor de la quinta expresion es 0
*/
/* En la ultima expresion tiene un resultado binario de tipo Int tal que 1 es verdadero y 0 es falso */
