//
// Created by rols on 4/6/17.
//

#include <iostream>
using namespace std;
int id = 0;
class ClassA {

public:
    ClassA() { id = 1;}
    ClassA(int objectNumber) {
        objectID = objectNumber;
        cout << objectID << " constructor" << endl;
    }
    ~ClassA() { cout << id << " destructor" << endl;}
private:
    int objectID;
};

static void create( void );

static ClassA a(id++);
class CD1 : virtual public ClassA {
public:
    CD1(): ClassA(id) {ClassA b(id);}
    ~CD1() {ClassA b(id++); }
};
class CD2 : public ClassA {
    CD1 a;
public:
    CD2(int i) : ClassA(i) {}
    virtual ~CD2() { ClassA b(id++); }
};
class CD3 : virtual public CD1, public CD2 {
public:
    CD3(int i) : CD1(), CD2(i) { static ClassA a(i);}
};

void main( ) {
    ClassA b(id++);
    static ClassA c(id++);
    CD3 a(id);
    create();
    ClassA f(id++);
}
void create( void ) {
    ClassA a(id++);
    static CD2 b(id++);
    CD1 c;
}