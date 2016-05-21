//
// Created by rols on 5/21/16.
//

#include <stdio.h>
#define M1(X) printf("%d", printf("""X"""))
#define M2(X) printf("%d", printf("""X\n"""))
#define M3(X,O,Y) X O Y
int main()
{
    printf("1:%d\n", M1(999)||M1(88));
    printf("2:%d\n", M3(M1(777),||,M1(66)));
    printf("3:%d\n", M3(M2(555),&&,M2(44)));
    return 0;
}