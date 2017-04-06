//
// Created by rols on 4/6/17.
//

#include <iostream>
using namespace std;
int mData = 20;
class UPInt {
public:
    UPInt& operator++() {cout << mData-- <<endl; UPInt* p = new UPInt; return *p;}
    const UPInt operator++(int) {cout << mData++ << endl; return *this;}
    UPInt& operator--() {cout << ++mData << endl; UPInt* p = new UPInt; return *p;}
    const UPInt operator--(int) {cout << mData-- << endl; return *this;}
    UPInt& operator+=(int);
};
void main() {
    UPInt i;
    UPInt j;
    ++i;
    j++;
    --j;
    i++;
    --i;
    ++j;
    j--;
    i--;
}