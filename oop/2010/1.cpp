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
    void fun(int i) { x+=i; cout << "avg";}
    virtual void fun(float i) { x*=i; cout << "bga"; }
    void fun1(int i) {x*=i+2;}
    void fun1(int i, float j) { x*=i*j; cout << "otr" << endl;}
    virtual void fun1(float i, float j) {x-=i*j; cout << "osm" << endl;}
    bool operator&&( A & rh) {
        return (x++ > (rh.x)--) || (++x > (rh.x)++);
    }
};
class B : public A
{
public:
    void fun(float) { fun1(2,3); x = x * 10; cout << "canj" ;}
    void fun1(float i, float j = 4) {x-=i*j; cout << "2010" ;}
};
int main()
{
    A a;
    B b;
    b.fun1(2,a.x);
    b.fun(1);
    a.fun(a.x);
    b.fun1(1);
    if(a && b)
        a.x +=7;
    cout << a.x << b.x << endl;
    exit(0);
}