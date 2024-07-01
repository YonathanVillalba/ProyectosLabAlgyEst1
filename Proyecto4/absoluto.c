#include <stdio.h>
#include <assert.h>

int pedir_entero(void);

int main(){
    int x = pedir_entero();
    if (x>=0){
        printf("el valor absoluto del numero dado es: %d\n", x);
    }
    else{
        x = x*(-1);
        printf("el valor absoluto del numero dado es: %d\n", x);
    }
    assert(x>=0);
    return 0;
}

int pedir_entero (void){
    int n;
    printf("ingrese el numero entero:\n");
    scanf("%d", &n);
    return n;
}
/*ingrese el numero entero:
-3
el valor absoluto del numero dado es: 3*/
