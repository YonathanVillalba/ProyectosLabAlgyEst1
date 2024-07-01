#include <stdio.h>
#include <assert.h>

int main(){
    int x,y,z;
    printf("Ingrese el valor para x:\n");
    scanf("%d", &x);
    printf("Ingrese el valor para y:\n");
    scanf("%d", &y);
    printf("Ingrese el valor para z:\n");
    scanf("%d", &z);
    int aux_x = x;
    int aux_y = y;
    int aux_z = z;
    assert(x==aux_x && y==aux_y && z==aux_z);
    if (x<=y){
        x=aux_y*aux_z;
        y=aux_z+aux_y+aux_x;
        z=aux_x+aux_y;
    }
    else{
        x= aux_y; 
        y= aux_z; 
        z= aux_x; 
    }
    assert(((x<=y && x==aux_y*aux_z && y==aux_z+aux_y+aux_x && z==aux_x+aux_y)) || (x>y && (x == aux_y && y== aux_z && z == aux_x)));
    printf("%d\n %d\n %d\n", x, y, z);
    return 0;
}
