//
// Created by rols on 4/6/17.
//

#include <stdio.h>
int main()
{
    int a1[5] = { 1, 2, 3, 4, 5 };
    int *p1 = (int*)(&a1+1);
    int a2[4][3] = {1,2,3,4,5,6,7,8,9};
    int (*p2)[3] = a2;
    printf("%d %d\n", *(a1+1), *(p1-1));
    printf("%d %d\n", (*p2)[2],(*p2)[1]);
    ++p2;
    printf("%d %d", (*p2)[1],(*p2)[2]);
    return (0);
}