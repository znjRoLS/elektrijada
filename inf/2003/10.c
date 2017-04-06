//
// Created by rols on 4/6/17.
//

#include <stdio.h>
#include <string.h>
int total;
void moves(char s, char t, char p, int n);
main()
{ int n;
    char L='L',C='0',D='D';
    moves(L,D,C,strlen("2003"));
    printf("%d",total);
}
void moves(char s, char t, char p, int n)
{ if (n==0) return;
    moves(s,p,t,n-1);
    total++;
    moves(p,t,s,n-1);
}