//
// Created by rols on 4/6/17.
//

#include <stdio.h>
#define T(x,y) { x+=y; y=x-y; x-=y; }
char p[]={0167, 044,0135,0155,056,
          0153,0173, 045,0177,0157};
void ps(int b, int r)
{
    int c;
    c=p[b]>> (r%2 ? r/2*3:3+(r-3)*4/r);
    if (r%2)
        printf(" %c ", c&1 ? '-' : ' ');
    else
        printf("%c %c", c&1 ? '|':' ',
               (c>>1)&1 ? '|':' ');
    printf(" ");
}
void f()
{
    int i,j,r,k,uc,ruc,c[2]={3};
    char a,b;
    for (i=0; i<10; i++)
    {
        for (j=i+1,r=i,ruc=0; j<10; j++)
        {
            for (a=p[r],b=p[j],uc=0,k=8;k;k--)
            {
                uc+=(a&1)==(b&1)?0:c[a&1]+c[b&1];
                a>>=1; b>>=1;
            }
            if (uc>ruc) { ruc=uc; r=j; }
        }
        if (r-i) T(p[i],p[r])
    }
}
main()
{
    int r;
    for (f(), r=1; r<=5; ps(0,r),r++)
        printf("\n");
}