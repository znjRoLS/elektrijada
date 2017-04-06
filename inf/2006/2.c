//
// Created by rols on 4/6/17.
//

#include <stdio.h>
#define M(T,X,Y) {T a=X*Y; y=a+x; f(n-1);}
int i,y,x=2;
void f(int n)
{
    if (n)
    { M(int,n-1,y) M(int,n,y) M(int,n+1,y) }
}
main()
{
    for ( ; ++i<3 ; f(i), printf("%d\n",y) );
}