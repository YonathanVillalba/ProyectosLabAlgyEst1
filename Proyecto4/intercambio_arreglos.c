#include <stdio.h>
#include <assert.h>
#define N 3

void intercambiar(int tam, int a[], int i, int j);
void pedir_arreglo(int n_max, int a[]);

int main(){
    int tam = N;
    int a[tam];
    int i, j;
    int z = 0;
    pedir_arreglo(tam, a);
    printf("Ingresar una posicion que desea intercambiar:\n");
    scanf("%d", &i);
    printf("Ingresar la otra posicion que desea intercambiar:\n");
    scanf("%d", &j);
    intercambiar(tam, a, i, j);
    while (z<tam){
        printf("%d\n", a[z]);
        z++;
    }
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

void intercambiar(int tam, int a[], int i, int j){
    int aux_i = a[i];
    int aux_j = a[j];
    assert(i<tam && j<tam);
    a[i] = aux_j;
    a[j] = aux_i;
    assert(a[i] == aux_j && a[j] == aux_i);
}
/*ingrese un valor del arreglo:
3
ingrese un valor del arreglo:
2
ingrese un valor del arreglo:
1
Ingresar una posicion que desea intercambiar:
0
Ingresar la otra posicion que desea intercambiar:
2
1
2
3*/