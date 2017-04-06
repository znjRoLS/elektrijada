//
// Created by rols on 4/6/17.
//

#include <stdio.h>
int f[10];
char s[]="INFO", t[]="ABCD";
int fn(int n)
{ return (n ? n*fn(n-1) : 1); }
void c(char *s, char *d)
{ while (*d++=*s++); }
int fl(char *s)
{ return (*s ? 1+fl(s+1) : 0); }
void ft(char *s)
{ while (*s) { *s=*(s+1); s++; }}
int main()
{
    int i, j, ti, tj, n=fl(s);
    int p[5]={12,23,24};
    for (i=0; p[i]; i++)
    {
        for (ti=p[i], tj=fn(j=n); j; tj/=j--)
        {
            f[j]=ti/tj; ti%=tj;
        }
        for (c(s,t), j=n-1; j>=0; ft(&t[f[j--]]))
            printf("%c", t[f[j]]);
        printf("\n");
    }
    return (0);
}