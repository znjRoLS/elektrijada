//
// Created by rols on 4/6/17.
//

#include <stdio.h>
#include <stdlib.h>
#define MR 5
main()
{ char **c;
    int i, j, k, m;
    c = calloc(MR, sizeof(char *));
    for (i=0; i<MR; i++)
    { *(c+i)=calloc(2*MR,sizeof(char));
        for (j=0; j<MR-i-1; j++)
            *(*(c+i)+j)=' ';
        for (k=1; k<=i+1; k++)
            *(*(c+i)+j++)=(i*10+k)%10+'0';
        for (m=k-2; m; m--)
            *(*(c+i)+j++)=(i*10+m)%10+'0'; }
    for ( ; i ; i-- )
    { for (j=0; j<5+i; j++)
            printf("%c", *(*(c+i-1)+j));
        printf("\n"); }
}