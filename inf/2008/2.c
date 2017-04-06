//
// Created by rols on 4/6/17.
//

#include <stdio.h>
#include <string.h>
#define MAX 10
void rpi(char *u, int *pi)
{
    int i=1,j=0,n=strlen(u);
    while (i<n)
        if (u[j]==u[i]) pi[i++]=++j;
        else if (j>0) j=pi[j-1]; else pi[i++]=0;
}
int f(char *u, char *t)
{
    int i=0,j=0,m,n, pi[MAX];
    n=strlen(u); m=strlen(t); rpi(t,pi);
    while (i<n)
        if (u[j]==t[i])
        { if (j==m-1) return (i-m+1); i++; j++; }
        else if (j>0) j=pi[j-1]; else i++;
    return (-1);
}
main()
{
    char *u="ELEKTRIJADA", t[MAX]="";
    int i=0, s=0, n=strlen(u);
    for (; i<n; t[0]=*(u+i), s+=f(u,t), i++);
    printf("%d", s);
}