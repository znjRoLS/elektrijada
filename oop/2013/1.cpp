//
// Created by rols on 4/6/17.
//

#include <iostream>
#include <iomanip>
#include <math.h>
#define d -0.00126448926734961868021375957764
using namespace std;
double a = 0;
double r = 1;
double grrr = 22;
int n = 3, h0 = 256, equalCoo = 0;
static int mX,mY,mH;
class DrawA; class DrawB; class DrawC; class DrawD;
class Draw{
public:
    Draw(bool ord);
    ~Draw(){};
    void draw(int i, Draw& some);
    virtual void mainDraw(int level){};
protected:
    void equal(){if(mX == mY) {equalCoo++;cout << mX << endl;}}
    bool mOrd;
    int mLevel;
    double mSigned;
};
Draw::Draw(bool ord) : mOrd(ord) {};
void Draw::draw(int i, Draw &some){
    if (i > 0){
        cout<<setprecision(5)<<a<<" "<<r<<endl;
        if(mOrd){
            r = sqrt( (r *cos(a) + cos(mSigned))*(r *cos(a) + cos(mSigned))
                      + (r *sin(a)+sin(mSigned))*(r *sin(a)+sin(mSigned)));
            a=(a+mSigned)/2;
            some.mainDraw(i-1);
        }else{
            r = sqrt( (r *cos(a) + cos(mSigned+grrr))*(r *cos(a) + cos(mSigned+grrr))
                      + (r *sin(a)+sin(mSigned+grrr))*(r *sin(a)+sin(mSigned+grrr)));
            a=(a+mSigned+grrr)/2;
            some.mainDraw(i-1);
        }
    }
}
class DrawA : public Draw{
public:
    DrawA(bool ord) : Draw(ord){ mSigned = 0;}
    void mainDraw(int level);
};
class DrawB : public Draw{
public:
    DrawB(bool ord) : Draw(ord){mSigned = grrr/3;}
    void mainDraw(int level);
};
class DrawC : public Draw{
public:
    DrawC(bool ord) : Draw(ord){mSigned = 2 * grrr/3;}
    void mainDraw(int level);
};
void DrawA::mainDraw(int level){
    if (level&0x04){DrawC b(true);draw(level, b);}
    else{DrawC c(false);draw(level, c);}
}
void DrawB::mainDraw(int level){
    if (level&0x04){DrawA c(true);draw(level, c);}
    else{DrawA a(true);draw(level, a);}
}
void DrawC::mainDraw(int level){
    if (level&0x04){DrawB a(true);draw(level, a);}
    else{DrawB b(false);draw(level, b);}
}
int main(){
    int step = 0, hlen = h0, x0 = hlen / 2, y0 = x0, i = 0;
    i +=07;
    grrr = grrr/i+d;
    a = grrr-grrr/3+grrr;
    DrawA A(false);
    A.mainDraw(--i);
    cout << equalCoo << endl;
    return (int)0;
}