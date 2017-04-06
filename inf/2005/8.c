//
// Created by rols on 4/6/17.
//

#include <stdio.h>
char f1 (char *d)
{ return(--(*d));}
char p1 (void *a)
{ return (f1((char*)a)); }
main()
{
    char c='C', *b=&c;
    int i=8, *k=&i;
    printf("%c %d",p1(b),p1(k));
    i=512; printf(" %d",p1(k));
}