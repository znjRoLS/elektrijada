//
// Created by rols on 4/6/17.
//

#include <stdio.h>
#define INF 1000
struct E { int u,v,w; } es[100];
int e, n, d[10];
void fbf(int s)
{
    int i, j;
    for (i=0; i<n; ++i) d[i]=INF; d[s]=0;
    for (i=0; i<n-1; ++i)
        for (j=0; j<e; ++j)
            if (d[es[j].u]+es[j].w<d[es[j].v])
                d[es[j].v]=d[es[j].u]+es[j].w;
}
int main()
{
    int i, j, w;
    FILE *fin=fopen("d3.txt", "r");
    fscanf(fin, "%d", &n);
    for (e=i=0; i<n; ++i)
        for (j=0; j<n; ++j)
        {
            fscanf(fin,"%d", &w);
            if (w!=0)
            { es[e].u=i; es[e].v=j; es[e].w=w; ++e;}
        }
    fclose(fin);
    fbf(4);
    for (i=0; i<n; ++i) printf("%d ",d[i]);
}