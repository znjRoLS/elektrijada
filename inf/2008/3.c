//
// Created by rols on 4/6/17.
//

#include <stdio.h>
double f(int i)
{
    double data = 1;
    while(i--) data/=2; return (data);
}
union unija {double d; float f; char c[8];} u;
main()
{
    int i, j, br;
    for (br=0, i=126; i<1022; i++)
        for (u.f=f(i), j=3; j>=0; j--)
            if (u.c[j]) br++; printf("%d", br);
}