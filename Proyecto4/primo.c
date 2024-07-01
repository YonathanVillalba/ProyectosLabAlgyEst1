#include <stdio.h>
#include<limits.h>
#include <stdbool.h>

int nesimo_primo(int n);
int pedir_entero (void);
bool es_primo(int s);

int main(){
    int n;
    printf("Ingresar la posicion del numero primo que queremos conocer:\n");
    scanf("%d", &n);
    while(n<0){
        printf("El numero ingresado no es valido, por favor a continuacion ingresar uno valido\n");
        scanf("%d", &n);
    }
    int resultado = nesimo_primo(n);
    printf("El resultado de hacer el nesimo primo del numero dado es: %d\n", resultado);
    return 0;
}

int pedir_entero (void){
    int n;
    printf("ingrese el numero entero:\n");
    scanf("%d", &n);
    return n;
}

bool es_primo(int s){
	int i=2;
	bool yes=true;
	while (i<s){
		if((s%i)!=0 && yes==true){
			yes=true; 
		} else {
			yes=false; 
		}
		i=i+1;
	} 
	return yes; 
}


int nesimo_primo(int n){
	int i=2, res=0, dos; 
	while(i<INT_MAX && res!=n){
    	if(es_primo(i)){
    		res=res+1;
		}
		i=i+1;
	} 
	dos=i-1;
	return dos; 
}

/*Ingresar la posicion del numero primo que queremos conocer:
-5
El numero ingresado no es valido, por favor a continuacion ingresar uno valido
5
El resultado de hacer el nesimo primo del numero dado es: 11*/
El numero ingresado no es valido, por favor a continuacion ingresar uno valido
5
El resultado de hacer el nesimo primo del numero dado es: 11*/
