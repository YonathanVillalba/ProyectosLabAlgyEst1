#include <stdio.h>
#include <limits.h>
#define N 5

struct datos_t{
    float maximo;
    float minimo;
    float promedio;
};

struct datos_t stats(int tam, int a[]);
void pedir_arreglo(int n_max, int a[]);

int main(){
    int tam = N;
    int a[tam];
    struct datos_t resultado;
    pedir_arreglo(tam, a);
    resultado = stats(tam, a);
    printf("El minimo del arreglo es: %.2f\n", resultado.minimo);
    printf("El maximo del arreglo es: %.2f\n", resultado.maximo);
    printf("El promedio del arreglo es: %.2f\n", resultado.promedio);
    return 0;
}


void pedir_arreglo(int n_max, int a[]){
    int i = 0;
    while (i<n_max){
        printf("ingrese un valor del arreglo:\n");
        scanf("%d", &a[i]);
        i++;
    }
}

struct datos_t stats(int tam, int a[]){
    struct datos_t sol = {INT_MIN, INT_MAX, 0};
    int i = 0;
    while (i<tam){
        if (a[i]<=sol.minimo){
            sol.minimo = a[i];
        }
        if (a[i]>=sol.maximo){
            sol.maximo = a[i];
        }
        sol.promedio = (sol.promedio + a[i]);
        i++;
    }
    sol.promedio = sol.promedio/tam;
    return sol;
}
/*ingrese un valor del arreglo:
10
ingrese un valor del arreglo:
7
ingrese un valor del arreglo:
4
ingrese un valor del arreglo:
7
ingrese un valor del arreglo:
7
El minimo del arreglo es: 4.00
El maximo del arreglo es: 10.00
El promedio del arreglo es: 7.00*/