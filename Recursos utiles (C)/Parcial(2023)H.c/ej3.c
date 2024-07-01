#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#define N 4

struct datos{
    bool es_divisible_2;
    int menor_divisible_por_2;
};

struct datos hay_divisibles(int tam, int a[]);
void pedir_arreglo(int tam, int a[]);

int main(){
    int tam = N;
    int a[tam];
    struct datos resultado;
    pedir_arreglo(tam, a);
    resultado = hay_divisibles(tam, a);
    printf("Existe un numero divisible por 2 en el arreglo (1 true, 0 false): %d\n", resultado.es_divisible_2);
    printf("El menor numero divisible por 2 en el arreglo es: %d\n", resultado.menor_divisible_por_2);
    return 0;
}

void pedir_arreglo(int tam, int a[]){
    int i = 0;
    while (i<tam){
        printf("ingrese un valor para el arreglo:\n");
        scanf("%d",&a[i]);
        i++;
    }
    
}

struct datos hay_divisibles(int tam, int a[]){
    struct datos sol = {false, INT_MAX};
    int i = 0;
    while (i<tam){
        if (a[i]%2 == 0){
            sol.es_divisible_2 = true;
            if (a[i]<=sol.menor_divisible_por_2){
                sol.menor_divisible_por_2 = a[i];
             }
        }
        i++;
    }
    return sol;
}

/*ingrese un valor para el arreglo:
1
ingrese un valor para el arreglo:
6
ingrese un valor para el arreglo:
4
ingrese un valor para el arreglo:
3
Existe un numero divisible por 2 en el arreglo (1 true, 0 false): 1
El menor numero divisible por 2 en el arreglo es: 4*/