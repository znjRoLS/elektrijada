//
// Created by rols on 4/6/17.
//

#include <iostream>
using namespace std;
int data = 0;
class A {
public:
    A( ){data++;}
    A& operator++( ) {cout << "1 " << data-- << endl; A* b = new A; return *b;}
    A& operator++(int) {cout << "2 " << data++ << endl; A* b = new A; return *b;}
    A& operator--( ) {cout << "3 " << ++data << endl; A* b = new A; return *b;}
    A& operator--(int) {cout << "4 " << --data << endl; A* b = new A; return *b;}
    A operator+(A& b) { data++; return --b;}
    ~A( ){ }
};
class B {
public:
    virtual void f(A& c, int d = 2) = 0;
};
class C : public A, public B {
public:
    void f(A& c, int d = 5) { A a; A b=a+c; data+=d--;};
};
void f(int i)
{
    C f;
    f.f(f,i%2);
    cout << data << endl;
    switch (i) {
        case 1: throw 1.2f; break;
        case 2: throw 3.2; break;
        case 3: throw A(); break;
        case 4: throw C(); break;
    }
}
int main()
{
    A i;
    B *j = new C();
    C l;
    int k = 1;
    f:
    try {
        for (; k<5; k++) f(k);
    }
    catch (A) {cout << "B";--i;}
    catch (C) {cout << "A";--i;}
    catch (double) {cout << "I";i--;}
    catch (float ) {cout << "L";++i;}
    if (k++<4) goto f;
    cout<<data;
    return (int)0;
}