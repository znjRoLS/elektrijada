//
// Created by rols on 4/6/17.
//

#include <stdio.h>
int fra(char *s) {
    int i, b=0, k, d, n;
    for (i=0; s[i]; b+=d, i++)
        if ((s[i]-'a')%2)
            for(d=5,k=0; k<(s[i]-'1')/2; d*=10,k++);
        else {
            for(d=1,k=0; k<(s[i]-'1')/2; d*=10,k++);
            d *= (s[i+1]-s[i]>2)? -1 : 1;
        }
    return b;
}
char *fr(int b, char s[]) {
    int i, c, k, bcs=0, d=1000;
    char sk[11][5]={"","1","11","111","12","2",
                    "21","211","2111","13","3"};
    for (k=6; k>=0; k-=2)
    {
        for(i=0, c=b/d; sk[c][i]; i++, bcs++)
            s[bcs]=sk[c][i]+k;
        b%=d; d/=10;
    }
    s[bcs]=0; return s;
}
main()
{
    char s[10], s1[10]="4321", s2[10]="211";
    printf("%s\n", fr(fra(s1)/fra(s2),s));
    printf("%s", fr(fra(s1)%fra(s2),s));
}