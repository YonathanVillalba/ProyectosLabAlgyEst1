/* Traducı al lenguaje C los programas 1.h y 1.i del practico. El estado σ0 debe solicitarse
al usuario, agregando las instrucciones necesarias para que el usuario pueda ingresar los
valores de las variables de entrada.*/

#include <stdio.h>
#include <stdbool.h>

int main (){
  int i;
  printf("Ingrese el valor de i\n");
  scanf("%d", &i);
  while (i!=0) {
  	i=i-1;
  }
  printf("el nuevo valor de i es %d\n", i);
  return 0;
}

/*Ingrese el valor de i
4
el nuevo valor de i es 0
 */