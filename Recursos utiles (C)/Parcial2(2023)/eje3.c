#include <stdio.h>
#include <stdbool.h>

struct triangulo{
    int l1;
    int l2;
    int l3;
};
struct caract_triangulo{
    bool es_equilatero;
    int perimetro;
};

struct caract_triangulo averiguar_caract(struct triangulo t);


int main(){
    struct triangulo tri;
    struct caract_triangulo resultado;
    printf("Ingresar un lado del triangulo:\n");
    scanf("%d", &tri.l1);
    printf("Ingresar un lado del triangulo:\n");
    scanf("%d", &tri.l2);
    printf("Ingresar un lado del triangulo:\n");
    scanf("%d", &tri.l3);
    resultado = averiguar_caract(tri);
    printf("El triangulo proporcionado es equilatero?\n");
    printf("%d\n", resultado.es_equilatero);
    printf("el perimetro es: %d\n", resultado.perimetro);
    return 0;
}

struct caract_triangulo averiguar_caract(struct triangulo t){
    struct caract_triangulo sol;
    sol.es_equilatero = true;
    sol.perimetro = t.l1+t.l2+t.l3;
    if (t.l1 == t.l2 && t.l2 == t.l3){
        sol.es_equilatero = true;
    }
    else{
        sol.es_equilatero = false;
    }
    return sol;
}