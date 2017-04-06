#include <stdio.h>

int x,c1,c2,sc2;

int f(int i)
{
    if (i && !((i-1)&i)) f((c1++,i>>1));
    return (c1);
}


void main()
{
    int i;
    for (i=1; i<10; i++, c1=0)
    {
        c2 += (x=f(i)) ? --x : x;
        if (sc2!=c2) printf("%d\n", sc2=c2);
    }
}
