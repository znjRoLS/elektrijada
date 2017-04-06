//
// Created by rols on 4/6/17.
//

#include <stdio.h>
#include <string.h>
#define MAX 10
main()
{ int mat[MAX][MAX],b,i,j,k,m,max,n;
    m=strlen("Elektrijada");
    n=strlen("2003");
    for (i=1,b=1; i<2*m-i; i++)
    { j=(i-m+1>1)?i-m+1:1;
        max=(i<m)?i:m;
        for ( ;j<=max; ) mat[i-j+1][j++]=b++;
    }
    for (i=1; i<n; i++)
    { for (j=i,k=1; j<n; k++,j++) printf("%d",mat[i][k]);
        printf("\n");
    }
}