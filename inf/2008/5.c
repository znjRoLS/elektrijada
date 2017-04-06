//
// Created by rols on 4/6/17.
//

#include <stdio.h>
char f1 (char *d) { return(++(*d));}
char p1 (void *a) { return (f1((char*)a)); }
main()
{
    char d, c='C', *pc=&c;
    int i, j, k, *pi=&i;
    for (i=3; i; d=p1(pc), i--);
    for (j=3; j; k=p1(pi), j--);
    printf("%c\n%d", p1(pc), p1(pi));
}