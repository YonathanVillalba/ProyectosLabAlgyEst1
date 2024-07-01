#include <stdio.h>
#include <stdbool.h>
#define N 3

bool todos_pares(int tam, int a[]);
bool existe_multiplo(int m, int tam, int a[]);
void pedir_arreglo(int n_max, int a[]);


int main(){
    int option;
    int tam = N;
    int a[tam];
    bool res_pares;
    bool res_multiplo;
    pedir_arreglo(tam, a);
    printf("ingrese el programa que desea utilizar utilizando 1 y 2 respectivante:\n");
    printf("1. ejecutar todos pares\n");
    printf("2. ejecutar existe_multiplo\n");
    scanf("%d", &option);
    if (option == 1) {
        res_pares = todos_pares(tam, a);
        printf("recordar 0 para false y 1 para verdadero\n");
        printf("los elementos del arreglo son todos pares?\n%d\n", res_pares);
    }
    else if(option == 2){
        int n;
        printf("Ingrese el numero con el que quiere verificar si existe un multiplo en el arreglo:\n");
        scanf("%d", &n);
        res_multiplo = existe_multiplo(n, tam, a);
        printf("recordad 0 para false y 1 para verdadero\n");
        printf("existe algun multiplo del numero dado en arreglo?\n%d\n", res_multiplo);
    }
    else{
        printf("El numero utilizado no es valido (usar 1 o 2)\n");
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

bool todos_pares(int tam, int a[]){
    bool sol1 = true;
    int i = 0;
    while (i<tam){
        sol1 = sol1 && a[i]%2==0;
        i++;
    }
    return sol1;
}

bool existe_multiplo(int m, int tam, int a[]){
    bool sol2 = false;
    int i = 0;
    while (i<tam){
        sol2 = sol2 || m % a[i] == 0;
        i++;
    }
    return sol2;
}
/*ingrese un valor del arreglo:
2
ingrese un valor del arreglo:
4
ingrese un valor del arreglo:
6
ingrese el programa que desea utilizar utilizando 1 y 2 respectivante:
1. ejecutar todos pares
2. ejecutar existe_multiplo
1
recordar 0 para false y 1 para verdadero
los elementos del arreglo son todos pares?
1*/

/*ingrese un valor del arreglo:
2
ingrese un valor del arreglo:
5
ingrese un valor del arreglo:
8
ingrese el programa que desea utilizar utilizando 1 y 2 respectivante:
1. ejecutar todos pares
2. ejecutar existe_multiplo
2
Ingrese el numero con el que quiere verificar si existe un multiplo en el arreglo:
4
recordad 0 para false y 1 para verdadero
existe algun multiplo del numero dado en arreglo?
1*/