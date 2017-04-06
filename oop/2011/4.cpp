//
// Created by rols on 4/6/17.
//

#include <iostream>
using namespace std;
int id = 0;
class CrAde {

public:
    CrAde():objectID(id) { id = 1;}
    CrAde(int objectNumber) {
        objectID = objectNumber;
        cout << objectID << " conC&D" << endl;
    }
    ~CrAde() {cout << objectID << " desC&D" << endl;}

private:
    int objectID;
};

void create( void );

CrAde a(id++);
static CrAde b(id++);
class CD1 : virtual public CrAde {
public:
    CD1( int i): CrAde(i) {CrAde b(i);}
    virtual ~CD1() {CrAde b(id++); }
};
class CD2 : virtual public CrAde {
    CrAde a;
public:
    CD2(int i) : CrAde(i) {}
    ~CD2() { cout << id << " desC&D" << endl; CrAde b(id++); }
};
class CD3 : public CD1, virtual public CrAde, public CD2 {
public:
    CD3(int i) : CD1(i), CD2(i), CrAde(i) { static CrAde a(id++);}
    ~CD3() {cout << id << " desC&D" << endl; }
};

int main( ) {
    CrAde b(id++);
    CD3 a(id++);
    static CrAde c(id++);
    create();
}
void create( void ) {
    static CrAde b(id++);
    CrAde c(id++);
}