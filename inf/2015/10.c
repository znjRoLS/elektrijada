//
// Created by rols on 4/6/17.
//

#include <stdio.h>
#include <stdlib.h>
struct N { char c; int n; struct N **p; };
typedef struct N NODE;
NODE *bt, *f;
NODE *newNode(char c)
{
    NODE *q = (NODE*) malloc(sizeof(NODE));
    q->p=NULL; q->n=1; q->c=c;
    return q;
}
NODE *fa(NODE *q, char s)
{
    if (!q) q=newNode(s);
    else if (q->c==s) q->n++;
    else
    {
        if (!q->p)
            q->p=(NODE**)calloc(2,sizeof(NODE*));
        if (s<q->c) *(q->p)=fa(*(q->p),s);
        else *(q->p+1)=fa(*(q->p+1),s);
    }
    return q;
}
void ft(NODE *q)
{
    if (q)
    {
        NODE **p;
        if (q->p) ft(*(q->p));
        printf("%c:%d\n", q->c,q->n);
        if (q->p) ft(*(q->p+1));
    }
}
NODE *fc(NODE *q, char *s)
{
    if (!q) q=newNode(*s++);
    for(;*s;s++)
        if (!q->p)
        {
            q->p=(NODE**)calloc(2,sizeof(NODE*));
            *(q->p)=newNode(*s);
            if (*(s+1)) fc(*(q->p),s+1);
        }
        else
        {
            int i,n;
            NODE **tmp=q->p;
            for (n=1; *tmp; tmp++, n++);
            tmp = (NODE**)calloc(n+1,sizeof(NODE*));
            for (i=0; i<n; i++)
                *(tmp+i)=*((q->p)+i);
            *(tmp+i-1)=newNode(*s);
            if (*(s+1)) fc(*(q->p),s+1);
            free(q->p);
            q->p=tmp;
        }
    return q;
}
void fx(NODE *q)
{
    NODE **p;
    if (q)
    {
        bt=fa(bt,q->c);
        if (q->p) for(p=q->p;*p;p++) fx(*p);
    }
}
void main() { fx(fc(f,"BECICI")); ft(bt); }