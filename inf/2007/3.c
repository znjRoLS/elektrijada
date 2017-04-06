//
// Created by rols on 4/6/17.
//

#include <stdio.h>
#define M 0xFF800000
union ufi { float f; int i; } fi;
main()
{
    int i, fii, s;
    for (fi.f=1; fi.f<4; fi.f*=2)
    {
        for (fii=~(fi.i|M); fii&1; fii>>=1, s++);
        for (fii=(fi.i&M); !(fii&1); fii>>=1, s--);
        printf("%d\n", fii);
    }
}