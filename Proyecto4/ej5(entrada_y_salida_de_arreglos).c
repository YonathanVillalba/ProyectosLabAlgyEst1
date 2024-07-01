#include <stdio.h>
#define N 5

void pedir_arreglo(int n_max, int a[]);
void imprimir_arreglo(int n_max, int a[]);

int main(){
    int tam = N;
    int a[tam];
    pedir_arreglo(tam, a);
    imprimir_arreglo(tam, a);
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

void imprimir_arreglo(int n_max, int a[]){
    int i = 0;
    printf("los elementos del arreglos son los siguientes:\n");
    while (i<n_max){
        printf("%d\n", a[i]);
        i++;
    }
}
/*ingrese un valor del arreglo:3
ingrese un valor del arreglo:2
ingrese un valor del arreglo:1
ingrese un valor del arreglo:5
ingrese un valor del arreglo:4
los elementos del arreglos son los siguientes:
3
2
1
5
4*/
