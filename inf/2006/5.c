//
// Created by rols on 4/6/17.
//

#include <stdio.h>
int m,k=4;
union unija { double d; float f;
    unsigned char c[8];} u;
int c01(unsigned char d) {return (d&1);}
void b01(unsigned char c)
{ static int k=8*sizeof(unsigned char);
    if (k-->0) { m+=c01(c); b01(c>>=1);}
    k=8*sizeof(unsigned char);
}
int a01(float f)
{ union unija u; u.f=f;
    static int k=sizeof(float);
    while (--k>=0) b01(u.c[k]);
    return (m);
}
main()
{ union unija u; u.d=2006;
    printf("%d", a01(u.d));
}