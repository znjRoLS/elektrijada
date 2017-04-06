//
// Created by rols on 4/6/17.
//

#include <iostream>
using namespace std;
int id = 1;
class ClassA {
public:
    ClassA() { id = 1;}
    ClassA(int objectCode) {
        objectID = 0;
        objectVAL = objectCode;
        cout << objectID << " " << objectVAL << " constructor" << endl;
    }
    ClassA(int objectNumber, int objectCode)
            : objectID(objectNumber), objectVAL(objectCode) {
        cout << objectID << " " << objectVAL << " constructor" << endl;
    }
    ClassA Print() {
        cout << objectID << " " << objectVAL << endl;
        return *this;
    }
    int getID() { return objectID; }
    int getVAL() { return objectVAL; }
    virtual ClassA funf(int i) {
        ClassA af(*this);
        af.fun(i);
        af.fun(*this);
        return af.Print();
    }
    void fun(int i) {
        objectID *= i;
    }
    virtual void fun(ClassA aa) {
        objectID += aa.objectID;
        objectVAL += aa.objectVAL;
    }
protected:
    int objectID;
    int objectVAL;
};
class ClassB : public ClassA {
public:
    ClassB(): ClassA(id) {ClassA a(id);}
    ClassB(ClassA a): ClassA(a) {ClassA aa(id);}
    ClassA funf(int i) {
        ClassA af(*this);
        af.fun(-i);
        af.fun(*this);
        return af.Print();
    }
    void fun(ClassA aa) {
        objectID -= aa.getID();
        objectVAL -= aa.getVAL();
    }
};
class ClassC : public ClassA {
protected:
    ClassA *a;
public:
    ClassC(int i) : ClassA(i) { a=new ClassA(i); }
    ClassC(ClassA aa) : ClassA(aa) { a=new ClassA(aa); }
    ClassA funf(int i) {
        ClassA af(a->funf(i*i));
        af.fun(i);
        af.fun(*this);
        return af.Print();
    }
};
class ClassD : public ClassC {
public:
    ClassD(int i) : ClassC(i) { a=new ClassB(i); }
    ClassD(ClassA aa) : ClassC(aa) { a=new ClassB(aa); }
    ClassA funf(int i) {
        ClassB af(a->funf(i*i));
        af.fun(-i);
        af.fun(*this);
        return af.Print();
    }
};
int main() {
    ClassA a(id, id+1);
    a.fun(id+1);
    a.funf(id*=2);
    ClassB b(a);
    b.fun(id);
    ClassB bb(id+1);
    bb.funf(id*=2);
    ClassC c(bb);
    c.funf(id);
    ClassD d(id*=2);
    d.funf(id/2);
    ClassD dd(c);
    dd.funf(id);
    return 0;
}