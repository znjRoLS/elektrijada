//
// Created by rols on 4/6/17.
//

#include <stdio.h>
int main()
{
    int array[2][2] = {0, 1, 3, 6};
    int i, sum = 0;
    for (i=0; i<4; ++i)
    {
        int x, y;
        x = i % 2; if (x) y=0; else y=1;
        sum += *array[x,y];
    }
    printf("%d", sum);
}