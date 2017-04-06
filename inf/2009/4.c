//
// Created by rols on 4/6/17.
//

#include <stdio.h>
#define t(a,b) a ## b
int main()
{
    int p[10]={}, q[10]={};
    int i=0, ii=0, iiii=0;
    int sp=0, sq1=0, sq2=0;
    for (i=0; i<5; i++)
        sp += p[i] = t(i,i+1);
    for (ii=0; ii<3; ii++)
        sq1 += q[t(ii,ii+1)] = p[t(ii,ii+1)];
    for (iiii=0; iiii<10; iiii++)
        sq2 += q[iiii];
    printf("%d %d %d", sp, sq1, sq2);
}