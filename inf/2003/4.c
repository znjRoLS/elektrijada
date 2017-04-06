//
// Created by rols on 4/6/17.
//

#include "stdio.h"
main()
{ int p1[10]={1,2,3,4,5,6};
    int p2[10]={1,2,3};
    int r[10]={0};
    int i,j,k;
    int n=8,c1=5,c2=2;
    for (i=c1; i>=c2; i--)
    { r[i-c2]=p1[i]/p2[c2];
        for (j=i; j>=i-c2; j--)
            p1[j]=-r[i-c2]*p2[c2-i+j]+p1[j];
        k=j=0;
        while (j<r[i-c2]) if (r[k++]==0) j++;
        p1[k]=i;
    }
    for (i=0; i<=c1;) printf("%d",p1[i++]);
}