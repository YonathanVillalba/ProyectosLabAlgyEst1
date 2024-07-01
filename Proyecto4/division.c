#include <stdio.h>
#include <assert.h>

struct div_t {
int cociente;
int resto;
};

struct div_t division(int x, int y);
int pedir_entero (void);

int main(){
    int dividendo = pedir_entero();
    int divisor;
    struct div_t resultado;
    printf("ingrese el divisor:\n");
    scanf("%d", &divisor);
    assert(divisor>0);
    resultado = division(dividendo, divisor);
    printf("El cociente de la division es: %d\n", resultado.cociente);
    printf("El resto de la division es: %d\n", resultado.resto);
    return 0;
}

int pedir_entero (void){
    int n;
    printf("ingrese el dividendo:\n");
    scanf("%d", &n);
    return n;
}

struct div_t division(int x, int y){
    struct div_t sol;
    sol.cociente = x/y;
    sol.resto = x%y;
    return sol;
}

/* 
ingrese el dividendo:
13
ingrese el divisor:
2
El cociente de la division es: 6
El resto de la division es: 1
*/