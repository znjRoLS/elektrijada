//
// Created by rols on 4/6/17.
//

#include <iostream>
#include <iomanip>
using namespace std;
class Derived
{
public:
    Derived(int broj);
    virtual void TillTheEnd();
protected:
    virtual Derived* Create(int broj);
    Derived* left;
    Derived* right;
    int info;
};
class Option : public Derived
{
public:
    Option(int broj);
    virtual void TillTheEnd();
protected:
    virtual Derived* Create(int broj);
};
class Sun : public Derived
{
public:
    Sun(int broj);
    virtual void TillTheEnd();
protected:
    virtual Derived* Create(int broj);
};
Derived::Derived(int broj)
{
    left = right = NULL;
    info = broj; if (broj>0) Create(broj >> 3);
}
Derived* Derived::Create(int broj)
{
    if (info & 1) right = new Option(info >> 1);
    else left = new Sun(info >> 2);
    return this;
}
void Derived::TillTheEnd()
{
    cout << "Derived: " << info<<endl;
    if (left) left->TillTheEnd();
    if (right) right->TillTheEnd();
}
Option::Option(int broj) : Derived(broj) {}
Derived* Option::Create(int broj)
{
    if (info & 1 ^ 1) right = new Sun(info >> 1);
    else left = new Derived(info >> 2);
    return left;
}
void Option::TillTheEnd()
{
    if (left) left->TillTheEnd();
    cout << "Option: " << info << endl;
    if (right) right->TillTheEnd();
}
Sun::Sun(int broj) : Derived(broj) {}
Derived* Sun::Create(int broj)
{
    if (info & 1 ^ 1) right = new Derived(info >> 1);
    else left = new Option(info >> 2);
    return left;
}
void Sun::TillTheEnd()
{
    if (left) left->TillTheEnd();
    if (right) right->TillTheEnd();
    cout << "Sun: " << info << endl;
}
int main(){
    int broj = 0x6C;
    Derived a(broj);
    a.TillTheEnd();
    return 0;
}