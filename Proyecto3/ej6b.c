#include <stdio.h>
#include <stdbool.h>

bool pedirBooleano(char n);
void imprimirBooleano(bool x);

int main(){
int x;
char n = 'n';

x = pedirBooleano(n);

imprimirBooleano(x);

return 0;
}

bool pedirBooleano(char n){
	int x;

	printf("Recuerda, 1 para Verdadero y 0 para Falso.\n");
	printf("Este booleano se almacena en %c: ", n);
	scanf("%d", &x);

	return x;
}

void imprimirBooleano(bool x){
	if(x == 0){
	printf("El valor de verdad es: Falso.\n");
	}
	else{
	printf("El valor de verdad es: Verdadero.\n");
	}
}

/* Recuerda, 1 para Verdadero y 0 para Falso.
Este booleano se almacena en n: 1
El valor de verdad es: Verdadero.*/