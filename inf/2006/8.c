//
// Created by rols on 4/6/17.
//

#include <stdio.h>
void mov(int *s, int *t, int *p, int n)
{
    if (n==0) return;
    mov(s,p,t,n-1); (*s)++;
    (*t)=((*t)<=(*p))?(*t)++:(*t)--;
    (*p)=((*p)>=(*t))?(*p)++:(*p)--;
    mov(p,t,s,n-1); (*s)++;
}
main()
{
    int L=0,C=010,D=0;
    mov(&L,&C,&D,3);
    printf("%d\n%d\n%d",L,C,D);
}