//
// Created by rols on 4/6/17.
//

#include <iostream>
using namespace std;
#define dim 20
int b = 0;
class Elem {
protected:
    int data;
    int weight;
public:
    Elem() { data = 0; weight = 1; b+=2; }
    Elem(int d, int w) : data(d), weight(w) {}
    Elem(Elem& el) : data(el.data), weight(el.weight) { b++; }
    Elem& operator=(const Elem &el) {
        data = el.data;
        weight = el.weight;
        b+=3;
        return *this;
    }
    bool operator<(Elem &el) {
        return Value() < el.Value();
    }
    bool Compare(Elem *el) {
        return Size() < el->Size();
    }
    virtual int Size() {
        return data * weight;
    }
    virtual int Value() {
        return data;
    }
    virtual void Print() {
        cout << data << " " << weight << endl;
    }
};
class Container : public Elem
{
    Elem *els[dim];
    int n;
public:
    Container() : n(0){
        for (int i=0; i<dim; i++)
            els[i] = NULL;
    }
    void Add(Elem *elem) {
        els[n++] = elem;
        data += elem->Value();
    }
    int Size() {
        int res = 0;
        for (int i=0; i<n; i++)
            res += els[i]->Size();
        return res;
    }
    int Value() {
        int res = 0;
        for (int i=0; i<n; i++)
            res += els[i]->Value();
        return res;
    }
    void Rearrange() {
        for (int i=1; i<n; i++) {
            int j = i;
            Elem* el = els[i];
            for (; j>0 && els[j] < els[j-1]; j--)
                els[j] = els[j-1];
            els[j] = el;
        }
    }
    Container* Join(Container &con) {
        Container* res = new Container();
        for (int i=0, ii=0; i<n || ii<con.n; ) {
            if (i<n && ii<con.n) {
                if (els[i]->Compare(con.els[ii]))
                    res->Add(els[i++]);
                else
                    res->Add(con.els[ii++]);
            } else if (i<n) {
                res->Add(els[i++]);
            } else {
                res->Add(con.els[ii++]);
            }
        }
        return res;
    }
    void Print() {
        Elem::Print();
        for (int i=0; i<n; i++)
            els[i]->Print();
    }
};
int main() {
    const int size = 5;
    int data = 64, weigth = 2;
    Elem arr[15] = { };
    Container con1, con2, *con3;
    for (int i=0; i<size; i++) {
        arr[2*i] = Elem(data-=data/2, weigth*=2);
        con1.Add(&arr[2*i]);
        arr[2*i+1] = Elem(data%size, weigth/4);
        con2.Add(&arr[2*i+1]);
    }
    con1.Rearrange();
    con1.Print();
    cout << b << endl;
    con2.Rearrange();
    Container con4 = con2;
    con4.Print();
    cout << b << endl;
    con3 = con1.Join(con2);
    con3->Print();
    cout << b << endl;
    return 0;
}