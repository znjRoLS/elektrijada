//
// Created by rols on 4/6/17.
//

#include <stdio.h>
int fk(int n)
{
    int i=1; for (;++i*i<=n;); return (--i);
}
int fp(int n)
{
    int p1=fk(n), p2=0;
    while (p1+p2<n)
    {
        if ((p1*p1-p2*p2)>n) p2++;
        else if ((p1*p1-p2*p2)==n) return (!p2);
        else p1++;
    }
    return (1);
}
int main()
{
    int n=1, bp=0;
    for (; n<10; n+=2) bp+=fp(n);
    printf("%d\n", bp);
    for (; n<20; n+=2) bp+=fp(n);
    printf("%d\n", bp);
    for (; n<30; n+=2) bp+=fp(n);
    printf("%d\n", bp);
    return (0);
}