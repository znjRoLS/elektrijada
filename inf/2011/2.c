//
// Created by rols on 4/6/17.
//

#include <stdio.h>
#define M 5
int bk=3, bv, bb=5, n, i;
int v[M] = {1,2,3,4};
int b[M][M] = {{1},{1,2},{1,2,3},{1,2,3,4}};
void f(int k, int brb)
{
    static int i;
    if (k<bk)
    {
        for (i=0; i<v[k]; i++)
            if (brb>=b[k][i])
                f(k+1,brb-b[k][i]);
    }
    else
    if (brb==0) ++n;
}
int main()
{
    f(bv,bb); printf("%d\n", n);
    f(bv,bb); printf("%d", n);
    return (0);
}