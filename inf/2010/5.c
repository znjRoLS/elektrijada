//
// Created by rols on 4/6/17.
//

#include <stdio.h>
#define M 5
int n = 4;
int d[M][M]={{},{1,2,3,5},{},{10,8,1,13,2}};
int ok(int K)
{
    int i, x, p = 0;
    for (i=0; i<n-1; i++)
    {
        x = d[2][i] + p;
        if (x<K)
            p = x - K - (d[1][i+1]-d[1][i]);
        else
        {
            p = x - K - (d[1][i+1]-d[1][i]);
            if (p<0) p=0;
        }
    }
    return ((d[2][n-1] + p) >= K);
}
int main()
{
    int i, min=0, max=1, mid;
    for (i=0; i<n; i++)
    {
        d[2][i]=d[3][n-i];
        if (d[2][i]>max) max=d[2][i];
    }
    while (min<max)
    {
        mid = (min+max+1)/2;
        if (ok(mid))
            min=mid;
        else
            max=mid-1;
    }
    printf("%d ", min);
    return (0);
}