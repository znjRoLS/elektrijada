//
// Created by rols on 4/6/17.
//

#include <stdio.h>
#include <math.h>
void frs(char *a)
{
    char ar[10], af[10];
    char top, p, q, exp, k, i, y, j, n;
    struct { char info, next; } node[100];
    for (n=i=0; a[i]; ++n,++i)
    {
        node[i].info=a[i];
        node[i].next=i+1;
    }
    node[--n].next=-1;
    top=0;
    for (k=1; k<=2; k++)
    {
        for (i=0; i<10; i++)
            af[i]=ar[i]=-1;
        while (top!=-1)
        {
            p=top;
            top=node[top].next;
            y=node[p].info;
            for (exp=j=1; j<k; exp*=10,j++);
            j = (y/exp)%10;
            q = ar[j];
            if(q == -1)
                af[j] = p;
            else
                node[q].next = p;
            ar[j] = p;
        }
        for (j=0; j<10 && af[j]==-1; j++);
        top = af[j];
        for ( ; j<=9; j=i)
        {
            for (i=j+1; i<10&&af[i]==-1; i++);
            if(i<=9)
            {
                p = i;
                node[ar[j]].next = af[i];
            }
        }
        node[ar[p]].next = -1;
    }
    for (j=0; j<=n; j++)
    {
        do
        {
            k = node[top].info;
            top = node[top].next;
        }
        while (k == node[top].info && top!=-1);
        printf("%c", k);
    }
}
int main()
{
    char *a = "SIOFOK";
    frs(a);
    return (0);
}