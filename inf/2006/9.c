//
// Created by rols on 4/6/17.
//

#include <stdio.h>
int x0,y0,px,py;
int nx[100],ny[100],n,t;
void f1(int); void f2(int);
void f3(int); void f4(int);
void fp(int a)
{
    int i;
    px += (a%2) ? 0 : 1-a;
    py -= (a%2) ? 2-a : 0;
    for (i=0; i<n; i++)
        if (!(nx[i]-px) && !(ny[i]-py))
        { t++; break; }
    if (i==n) { n++; nx[n]=px; ny[n]=py; }
}
void f1(int i)
{ if (i)
    { f4(i-1); fp(2);
        f1(i-1); fp(3);
        f1(i-1); fp(0);
        f2(i-1); }
}
void f2(int i)
{ if (i)
    { f3(i-1); fp(1);
        f2(i-1); fp(0);
        f2(i-1); fp(3);
        f1(i-1); }
}
void f3(int i)
{ if (i)
    { f2(i-1); fp(0);
        f3(i-1); fp(1);
        f3(i-1); fp(2);
        f4(i-1); }
}
void f4(int i)
{ if (i)
    { f1(i-1); fp(3);
        f4(i-1); fp(2);
        f4(i-1); fp(0);
        f3(i-1); }
}
main()
{
    f1(2); printf("%d\n%d",t,n);
}