//
// Created by rols on 4/6/17.
//

#include <stdio.h>
#define KV(x) (x)*(x)
int i;
int cappy(int k)
{
    int s=0;
    static int ctrl[10], h; h=k==1;
    if (!h && k<10 && !ctrl[k] || k>9)
    {
        ctrl[k]=1;
        while (k) {s+=KV(k%10); k/=10;}
        cappy(s);
    }
    for (s=0; s<10; s++) ctrl[s]=0;
    return (h);
}
int main()
{
    for (i=1; i<=10; i++)
        if (cappy(i)) printf("%d ", i);
}