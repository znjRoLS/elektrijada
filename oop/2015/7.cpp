//
// Created by rols on 4/6/17.
//

#include <iostream>
using namespace std;
template <class T, int n>
class Data {
public:
    T arVal[n];
    Data() {
        for (int i=0; i<n; i++) arVal[i] = T();
    }
    Data(T arValues[]) {
        for (int i=0; i<n; i++) arVal[i] = arValues[i];
    }
    int CompareAndCorrect(Data<T, n> &data, T corr) {
        int res = 0;
        for (int i=n-1, p=1; i>=0; i--, p*=2)
            if (arVal[i] >= data.arVal[i]) {
                res += p;
                data.arVal[i] += corr / 2;
            } else {
                data.arVal[i] -= corr / 2;
            }
        return res;
    }
    void Print() {
        for (int i=0; i<n; i++) cout << arVal[i] << " ";
    }
};
template <class T, int n>
class Element {
public:
    Data<T, n> *data;
    T val;
    Element<T, n> *ptr;
    Element() {
        data = NULL; val = T(); ptr = NULL;
    }
    Element(Data<T, n> *d, T v, Element<T, n>* p) {
        data = d; val = v; ptr = p;
    }
    T GetValue() {
        if (ptr != NULL) return val + ptr->GetValue();
        else return val;
    }
    void SetValue(T value) { val = value; }
    Data<T, n>* Create(T corr) {
        T arV[n];
        for (int i=0; i<n; i++)
            arV[i] = (2 * corr) * (data->arVal[i] / (2 * corr)) + corr;
        return new Data<T, n>(arV);
    }
    void Print(bool bVal = true) {
        if (bVal) cout << val << " | ";
        if (data != NULL) data->Print();
        if (ptr != NULL) {
            cout << "| ";
            ptr->Print(false);
        }
        if (bVal) cout << endl;
    }
};
template <class T, int n, int m>
class Collection {
    Element<T, n> **arElem;
    Data<T, n> data;
    T corr;
    int fact;
    void Connect(int num, T valOld, T valNew, T corr) {
        int numNew = (num - 1) / fact;
        T vOld = T(), vNew = T();
        if (arElem[numNew] != NULL) {
            vOld = arElem[numNew]->GetValue();
            vNew = vOld-valOld+valNew;
            arElem[numNew]->SetValue(vNew);
        } else {
            Data<T, n> *data = arElem[num]->Create(corr);
            vNew = valNew;
            arElem[numNew] = new Element<T, n>(data, valNew, arElem[numNew]);
        }
        if (numNew != 0)
            Connect(numNew, vOld, vNew, 2*corr);
    }
    int Find(Data<T, n> dt, Data<T, n> data, T &corr, int mm, int num) {
        if (mm == 1) return num;
        num *= fact;
        num += dt.CompareAndCorrect(data, corr) + 1;
        corr /= 2;
        return Find(dt, data, corr, mm-1, num);
    }
    void Search(Data<T, n> dt, T corr, int num) {
        if (num < m*m*m && arElem[num] != NULL) {
            arElem[num]->Print();
            int numNew = dt.CompareAndCorrect(*arElem[num]->data, corr);
            for (int i=0; i<fact; i++) {
                int numTmp = (~i & numNew) | (i ^ numNew);
                Search(dt, corr/2, fact*num+numTmp+1);
            }
        }
    }
public:
    Collection(Data<T, n> d) : fact(n*n), data(d) {
        arElem = new Element<T, n>*[m*m*m];
        for (int i=0; i<m*m*m; i++) arElem[i] = NULL;
        corr = data.arVal[1];
    }
    void Search(Data<T, n> dt) { Search(dt, corr, 0); }
    void Create(Data<T, n> *arD, int sz) {
        for (int i=0; i<sz; i++) {
            T valOld = T(), cr = corr;
            int num = Find(arD[i], data, cr, m, 0);
            if (arElem[num] != NULL)
                valOld = arElem[num]->GetValue();
            arElem[num] = new Element<T, n>(&arD[i], T(1), arElem[num]);
            T valNew = arElem[num]->GetValue();
            Connect(num, valOld, valNew, 2*cr);
        }
    }
};
int main() {
    int size = 16;
    int data[] = { 24,8, 17,1, 31,3, 26,2, 19,11, 22,6, 17,13, 27,13,
                   29,5, 23,14, 18,3, 30,9, 23,3, 25,15, 31,14, 22,10 };
    Data<int, 2> arData[15], collData(data);
    for (int i=1; i<size; i++)
        arData[i-1] = Data<int,2>(&data[2*i]);
    Collection<int, 2, 3> coll(collData);
    coll.Create(arData, size-2);
    coll.Search(arData[size-2]);
    return 0;
}