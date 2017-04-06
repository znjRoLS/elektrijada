//
// Created by rols on 4/6/17.
//

#include<stdio.h>
int main()
{
    int i, j, c, g[8]={0};
    for (i=0; i<15; i++)
    {
        for (j=0; g[j]; j++) g[j]=0; g[j]=1;
        if (i%4==3)
        {
            for (j=i/4+1; j>=0; j--)
            {
                c = g[j]&&!g[j+1]||!g[j]&&g[j+1];
                printf("%d", c);
            }
            printf("\n");
        }
    }
    return (0);
}