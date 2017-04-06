//
// Created by rols on 4/6/17.
//

#include <stdio.h>
void main()
{
      signed char x[]={-256,-255,-129,-128,-127,
                       -1,127,128,255,256};
      signed char fv[10]={}, fc[10]={};
      int i,j,m=-1;
      for (i=0;i<sizeof(x); i++)
        if (x[i]>100u)
        {
              for (j=0;j<m;j++)  
                if (x[i]==fv[j]) break;
              fv[j]=x[i],fc[j]++;  
              if (j>=m) m++;
            }
      for(j=0; j<m; j++)
        printf("%d(%d)\n", fv[j],fc[j]);
}