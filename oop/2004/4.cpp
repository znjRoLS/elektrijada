//
// Created by rols on 4/6/17.
//

#include <iostream>
using namespace std;
class Base
{
public:
    int x;
    Base(){x = 5;}
    virtual int a();
    int b();
    void operator() (Base& x);
};
int Base::a(){cout << "Base A\n";this
            ->x;return b();}
int Base::b(){cout << "Base B\n";return this
            ->x;}
void Base::operator() (Base& x){
    this
            ->x = x.a() * x.b();
    cout << this->x << endl;
}
class Derived: public Base{
public:
    int a();
    int b();
};
int Derived::a(){ cout << "Derived A\n";return b()*100;}
    int Derived::b(){ cout << "Derived B\n";return this
                  ->x * 10;}
    int main(){
        Base obj;
        Base *d = new Derived();
        obj.a(); d
                ->a(); obj.b();

        d
                ->b(); obj(*d); (*d)(obj);
        return 0;
    }