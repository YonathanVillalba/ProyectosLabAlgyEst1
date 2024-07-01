#include <stdio.h>
#define N 3

int sumatoria(int tam, int a[]);
void pedir_arreglo(int n_max, int a[]);

int main(){
    int tam = N;
    int a[tam];
    int resultado;
    pedir_arreglo(tam, a);
    resultado = sumatoria(tam, a);
    printf("El resultado de hacer la sumatoria de los elementos del arreglo es: %d\n", resultado);
    return 0;
}


void pedir_arreglo(int n_max, int a[]){
    int i = 0;
    while (i<n_max){
        printf("ingrese un valor del arreglo:");
        scanf("%d", &a[i]);
        i++;
    }
}

int sumatoria(int tam, int a[]){
    int sol = 0;
    int i = 0;
    while (i<tam){
        sol = sol + a[i];
        i++;
    }
    return sol;
}
/*ingrese un valor del arreglo:5       
ingrese un valor del arreglo:1
ingrese un valor del arreglo:1
El resultado de hacer la sumatoria de los elementos del arreglo es: 7*/
