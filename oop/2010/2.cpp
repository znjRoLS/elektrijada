//
// Created by rols on 4/6/17.
//

#include <iostream>
using namespace std;
int id = 0;
class CandD {

public:
    CandD() { id = 1;}
    CandD(int objectNumber) {
        oID = objectNumber;
        cout << oID << " Canj" << endl;
    }
    ~CandD() { cout << id << " 2010" << endl;}
private:
    int oID;
};

void gen( void );

CandD a(id++);
class CD1 : virtual public CandD {
public:
    CD1( int i): CandD(i) {CandD b(i);}
    ~CD1() {CandD b(id++); }
};
class CD2 : virtual public CandD {
    CandD a;
public:
    CD2(int i) : CandD(i) {}
    virtual ~CD2() { CandD b(id++); }
};
class CD3 : virtual public CD1, public CD2 {
public:
    CD3(int i) : CD1(i), CD2(i) { static CandD a(i);}
};

void main( ) {
    CandD b(id++);
    static CandD c(id++);
    CD3 a(id);
    gen();
    CandD f(id++);
    exit(0);
}
void gen( void ) {
    CandD a(id++);
    static CandD b(id++);
    CandD c(id++);
}