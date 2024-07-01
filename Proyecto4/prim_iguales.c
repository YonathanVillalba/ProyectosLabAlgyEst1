#include <stdio.h>
#define N 5

int prim_iguales(int tam, int a[]);
void pedir_arreglo(int n_max, int a[]);

int main(){
    int tam = N;
    int a[tam];
    pedir_arreglo(tam, a);
    int resultado = prim_iguales(tam, a);
    printf("La longitud del tramo inicial mas largo es: %d\n", resultado);
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

int prim_iguales(int tam, int a[]){
    int sol = 0;
    int i = 0;
    while (i<tam){
        if (a[0] == a[i]){
            sol++;
        }
        i++;
    }
    return sol;
}
/*ingrese un valor del arreglo:
3
ingrese un valor del arreglo:
3
ingrese un valor del arreglo:
3
ingrese un valor del arreglo:
2
ingrese un valor del arreglo:
1
La longitud del tramo inicial mas largo es: 3*/