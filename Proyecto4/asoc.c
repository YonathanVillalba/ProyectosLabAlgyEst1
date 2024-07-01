#include <stdio.h>
#include <stdbool.h>
#define N 3

typedef char clave_t;
typedef int valor_t;

struct asoc{
    clave_t clave;
    valor_t valor;
};

bool asoc_existe(int tam, struct asoc a[], clave_t c);

int main(){
    int tam = N;
    struct asoc a[tam];
    clave_t clave_verificar;
    int i = 0;
    while (i<tam){
        printf("Ingrese una clave:\n");
        scanf(" %c", &a[i].clave);
        printf("Ingrese un valor correspondiente:\n");
        scanf("%d", &a[i].valor);
        i++;
    }
    printf("Ingresar la clave a verificar:\n");
    scanf(" %c", &clave_verificar);
    bool resultado = asoc_existe(tam, a, clave_verificar);
    if (resultado == 1){
        printf("La clave se encuentra en el arreglo\n");
    }
    else{
        printf("La clave no se encuentra en el arreglo\n");
    }
    return 0;
}

bool asoc_existe(int tam, struct asoc a[], clave_t c){
    int i = 0;
    while (i<tam){
        if (a[i].clave == c){
            return true;
        }
        i++;
    }
    return false;
}
/*Ingrese una clave:
m
Ingrese un valor correspondiente:
4
Ingrese una clave:
c
Ingrese un valor correspondiente:
2
Ingrese una clave:
y
Ingrese un valor correspondiente:
5
Ingresar la clave a verificar:
y
La clave se encuentra en el arreglo*/