//
// Created by rols on 5/13/17.
//

#include <iostream>

#include <stdlib.h>

using namespace std;

int id = 0;

class A {

public:

    A() {

        id += objID = id *= -1;

    }

    A(int objectNumber) {

        id += objID = objectNumber;

        objID = id < 0 ? ++objID : -objID;

        cout << ++id << " OOP" << endl;

    }

    ~A() {

        id *= -1;

        id > 0 ? (cout << objID << " JADA " << endl, -id) : (id--, cout << -id << "

        JADA " << endl, id);

    }

private:

    int objID;

};

class B : public A {

    A a;

public:

    B() : A(id) { }

    B(int i) : A(i) { static B b; }

    ~B() { A b(); }

};

class C : virtual public A {

public:

    C() : A(id) { }

    C(int i) : A() { static B b(i); }

    virtual ~C() { A b(1); }

};

class D : public B, public C {

public:

    D(int i) : B(1), C(i) { static A a(i); }

    ~D() { }

};

int main() {

    D b(id);

    exit(0);

}

B b(id++);