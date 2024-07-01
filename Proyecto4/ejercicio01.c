#include <stdio.h>
#include <assert.h>

void hola_hasta(int n);
int pedir_entero(void);

int main(){
    hola_hasta(pedir_entero());
    return 0;
}

int pedir_entero (void){
    int n;
    printf("ingrese el numero entero:\n");
    scanf("%d", &n);
    return n;
}

void hola_hasta (int n){
    int i = 0;
    assert(n>0);
    while (i<n){
        printf("hola\n");
        i++;
    }
    
}

/*ingrese el numero entero:
3
hola
hola
hola*/