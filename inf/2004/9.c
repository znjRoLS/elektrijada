//
// Created by rols on 4/6/17.
//

#include <stdio.h>
struct nm { int bc; char c[10];};
void SHR (int s, int n, struct nm *c)
{
    int i=0,j,k;
    for ( ; i<n; i++)
        if (s)
        { j=c->bc-1;
            for (k=0; j>=0; j--)
            { k=k*10+c->c[j];
                c->c[j]=k/2;
                k%=2;}
            if ((c->bc>1)&&(!c->c[c->bc-1]))
                (c->bc)--;
            if ((c->bc==1) && (!c->c[0]))
                break; }
        else
        { for (j=0, k=0; j<c->bc; j++)
            { k+=2*c->c[j];
                c->c[j]=k%10;
                k/=10;}
            if (k) { c->c[j]=k; c->bc++; }}
}

void S (c1, c2, c3)
        struct nm *c1, *c2, *c3;
{
    int i=0, k=0, m;
    m=(c1->bc<c2->bc) ? c1->bc : c2->bc;
    for ( ; i<m; i++)
    { k+=c1->c[i]+c2->c[i];
        c3->c[i]=k%10;
        k/=10;}
    if (c1->bc > c2->bc)
        for ( ; i<c1->bc; i++)
        { k+=c1->c[i];
            c3->c[i]=k%10;
            k/=10; }
    else
        for ( ; i<c2->bc; i++)
        { k+=c2->c[i];
            c3->c[i]=k%10;
            k/=10; }
    if (k) c3->c[i++]=k; c3->bc=i;
}
main()
{ int i;
    struct nm b1={2,{0,1}},b2={3,{0,0,1}};
    struct nm r={1,{0}};
    while ((b1.bc>1) || b1.c[0])
    { if (b1.c[0] % 2) S(&b2,&r,&r);
        SHR(1,1,&b1); SHR(0,1,&b2);}
    for (i=r.bc; i>0; i--)
        printf("%d", r.c[i-1]);
}