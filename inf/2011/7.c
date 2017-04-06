//
// Created by rols on 4/6/17.
//

#include <stdio.h>
int a=1, b=2;
#define M(a,b) a ## b(a)
#define a t(f1,t(f1,f2(b)))
#define b(x) t(f2,t(f2,f1(a)))
#define ab(x) a+b(b)
typedef int (*i2i)(int);
int f1(int x) { return (++x); }
int f2(int x) { return (--x); }
int t(i2i f,int x) {return(f(f(x)));}
int main()
{
    printf("%d\n%d", M(a,b), ab(5));
    return (0);
}