
#include <stdio.h>

long n, m;
void fv(long cd, long bb, long nn)
{
    long ai = cd + bb / nn;
    printf("%d ", ai);
    bb %= nn;
    if (ai>m && n>0) m=ai;
    if (bb>0) { n++; fv(nn/bb, nn%bb, bb); }
}

void e2012_6()
{
    FILE *fin;
    if ((fin=fopen("input.txt","r"))!=NULL)
    {
        char c[100];
        long cd=0, bb=0, nn=1, i=0, rcd=1;
        fscanf(fin, "%s", c);
        for ( ; c[i]; i++)
        if (c[i]=='.') rcd=0;
        else
        if (rcd) cd=cd*10+c[i]-'0';
        else { bb=bb*10+c[i]-'0'; nn*=10; }
        fv(cd, bb, nn);
        printf("\n%d", m);
    }
}
