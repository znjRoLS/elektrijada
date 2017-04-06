//
// Created by rols on 4/6/17.
//

#include <iostream>
#include <stdlib.h>
using namespace std;
int id = 0;
class A {
public:
    A() {
        id += objectID = id *= -1;
    }
    A(int objectNumber) {
        id += objectID = objectNumber;
        cout << id << " OOP" << endl;
    }
    ~A() {
        id *= -1;
        objectID = id > 0 ? ++objectID : objectID--;
        cout << objectID << " JADA " << endl;
    }
private:
    int objectID;
};
void remove( void );
class B : virtual public A {
public:
    B() : A(id) { static A b(id++); }
    B( int i): A(i) { A b(id); }
    ~B() { A b(1); }
};
class C : public A {
    A a;
public:
    C(int i) : A(i) {}
    virtual ~C() { A b(); }
};
B b(id++);
class D : public B, virtual public C {
public:
    D(int i) : B(i), C(i) {
        static A a(i);
    }
};
int main( ) {
    B d();
    D c(id);
    remove();
    exit(0);
}
void remove( void ) {
    C c(id++);
    static A b(id);
};