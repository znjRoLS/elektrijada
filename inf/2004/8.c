//
// Created by rols on 4/6/17.
//

#include <stdio.h>
#define S(t,m,n) {t p=m; m=n; n=p; b++;}
int b;
void fsj(int d, int g, int a[])
{ int i,j;
    if (d>=g) return;
    if (d==g-1)
    { if (a[d]>a[g]) S(int,a[d],a[g]);
        return; }
    for (i=d, j=g; i<j; i++, j--)
        if (a[i]>a[j]) S(int,a[i],a[j]);
    fsj(j,g,a);
    for (j--; j>=d; j--)
        for (i=j; a[i]>a[i+1]; i++)
        S(int,a[i],a[i+1]);
}
main()
{ int niz[]={4,0,3,2,8,7,6,1,9,5},i;
    fsj(1,9,niz); printf("%d",b);
    for (i=1; i<5; i++)
        printf(" %d",niz[i]);
}