//
// Created by rols on 4/6/17.
//

#include <stdio.h>
int k=4;
int c01(char d) {return (d&1);}
int b01(char d)
{
    static int k=8, m;
    if (k-->0) {m+=c01(d); b01(d>>=1);}
    return (m+k);
}
void a01(char d)
{
    static int r;
    printf("%d ", r+=b01(d));
    if (k-->0) a01(d>>=1);
}
main() { a01(32);}