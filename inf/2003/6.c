//
// Created by rols on 4/6/17.
//

#include <stdio.h>
#include <string.h>
void funkcija(int x, int b)
{ if (x) funkcija(x++/b++,b);
    printf("%d",x%b);
}
main()
{ int m,n;
    m=strlen("Elektrijada 2003");
    n=strlen("Budva");
    funkcija(m,n);
}