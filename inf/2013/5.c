//
// Created by rols on 4/6/17.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct N
{ int d,r,c,s; struct N *p[4]; } NOD;
typedef struct L { NOD *top; int c,s; } LAT;
NOD nN(int x, int s)
{
    int i; NOD n; n.d=0; n.r=x; n.c=0; n.s=s;
    for (i=0; i<4; n.p[i++]=0);
    return (n);
}
void uN(NOD *n, int x) { n->d=x; n->c++; }
NOD *fN(NOD *n, int x)
{
    NOD *pn=0; int i;
    if (x<n->r || n->r+n->s<x) pn=0;
    else if (!n->p[0]) pn=n;
    else
        for (i=0; !pn && i<4; i++)
            pn=fN(n->p[i],x);
    return (pn);
}
void sN(NOD *n)
{
    NOD *pn; int i, x;
    for (i=0; i<4; i++)
    {
        x=i*(n->s)/2;
        n->p[i] = (NOD *) malloc(sizeof(NOD));
        *(n->p[i]) = nN(n->r+x,(n->s)/2);
    }
    pn=fN(n,n->d); n->c--; uN(pn,n->d);
}
void tN(NOD *n, int top)
{
    if (!n->p[0] && n->c>0)
        printf("%d\n", n->d);
    else if (n->p[0])
    {
        int i, x=(top&1)?-1:1, t=top++;
        for(i=0; i<4; i++,t+=x) tN(n->p[t&3],top);
    }
}
void gL(LAT *n, int x)
{
    if (!n->top)
    {
        n->top = (NOD *) malloc(sizeof(NOD));
        *(n->top) = nN(0,n->s);
        uN(n->top,x); n->c++;
    }
    else
    {
        NOD *pn=fN(n->top,x);
        while (pn->c) { sN(pn); pn=fN(pn,x); }
        uN(pn,x); n->c++;
    }
}
void tL(LAT *n, int top) { tN(n->top,++top); }
int main()
{
    int i, x[] = {1,12,11,6,10,5,14,9};
    LAT ll = {0,0,16};
    for (i=0; i<5; i++) gL(&ll,x[i]);
    tL(&ll,0);
    return (0);
}