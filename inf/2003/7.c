//
// Created by rols on 4/6/17.
//

#include <stdio.h>
void cc(char *k,char *p)
{ char *alfabet="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *alfa=alfabet;
    for (; *k; k++)
    {
        for (; *alfabet; )
            if (*alfabet++==*k) {*alfabet=' ';*p++=*k;}
        alfabet=alfa;
    }
    *p='\0';
}
main()
{ char *k, *p="BUDVA";
    cc(p,k);
    printf("%s",k);
}