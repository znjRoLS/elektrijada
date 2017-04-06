//
// Created by rols on 4/6/17.
//

#include <iostream>
using namespace std;
class Operate {
public:
    virtual void execute(int data[], int n) = 0;
};
class Add : public Operate {
    int *coef;
    int n;
public:
    Add() { n = 0; coef = NULL; };
    Add(int *d, int no) {
        n = no;
        coef = new int[no];
        for (int i=0; i<n; i++)
            coef[i] = d[i];
    };
    void execute(int data[], int n) {
        for (int i=0; i<n; i++)
            data[i] += coef[i];
    };
};
class Square : public Operate {
    Operate *step;
    virtual void process(int data[], int n, int coef[]) {
        for (int i=0; i<n; i++)
            data[i] += coef[i];
    };
public:
    Square() { step = NULL; };
    Square(Operate *st) { step = st; };
    Operate* set(Operate *st) { step = st; return this; };
    Operate* get() { return step; };
    void execute(int data[], int n) {
        int *d = new int[n];
        for (int i=0; i<n; i++)
            d[i] = 0;
        step->execute(d, n);
        process(data, n, d);
        delete[] d;
    };
};
class Exponent : public Square {
    int axis;
    void process(int data[], int n, int coef[]) {
        for (int i=0; i<n; i++)
            data[i] += (i==axis ? -1 : 1) * coef[i];
    };
public:
    Exponent(Operate *st, int ax=0) : Square(st) { axis = ax; };
};
int limit[2] = {9, 14};
int mat[9][14];
int check(int data[], int d[], int n) {
    bool eq = true;
    for (int i=0; i<n; i++, eq=eq&&data[i]==d[i])
        if (d[i] < 0 || d[i] >= limit[(i+1)%2]) return i+2;
    return eq ? 1 : mat[d[1]][d[0]];
}
int main() {
    int n = 2, data[2] = {}, d[2] = {}, test[2] = {12, 8}, m = 4;
    int a[] = {2, 1};
    int b[] = {1, 2};
    Operate *oper[2];
    oper[0] = new Add(a, n);
    oper[1] = new Add(b, n);
    Square *square[2];
    square[0] = new Exponent(oper[0]);
    square[1] = new Exponent(oper[0], 1);
    int vn[] = {0,0,0,1,1,0,0,0,0,1,1,0,0,1};
    int vp[] = {0,0,0,1,1,1,0,0,0,1,0,0,0,0};
    for (int i=2; i<limit[0]-1; i++)
        for (int j=0; j<limit[1]; j++)
            if (i % 2) mat[i][j] = vn[j];
            else mat[i][j] = vp[j];
    bool end = false;
    int ind = 0, ret = 0;
    Square *sqrt = new Square(oper[0]);
    Square *ex = new Exponent(oper[0], 1);
    while (!end) {
        for (int i=0, ret=1; ret && i<n*n*n; i++) {
            for (int j=0; j<n; j++)
                d[j] = data[j];
            if (i/4)
                if ((i/2)&1 ^ (i/4)&1)
                    sqrt->set(square[(i+1)%2]->set(
                            square[i%2]->set(oper[i&1^(i/2)&1])));
                else
                    sqrt->set(square[i/4]->set(oper[i&1^(i/2)&1]));
            else
            if ((i/2)&1 ^ (i/4)&1)
                sqrt->set(square[0]->set(oper[i&1^(i/2)&1]));
            else
                sqrt->set(oper[i&1^(i/2)&1]);
            if (ind % 2)
                sqrt->set(ex->set(sqrt->get()));
            sqrt->execute(d, n);
            if ((ret = check(data, d, n)) == 3) {ind++; i=-1;};
        }
        end = true;
        for (int i=0; i<n; i++) {
            cout << (data[i] = d[i]) << " ";
            end = end && test[i] == data[i];
        }
        cout << endl;
    }
    delete sqrt;
    delete ex;
    for (int i=0; i<n; i++)
        delete oper[i];
}