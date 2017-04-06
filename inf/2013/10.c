//
// Created by rols on 4/6/17.
//

#include <stdio.h>
int f(int n)
{
    static int x;
    x+=n;
    if (n>0) { f(--n); f(--n); }
    return (x);
}
int main()
{
    printf("%d", f(4));
    return (0);
}