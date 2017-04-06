//
// Created by rols on 4/6/17.
//

#include <stdio.h>
#define M(T,X,Y) {T a=X/Y; y+=a+++x; f(n-1);}
int i=3,y,x;
void f(int n)
{
    if (n)
    {
        M(int,++x,++y) M(int,x,y) M(int,x++,y++)
    }
}
main()
{
    for ( ; i-->1 ; f(i), printf("%d\n",y) );
}