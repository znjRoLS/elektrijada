//
// Created by rols on 4/6/17.
//

#include <stdio.h>
main()
{
    unsigned char p1=0125, p2=025, p3;
    p1&=~(0xF*0x10); p2|=p1/4;
    printf("%o", p3=~(~p1^~p2));
}