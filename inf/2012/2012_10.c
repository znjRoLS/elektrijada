
#include <stdio.h>
#include <stdlib.h>

typedef struct ln{char c; struct ln *nx;} LN;

LN *lh, *lv;

void la(LN **q, int d)
{
    LN *t=*q; int x=0;
    if (*q==NULL)
    t=*q=(LN *)malloc(sizeof(LN));
    else
    {
        for ( ; t->nx ; t=t->nx)
        if (x=t->c==d) break;
        if (!x) t=t->nx=(LN *)malloc(sizeof(LN));
    }
    t->c=d; t->nx=NULL;
}

void lp()
{
    for (lv=lh; lv; lv=lv->nx) putchar(lv->c);
}

void lss()
{
    LN *a=lh,*b=NULL,*c=lh,*d=NULL,*t=NULL;
    while(a->nx)
    {
        d=b=a->nx;
        while (b)
        {
            if (a->c>b->c)
            {
                if (a->nx==b)
                {
                    if (a==lh)
                    {
                        a->nx=b->nx; b->nx=a; t=a; a=b;
                        b=t; lh=c=a; d=b; b=b->nx;
                    } else {
                        a->nx=b->nx; b->nx=a; c->nx=b;
                        t=a; a=b; b=t; d=b; b=b->nx;
                    }
                } else {
                    if (a==lh)
                    {
                        t=b->nx; b->nx=a->nx; a->nx=t;
                        d->nx=a; t=a; a=b; b=t; d=b;
                        b=b->nx; lh=a;
                    } else {
                        t=b->nx; b->nx=a->nx; a->nx=t;
                        c->nx=b; d->nx=a;
                        t=a; a=b; b=t; d=b; b=b->nx;
                    }
                }
            } else { d=b; b=b->nx; }
        }
        c=a; a=a->nx;
    }
}

void e2012_10()
{
    LN *nn=NULL; int i;
    char txt[]="INFORMATICS";
    for (i=0; txt[i]; i++) la(&nn, i[txt]);
    lh=nn; lp(); putchar('\n'); lss(); lp();
}
