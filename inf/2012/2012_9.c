
#include <stdio.h>
#include <stdlib.h>

void **md2(int nu, int nd, int *pd);

void md3(char ***tip,int nu,int nd,int *pd);

int gu,te;

void *mdalloc(int nd, int w, int *pd)
{
    int i;
    char ***tip;
    if (pd == NULL) return (NULL);
    gu = w;
    tip = (char ***)md2(pd[0], nd, &pd[1]);
    if (nd>1 && tip)
    md3(tip, pd[0], nd-1, &pd[1]);
    return (tip);
}

void mdfree(void *tip, int nd)
{
    if (nd!=1)
    mdfree(((void **)tip)[0], nd-1);
    free(tip);
}

void **md2(int nu, int nd, int *pd)
{
    char **tip;
    if (nd==1)
    tip=(char**) malloc(nu*gu);
    else
    {
        tip=(char**) malloc(nu*sizeof(char *));
        if (tip)
        {
            tip[0]=(char *)md2(nu*pd[0],nd-1,&pd[1]);
            if (tip[0]==NULL)
            {
                free(tip); tip = NULL;
            }
        }
    }
    return ((void **)tip);
}

void md3(char ***tip, int nu, int nd, int *pd)
{
    int i;
    for( i=1; i<nu; i++, te++)
    {
        if (nd==1)
        tip[i] = (char **)((char *)tip[0]+i*pd[0]*gu);
        else
        tip[i]=tip[0]+i*pd[0];
    }
    if (nd>1)
    md3((char ***)tip[0],nu*pd[0],nd-1,&pd[1]);
}

void e2012_9()
{
    int a[]={2,3,4};
    int ***ma;
    ma = (int***) mdalloc(3,4,a);
    printf("%d\n%d", sizeof(ma), te);
    mdfree(ma,3);
}
