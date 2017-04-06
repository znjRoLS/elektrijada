//
// Created by rols on 4/6/17.
//

#include <stdio.h>
void fsi(char s[], int b[])
{
    int i, j;
    for (i=0; i<10; b[i]=0, i++);
    for (i=0; s[i]!=0; i++);
    for (i--,j=0 ; i>=0; b[j]=s[i]-'0', i--,j++);
}
int fl(int n1[], int n2[], int k)
{
    int i;
    for (i=9; i>0; i--)
    {
        if (n1[i]<n2[i]) return 1;
        else if (n1[i]>n2[i]) return 0;
    }
    return (k ? n1[0]<n2[0] : n1[0]<=n2[0]);
}
void fd(int n[])
{
    int i, p, t;
    for (p=0, i=0; i<9; i++)
    { t=n[i]*2; n[i]=t%10 + p; p=t/10; }
}
void fp(int n[])
{
    int i, p, t;
    for (p=0, i=9; i>=0; i--)
    { t = p*10 + n[i]; n[i]=t/2; p=t%2; }
}
void fm(int n1[], int n2[], int rez[])
{
    int i, j, p;
    for (i=0; i<=9; i++)
    {
        if (n2[i]<=n1[i]) rez[i]=n1[i]-n2[i];
        else
        {
            j=i+1;
            do
            { p=0; n1[j]--;
                if (n1[j]==-1) { n1[j]=9; j++; p=1; }
            } while (p);
            rez[i]=10+n1[i]-n2[i];
        }
    }
}
int main()
{
    char ns1[10]="10", ns2[10]="1000";
    int i, s;
    for (s=2; s; s--)
    {
        int n[10]={0}, p[10]={2}, kod[10]={0};
        if (s==1) fsi(ns1,n); else fsi(ns2,n);
        while (fl(p,n,1)) fd(p);
        fp(p); fm(n,p,kod); fd(kod);
        for (i=9; !kod[i]; i--);
        for(; i>=0; i--) printf("%d", kod[i]);
        printf("\n");
    }
}