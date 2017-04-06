//
// Created by rols on 4/6/17.
//

#include <stdio.h>
union unija { float f; double d; } u;
main()
{
    extern unija u;
    u.d=1;
    printf("%4.2f %4.2f", u.d, u.f);
}