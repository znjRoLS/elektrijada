//
// Created by rols on 4/6/17.
//

#include <stdio.h>
#define RS(a,b) a+=b, b=a-b, a-=b
int f(int x) { return x<10?x:x%10+f(x/10); }
void fs(int a[], int ib, int ie)
{
      if (ib<ie)
      {
            int i=ib, j=ie, pi=a[ib];
            while (i<j)
            {
                  while (f(a[i])>=f(pi) && i<j) i++;
                  while (f(a[j])<f(pi)) j--;
                  if (i<j) RS(a[i],a[j]);
                }
            a[ib]=a[j]; a[j]=pi;
            fs(a,ib,j-1); fs(a,j+1,ie);
          }
}
int main()
{
      int i=0, niz[10]={2015,19,5,2016,20,6};
      fs(niz,0,5);
      while (niz[i]) printf("%d\n", niz[i]), i++;
      return 0;
}  