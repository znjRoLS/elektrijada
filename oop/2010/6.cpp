//
// Created by rols on 4/6/17.
//

#include <iostream>
using namespace std;
class Basic {
public:
    int no;
public:
    Basic() {no = 0;};
    Basic(int num) {no = num;};
    Basic(Basic &b) { no=b.no; cout<<"Basic"<<endl; };
    Basic& operator=(Basic &b) { no=b.no; return *this; };
    virtual ~Basic() {};
    virtual bool IsGreater(Basic* pB) { return no > pB->no; };
    virtual void Write() { cout << no << " ";};
    virtual void Swap(Basic *b) { Basic tmp=*b; *b=*this; *this=tmp; }
};
class DerivedA : public Basic {
    int ind;
public:
    DerivedA() { ind=0; };
    DerivedA(int num) : Basic(num) { ind=0; };
    DerivedA(DerivedA &a) { no = a.no; cout<<"DerivedA"<<endl; };
    DerivedA& operator=(DerivedA &a) { no=a.no; ind++; return *this; };
    virtual ~DerivedA() {};
    virtual bool IsGreater(Basic* pB) {return no < pB->no; };
    virtual void Write() { cout << no << " " << ind << " ";};
    void Swap(Basic *b) {Swap((DerivedA *)b);};
    void Swap(DerivedA *a) { DerivedA tmp=*a; *a=*this; *this=tmp;}
};
class DerivedB : public Basic {
    int ind;
public:
    DerivedB() { ind=0; };
    DerivedB(int num) : Basic(num) { ind=0; };
    DerivedB(DerivedB &b) { no = b.no; cout<<"DerivedB"<<endl; };
    DerivedB& operator=(DerivedB &b) { no=b.no; ind++; return *this; };
    virtual ~DerivedB() {};
    bool IsGreater(Basic* pB) { return no < pB->no; };
    virtual void Write() { cout << no << " " << ind << " ";};
    void Swap(Basic *b) {Swap((DerivedB *)b);};
    virtual void Swap(DerivedB *b) { DerivedB tmp=*b; *b=*this; *this=tmp; }
};
class DerivedD : public DerivedB {
public:
    DerivedD() {};
    DerivedD(int num) : DerivedB(num) { };
    DerivedD(DerivedD &d) { no = d.no; cout<<"DerivedD"<<endl; };
    virtual ~DerivedD() {};
    bool IsGreater(Basic* pB) { return no > pB->no;};
    void Swap(Basic *b) {Swap((DerivedD *)b);};
    void Swap(DerivedD *d) { DerivedD tmp=*d; *d=*this; *this=tmp;}
};
int main()
{
    int i, n=5;
    Basic** aBasic = new Basic*[n];
    aBasic[0] = new DerivedA(4);
    aBasic[1] = new Basic(7);
    aBasic[2] = new Basic(3);
    aBasic[3] = new DerivedB(15);
    aBasic[4] = new DerivedD(11);
    for (i=0; i<n-1; i++) {
        int nMax = i;
        for (int j=i+1; j<n; j++)
            if (aBasic[j]->IsGreater(aBasic[nMax]))
                nMax = j;
        if (nMax != i)
            aBasic[nMax]->Swap(aBasic[i]);
    }
    for (i=0; i<n; i++)
        aBasic[i]->Write();
    cout << endl;
    for (i=0; i<n-1; i++) {
        int nMax = i;
        for (int j=i+1; j<n; j++)
            if (!aBasic[nMax]->IsGreater(aBasic[j]))
                nMax = j;
        if (nMax != i)
            aBasic[i]->Swap(aBasic[nMax]);
    }
    for (i=0; i<n; i++)
        aBasic[i]->Write();
    cout << endl;
    return 0;
}