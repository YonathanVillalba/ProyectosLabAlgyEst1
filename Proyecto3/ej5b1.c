/*  Traducı a lenguaje C los programas que siguen a continuacion, agregando las instrucciones necesarias para que el usuario pueda ingresar los valores. Luego, complet´a los
estados, donde el estado a completar es el resultado de realizar 1, 2, 3 o 4 iteraciones
del ciclo. Una iteracion es la ejecucion completa del cuerpo del ciclo. */
#include <stdio.h>

#include <stdbool.h>

int main(){
	int x, y, i;
	printf("ingresar los valores para x\n");
	scanf("%d", &x);
	printf("ingresar los valores para y\n");
	scanf("%d", &y);
	i=0;
	while (x>=y){
		x=x-y;
		i=i+1;
	}
	printf("el valor de x es %d\n", x);
	printf("el valor de y es %d\n", y);
	printf("el valor de i es %d\n", i);
return 0;
}

/* 1er Iteracion: x=10 y=3 i=1
2da iteracion: x=7 y=3 i=2
3er iteraciom: x=4 y=3 i=3
4ta iteracion: x=1 y=3 i=4*/