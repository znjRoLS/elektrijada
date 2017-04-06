//
// Created by rols on 4/6/17.
//

#include <stdio.h>
typedef struct S
{  
      void (*foo[24])(void*);
      char *******(*bar)(void*);
} SA[10];
void main()
{
      SA array[10];
      printf("%d\n%d", sizeof(SA),sizeof(array));
}