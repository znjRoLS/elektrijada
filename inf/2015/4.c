//
// Created by rols on 4/6/17.
//

#include <stdio.h>
int main()
{
    char *s[]={"PERFECT","MISC","TUBE","GREEN"};
    int i,j;
    for(i=0;i<sizeof(s)/sizeof(char*);i++)
       for(j=0;j<sizeof(s[i])/sizeof(char);j++)
          j+i&0123>>i||printf("%c",j[i[s]]);
    return 0;
}