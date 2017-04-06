//
// Created by rols on 4/6/17.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void my(char** p) { ++p; }
int main()
{
    char* s = (char*)malloc(10);
    strcpy(s, "BUDVA");
    my(&s); my(&s); my(&s);
    printf("%s", s);
    return (0);
}