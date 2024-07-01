#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

struct datos{
    bool esta_ordenado_asc;
    int maximo;
};

struct datos esta_ordenado_asc(int tam, int a[]);
void pedir_arreglo(int tam, int a[]);

int main(){
    int tam;
    printf("ingrese la cantidad de elementos que tendra el arreglo:\n");
    scanf("%d", &tam);
    int a[tam];
    struct datos resultado;
    pedir_arreglo(tam, a);
    resultado = esta_ordenado_asc(tam, a);
    printf("La cadena se numeros se encuentra ordenada?\n");
    printf("%d\n",resultado.esta_ordenado_asc);
    printf("El numero mas grande de la cadena es: %d\n",resultado.maximo);
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

struct datos esta_ordenado_asc(int tam, int a[]){
    struct datos sol;
    sol.esta_ordenado_asc = true;
    sol.maximo = INT_MIN;
    int i = 0;
    while (i<tam){
        if (a[i]<a[i+1]){
            sol.esta_ordenado_asc = sol.esta_ordenado_asc && true;
        }
        else{
            sol.esta_ordenado_asc = false;
        }
        if (a[i]>sol.maximo) {
            sol.maximo = a[i];
        }
        i++;
    }
    return sol;
}