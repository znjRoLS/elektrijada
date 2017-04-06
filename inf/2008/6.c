//
// Created by rols on 4/6/17.
//

#include <stdio.h>
enum Roman {I,II,III,V=5,IV=4,VI,VII=VI+1};
main()
{
    int rom[3][3]={{I,II,III},{IV,V,VI},{VII}};
    int i,j,s=0,t=0;
    for(i=0; i<2; i++)
        for(j=0; j<3; s+=rom[i][j],j++);
    for(i=0; i<2; i++)
        for(j=0; j<3; t+=*rom[i,j],j++);
    printf("%d\n%d", s, t);
}