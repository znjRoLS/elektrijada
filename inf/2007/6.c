//
// Created by rols on 4/6/17.
//

// Suppose that the next figure shows screen after
// the function call init():
// 40 0 0 10 30 40 0 14 30 40 0 11 30 40 0 403010

#include <stdio.h>
unsigned char c='1', d=0100;
unsigned char *pc=&c, **ppc=&pc;
unsigned char *pd=&d, **ppd=&pd;
void init()
{
    int i;
    for (i=1;i<020;printf("%x ",*(pc+i++)));
    printf("%x\n",pc);
}
void print()
{
    printf("%o\n%o",**ppc, **ppd%0x100);
}
main()
{
    init();
    print();
}