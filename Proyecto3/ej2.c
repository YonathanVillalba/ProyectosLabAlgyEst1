/* 2. Debugging Utiliza GDB o printf como ayuda y encontra valores para las variables que
forman el estado: */

#include <stdio.h>
#include <stdbool.h>


int main(){
int x, y, z, b, w;
bool b1, w1;
printf("introducir valor para x\n");
scanf("%d", &x);
printf("introducir valor para y\n");
scanf("%d", &y);
printf("introducir valor para z\n");
scanf("%d", &z);
printf("introducir valor para b\n");
scanf("%d", &b);
b1=b;
printf("introducir valor para w\n");
scanf("%d", &w);
w1=w;
printf("el valor de la primera expresion del segundo ejercicio es %d\n", x%4==0);
printf("el valor de la segunda expresion del segundo ejercicio es %d\n", x+y == 0 && y - x == (-1)*z );
printf("el valor de la tercera expresion del segundo ejercicio es %d\n", !b1 && w1);
return 0;

}

/* introducir valor para x
4
introducir valor para y
-4
introducir valor para z
8
introducir valor para b
1
introducir valor para w
0
el valor de la primera expresion del segundo ejercicio es 1
el valor de la segunda expresion del segundo ejercicio es 1
el valor de la tercera expresion del segundo ejercicio es 0
*/