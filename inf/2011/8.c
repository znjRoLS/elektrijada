//
// Created by rols on 4/6/17.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct X {int a,b,c; struct X *p;} M;
M *kor = NULL;
int f(int a, int b)
{
    M *c = kor;
    while (c)
    {
        if (c->a == a && c->b == b) return 1;
        c = c->p;
        if (c == kor) break;
    }
    return (0);
}
void add(int a, int b)
{
    M *c, *t;
    if (f(a,b))
    {
        c = kor;
        while (c)
        {
            if (c->a==a && c->b==b) break;
            c = c->p;
        }
        c->c++;
    }
    else
    {
        t = (M*)malloc(sizeof(M));
        t->a = a; t->b = b; t->c = 1;
        t->p = (kor==NULL)? t : kor->p;
        kor = (kor==NULL)? t : kor;
        kor->p = t;
    }
}
int ff(int n)
{
    int x0=0, y0=1, x1=1, y1=n, a, b, br=0;
    do
    {
        a = (y0+n)/y1*x1-x0;
        b = (y0+n)/y1*y1-y0;
        add(a,b);
        x0=x1; x1=a; y0=y1; y1=b;
        br++;
    }
    while (x0<y0);
    return (br);
}
int main()
{
    int a, b, ma, mb, m=1;
    for (a=1; a<10; ff(a++));
    ma=a=kor->a; mb=b=kor->b;
    while (kor)
    {
        kor = kor->p;
        if (kor->c > m)
        { ma=kor->a; mb=kor->b; m=kor->c; }
        if (kor->a==a && kor->b==b) break;
    }
    printf("%d\n%d\n%d", ma, mb, m);
    return (0);
}