//
// Created by rols on 4/6/17.
//

#include <stdio.h>
int main()
{
    const char s1[] = "Informatics";
    const char* s2 = "Elektrijada";
    printf("%u", sizeof(s1)+sizeof(s2));
    return (0);
}