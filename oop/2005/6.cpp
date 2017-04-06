//
// Created by rols on 4/6/17.
//

#include <iostream>
#include <string>
using namespace std;
class CSTRING {
protected:
    char *niz;
    int duz;
public:
    CSTRING() {};
    void Postavi(char* s1, int n);
    ~CSTRING();
    void operator--();
    int tezina (void);
};
int CSTRING::tezina(void) { return duz * 3;}
void CSTRING::Postavi(char *sl, int n) {
    int i;
    duz=n;
    niz=new char[duz];
    for(i=0;i<duz;i++)
        niz[i]=sl[i];
}
CSTRING::~CSTRING() { delete[] niz; duz=0; }
void CSTRING::operator --() {
    int i, j;
    char* pomniz=new char[duz];
    for(i=0;i<duz;i++)
        pomniz[i]=niz[i];
    for(i=0;i<duz;i++)
        if(pomniz[i]=='A' || pomniz[i]=='a' || pomniz[i]=='E' || pomniz[i]=='e'
           || pomniz[i]=='I' || pomniz[i]=='i' || pomniz[i]=='O' || pomniz[i]=='o' ||
           pomniz[i]=='U' || pomniz[i]=='u') {
            if (i!=duz-1)
                for(j=i+1;j<duz;j++)
                    pomniz[j-1]=pomniz[j];
            duz--;
        }
    for(i=0;i<duz;i++)
        niz[i]=pomniz[i];
    delete[] pomniz;
    return;
}
class CNIZ {
    int *niz;
    int n;
public:
    CNIZ(int n1);
    ~CNIZ();
    void Sort();
    void Upis();
    void Stampanje();
};
CNIZ::CNIZ(int n1) { n=n1; niz=new int[n]; }
CNIZ::~CNIZ() { delete[] niz; }
void CNIZ::Sort() {
    int i,j;
    for (i=0;i<n-1;i++)
        for(j=i;j<n;j++)
            if (niz[i]>=niz[j]) {
                niz[i]=niz[i]+niz[j];
                niz[j]=niz[i]-niz[j];
                niz[i]=niz[i]-niz[j];
            }
    return;
}
void CNIZ::Upis() {
    CSTRING *stringovi;
    int i;
    stringovi = new CSTRING[3];
    char *sadrzaj1 = new char[8];
    char *sadrzaj2 = new char[4];
    char *sadrzaj3 = new char[10];
    sadrzaj1 = "KOPAONIK";
    sadrzaj2 = "2005";
    sadrzaj3 = "ELEKTRIJADA";

    stringovi[0].Postavi(sadrzaj1,8);
    stringovi[1].Postavi(sadrzaj2,4);
    stringovi[2].Postavi(sadrzaj3,5);
    for(i=0;i<3;i++) --stringovi[i];

    for(i=0;i<n;i++)
        niz[i]=2*stringovi[i%3].tezina();
    return;
}
void CNIZ::Stampanje() {
    int i;
    for(i=0;i<n;i++)
        cout<<niz[i]<<" ";
    cout<<"\n";
    return;
}
int main() {
    int br1=7;
    CNIZ niz1(br1);
    niz1.Upis();
    niz1.Sort();
    niz1.Stampanje();
}