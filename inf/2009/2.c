//
// Created by rols on 4/6/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX(a,b) ((a)>(b))?(a):(b)
#define P(x,y) *(*(td+i+x)+j+y)
int fs(char *s1, char *s2)
{
    int i, j, m=strlen(s1)+1, n=strlen(s2)+1;
    int **td=(int**)calloc(m,sizeof(int*));
    for (i=0; i<m; i++)
        *(td+i)=(int*)calloc(n,sizeof(int));
    for (i=0; i<m; i++)
        for (j=0; j<n; j++) P(0,0)=0;
    for (i=1; i<m; i++)
        for (j=1; j<n; j++)
            if (*(s1+i-1)==*(s2+j-1))
                P(0,0) = 1 + P(-1,-1);
            else
                P(0,0) = MAX(P(-1,0),P(0,-1));
    return (P(-1,-1));
}
int main()
{
    printf("%d\n",fs("BUDVA","BEOGRAD"));
    printf("%d",fs("ELEKTRIJADA","BEOGRAD"));
}