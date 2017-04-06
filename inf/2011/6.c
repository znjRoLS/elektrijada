//
// Created by rols on 4/6/17.
//

#include <stdio.h>
char s[]="Kopaonik";
char *func() { return s; }
union DATA { unsigned char data;
    int d:5;
    unsigned char m:4; } x;
int main(int argc, char **argv)
{
    printf("%s\n",__func__);
    x.data = 021; printf("%d\n", x.d>>x.m );
    x.data = 077; printf("%d", x.d>>x.m );
    return (0);
}