//
// Created by rols on 4/6/17.
//

#include <iostream>
using namespace std;
int data = 0;
class A
{
public:
    A( ){data++;}
    A& operator++( ) { cout << "1 " << data-- << endl; A* b = new A; return *b;}
    A operator++(int) { cout << "2 " << data++ << endl; A* b = new A; return *b;}
    A& operator--( ) { cout << "3 " << ++data << endl; A* b = new A; return *b;}
    A operator--(int) { cout << "4 " << --data << endl; A* b = new A; return *b;}
    void operator+(A b) { data++;}
    ~A( ){data++;}
};
class B
{
public:
    virtual void f(int d = 2) = 0;
};
class C : public A, public B
{
public:
    void f(int d = 5) { A a; a++; data+=d--;};
};
int main()
{
    A i, j;
    B *c = new C;
    --++i--+++j--;
    c->f(data);
}