#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#define N 5

typedef struct {
int cuantas_a;
int cuantas_x;
int cuantas_z;
} s_total;

s_total totales(char a[], int tam);
void llena_con_char(char a[], int tam);

int main(){
	int tam = N;
	char a[tam];
	llena_con_char(a, tam);
	s_total resultado = totales(a, tam);
	printf("La cantidad de a's en el arreglo es de: %d\n", resultado.cuantas_a);
	printf("La cantidad de x's en el arreglo es de: %d\n", resultado.cuantas_x);
	printf("La cantidad de z's en el arreglo es de: %d\n", resultado.cuantas_z);
	return 0;
}

void llena_con_char(char a[], int tam){
	int i = 0;
	while(i<tam){
		printf("Ingrese una letra para el arreglo\n");
		scanf(" %c", &a[i]);
		i++;
	}
}

s_total totales(char a[], int tam){
	s_total sol = {0,0,0};
	int i = 0;
	while(i<tam){
		if (a[i] == 'a'){
			sol.cuantas_a++;
		}
		if (a[i] == 'x'){
			sol.cuantas_x++;
		}
		if (a[i] == 'z')
		{
			sol.cuantas_z++;
		}
		i++;
	}
	return sol;
}

/*Ingrese una letra para el arreglo
a
Ingrese una letra para el arreglo
a
Ingrese una letra para el arreglo
x
Ingrese una letra para el arreglo
x
Ingrese una letra para el arreglo
z
La cantidad de a's en el arreglo es de: 2
La cantidad de x's en el arreglo es de: 2
La cantidad de z's en el arreglo es de: 1
*/
/*Ingrese una letra para el arreglo
g
Ingrese una letra para el arreglo
h
Ingrese una letra para el arreglo
j
Ingrese una letra para el arreglo
k
Ingrese una letra para el arreglo
l
La cantidad de a's en el arreglo es de: 0
La cantidad de x's en el arreglo es de: 0
La cantidad de z's en el arreglo es de: 0
*/