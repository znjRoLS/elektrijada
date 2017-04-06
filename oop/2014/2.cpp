//
// Created by rols on 4/6/17.
//

#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#define d -0.00126448926734961868021375957764
using namespace std;
double a = 0, r = 1, grrr = 22, devider = 8;
int n = 3, h0 = 256, equalCoo = 073;
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
    double elektrijada;
};
Draw::Draw(bool ord) : mOrd(ord) {};
void Draw::draw(int i, Draw &some){
    double x, y;
    if (i > 0){
        cout<<fixed<<setprecision(3)<<a<<" "<<r<<"="<<
            ((r*cos(a)<0.00001&&r*cos(a)>-0.00001)?0:r*cos(a))
            <<"|"<<((r*sin(a)<0.00001&&r*sin(a)>-0.00001)?0:r*sin(a))<<endl;
        if(mOrd){
            r = sqrt((r *cos(a) + elektrijada*cos(mSigned+grrr))
                     * (r *cos(a) + elektrijada*cos(mSigned+grrr))
                     + (r*sin(a)+elektrijada*sin(mSigned+grrr))
                       * (r*sin(a)+elektrijada*sin(mSigned+grrr)));
            r = fabs(r-1)<0.00001?1:r;
            x = (r *sin(a)+elektrijada*sin(mSigned+grrr));
            y = (r *cos(a) + elektrijada*cos(mSigned+grrr));
        }else{
            r = sqrt((r*cos(a)+elektrijada*cos(mSigned))
                     * (r*cos(a)+elektrijada*cos(mSigned))
                     + (r *sin(a)+elektrijada*sin(mSigned))
                       * (r *sin(a)+elektrijada*sin(mSigned)));
            r = fabs(r-1)<0.00001?1:r;
            x = (r *sin(a)+elektrijada*sin(mSigned));
            y = (r *cos(a) + elektrijada*cos(mSigned));
        }
        a = fabs(y)<0.00001 ?
            (x>0?1:-1)*grrr/2 : (y<0?grrr/2:0) + (y<0?grrr/2:0) + atan(x/y);
        a+=2*grrr;
        a-=(2*grrr)*(int)(a/2/grrr);
        some.mainDraw(i-1);
    }
}
class DrawA : public Draw{
public:
    DrawA(bool ord) : Draw(ord){ mSigned = grrr/devider;
        elektrijada = 2*cos(3*mSigned);}
    void mainDraw(int level);
};
class DrawB : public Draw{
public:
    DrawB(bool ord) : Draw(ord){mSigned = 3*grrr/devider;
        elektrijada = 2*cos(mSigned); }
    void mainDraw(int level);
};
class DrawC : public Draw{
public:
    DrawC(bool ord) : Draw(ord){mSigned = 5*grrr/devider;
        elektrijada = 2*cos(3*mSigned/5); }
    void mainDraw(int level);
};
class DrawD : public Draw{
public:
    DrawD(bool ord) : Draw(ord){mSigned = 7 * grrr/devider;
        elektrijada = 2*cos(3*(grrr-mSigned));}
    void mainDraw(int level);
};
void DrawA::mainDraw(int level){if((level+3)&010){DrawB b(false);draw(level, b);}
    else{DrawB c(true);draw(level, c);}}
void DrawB::mainDraw(int level){if((level+3)&010){DrawC c(false);draw(level, c);}
    else{DrawC f(true);draw(level, f);}}
void DrawC::mainDraw(int level){if((level+3)&010){DrawD a(false);draw(level, a);}
    else{DrawD b(true);draw(level, b);}}
void DrawD::mainDraw(int level){if((level+3)&010){DrawA a(true);draw(level, a);}
    else{DrawA b(true);draw(level, b);}}
int main(int argc, char* argv[]){
    int step = 0, hlen = h0, x0 = hlen / 2, y0 = x0, i = 0;
    i +=011;
    grrr = grrr/(i-2)+d;
    a = grrr-grrr/2+grrr;
    DrawA A(false);
    A.mainDraw(--i);
    cout << equalCoo << endl;
    return 0;
}