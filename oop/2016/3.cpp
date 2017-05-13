//
// Created by rols on 5/13/17.
//

#include <iostream>

#include <iomanip>

using namespace std;

class A {

public:

    A(){X=9;A1=A2=NULL;}

    A(int x){X=x;A1=A2=NULL;}

    int X;

    A *A1, *A2;

    virtual void Drive();

};

void A::Drive() {

    cout << X * X << " ";

    if(A1!=NULL) A1->Drive();

    if(A2!=NULL)(*A2).Drive();

}

class B : public A {

public:

    B(int x):A(x){A* t;t=A1;A1=A2;A2=t;}

    virtual void Drive();

};

void B::Drive() {

    if(A1!=NULL)A1->Drive();

    cout << X * X << " ";

    if(A2!=NULL)A2->Drive();

}

class C : public A {

public:

    C(int x):A(x){}

    virtual void Drive();

};

void C::Drive() {

    if(A2!=NULL)A2->Drive();

    if(A1!=NULL)A1->Drive();

    cout << X * X << " ";

}

int main() {

    A* a[10], *t = NULL;

    for(int i = 0; i<10; i++) {

        switch(i%3) {

            case(0): a[i] = new A(i); break;

            case(1): a[i] = new B(i); break;

            case(2): a[i] = new C(i); break;

            default: a[i] = NULL; break;

        }

        if(t==NULL) t = new A();

        switch(i%2)

        {

            case(1): t->A2 = a[i]; t = a[i/2]; break;

            default: t->A1 = a[i]; break;

        }

    }

    a[0]->Drive();

    return 0;

}

Task 4. What is the output