//
// Created by rols on 4/6/17.
//

#include <stdio.h>
int i , niz[7];
int ff(int n)
{
    int x0=0,y0=1,x1=1,y1=n,a,b,br=0;
    do {
        a=(y0+n)/y1*x1-x0; b=(y0+n)/y1*y1-y0;
        x0=x1; x1=a; y0=y1; y1=b; br++;
    } while (x0<y0);
    return (br);
}
int fm1(int *n, int nn)
{ int i,j;
    for( i=j=1; j<nn ; j++)
        if ((*(n+j)-*(n+j-1))>(*(n+i)-*(n+i-1)))
            i=j;
    return (i);
}
int fm2(int *n, int nn)
{ int i,j;
    for( i=j=1; j<nn ; j++)
        if ((*(n+j)-*(n+j-1))<(*(n+i)-*(n+i-1)))
            i=j;
    return (i);
}
main()
{
    for(i=1; i<=5; niz[i-1]=ff(i), i++);
    printf("%d\n", niz[fm1(niz,7)]);
    printf("%d", niz[fm2(niz,7)]);
}