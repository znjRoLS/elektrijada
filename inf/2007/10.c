//
// Created by rols on 4/6/17.
//

#include <stdio.h>
int fra(char *s)
{
    int i, b=0, k, kor, n;
    for (i=0; s[i]; b+=kor, i++)
        if ((s[i]-'a')%2)
            for( kor=5, k=0; k<(s[i]-'a')/2; k++)
                kor*=10;
        else
        {
            for( kor=1, k=0; k<(s[i]-'a')/2; k++)
                kor*=10;
            kor *= (s[i+1]-s[i]>2)? -1 : 1;
        }
    return b;
}
void far(int b, char s[])
{
    int i, c, k, bcs=0, d=1000;
    char sk[11][5] = {"", "a", "aa", "aaa",
                      "ab", "b", "ba", "baa",
                      "baaa", "ac", "c"};
    for (k=6; k>=0; k-=2)
    {
        for( i=0, c=b/d; sk[c][i]; i++, bcs++)
            s[bcs]=sk[c][i]+k;
        b%=d; d/=10;
    }
    s[bcs]=0;
}
int main()
{
    char s1[20]="e", s2[20]="b", s[20]="";
    int op, p1=fra(s1), p2=fra(s2), r=0;
    for (op=1; op<3; op++)
    {
        switch (op)
        {
            case 1: r += p1/p2;
            case 2: r += p1-p2;
        }
        far(r,s); printf("%s\n", s);
    }
}