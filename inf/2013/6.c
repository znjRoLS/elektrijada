//
// Created by rols on 4/6/17.
//

//sizeof (char *) is 4

#include <stdio.h>
char *f(char **p)
{
    char *t = (p += sizeof(p))[-1];
    return (t);
}
int main()
{
    char *t;
    char *s1[]={"ab","cd","ef","gh","ij"};
    char *s2[]={"ba","dc","fe","hg","ji"};
    char *s3[]={"aba","cdc","efe","ghg","iji"};
    t = f((s1,s2)),f((s2,s3));
    printf("%s", t);
    return (0);
}