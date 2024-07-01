#include <stdio.h>
#include <assert.h>

int pedir_entero (void);

int main(){
    int x = pedir_entero();
    int y = pedir_entero();
    int z = x;
    assert(x==x && y==y && z==x);
    printf ("el valor sin intercambiar de x = %d y el valor de y = %d\n", x, y);
    x = y;
    y = z;
    assert(x==x && y==z);
    printf("los valores dados intercambiados son: x = %d e y = %d\n", x, y);
    return 0;
}

int pedir_entero (void){
    int n;
    printf("ingrese el numero entero:\n");
    scanf("%d", &n);
    return n;
}
/*ingrese el numero entero:
3
ingrese el numero entero:
2
el valor sin intercambiar de x = 3 y el valor de y = 2
los valores dados intercambiados son: x = 2 e y = 3*/
