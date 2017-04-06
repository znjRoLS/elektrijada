//
// Created by rols on 4/6/17.
//

#include <stdio.h>
int f(int n)
{
    int x0=0,y0=1,x1=1,y1=n,a,b,br=0;
    do {
        a=(y0+n)/y1*x1-x0; b=(y0+n)/y1*y1-y0;
        x0=x1; x1=a; y0=y1; y1=b; br++;
    }
    while (x0<y0);
    return (br);
}
main()
{
    printf("%d %d",f(5),f(20));
}