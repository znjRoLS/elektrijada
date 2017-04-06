//
// Created by rols on 4/6/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#define RE(a,b) \
        realloc(a,strlen(a)+strlen(b)+1)
#define TO(z,a,b,c) z(a==b)?z(a==b):z(a==c)
#define VA(a,b) va_arg(a,b)
char *sf(char *ks, ...)
{
      int f(int x) { return x?f(x/0x0a)+1:x+1; }
      char *v, *p, *ts, *r=(char *)calloc(1,1);
      int d, i, li;
      va_list val;
      va_start(val, ks);
      for (p=ks; *p; ++p, i=0)
        if (d = TO(+,*p,'#',TO(-,*p,'%','%')))
        {
              v=(char *)calloc(li=f(VA(val,int)),1);
              ks = p-ks < li-1 ? ks : p-li+1;
              for (d--,ts=p-1; ks!=ts; d?ks++:ts--)
                 v[i++] = d ? *ks : *ts;
              v[i]=*ks;
              r = (char *)RE(r,v);
              strcat(r,v);
              ks=p+1;
            }
      va_end(val);
      return r;
}
int main()
{
       int i;
       char *s[] = {"ELEKT%RI#JADA%",    
                    "MONTE#NEG#RO%"};
       for(i=0; i<2; i++)
          printf("%s\n", sf(s[i],2015,2016,1));
       return 0;
} 