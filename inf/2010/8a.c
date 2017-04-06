//
// Created by rols on 4/6/17.
//

#include <stdio.h>
#define M(a,b) a%:%:b
main()
{
    int a=1, b=2, ab[]={10,20}, c;
    printf( "%d", M(a,b)<:a:> );
    printf( "%d", M(a,b)<:a:>?a:b );
    printf( "%d", c=M(a,b)<:a:>?a:b );
}