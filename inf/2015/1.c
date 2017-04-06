//
// Created by rols on 4/6/17.
//

#include <stdio.h>
#define MAX 20
int main()
{
  signed char niz[MAX][MAX], c=0;
  int d=1, x=0, i, j;
  FILE *f=fopen("file1.txt", "r");
  while (fscanf(f, "%s", niz[x++])!=EOF);
  for (c-=--x;c++&**niz;d<<=1,d+=!(c<<x>0));
  d -= c;
  for (i=0; i<x;
      i==1?printf("%c\n",niz[i][x>>1]):i,++i)
    for (j=0;j<=i;printf("%c", niz[i][j++]));
  printf("%X", d);
  return 0;
}