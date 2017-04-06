//
// Created by rols on 4/6/17.
//

//d:\>program ‐s "ELEKTRIJADA BECICI" ‐p E ‐n 2

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define F(e) "ERR: "#e
#define T(e) "REZ: "#e
int fs(char *s, char *p)
{
      static int br;
      if (s=strstr(s,p)) br++, fs(s+strlen(p),p);
      return br;
}
int main(int argc, char* argv[])
{
      char *p=0, *s=0, *psn=0;
      int i, n=1;
      for (i=1; i<argc; i++)
      {
            if (!strcmp(argv[i],"‐p"))
            {
                   if (++i<argc) p=argv[i];
                   else return printf(F(p)), 1;
                }
            else if (!strcmp(argv[i],"‐s"))
            {
                   if (++i<argc) s=argv[i];
                   else return printf(F(s)), 1;
                }
            else if (!strcmp(argv[i],"‐n"))
            {
                   if (++i<argc) n=atoi(argv[i]);
                   else return printf(F(n)), 1;
                }
            else return printf(F(psn)), 1;
          }
      if (!p) return printf(F(p)), 1;
      if (!s) return printf(F(s)), 1;
      if (fs(s,p)!=n)
         return printf(F(n)"=%d",fs(s,p)), 1;
      else
         return printf(T(n)"=%d",fs(s,p)), 0;
} 