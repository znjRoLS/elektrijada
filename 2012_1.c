
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *fs(char *st, char *sp)
{
    int i, j;
    char *res=NULL, *t=NULL;
    if (!sp[0]) return (st);
    t = (char*) malloc(strlen(sp)+1);
    t[0] = -1;
    for (i=0; sp[i]; i++)
    {
        t[i+1] = t[i] + 1;
        while (t[i+1]>0 && sp[i]!=sp[t[i+1]-1])
        t[i+1] = t[t[i+1]-1] + 1;
    }
    for (i=j=0; st[i]; )
    {
        if (j<0 || st[i]==sp[j])
        {
            ++i, ++j;
            if (!sp[j])
            { res = st+i-j; break; }
        }
        else j=t[j];
    }
    free(t);
    return (res);
}

void e2012_1()
{
    int i;
    static char *s="ELEKTRIJADA", *res;
    for (i=0; s[i]; i++)
    res=fs(s,s+i);
    printf("%s", res);
}
