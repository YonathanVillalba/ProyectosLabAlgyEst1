#include <stdio.h>
#define N 5

struct comp_t {
int menores;
int iguales;
int mayores;
};

struct comp_t cuantos(int tam, int a[], int elem);
void pedir_arreglo(int n_max, int a[]);

int main(){
    int tam = N;
    int a[tam];
    int elem;
    pedir_arreglo(tam, a);
    printf("Ingrese el numero que quiere comparar:\n");
    scanf("%d", &elem);
    struct comp_t resultado = cuantos(tam, a, elem);
    printf("La cantidad de elementos menores al numero dado son: %d\n", resultado.menores);
    printf("La cantidad de elementos mayores al numero dado son: %d\n", resultado.mayores);
    printf("La cantidad de elementos iguales al numero dado son: %d\n", resultado.iguales);
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

struct comp_t cuantos(int tam, int a[], int elem){
    struct comp_t sol = {0,0,0};
    int i = 0;
    while (i<tam){
        if (a[i]<elem){
            sol.menores++;
        }
        else if (a[i]>elem){
            sol.mayores++;
        }
        else if (a[i] == elem){
            sol.iguales++;
        }
        i++;
    }
    return sol;
}
/*ingrese un valor del arreglo:
1
ingrese un valor del arreglo:
1
ingrese un valor del arreglo:
1
ingrese un valor del arreglo:
2
ingrese un valor del arreglo:
3
Ingrese el numero que quiere comparar:
2
La cantidad de elementos menores al numero dado son: 3
La cantidad de elementos mayores al numero dado son: 1
La cantidad de elementos iguales al numero dado son: 1*/