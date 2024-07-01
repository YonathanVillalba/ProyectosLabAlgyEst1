/* a) entradas.c que lee una variable de tipo int y la imprime por pantalla. En esta ocasion
el programa debe utilizar dos funciones a definir (adem´as de la funci´on main):
una funcion que le pide un entero al usuario y lo devuelve, con prototipo:
int pedirEntero(void)
que toma un entero como parametro y lo imprime:
void imprimeEntero(int x) */

#include <stdio.h>
#include <stdbool.h>


int pedirEntero(char name);

int main (void){
	int m;
	m = pedirEntero ('m');
	printf("m vale: %d\n", m);
	
	return 0;
}

int pedirEntero(char name){
	int n;
	printf("ingrese un entero para la variable %c : ", name);
	scanf ("%d", &n);

	return n;
}

/* ingrese un entero para la variable m : 2
m vale: 2
*/