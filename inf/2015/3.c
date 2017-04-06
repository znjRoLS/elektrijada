//
// Created by rols on 4/6/17.
//

#include <stdio.h>
#include <stdlib.h>
int ***fc(int n)
{
      int i,j,k;
      int ***p=(int***) malloc(n*sizeof(int **));
      for (i=0; i<n; i++)
      {
            *(p+i)=(int**) malloc(n*sizeof(int *));
            for (j=0; j<n; j++)
            {
                  *(*(p+i)+j)=
                    (int*) malloc(n*sizeof(int));
                  for (k=0; k<n; k++)
                    *(*(*(p+i)+j)+k)=n*(n*i+j)+k;
                }
          }
      return p;
}
int ***ft(int ***q, int n)
{
      int i,j,k,x;
      for (x=***q, i=0; i<n; i++)
        for (j=0; j<n; j++)
          for (k=0; k<n; k++)
            if (i[j[k[q]]]>x && i[j[k[q]]]%2)
               printf("%o\n", x=i[j[k[q]]]);
      return q;
}
void ff(int ***r, int n)
{
      int i,j;
      for(i=0; i<n; free(*(r+i)), i++)
        for(j=0; j<n; free(*(*(r+i)+j)),j++);
      free(r);
}
int main()
{
      ff(ft(fc(3),3),3);
      return 0;
}