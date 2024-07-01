#include <stdio.h>
#include <stdbool.h>

struct lienzo {
    int l1;
    int l2;
    int l3;
    int l4;
};

struct tipo_lienzo{
    bool es_figura;
    bool es_paisaje;
    bool ninguna_de_las_anteriores;
};

struct tipo_lienzo verificar_lienzo(struct lienzo t);

int main(){
    struct lienzo lados;
    struct tipo_lienzo resultado;
    printf("Ingrese el primer lado del lienzo: \n");
    scanf("%d", &lados.l1);
    printf("Ingrese el segundo lado del lienzo: \n");
    scanf("%d", &lados.l2);
    printf("Ingrese el tercer lado del lienzo: \n");
    scanf("%d", &lados.l3);
    printf("Ingrese el cuarto lado del lienzo: \n");
    scanf("%d", &lados.l4);
    resultado = verificar_lienzo(lados);
    if(resultado.es_figura){
        printf("El tipo de lienzo que voy a utilizar es figura\n");
    }
    if(resultado.es_paisaje){
       printf("El tipo de lienzo que voy a utilizar es paisaje\n");
    }
    if (resultado.ninguna_de_las_anteriores){
        printf("No voy a utilizar ninguna de las anteriores\n"); 
    }
    
    return 0;
}

struct tipo_lienzo verificar_lienzo(struct lienzo t){
    struct tipo_lienzo sol= {false, false, false};
    if (t.l1 == t.l2 && t.l2 == t.l3 && t.l3== t.l4){
        sol.es_figura = true;
    }
    if (t.l1 == t.l3 && t.l2 == t.l4 && t.l1 != t.l2 && t.l3 != t.l4){
        sol.es_paisaje = true;
    }
    if(sol.es_figura == false && sol.es_paisaje == false){
        sol.ninguna_de_las_anteriores = true;
    }
    return sol;
}