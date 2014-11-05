
#include <stdio.h>

typedef struct time_1
{
    unsigned int hh:4, mm:6, am:1;
} T1;

typedef struct time_2
{
    unsigned int hh:4, mm:6, :5, am:1;
} T2;

typedef struct time_3
{
    unsigned int hh:4;
    unsigned short int :0;
    unsigned int mm:6, am:1;
} T3;


void e2012_8()
{
    union u_1 { T1 t; int d; } u1; u1.d=0;
    union u_2 { T2 t; int d; } u2; u2.d=0;
    union u_3 { T3 t; int d; } u3; u3.d=0;
    u1.t.hh=11; u1.t.mm=31; u1.t.am=1;
    u2.t.hh=11; u2.t.mm=31; u2.t.am=1;
    u3.t.hh=11; u3.t.mm=31; u3.t.am=1;
    printf("%x\n", u1.d);
    printf("%x\n", u2.d);
    printf("%x", u3.d);
}
