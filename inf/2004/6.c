//
// Created by rols on 4/6/17.
//

#include <stdio.h>
char fp1 (char d) { return(--d);}
char fp2 (char d) { return(++d);}
char ff (char (*p)(), char *a)
{ return ((*p)(a)); }
main()
{
    char (*p[2])()={fp1,fp2}, *b='C';
    printf("%c",ff(p[1],b));
    printf("%c",ff(p[0],b));
}