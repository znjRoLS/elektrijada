//
// Created by rols on 4/6/17.
//

#include <stdio.h>
int kdn(int a,int b)
{
    int k=0,t,s=1;
    while (!((a%2)+(b%2)))
    { k++; a/=2; b/=2; }
    t = a%2 ? -b : a;
    while (t)
    {
        while (!(t%2)) t/=2;
        if (t>0) a=t; else b=-t;
        t=a-b;
    }
    for ( ; k ; s*=2,k-- );
    return (a*s);
}
int f(int n,int a)
{
    int k;
    k=kdn((n-1)*a,(n+1)*a);
    for (;n;n--)
        k=kdn(k,kdn((n-1)*a,(n+1)*a));
    return (k);
}
main()
{
    printf("%d", f(10,9));
}