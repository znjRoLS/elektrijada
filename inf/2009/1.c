//
// Created by rols on 4/6/17.
//

#include <stdio.h>
#define A *(p+b)
#define B *(p+b+1)
#define S(C,D) { C+=D; D=C-D; C-=D; }
int b,c;
void f2(int *p, int n)
{
    static int b;
    while (b<n)
        if (B>A) { S(A,B) if (b) b--; } else b++;
}
void f1(int *p)
{
    static int n;
    while (n++<0100)
        if ((n&0xf)==((n&0xf0)>>4)) { A=n; b++; }
}
main()
{
    static int a[100];
    f1(a); f2(a,--b);
    while (a[c]) printf("%d ",a[c++]);
}