//
// Created by rols on 4/6/17.
//

#include <stdio.h>
#define M(X,Y) {x=a+++b; y=X+a; z+=y+b;}
int a, b, x, y, z;
void f(){M(x,y) M(x++,y) M(x,++y) M(x++,y++)}
main() {f(); printf("%d\n%d\n%d", x, y, z);}