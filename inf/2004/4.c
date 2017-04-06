//
// Created by rols on 4/6/17.
//

#include <stdio.h>
int mcf(int x, int y)
{
    if (!x) return(y+1);
    if (!y) return(mcf(x-1,1));
    return(mcf(x-1,mcf(x-1,y-1)));
}
main()
{
    printf("%d%d",mcf(1,0),mcf(11,10));
}