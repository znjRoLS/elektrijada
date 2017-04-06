//
// Created by rols on 4/6/17.
//

#include <stdio.h>
int acf(int x, int y)
{ if (x==0) return(y+1);
    if (y==0) return(acf(x-1,1));
    return(acf(x-1,acf(x,y-1)));
}
main()
{ printf("%d %d %d",2,5,acf(2,5));}