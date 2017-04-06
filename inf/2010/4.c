//
// Created by rols on 4/6/17.
//

#include <stdio.h>
#define M(a,b) a ## b
int fi(int i) { return i*i; }
int f0(int i) { return ++i; }
int f1(int i) { return --i; }
int f2(int i) { return i; }
typedef int (*ptf)(int);
int (*g(int i))(int) { return (M(f,i)); }
void k(int n, int b)
{
    do
        printf("%d",(*g(n%b))(n%b));
    while(n/=b);
}
int main()
{
    k(4,2); printf("\n"); k(14,3); return(0);
}