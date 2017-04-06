//
// Created by rols on 4/6/17.
//

#include <stdio.h>
#define N 5
int ops[N],s[N],ae[N],be[N];
void next (int n, int lim, int *opt,
           int sa, int sb, int i)
{
    auto int j;
    if (i<n) {
        if (sb-be[i]>*opt)
            next(n,lim,opt,sa,sb-be[i],i+1);
        if (sa+ae[i]<lim) {
            s[i]=1;
            next(n,lim,opt,sa+ae[i],sb,i+1);
            s[i]=0;
        }
    }
    else if (sb>*opt)
        for(*opt=sb,j=0; j<n; ops[j]=s[j],j++);
}
void najsel(int n, int lim, int *opt)
{
    int i,j,k,sb,sa;
    for (i=sb=0; i<n; sb+=be[i], i++);
    sa=*opt=0;
    next(n,lim,opt,sa,sb,0);
}
main() {
    int opt,i;
    for (i=0; i<N; i++) ae[i]=N-(be[i]=i);
    najsel(N,N,&opt); printf("%d ",opt);
    najsel(N,2*N,&opt);printf("%d",opt);
}