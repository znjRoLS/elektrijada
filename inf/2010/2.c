//
// Created by rols on 4/6/17.
//

#include <stdio.h>
long i=1, s, n=11, ok, nok;
void test(long x)
{
    int a; s=0;
    while (x) { a=x%10; s+=a*a; x/=10; };
    if ((s==1)||(s==4)||(s==i)) return;
    test(s);
}
int main()
{
    for(; i<n; ok+=s==1,nok+=s!=1,i++) test(i);
    printf("%d\n%d", ok, nok);
    return (0);
}