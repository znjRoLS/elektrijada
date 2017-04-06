
#include <stdio.h>

void main()
{
    int i, c, k, n;
    char *s="39";
    for (i=c=0, k=1; s[i]; k=1, c=0, i++)
    {
        int x[100] = { 0, 1 };
        while (k)
        {
            c++;
            if (x[k]==s[i]-'0')
            { k--; x[k]++; }
            else
            { k++; x[k]=x[k-1]+1; }
        }
        printf("%d\n", c);
    }
}
