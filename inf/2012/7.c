
#include <stdio.h>
#define X(a,b) printf(a,b)

void main()
{
    static char s[]="INFORMATICS";
    1 || printf("A");
    0 || printf("B");
    1 && printf("C");
    0 && printf("D");
    X("%d",X("%o\n",X("\n%s\n",s)));

}
