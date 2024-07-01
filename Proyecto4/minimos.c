#include <stdio.h>
#include <limits.h>
#define N 5

int minimo_pares(int tam, int a[]);
int minimo_impares(int tam, int a[]);
void pedir_arreglo(int n_max, int a[]);

int main(){
    int tam = N;
    int a[tam];
    pedir_arreglo(tam, a);
    int min_par = minimo_pares(tam, a);
    int min_impar = minimo_impares(tam,a);
    printf("El valor minimo par del arreglo es: %d\n", min_par);
    printf("El valor minimo impar del arreglo es: %d\n", min_impar);
    if (min_par<min_impar){
        printf("El valor mas chico del arreglo es: %d\n", min_par);
    }
    else{
        printf("El valor mas chico del arreglo es: %d\n", min_impar);
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

int minimo_pares(int tam, int a[]){
    int sol_par = INT_MAX;
    int i = 0;
    while (i<tam){
        if (a[i]%2 == 0 && a[i]<sol_par){
            sol_par = a[i];
        }
        i++;
    }
    return sol_par;
}

int minimo_impares(int tam, int a[]){
    int sol_impar = INT_MAX;
    int i = 0;
    while (i<tam){
        if (a[i]%2 != 0 && a[i]<sol_impar){
            sol_impar = a[i];
        }
        i++;
    }
    return sol_impar;
}
/*ingrese un valor del arreglo:
3
ingrese un valor del arreglo:
1
ingrese un valor del arreglo:
2
ingrese un valor del arreglo:
4
ingrese un valor del arreglo:
7
El valor minimo par del arreglo es: 2
El valor minimo impar del arreglo es: 1
El valor mas chico del arreglo es: 1*/