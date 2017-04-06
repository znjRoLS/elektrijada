//
// Created by rols on 4/6/17.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct nd {int v,c; struct nd *p;} my;
my *kor = NULL;
int f(int v)
{
    my *c = kor;
    while (c)
    {
        if (c->v == v) return 1; c = c->p;
        if (c == kor) break; continue;
    }
    return (0);
}
void add(int v)
{
    my *c, *t;
    do if (f(v%10))
        {
            c = kor;
            while (c)
            {
                if (c->v == v%10) break; c = c->p;
                continue;
            }
            c->c++;
        } else {
            t = (my*)malloc(sizeof(my));
            t->v = v%10; t->c = 1;
            t->p = (kor==NULL)? t : kor->p;
            kor = (kor==NULL)? t : kor;
            kor->p = t;
        }
    while (v/=10);
}
int main()
{
    int i=0;
    while (i<100) add(i++);
    while (kor)
    {
        if (kor->v == 0) break; kor = kor->p;
        continue;
    }
    printf("%d %d\n", kor->v, kor->c);
    printf("%d %d", kor->p->v, kor->p->c);
    return (0);
}