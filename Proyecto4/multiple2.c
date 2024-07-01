#include <stdio.h>
#include <assert.h>

int main(){
    int x, y, z, aux_x, aux_y, aux_z;
    printf("Ingrese el valor para x:\n");
    scanf("%d", &x);
    printf("Ingrese el valor para y:\n");
    scanf("%d", &y);
    printf("Ingrese el valor para z:\n");
    scanf("%d", &z);
    aux_x = x;
    aux_y = y;
    aux_z = z;
    assert(x==aux_x && y==aux_y && z == aux_z);
    x = aux_y;
    y = aux_x + aux_y + aux_z;
    z = aux_x + aux_y;
    assert(x == aux_y && y == aux_x + aux_y + aux_z && z == aux_x + aux_y);
    printf("El nuevo valor para x = %d\n",x);
    printf("El nuevo valor para y = %d\n",y);
    printf("El nuevo valor para z = %d\n",z);
    return 0;
}
/*Ingrese el valor para x:
2
Ingrese el valor para y:
4
Ingrese el valor para z:
6
El nuevo valor para x = 4
El nuevo valor para y = 12
El nuevo valor para z = 6*/
