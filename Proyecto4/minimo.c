#include <stdio.h>
#include <assert.h>

int pedir_entero(void);

int main(){
    int x, y;
    x = pedir_entero();
    y = pedir_entero();
    assert(x!=y);
    if (x>y){
        printf("El numero menor es %d\n", y);
    }
    else{
        printf("El numero menor es %d\n", x);
    }
    
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
El numero menor es 2*/
