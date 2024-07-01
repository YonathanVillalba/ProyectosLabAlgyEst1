/*Escribı el programa del ejercicio 4b, pero utilizando las funciones del ejercicio anterior.
¿Que ventajas enconaras en esta nueva version?. ¿Podrıa escribir alguna otra funcion
en ese ejercicio, cual?. ¿En que otros ejercicios de ese Proyecto lo podrıas utilizar?.
Reescribı los programas donde puedas utilizarlas. */

#include <stdio.h>
#include <stdbool.h>

int pedirEntero(void) {
    int x;
    printf("Ingrese un entero: ");
    scanf("%d", &x);
    return x;
}

void imprimeEntero(int x) {
    printf("%d\n", x);
}

int main() {
    int x, y, z, m;
    
    x = pedirEntero();
    y = pedirEntero();
    z = pedirEntero();
    
    if (x < y)
        m = x;
    else
        m = y;
    
    if (m >= z)
        m = z;
    
    printf("El valor final de m es: ");
    imprimeEntero(m);
    
    return 0;
}

/* Ingrese un entero: 2
Ingrese un entero: 3
Ingrese un entero: 4
El valor final de m es: 2
*/