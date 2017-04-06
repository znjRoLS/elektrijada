//
// Created by rols on 4/6/17.
//

#include <stdio.h>
#include <stdlib.h>
#define QN (NODE*)malloc(sizeof(NODE))
typedef struct node
{ char c; int i; struct node *n,*u; } NODE;
void add(NODE **p, char *s)
{
    NODE *q;
    if (*s)
        if (*p==NULL)
            *p=QN,(*p)->c=*s,(*p)->i=1,(*p)->u=NULL,
                    (*p)->n=QN,(*p)->n->n=*p,q=*p=(*p)->n,
                               (*p)->c=*s,(*p)->i=1,(*p)->u=NULL;
        else
        {
            q=(*p)->n->n;
            while (q->c!=*s && q!=*p) q=q->n;
            if (q->c!=*s)
                q=QN,q->c=*s,q->i=1,q->u=NULL,
                        q->n=(*p)->n,*p=(*p)->n=q,q->n->i++;
            else q->i++;
        }
    for(s++;*s;s++)
    {
        if (q->u) q=q->u;
        else q=q->u=QN,q->u=NULL;
        q->c=*s;q->i=1;
        if (q->u) q->u->i=0;
    }
}
int main()
{
    NODE *f=NULL, *q;
    char w[100];
    int i=2;
    FILE *fp=fopen("file9.txt", "r");
    while (fscanf(fp,"%s",w)!=EOF) add(&f,w);
    while (f->u) f=f->n;
    printf("%d", f->i);
    while(i--)
    {
        q=f=f->n; printf("\n%d ", q->i);
        while (q)
        {
            if (!q->i) break;
            printf("%c", q->c); q=q->u;
        }
    }
    return 0;
}