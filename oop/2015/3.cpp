//
// Created by rols on 4/6/17.
//

#include <iostream>
#include <stdlib.h>
using namespace std;
int id = 0;
class A {
public:
    A() { id += objID = id *= -1; }
    A(int objectNumber) {
        id += objID = objectNumber;
        objID = id > 0 ? objID++ : --objID;
        cout << ++id << " OOP" << endl;
        id *= -1;
    }
    ~A() {
        id *= -1;
        id > 0 ? (cout << objID+id << " JADA " << endl, id++)
               : (cout << objID-id << " JADA " << endl, id--);
    }
private:
    int objID;
};
class B : virtual public A {
    A a;
public:
    B() : A(id) { }
    B(int i) : A(i) { static A b(i); }
    ~B() { A b(); }
};
class C : public A {
public:
    C(int i) : A(id) {
//on create :-)
        A b(i);
    }
    virtual ~C() {
//on remove :-\
A b(1);
    }
};
class D : public B, virtual public C, virtual public A {
public:
    D(int i) : B(i), A(i), C(1) { static A a(i); }
};
int main() {
    C c(), c();
    D b(id);
    c(), c();
    exit(0);
}
B b(id++);
C c() {
    static C c(id++);
    return c;
};
C c();