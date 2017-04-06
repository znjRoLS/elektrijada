//
// Created by rols on 4/6/17.
//

#include "iostream"
using namespace std;
template<class Tip, int n>
class Data {
    Tip arVal[n];
public:
    Data() { for (int i=0; i<n; i++) arVal[i] = -1; };
    Data(Tip arV[]) { for (int i=0; i<n; i++) arVal[i] = arV[i]; };
    Tip Value() {
        Tip val = 0;
        for (int i=0; i<n/2; i++)
            val += (arVal[i+n/2]-arVal[i]);
        return val;
    };
    void Print() {
        for (int i=0; i<n; i++) cout << arVal[i] << " ";
        cout << endl;
    };
    void Combine(Data& data) {
        for (int i=0; i<n/2; i++)
            if (arVal[i] == -1) {
                arVal[i] = data.arVal[i];
                arVal[i+n/2] = data.arVal[i+n/2];
            } else {
                arVal[i] = arVal[i]-data.arVal[i]>0 ? data.arVal[i] : arVal[i];
                arVal[i+n/2] = arVal[i+n/2]-data.arVal[i+n/2]<0
                               ? data.arVal[i+n/2] : arVal[i+n/2];
            }
    };
};
template<class Tip, int dim>
class Set {
    Tip arData[dim];
    Set* arSet[dim+1];
    int n;
    int Overlap(Tip data) {
        arData[n++] = data;
        int ii=1, dd = 0, norm = 10000;
        for (int i=0; i<n-1; i++, ii<<=1);
        for (int d=1, i=0; i<n-1; d<<=1, i++) {
            dd = Compare(d|ii, norm) ? d|ii : dd;
        }
        n--;
        for (dd=dd^ii, ii=0; dd>1; ii++, dd>>=1);
        return ii;
    };
    Set* Duplicate() {
        int dd = 0, norm = 10000;
        for (int i=1, s=0; s<dim-1; i++) {
            s = 0;
            for (int d = i; d; s+=d%2, d>>=1);
            if (s == dim/2)
                dd = Compare(i, norm) ? i : dd;
        }
        return Reorder(dd);
    };
    bool Compare(int d, int& norm) {
        Tip data[2];
        for (int i=0; i<n; d>>=1, i++)
            data[d%2].Combine(arData[i]);
        if (data[0].Value() + data[1].Value() < norm) {
            norm = data[0].Value() + data[1].Value();
            return true;
        }
        return false;
    };
    Set* Reorder(int dd) {
        Set *pSet = new Set();
        for (int i=0, ii=0; i<n; i++, dd>>=1) {
            if (dd%2) {
                if (arSet[i]) arSet[i]->arSet[dim] = pSet;
                pSet->arData[pSet->n] = arData[i];
                pSet->arSet[pSet->n++] = arSet[i];
            } else {
                arData[ii] = arData[i];
                arSet[ii++] = arSet[i];
            }
        }
        for (int j=n-=dim/2; j<dim; j++) arSet[j] = NULL;
        if (!arSet[dim]) {
            Set *pSetP = new Set();
            pSetP->arSet[pSetP->n++] = this;
            arSet[dim] = pSetP;
        }
        pSet->arSet[dim] = arSet[dim];
        return arSet[dim]->Update(this, pSet);
    };
    Set* Update(Set* pOld, Set* pNew) {
        int i = 0;
        for ( ; i<n && arSet[i]!=pOld; i++);
        arData[i] = pOld->Size();
        arData[n] = pNew->Size();
        arSet[n++] = pNew;
        if (n >= dim) return Duplicate();
        return this;
    };
    Tip Size() {
        Tip data;
        for (int i=0; i<n; i++) data.Combine(arData[i]);
        return data;
    };
public:
    Set() : n(0) {
        for (int i=0; i<dim+1; i++) arSet[i] = NULL;
    };
    void Print() {
        if (arSet[n-1]) {
            for (int i=0; i<n; i++) arSet[i]->Print();
        } else {
            for (int i=0; i<n; i++) arData[i].Print();
            cout << endl;
        }
    };
    Set* Update(Tip& data) {
        if (n>0 && arSet[n-1]) {
            int ind = Overlap(data);
            Set *pSet = arSet[ind]->Update(data);
            return pSet != arSet[ind] ? pSet : this;
        } else {
            arData[n++] = data;
            Size();
            return n >= dim ? Duplicate() : this;
        }
    };
};
int main() {
    int arVal[12][4] = { {1,5,3,7}, {4,3,6,7}, {3,4,7,6}, {5,7,8,9}, {8,4,10,7}, {6,3,7,5},
                         {13,11,14,15}, {2,12,5,14}, {5,13,7,15}, {11,6,13,8}, {12,1,15,4}, {9,10,11,12} };
    Set< Data<int, 4>, 5 > *pSet = new Set< Data<int, 4>, 5 >;
    for (int i=0; i<12; i++) {
        Data<int, 4> data(arVal[i]);
        pSet = pSet->Update(data);
    }
    pSet->Print();
    return 0;
}