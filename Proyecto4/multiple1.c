#include <stdio.h>
#include <assert.h>

int main(){
    int x, y, aux_x, aux_y;
    printf("Ingrese el valor para x:\n");
    scanf("%d", &x);
    printf("Ingrese el valor para y:\n");
    scanf("%d", &y);
    aux_x = x;
    aux_y = y;
    assert(x==aux_x && y==aux_y);
    x = aux_x+1;
    y = aux_x + aux_y;
    assert(x == aux_x+1 && y == aux_x + aux_y);
    printf("El nuevo valor para x = %d\n",x);
    printf("El nuevo valor para y = %d\n",y);
    return 0;
}
/*Ingrese el valor para x:
2
Ingrese el valor para y:
4
El nuevo valor para x = 3
El nuevo valor para y = 6*/
