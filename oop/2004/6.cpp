//
// Created by rols on 4/6/17.
//

#include "iostream.h"
int n = 3, h0 = 256, equalCoo = 0;
static int mX,mY,mH;
class DrawA; class DrawB; class DrawC; class DrawD;
class Draw{
public:
    Draw(bool ord, int sign);
    ~Draw(){};
    void draw(int i, Draw& first, Draw& second);
    virtual void mainDraw(int level){};
protected:
    void equal(){if(mX == mY) {equalCoo++;cout << mX << endl;}}
    bool mOrd;
    int mSign;
    int mLevel;
};
Draw::Draw(bool ord, int sign) : mOrd(ord), mSign(sign) {};
void Draw::draw(int i, Draw &first, Draw &second){
    if (i > 0){
        if(mOrd){
            first.mainDraw(i-1); mX = mX - mSign * mH;equal();
            draw(i-1, first, second); mY = mY - mSign * mH;equal();
            draw(i-1, first, second); mX = mX + mSign * mH;equal();
            second.mainDraw(i-1);
        }else{
            first.mainDraw(i-1); mY = mY - mSign * mH;equal();
            draw(i-1, first, second); mX = mX - mSign * mH;equal();
            draw(i-1, first, second); mY = mY + mSign * mH;equal();
            second.mainDraw(i-1);
        }
    }
}
class DrawA : public Draw{
public:
    DrawA(bool ord, int sign) : Draw(ord, sign){}
    void mainDraw(int level);
};
class DrawB : public Draw{
public:
    DrawB(bool ord, int sign) : Draw(ord, sign){}
    void mainDraw(int level);
};
class DrawC : public Draw{
public:
    DrawC(bool ord, int sign) : Draw(ord, sign){}
    void mainDraw(int level);
};
class DrawD : public Draw{
public:
    DrawD(bool ord, int sign) : Draw(ord, sign){}
    void mainDraw(int level);
};
void DrawA::mainDraw(int level){DrawD d(false,1); DrawB b(false, -1); draw(level,d,b);}
void DrawB::mainDraw(int level){DrawC c(true, -1);DrawA a(true, 1); draw(level,c,a);}
void DrawC::mainDraw(int level){DrawB b(false,-1); DrawD d(false, 1); draw(level,b,d);}
void DrawD::mainDraw(int level){DrawA a(true,1); DrawC c(true,-1); draw(level,a,c);}
int main(int argc, char* argv[]){
    int step = 0, hlen = h0, x0 = hlen / 2, y0 = x0, i = 0;
    while(true){
        i++;
        hlen = hlen / 2;
        x0 = x0 + (hlen / 2);
        y0 = y0 + (hlen / 2);
        5
        mX = x0; mY = y0; mH = hlen;
        DrawA A(true, 1);
        A.mainDraw(i);
        if ( i == n ){
            cout << equalCoo << endl;
            return 1;
        }
    }
    cout << equalCoo << endl;
    return 0;
}