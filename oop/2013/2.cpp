//
// Created by rols on 4/6/17.
//

#include <iostream>
using namespace std;
int id = 0;
class A {
public:
    A() {
        id *= 2;
    }
    A(int objectNumber) {
        id += objectID = objectNumber;
        cout << objectID << " OOP" << endl;
    }
    ~A() {
        cout << id << " JADA " << id-- << endl;
    }
private:
    int objectID;
};
void create( void );
class B : public A {
public:
    B() : A(id) { static A b(id++); }
    B( int i): A(i) { A b(id); }
    ~B() { A b(id++); }
};
A a(id++);
class C : virtual public A {
    A a;
public:
    C(int i) : A(i) {}
    virtual ~C() { A b(); }
};
class D : public B, public C {
public:
    D(int i) : B(i), C(i) {
        static A a(i);
    }
};
int main( ) {
    C b(id);
    D c(id++);
    B d();
    create();
    return (int)0;
}
B b(1);
void create( void ) {
    static A b(id);
    C c(id++);
};