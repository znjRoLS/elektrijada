//
// Created by rols on 4/6/17.
//

#include <stdio.h>
#define V(a,b,c) (((a)[(b)])=(c))
int main()
{
    int n=10, k=1, t, i;
    int v1[10]={2}, v2[10]={1}, v[10]={0};
    for (k=1; k<n; k++)
    {
        if (k<3) V(v,0,V(v,0,k));
        for (i=0; i<10; i++) V(v,i,V(v,i,0));
        for (i=t=0; i<10; V(v,i++,t%10),t/=10)
            t+=V(v1,i,v1[i])+V(v2,i,v2[i]);
        for (i=0; i<10; i++)
        {
            V(v2,i,V(v2,i,V(v1,i,V(v1,i,v1[i]))));
            V(v1,i,V(v1,i,V(v,i,V(v,i,v[i]))));
        }
        if (!(k%4))
        {
            for (i=9; i>0&&!V(v,i,v[i]); i--);
            while (i>=0) printf("%d", v[i--]);
            printf("\n");
        }
    }
    return (0);
}