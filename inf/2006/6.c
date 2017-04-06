//
// Created by rols on 4/6/17.
//

// Suppose that the next figure shows screen after
// the function call init():
// 40 0 0 10 30 40 0 11 30 40 0 14 30 40 0 403010

#include <stdio.h>
unsigned char c='0', d=0100;
unsigned char *pc=&c, *pd=&d,
        **ppc=&pc, **ppd=&pd;
void init()
{ int i;
    for (i=1;i<020;printf("%x ",*(pc+i++)));
    printf("%x\n",pc);
}
void print()
{ printf("%x\n%x\n%x",&ppd,**ppc,ppc); }
main() { init(); print(); }