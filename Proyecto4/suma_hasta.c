#include <stdio.h>

int suma_hasta(int n);
int pedir_entero(void);

int main(){
    int resultado;
    int entero = pedir_entero();
    if (entero>= 0){
        resultado = suma_hasta(entero);
        printf("El resultado de sumar n veces el numero dado es: %d\n", resultado);
    }
    else{
        printf("El numero ingresado no es valido, solo son validos aquellos mayores o iguales a 0\n");
    }
    return 0;
}

int pedir_entero (void){
    int n;
    printf("ingrese el numero entero:\n");
    scanf("%d", &n);
    return n;
}

int suma_hasta(int n){
    int sol = 0;
    int i = 0;
    while (i<n){
        sol = sol + i;
        i++;
    }
    return sol;
}
/*ingrese el numero entero:
4
El resultado de sumar n veces el numero dado es: 6*/
