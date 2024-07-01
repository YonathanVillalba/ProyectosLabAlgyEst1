#include <stdio.h>
#include <assert.h>

int main(){
	int x, y, z;
	int aux_x, aux_y, aux_z;
	printf("ingrese el valor para x\n");
	scanf("%d", &x);
	printf("ingrese el valor para y\n");
	scanf("%d", &y);
	printf("ingrese el valor para z\n");
	scanf("%d", &z);
	aux_x = x;
	aux_y = y;
	aux_z = z;
	assert(x==aux_x && y==aux_y && z==aux_z);
	x = aux_y;
	y = aux_x + aux_y - aux_z;
	z = aux_x*(1 + aux_y*aux_y);
	assert(x==aux_y && y==aux_x+aux_y-aux_z && z==aux_x*(1+aux_y*aux_y));
	printf("El nuevo valor para x es: %d\n", x);
	printf("El nuevo valor para y es: %d\n", y);
	printf("El nuevo valor para z es: %d\n", z);
	return 0;
}

/*ingrese el valor para x
2
ingrese el valor para y
4
ingrese el valor para z
5
El nuevo valor para x es: 4
El nuevo valor para y es: 1
El nuevo valor para z es: 34
*/