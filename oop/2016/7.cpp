//
// Created by rols on 5/13/17.
//

#include <iostream>

#include <math.h>

using namespace std;

template <class T>

class Elem {

    T a;

    T b;

public:

    Elem<T>() {

        a = T(); b = T();

    }

    Elem<T>(T aa, T bb) {

        a = aa;

        b = bb;

    }

    Elem<T> Join(Elem<T>& elj, bool bInc=false) {

        Elem<T> el(*this);

        if (bInc) {

            el.a += elj.a;

            el.b += elj.b;

        } else {

            el.a -= elj.a;

            el.b -= elj.b;

        }

        return el;

    }

    Elem<T> Move(T d) {

        Elem<T> el(d * a, d * b);

        return el;

    }

    T Evaluate(Elem<T>& pt) {

        T val = a * pt.a + b * pt.b;

        return val;

    }

    void Print() {

        cout << a << " " << b << endl;

    }

};

template <class T>

class Relation {

    Elem<T> min;

    Elem<T> max;

public:

    Relation<T>(Elem<T>& mini, Elem<T>& maxi) {

        min = mini; max = maxi;

    }

    double Check(Elem<T> el) {

        Elem<T> join = max.Join(min);

        Elem<T> elJoin = el.Join(min);

        T elVal = join.Evaluate(elJoin);

        if (elVal <= 0) {

            elVal = elJoin.Evaluate(elJoin);

        } else {

            T val = join.Evaluate(join);

            if (val <= elVal) {

                elJoin = el.Join(max);

                elVal = elJoin.Evaluate(elJoin);

            } else {

                T div = elVal / val;

                Elem<T> elNew = join.Move(div);

                elNew = min.Join(elNew, true);

                elJoin = elNew.Join(el);

                elVal = elJoin.Evaluate(elJoin);

            }

        }

        return sqrt(elVal);

    }

};

template <class T>

class Set{

    Elem<T>* arMem;

    int nMem;

    int* arSub;

    int nSub;

public:

    Set(int arV[], int nV) {

        nMem = nV;

        arMem = new Elem<T>[nMem];

        arSub = new int[nMem];

        for (int i=0; i<nMem; i++) {

            arMem[i] = Elem<T>((arV[i]&0xF0)>>4, arV[i]&0xF);

        }

        nSub = 0;

    }

    void CreateSub(int seed) {

        int sd = seed / 2;

        for (int i = sd; i<nMem; i+=seed) {

            arSub[nSub++] = i;

        }

        arSub[nSub++] = sd;

    }

    void UpdateSub(double e) {

        for (int s=0,c=0; s<nSub-1; s+=c+1) {

            c = Check(s, arSub[s], arSub[s+1], e);

        }

    }

    int Check(int m, int s, int ss, T e) {

        int check = 0;

        Relation<T> rel(arMem[s],arMem[ss]);

        int belongs = s;

        T dBelongs = e;

        for (int i=(s+1)%nMem; i!=ss; i=(i+1)%nMem) {

            T dB = rel.Check(arMem[i]);

            if (dB > dBelongs) {

                dBelongs = dB;

                belongs = i;

            }

        }

        if (dBelongs != e) {

            for (int i = nSub++; i>m; i--) {

                arSub[i] = arSub[i-1];

            }

            arSub[m+1] = belongs;

            check += Check(m+1, belongs, ss, e);

            check += Check(m, s, belongs, e);

            check ++;

        }

        return check;

    }

    void Print() {

        for (int i=0; i<nSub; i++) {

            arMem[arSub[i]].Print();

        }

    }

};

int main() {

    int nVal = 0x1E;

    int arVal[] = {0x84, 0x73, 0x51, 0x42, 0x23, 0x12, 0x2, 0x33, 0x26, 0x35,

                   0x28, 0x47, 0x56, 0x79, 0x9D, 0xAE, 0xAF, 0xBD, 0xCA, 0xC8,

                   0xB6, 0xD7, 0xD6, 0xE5, 0xE3, 0xF2, 0xE3, 0xC2, 0xA3, 0x95};

    Set<double> set(arVal, nVal);

    set.CreateSub(0xA);

    set.UpdateSub(2);

    set.Print();

    return 0;

}