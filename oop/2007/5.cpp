//
// Created by rols on 4/6/17.
//

#include <iostream>
using namespace std;
class A
{
public:
    float x;
public:
    A(): x(1){}
    void f(int i) { x+=i; cout << "asd";}
    virtual void f(float i) { x*=i; cout << "aca"; }
    void f1(int i) {x*=i+2;}
    void f1(int i, float j) { x*=i*j; cout << "bcs" << endl;}
    virtual void f1(float i, float j) {x-=i*j; cout << "ort" << endl;}
};
class B : public A
{
public:
    void f(float) { f1(2,3); x = x * 10; cout << "swe" ;}
    void f1(float i, float j = 4) {x-=i*j; cout << "otk" ;}
};
int main()
{
    A a;
    B b;
    a.f(a.x);
    b.f1(2,a.x);
    b.f(1);
    b.f1(1);
    cout << a.x << endl;
    cout << b.x << endl;
}