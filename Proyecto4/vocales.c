#include <stdio.h>
#include <stdbool.h>

bool es_vocal(char letra);
char pedir_letra(void);

int main(){
    bool resultado;
    char letra = pedir_letra();
    resultado = es_vocal(letra);
    printf("la letra dada es vocal?(recordad 1 true 0 false)\n");
    printf("%d\n", resultado);
    return 0;
}

char pedir_letra(void){
    char a;
    printf("Ingrese una letra:\n");
    scanf("%c", &a);
    return a;
}

bool es_vocal(char letra){
    if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u' ||
        letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U'){
         return true;
    }
    else{
        return false;
    }
}
/*Ingrese una letra:
a   
la letra dada es vocal?(recordad 1 true 0 false)
1*/
