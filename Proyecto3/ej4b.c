/* Traducı a lenguaje C los programas que siguen a continuacion, agregando las instrucciones necesarias para que el usuario pueda ingresar los valores de las variables de entrada.
Luego, completa los estados y Volve a ejecutar nuevamente con otros estados iniciales. ¿Que hace este programa?
¿Cual es el valor final de la variable m?. */

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

int main (){
	int x, y, z, m;
	printf("ingresar los valores para x\n");
	scanf("%d", &x);
	printf("ingresar los valores para y\n");
	scanf("%d", &y);
	printf("ingresar los valores para z\n");
	scanf("%d", &z);
	printf("ingresar los valores para m\n");
	scanf("%d", &m);
	if (x<y)
	{
	  m=x;
	} else {
	  m=y;
	}
	if (m<z) 
	{

	} else {
		m=z;
	}
	printf("el nuevo valor de x es %d\n", x);
	printf("el nuevo valor de y es %d\n", y);
	printf("el nuevo valor de z es %d\n", z);
	printf("el nuevo valor de m es %d\n", m);
	return 0;
}

/* este programa lo que hace es toma cuatro valores y devuelve el menor valor mediante la variable m, ya que aunque se le de un valor en un principio despues se le cambia por el menor valor entre las variables x, y, z.
el valor final de la variable m es el menor entre las anteriores. */

/*ingresar los valores para x
5
ingresar los valores para y
4
ingresar los valores para z
8
ingresar los valores para m
0
el nuevo valor de x es 5
el nuevo valor de y es 4
el nuevo valor de z es 8
el nuevo valor de m es 4
*/