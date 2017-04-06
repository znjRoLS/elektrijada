//
// Created by rols on 4/6/17.
//

#include <stdio.h>
main()
{
    unsigned char p1=0125, p2=025, p3;
    p1&=~(0xF*0x10);
    p2|=p1/4; p3=~(~p1|~p2);
    printf("%o %o %o",p1,(p1^p2)>>5,p3);
}