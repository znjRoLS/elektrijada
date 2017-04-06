//
// Created by rols on 4/6/17.
//

#include <stdio.h>
main()
{
    int k=0;
    struct enkoder
    {
        char fi:4;
        char d:1;
        unsigned int k;
    } t = { 0, 127 , 0};

    for ( t.d=--t.fi; t.fi; t.fi+=t.d, t.k++ );
    printf("%d\n",t.k);
    for ( t.d=--t.fi; t.fi; t.fi-=t.d, t.k++ );
    printf("%d",t.k);
}