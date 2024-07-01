#include <stdio.h>
#include <assert.h>

struct info_t {
    int op_sum; // Guarda la suma
    int op_mul; // Guarda la multiplicación
    int op_div; // Guarda la división entera
    int op_dist; // Guarda el valor absoluto de la resta
};

struct info_t operar(int x, int y);

int main(){
    int x, y;
    struct info_t resultado;
    printf("Ingrese el valor de x:\n");
    scanf("%d", &x);
    printf("Ingrese el valor de y:\n");
    scanf("%d", &y);
    assert(x>0 && y>0 && x>y);
    resultado = operar(x, y);
    printf("El resultado de la suma de x e y es: %d\n", resultado.op_sum);
    printf("El resultado de la multiplicacion de x e y es: %d\n", resultado.op_mul);
    printf("El resultado de la division de x e y es: %d\n", resultado.op_div);
    printf("El resultado de la resta de x e y es: %d\n", resultado.op_dist);
    return 0;
}

struct info_t operar(int x, int y){
    struct info_t sol;
    sol.op_sum = x+y;
    sol.op_mul = x*y;
    sol.op_div = x/y;
    sol.op_dist = x-y;
    return sol;
}
/*Ingrese el valor de x:
10
Ingrese el valor de y:
2
El resultado de la suma de x e y es: 12
El resultado de la multiplicacion de x e y es: 20
El resultado de la division de x e y es: 5
El resultado de la resta de x e y es: 8*/