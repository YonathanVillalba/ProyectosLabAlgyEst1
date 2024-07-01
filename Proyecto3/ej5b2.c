/*  Traducı a lenguaje C los programas que siguen a continuacion, agregando las instrucciones necesarias para que el usuario pueda ingresar los valores. Luego, complet´a los
estados, donde el estado a completar es el resultado de realizar 1, 2, 3 o 4 iteraciones
del ciclo. Una iteracion es la ejecucion completa del cuerpo del ciclo. */

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

int main (){
	int x, i,type_bool;
	bool res; 
	printf("ingresar los valores para x\n");
	scanf("%d", &x);
	printf("ingresar los valores para i\n");
	scanf("%d", &i);
	printf("Ingresar 0 para asignar verdadero a res\nSino, ingresar 1 para valor falso\n");	
	scanf("%d", &type_bool);
	if(type_bool==0){
		res=true; 
	} else {
		res=false;
	}
	while(i<x && res){
		res=res && (x%i!=0);
		i=i+1;

	}
	printf("el nuevo valor de x es %d\n", x);
	printf("el nuevo valor de i es %d\n", i);
	return 0;
}

/*
ingresar los valores para x
5
ingresar los valores para i
0
Ingresar 0 para asignar verdadero a res
Sino, ingresar 1 para valor falso
1
el nuevo valor de x es 5
el nuevo valor de i es 0
*/



