//
// Created by rols on 4/6/17.
//

#include <stdio.h>
#define pchar(char) *(char)
typedef char* pchar;
char b, c, n=010;
void g(pchar p)
{
    int b=0;
    while (pchar(p+b))
        printf("%0X ", pchar(p+b++));
    printf("\n");
}
void f(pchar p)
{
    while (n++<030)
        if ((n&0x3)==((n&0x30)>>4))
        {
            pchar(p+b++)=n;
            g(p);
        }
}
int main()
{
    static char a[5];
    f(a);
    return (0);
}