/* en un archivo saludos.c implementar las funciones siguientes (Ademas de la main):
una que imprime el string "hola", que no toma ni devuelve parametros, con
prototipo:
void imprimeHola(void)
similar a la anterior con la el string "chau":
void imprimeChau(void)
Ese programa tiene que imprimir dos veces “Hola” seguido de dos veces “Chau”,
llamando a las dos ultimas funciones desde el main. */

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>


void imprimeHola(){
	printf("Hola\n");
}



void imprimeChau(){
	printf("Chau\n");
}


int main (){
	imprimeHola();
	imprimeHola();
	imprimeChau();
	imprimeChau();
	return 0;
}

/* Hola
Hola
Chau
Chau
*/