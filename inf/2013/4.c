//
// Created by rols on 4/6/17.
//

#include <stdio.h>
typedef struct { int u,v,w; } E;
E es[1024];
int n, e, d[32];
void fbf(int s)
{
    int i, j;
    for (i=0; i<n-1; ++i)
        for (j=0; j<e; ++j)
            if (d[es[j].u]+es[j].w>d[es[j].v])
                d[es[j].v]=d[es[j].u]+es[j].w;
}
int main(int argc, char *argv[])
{
    int i, j, w;
    FILE *fin = fopen("data4.txt", "r");
    fscanf(fin, "%d", &n);
    for (i=0; i<n; ++i)
        for (j=0; j<n; ++j)
        {
            fscanf(fin, "%d", &w);
            if (w)
            {
                es[e].u=i; es[e].v=j; es[e].w=w; ++e;
            }
        }
    fclose(fin);
    fbf(0);
    for (i=0; i<n; ++i) printf("%d\n", d[i]);
    return (0);
}