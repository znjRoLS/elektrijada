//
// Created by rols on 4/6/17.
//

#include <iostream>
using namespace std;
int dat=1;
class StariVek;
class B {
public:
    B() { cout<<"2012"<<endl; };
    virtual void f(int d=5)=0;
    ~B(){ cout <<"day"<<endl;};
};
class A {
    unsigned i;
public:
    int pod;
    A& operator++() { cout << "A " << pod-- << dat++ << endl; A* b = new A;
        return *b;}
    A& operator++(int) { cout << "B " << pod++ << dat-- << endl; A* b = new A;
        return *b;}
    A& operator--() { cout << "C " << dat++ << ++pod << endl; A* b = new A;
        return *b;}
    A& operator--(int) { cout << "D " << dat--<< --pod << endl; A* b = new A;
        return *b;}
    void operator+(A& b) { pod++;}
    friend void B::f(int);
    A() : i(0), pod(dat) {pod++; cout << "Kranev" << endl;}
    ~A(){pod++; cout << "Have ";}
};
const StariVek& returnPraistorija(const StariVek& p) { return p; }
class StariVek : public A, public B {
public:
    void f(int d=2){ A c; c++; pod*=d--;}
    StariVek(){cout << "EL" << endl;}
    ~StariVek(){cout << "a nice ";}
};
StariVek returnStariVek(StariVek s){ return s; }
class ModernoDoba : public StariVek {
public:
    ModernoDoba(){cout << "enjoy" << endl;}
    ~ModernoDoba(){cout << "party time" << endl;}
};
StariVek returnModernoDoba(StariVek s) { return s; }
int main(int argc, char* argv[])
{
    ModernoDoba x;
    A v,w;
    B *c = new StariVek;
    --++v--+++w--;
    ++--++v+++w--;
    returnModernoDoba(returnStariVek(returnModernoDoba(returnPraistorija(x))));
    return int(0);
}