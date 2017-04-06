//
// Created by rols on 4/6/17.
//

#include <iostream>
using namespace std;
class A {
public:
    virtual int addition (int a, int b) { cout << "A"; return (a+b); }
    int subtraction (int a, int b) { cout << "B";return (a-b); }
};
class B : public A {
public:
    int addition (int a, int b) { cout << "D"; return (a+2*b); }
    virtual int subtraction (int a, int b) { cout << "E";return (a-b); }
};
int main ()
{
    A *a = new B();
    B *b = new B();
    cout << a ->addition(a ->subtraction(5, 4), b->addition(a->addition(1,2),b->subtraction(3,2))) << endl;
    return 0;
}