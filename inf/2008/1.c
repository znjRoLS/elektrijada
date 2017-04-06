//
// Created by rols on 4/6/17.
//

#include <stdio.h>
int data[1000], n;
void f(int n) { for ( ; n ; data[n] = n--); }
int g(int s)
{
    int i, j, k, b=n;
    while(b>1) {
        for(i=s; data[i]; data[i]=0, i+=2);
        s = (data[i-1]) ? 1 : 2;
        for(i=1; i<=b; i++)
            if (!data[i]) {
                for(j=i; j<b; j++) data[j]=data[j+1];
                data[j]=0; b--; }
    }
    return (data[1]);
}

int main()
{
    f(n=10); printf("%d\n", g(2));
    f(n=100); printf("%d\n", g(1));
}