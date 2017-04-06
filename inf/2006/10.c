//
// Created by rols on 4/6/17.
//

#include <stdio.h>
#define MAX 10
int f(int m, int n, int *x, int *y, int *z)
{
    int i,j,k;
    int c[MAX][MAX]={0};
    for (i=1; i<=m; i++)
        for (j=1; j<=n; j++)
            if (x[i-1]==y[j-1])
                c[i][j]=c[i-1][j-1]+1;
            else if (c[i-1][j]>c[i][j-1])
                c[i][j]=c[i-1][j];
            else
                c[i][j]=c[i][j-1];
    for (i=m, j=n, k=c[m][n]; k>0;)
    {
        if (c[i][j]==(c[i-1][j-1]+1))
        { k--; j--; i--; z[k]=x[i]; continue; }
        if (c[i][j]==c[i-1][j])
        { i--; continue; }
        j--;
    }
    return (c[m][n]);
}
main()
{
    int i,k, c[8]={}, b[8]={5}, a[6]={3};
    for (i=1; i<4; b[4-i]+=b[3+i]+=i, i++);
    for (i=1; i<3; a[3-i]+=a[3+i]+=i, i++);
    printf("%d\n", k=f(8,6,b,a,c));
    for (i=0; k>=0; i+=c[k--]);
    printf("%d",i);
}