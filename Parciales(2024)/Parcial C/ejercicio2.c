#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#define N 5

void llena_con_char(char a[], int tam);
bool hay_mas_de_2_consonantes(char a[], int tam);

int main(){
	int tam = N;
	assert(tam>0);
	char a[tam];
	llena_con_char(a, tam);
	bool resultado = hay_mas_de_2_consonantes(a, tam);
	printf("El arreglo tiene 3 o mas consonantes? (recordar 1 true 0 false): %d\n", resultado);
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

bool hay_mas_de_2_consonantes(char a[], int tam){
	bool sol = false;
	int cant_cons = 0;
	int i = 0;
	while(i<tam){
		if (a[i] != 'a' && a[i] != 'e' && a[i] != 'i' && a[i] != 'o' && a[i] != 'u' &&
        a[i] != 'A' && a[i] != 'E' && a[i] != 'I' && a[i] != 'O' && a[i] != 'U'){
			cant_cons++;
		}
		else {
			sol = false;
		}
		i++;
	}
	if (cant_cons>=3){
		sol = true;
	}
	else if (cant_cons<3){
		sol = false;
	}
	return sol;
}

/*Ingrese una letra para el arreglo
a
Ingrese una letra para el arreglo
e
Ingrese una letra para el arreglo
c
Ingrese una letra para el arreglo
d
Ingrese una letra para el arreglo
u
El arreglo tiene 3 o mas consonantes? (recordar 1 true 0 false): 0
*/
/*Ingrese una letra para el arreglo
c
Ingrese una letra para el arreglo
d
Ingrese una letra para el arreglo
f
Ingrese una letra para el arreglo
g
Ingrese una letra para el arreglo
h
El arreglo tiene 3 o mas consonantes? (recordar 1 true 0 false): 1
*/