//
// Created by rols on 4/6/17.
//

#include <stdio.h>
main()
{ struct tacka
    {int x,y,smjer:3;
        unsigned int brzina:4;
        short int boja;} a;
    a.x=0x100; a.y=0x200; a.smjer=7; a.brzina=20; a.boja=0x500;
    printf("%d %d %d",a.brzina,a.smjer,a.smjer+a.brzina);
}