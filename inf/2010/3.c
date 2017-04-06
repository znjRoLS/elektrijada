//
// Created by rols on 4/6/17.
//

#include <stdio.h>
long i=9, ok, nok;
int test(long x)
{
    int a, s=0;
    while (x) { a=x%10; s+=a*a; x/=10; };
    if ((s==1)||(s==4)||(s==i)) return(s);
    return (test(s));
}
int main()
{
    for( ; i>=0; i--)
        test(i) ? ok++ : nok++;
    printf("%ld\n%ld", ok, nok);
    return (0);
}