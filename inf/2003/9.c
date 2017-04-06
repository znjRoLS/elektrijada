//
// Created by rols on 4/6/17.
//

#include <stdio.h>
main()
{ unsigned int p1=0125252, p2=0052525;
    p1&=~(0xF<<8); p2|=p1>>8;
    printf("%o",~(~p1^~p2));
}