//
// Created by rols on 4/6/17.
//

#include <stdio.h>
#define T1(x,y) { x+=y; y=x-y; x-=y; }
#define T2(x) (x&1 ? '*' : ' ')
#define T3(x) ((x>>1)&1 ? '*':' ')
char p[]={0167,044,0135,0155,056,0153,
          0173,045,0177,0157};
void ps(int b, int r)
{
    int c;
    c=p[b]>> (r%2 ? r/2*3:3+(r-3)*4/r);
    if (r%2) printf(" %c ", T2(c));
    else printf("%c %c", T2(c),T3(c));
    printf(" ");
}
void f()
{
    int i,j,r,k,uc,ruc,c[2]={8};
    char a,b;
    for (i=0; i<10; i++)
    { for (j=i+1,r=i,ruc=0; j<10; j++)
        { for (a=p[r],b=p[j],uc=0,k=7;k;k--)
            { uc+=(a&1)-(b&1); a>>=1; b>>=1; }
            if (uc<ruc) { ruc=uc; r=j; }
        }
        if (r-i) T1(p[i],p[r])
    }
}
main()
{
    int r;
    for (f(), r=1; r<=3; r++)
    { ps(0,r); printf("\n"); }
}