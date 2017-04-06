//
// Created by rols on 4/6/17.
//

#include<stdio.h>
int fsbt(int m, int n)
{
    static char sb[20];
    static int t, p, lb,ln, rb,rn, xb,xn;
    p=t;
    if (!t)
    {
        if (1.0*m/n < 1)
        { lb=0; ln=rb=rn=1; sb[t++]='L'; }
        else
        { lb=ln=rb=1; rn=0; sb[t++]='R'; }
        xb=lb+rb; xn=ln+rn;
    }
    if ( !((xb==m) && (xn==n)) )
    {
        if (1.0*m/n < 1.0*xb/xn)
        { rb=xb; rn=xn; sb[t++]='L'; }
        else
        { lb=xb; ln=xn; sb[t++]='R'; }
        xb=lb+rb; xn=ln+rn;
        fsbt(m,n);
    }
    sb[t]=0; t=0; return (p);
}
int main()
{
    printf("%d\n%d", fsbt(3,4), fsbt(8,7));
}