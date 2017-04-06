//
// Created by rols on 4/6/17.
//

#include <iostream.h>
unsigned long address = 0;
int dword = 8;
int dd = 7;
int word = 4;
int byte = 1;
class A
{
public:
    unsigned long operator+() {cout << "opA+()" << endl; return address+word;}
    unsigned long operator+(unsigned long) {cout << "opA+(ul)" << endl; return address+word;}
    unsigned long operator+(A) {cout << "op+(A)" << endl; return address+dd;}
    unsigned long operator-() {cout << "opA-()" << endl; return address-dword;}
    unsigned long operator-(unsigned long) {cout << "opA-(ul)" << endl; return address-word;}
    unsigned long operator-(A) {cout << "op-(A)" << endl; return address-dd;}
};
class B
{
public:
    unsigned long operator-() {cout << "opB-()" << endl; return address-dword;}
    unsigned long operator-(unsigned long) {cout << "opB-(ul)" << endl; return address-word;}
    unsigned long operator-(B) {cout << "op-(B)" << endl; return address-dd;}
    unsigned long operator+() {cout << "opB+()" << endl; return address+word;}
    unsigned long operator+(unsigned long) {cout << "opB+(ul)" << endl; return address+word;}
    unsigned long operator+(B) {cout << "op+(B)" << endl; return address+dd;}
};
unsigned long operator+(A a) {cout << "op+(A)ext" << endl; return address+dd+6;}
unsigned long operator+(unsigned long g, A a) {cout << "op+(ul,A)ext" << endl; return g+6;}
unsigned long operator-(A a) {cout << "op-(A)ext" << endl; return address-dd-7;}
unsigned long operator-(unsigned long g, A a) {cout << "op-(g,A)ext" << endl; return g-7;}
void main()
{
    A a, d, e, m, n;
    B g, h;
    unsigned long b, c, f;
    address = 30;
    b = 3U; c = 5U; f = 1U;
    B* i = (B*)new A();
    cout << b-e-m+b+(*i+g)+n-(a+c)+(h-(d-f)) << endl;
}