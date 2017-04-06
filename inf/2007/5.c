//
// Created by rols on 4/6/17.
//

#include <stdio.h>
typedef int (*i2i)(int);
int f1(int x) { return (++x); }
int f2(int x) { return (--x); }
int t(i2i f1, int x) { return (f1(f1(x))); }
main()
{
    printf("%d\n",t(f1,t(f1,f2(10))));
    printf("%d\n",t(f2,t(f2,f1(10))));
}