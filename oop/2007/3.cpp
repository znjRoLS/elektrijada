//
// Created by rols on 4/6/17.
//

#include <iostream>
using namespace std;
int id = 0;
class CreateAndDestroy {

public:
    CreateAndDestroy() { id = 1;}
    CreateAndDestroy(int objectNumber) {
        objectID = objectNumber;
        cout << objectID << " constructor" << endl;
    }
    ~CreateAndDestroy() {
        cout << id << " destructor" << endl;
    }
private:
    int objectID;
};

void create( void );

CreateAndDestroy a(id++);
class CD1 : virtual public CreateAndDestroy {
public:
    CD1( int i): CreateAndDestroy(i) {CreateAndDestroy b(i);}
    ~CD1() {CreateAndDestroy b(id++); }
};
class CD2 : virtual public CreateAndDestroy {
    CreateAndDestroy a;
public:
    CD2(int i) : CreateAndDestroy(i) {}
    virtual ~CD2() { CreateAndDestroy b(id++); }
};
class CD3 : virtual public CD1, public CD2 {
public:
    CD3(int i) : CD1(i), CD2(i) { static CreateAndDestroy a(i);}
};

int main( ) {
    CreateAndDestroy b(id++);
    static CreateAndDestroy c(id++);
    CD3 a(id);
    create();
    CreateAndDestroy f(id++);
}
void create( void ) {
    CreateAndDestroy a(id++);
    static CreateAndDestroy b(id++);
    CreateAndDestroy c(id++);
}