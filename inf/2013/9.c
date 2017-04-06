//
// Created by rols on 4/6/17.
//

#include <stdio.h>
int main()
{
    signed char i=1, j=0;
    for ( ; i && i<=100; i*=10, j++);
    printf("%d\n%d", i, j);
    for (i=100 ; j++<=10; )
        printf("\n%d", i+=i);
    return (0);
}