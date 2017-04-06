//
// Created by rols on 4/6/17.
//

#include <iostream>
using namespace std;
enum Years { CCCXII, CCCXI, CCCX=310, CCCXIII=CCCX+CCCXII,
    MMXI, MMXII, MMXIII, MMX=2010 };
static int jubile;
class Opa {
    int *pi;
public:
    int x;
    enum Years year;
    int jubilee() {cout << "Constantine the Great\n"; return x; };
    virtual int province();
    int jubilee(Opa& x);
    Opa(){jubile=0; x=3; year = MMXIII;};
    Opa(int i) : pi(new int(i)) {jubile++;}
    Opa(const Opa &x) : pi(new int(*x.pi)){this->x=313;}
    Opa& operator= (const Opa&);
};
Opa& Opa::operator= (const Opa& x) {
    if (this != &x) {
        delete pi;
        pi = new int(*x.pi);
    };
    return *this;
}
int Opa::jubilee(Opa& x){
    cout << "Edict of Milan " << year; this->x = x.jubilee() * x.province();
    cout << this->x <<endl; return this->x*2;
}
int Opa::province(){cout << "Mediana\n";return this->x*200+71;}
class Repa: public Opa{
public:
    virtual int jubilee();
    int jubilee(Opa& x);
    int province();
};
int Repa::jubilee(){ cout << "Year\n";return province()*10;}
int Repa::jubilee(Opa& x){ cout << year;return x.province()*10;}
int Repa::province(){ cout << "Naissus\n";return this->x *20;}
int main(){
    Years year = CCCXIII;
    Opa viminacium();
    Opa *roman = new Repa();
    Opa celebration;
    Repa emperor;
    cout << celebration.jubilee() + celebration.jubilee(emperor) << endl;
    cout << roman->jubilee() << celebration.province() << endl;
    cout << jubile*year << endl;
    return (int)0;
}