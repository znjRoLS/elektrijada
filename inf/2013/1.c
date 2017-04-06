//
// Created by rols on 4/6/17.
//

#include <stdio.h>
#define S(x) sizeof(x)
typedef unsigned char UC;
UC fltfr(float fl)
{
    UC fr=(UC)fl, i=0;
    for (fl-=(UC)fl; i<S(fr)*4; i++, fl-=(UC)fl)
        fr = fr << 1 | (UC)(fl*=2);
    return (fr);
}
float frtfl(UC fr)
{
    float fl = fr >> S(fr)*4;
    UC i, m=1;
    for ( i=1; i<S(fr)*4; i++, m<<=1, m|=1);
    fr &= m;
    fl += (float)fr / (1<<S(fr)*4);
    return (fl);
}
int main()
{
    UC i=2, j=1, sfr=0;
    float sfl=0;
    for ( ; j<11; j+=9)
    {
        for ( ; i<10*j; i*=2)
        {
            sfl += frtfl(i);
            sfr += fltfr(frtfl(i));
        }
        printf("%d %5.3f\n", sfr, sfl);
    }
    return (0);
}