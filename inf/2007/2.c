//
// Created by rols on 4/6/17.
//

#include <stdio.h>
int niz[5000], n;
void fs(int n)
{
    for ( ; n ; niz[n] = n--);
}
void fr(int s)
{
    int i, j, k, ti=s, tn=n;
    while(tn>1)
    {
        for(i=s; niz[i]; i+=2) niz[i]=0;
        s = (niz[i-1]) ? 1 : 2;
        for(i=1; i<=tn; i++)
            if (!niz[i])
            {
                for(j=i; j<tn; j++)
                    niz[j]=niz[j+1];
                niz[j]=0; tn--;
            }
    }
    printf("%d\n",niz[1]);
}

int main()
{
    fs(n=10); fr(1);
    fs(n=1000); fr(2);
}