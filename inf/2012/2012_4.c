
#include <stdio.h>

int x,c1,c2;

int f1(int i)
{
    if (i && (i-1)&i == 0) f1((c1++,i>>1));
    return (c1);
}

void e2012_4()
{
    int i;
    for (i=1; i<10; i++, c1=0)
    c2 += (x=f1(i)) ? --x : x;
    printf("%d", c2);
}
