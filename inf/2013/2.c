//
// Created by rols on 4/6/17.
//

#include <stdio.h>
int x;
int *fop(int b[][3])
{
    ++b;
    b[!x][!x] = b[x][x];
    printf("%d\n", b[!x][!x]);
    return ((int*)b);
}
int fos(int *p)
{
    int s=0;
    while (*p++) s+=*p;
    return (s);
}
int main()
{
    int a[3][3] = {{8,7,6},{5,4,3},{2,1,0}};
    printf("%d", fos(fop(a)));
    return (0);
}