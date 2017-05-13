//
// Created by rols on 5/13/17.
//

#include <iostream>

using namespace std;

class Base{

protected:

    int x;

    int id;

public:

    Base() : id(1) { x = 16; cout << "Base 16" << endl;}

    Base(int xx) : x(++xx), id(1) { cout << "Base " << x << endl;}

    Base(Base& b) : x(b.x), id(1) { cout << "Base " << x << endl;}

    Base* fun(Base& b){

        b.x += x;

        return &b;

    }

    virtual Base funf(Base b){

        x += b.x;

        return *this;

    }

};

class Derived : public Base{

    Base bb;

public:

    Derived() { cout << "Derived 16" << endl;};

    Derived(int xx) : bb(8) { cout << "Derived " << x << endl;}

    Derived(Derived& d) : bb(8) { cout << "Derived " << x << endl;}

    Base* fun(Base& b){

        x = x << id + 1 | 0x1;

        return bb.fun(b);

    }

    Base funf(Base b){

        x = x << id + 1 | 0x2;

        bb.funf(b);

        return *this;

    }

    Derived funf(Derived b){

        x = x << 2 | 0x3;

        bb.funf(b);

        return *this;

    }

};

int main()

{

    Base b;

    Derived d;

    Base *bd = new Derived();

    Derived dd(4);

    Base *bf = b.fun(dd);

    b = bf->funf(b);

    bd->fun(dd);

    d = d.funf(dd);

    return 0;

}