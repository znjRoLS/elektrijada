//
// Created by rols on 4/6/17.
//

#include <stdio.h>
int i, j;
int sd(char s[])
{
    int i=0, tc=0;
    while (s[i++]) tc++; return (tc);
}
void sp(char *s)
{
    char c=*s; static int i;
    if (i<sd(s))
    {
        *s=*(s+sd(s)-1); *(s+sd(s)-1)=c;
        i++; sp(s+1);
    }
    i=0;
}
main()
{
    char sp1[10]={'O','H','R','I','D'};
    char sp2[5]={'2','0','0','6'};
    char spuk[15];
    sp(sp2); sp(sp1);
    for (; i<=sd(sp2); spuk[i]=sp2[i], i++);
    for (; j<=sd(sp1); spuk[i++]=sp1[j++]);
    printf("%s", spuk);
}