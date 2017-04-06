//
// Created by rols on 4/6/17.
//

#include <iostream>
using namespace std;
int data = 0;
class A {
public:
    A( ){data++;}
    A& operator++( ) {cout << "1 " << data-- << endl; A* b = new A; return *b;}
    int operator++(int) {cout << "2 " << data++ << endl; A* b = new A; return --
                data;}
    int operator--( ) {cout << "3 " << ++data << endl; A* b = new A; return data++;}
    A& operator--(int) {cout << "4 " << --data << endl; A* b = new A; return *b;}
    int operator+(A& b) { data++; return data;}
    A& operator-(A& b) { data++; return ++b;}
    ~A( ){ }
};
int operator+(A a, int k) {cout << "operator+(int,A)ext" << endl; return a+a ;}
A& operator+ (int k, A a) {cout << "operator+(A,int)ext" << endl; return a-a; }
A& operator-(int a, A k) {cout << "operator-(int,A)ext" << endl ; return k-k; }
int operator- (A k, int a) {cout << "operator-(A,int)ext" << endl; return data+1; }
int main()
{
    A a, b;
    ++a---b+++b---++a;
    ++a---b+(++b-(--++a));
    return (int)0;
}