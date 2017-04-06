//
// Created by rols on 4/6/17.
//

#include <iostream.h>
#define MAXOP(a,b) a>b ? a : b
#define DIVOP(a,b) a/b
#define MNOP(a) a*a
class B;
class A {
    unsigned i;
public:
    A(unsigned);
    void foo(void) {
        cout << "\nFunction";
    }
    friend int f(A&, B&);
};
A::A(unsigned j) : i(j) { }
class B {
    unsigned i;
public:
    B(unsigned);
    void(A::*ptr)(void);
    friend int f(A&, B&);
};
B::B(unsigned j):i(j){}
int f(A& a, B& b)
{
    int x = 3;
    return MAXOP(a.i + x, x + b.i)*DIVOP(a.i + 4, 2+ b.i);
}
int main()
{
    B xx(7);
    A yy(5);
    void(A::*ptr2)(void);
    ptr2=&A::foo;
    cout << f(yy, xx);
    (yy.*ptr2)();
    xx.ptr=&A::foo;
    (yy.*(xx.ptr))();
    return 0;
}