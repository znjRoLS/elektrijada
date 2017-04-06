//
// Created by rols on 4/6/17.
//

#include <iostream>
using namespace std;
class Kop{
public:
    int x;
    Kop(){x = 3;}
    virtual int a();
    int b();
    void operator() (Kop& x);
    bool operator|| (Kop& rh) {
        return (x-- >= (rh.x)++) || (--x > (rh.x)++);
    }
};
int Kop::a(){cout << this->x << "KopA\n"; return b();}
int Kop::b(){cout << x << "KopB\n"; return this->x;}
void Kop::operator() (Kop& x){
    this->x = x.a() * x.b();
    cout << this->x << endl;
}
class Jada: public Kop{
public:
    int a();
    int b();
};
int Jada::a(){ cout << "JadaA\n";return b()*100;}
int Jada::b(){ cout << "JadaB\n";return this->x * 10;}
int main(){
    Kop obj;
    Jada obj1;
    Kop *d = new Jada();
    obj.a(); d->a(); obj.b();
    if (obj || obj1)
        obj.x = (obj.x)++*--(obj1.x);
    d->b(); obj(*d); (*d)(obj);
    return 0;
}