//
// Created by rols on 4/6/17.
//

#include <stdio.h>
union DATA { short data;
    int d:5;
    unsigned short m:4; } x;
main()
{ x.data = 51;
    printf("%d%d", sizeof(x),x.d>>x.m );
}