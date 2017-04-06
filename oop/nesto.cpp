//
// Created by rols on 4/6/17.
//

#include <iostream>

using namespace std;

void f()
{



    cout << "hehe" << endl;
}

class A
{

public:
    A(){cout << "const a" << endl;}
    A(const A&){cout << "copy const a" << endl;}
    A(A&&){cout << "move const a" << endl;}
    ~A(){cout << "dest a" << endl;}

};

class B : virtual public A
{

public:
    B(){cout << "const b" << endl;}
    ~B(){cout << "dest b" << endl;}

};

class C: public A
{

public:
    C(){cout << "const c" << endl;}
    ~C(){cout << "dest c" << endl;}


};


class D: public B, virtual public A, virtual public C
{

public:
    D(){static A c; cout << "const d" << endl;}
    ~D(){cout << "dest d" << endl;}
    void operator--(int){}
};



A mlatka(A edesi)
{
    cout << "maltka" << endl;
    A v;
    return v;
}


class O
{

public :
    virtual int a()
    { cout << " ao" << endl; return 1;}

    int b()
    {a(); cout << "bo after a" << endl; return 10;}
};

class I: public O
{
public:
    int a ()
    {cout << "ai" << endl; return 100;}

    int b()
    {a(); cout << "bi after a" << endl; return 1000;}


};

class U : public I
{
public:
    int a()
    {cout << "au" << endl; return 10000;}
};



int main()
{

    D d;
    D e;

    int g = 2;
    int h = 3;
    cout << g++ + ++h << endl;


    //A b;
    //A a = mlatka(b);

    cout << "jjeeeje" << endl;


    O o;
    I i;
    O *po = &i;
    I *pi = (I*)&o;

    o.b();
    i.b();
    po->b();
    pi->b();

    U u;
    O *ou = &u;
    u.a();
    ou->a();

    return 0;

}
