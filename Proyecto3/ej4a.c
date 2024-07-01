/* Traducı al lenguaje C los programas 1.e y 1.f de este practico */

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

int main (){
	int x, y;
	printf("ingresar los valores para x\n");
	scanf("%d", &x);
	printf("ingresar los valores para y\n");
	scanf("%d", &y);
	if (x>=y)
	{
	  x=0;
	} else {
	  x=2;
	}
    printf("el nuevo valor de x es %d\n", x);
    printf("el nuevo valor de y es %d\n", y);
return 0;
}


/* en el punto e y en el punto f el programa es el mismo, lo unico que cambia es el valor del estado inicial */

/*ingresar los valores para x
5
ingresar los valores para y
2
el nuevo valor de x es 0
el nuevo valor de y es 2
*/
/*ingresar los valores para x
0
ingresar los valores para y
5
el nuevo valor de x es 2
el nuevo valor de y es 5
*/