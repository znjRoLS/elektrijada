//
// Created by rols on 4/6/17.
//

#include <stdio.h>
#include <stdlib.h>
#define M 6
main()
{ int **c;
    int i, j, k, m;
    c = (int **) calloc(M,sizeof(int *));
    for (i=0; i<M; i++)
    { *(c+i)=(int *) calloc(2*M,sizeof(int));
        for (j=0; j<M-i-1; j++)
            *(*(c+i)+j)=0;
        for (k=1; k<=i+1; k++)
            *(*(c+i)+j++)=(i*10+k)%10;
        for (m=k-2; m; m--)
            *(*(c+i)+j++)=(i*10+m)%10; }
    for (i=1 ; i<4 ; i++ )
    {
        for (j=3; j<5+i; j++)
        {
            k=*(*(c+i-1)+j);
            printf("%c", k ? k+'0' : ' ');
        }
        printf("\n"); }
}