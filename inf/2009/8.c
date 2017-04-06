//
// Created by rols on 4/6/17.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct nd
{int v; struct nd *r,*l;} my;
my *kor=NULL;
void add(int v)
{
    my *p, *c, *t;
    t=(my*)malloc(sizeof(my));
    t->v=v; t->r=NULL; t->l=NULL;
    if(kor==NULL) { kor=t; return; }
    p=NULL; c=kor;
    while(c) { p=c; c=(v)?c->l:c->r; }
    if(v<p->v) p->l=t; else p->r=t;
}
void traversal(my *kor)
{
    my *q[100] = {(my*)0};
    int s=0, qp=0;
    while(kor)
    {
        printf("%d ", kor->v);
        if(kor->l) { q[s++]=kor->l; }
        if(kor->r) { q[s++]=kor->r; }
        kor = q[qp++];
    }
}
int main()
{
    int nds[10]={5,1,20,23,13}, i=0;
    while (nds[i]) add(nds[i++]);
    traversal(kor);
}