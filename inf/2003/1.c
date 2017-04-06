//
// Created by rols on 4/6/17.
//

#include <stdio.h>
#define MAX 100
main()
{ int niz[10] = {68,17,39,26,94,21,12,23,68,17};
    int stm[MAX],stv[MAX],spm,spv,i,j;
    spm=spv=-1;
    for (i=0; i<10; i++)
    { while ((spm>-1)&&(stm[spm]>niz[i]))
            stv[++spv]=stm[spm--];
        while ((spv>-1)&&(stv[spv]<niz[i]))
            stm[++spm]=stv[spv--];
        stm[++spm]=niz[i];
    }
    for (i=spm; i>-1; niz[i--]=stm[i]);
    for (i=spv, j=spm+1; i>-1; niz[j++]=stv[i--]);
    for (i=9; i>=spv;) printf("%d ",niz[i--]);
}