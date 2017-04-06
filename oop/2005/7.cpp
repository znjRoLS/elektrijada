//
// Created by rols on 4/6/17.
//

#include <iostream>
using namespace std;
int n = 3, h0 = 512, equalCoo = 0;
static int mX,mY,mH;
class DrawA;
class DrawB;
class DrawC;
class DrawD;
void equal(){if(mX == 128) {equalCoo++;cout << mY << endl;}}
class DrawA {
public:
    void drawA(int);
};
class DrawB {
public:
    void drawB(int);
};
class DrawC {
public:
    void drawC(int);
};
class DrawD {
public:
    void drawD(int);
};
void DrawA::drawA(int i) {
    if(i==0) return;
    drawA(i-1); mX+=mH; mY-=mH; equal();
    DrawB b; b.drawB(i-1); mX+=2*mH; equal();
    DrawD d; d.drawD(i-1); mX+=mH; mY+=mH; equal();
    drawA(i-1); equal();
};
void DrawB::drawB(int i) {
    if(i==0) return;
    drawB(i-1); mX-=mH; mY-=mH; equal();
    DrawC c; c.drawC(i-1); mX-=2*mH; equal();
    DrawA a; a.drawA(i-1); mX+=mH; mY-=mH; equal();
    drawB(i-1); equal();
}
void DrawC::drawC(int i) {
    if(i==0) return;
    drawC(i-1); mX-=mH; mY+=mH; equal();
    DrawD d; d.drawD(i-1); mX-=2*mH; equal();
    DrawB b; b.drawB(i-1); mX-=mH; mY-=mH; equal();
    drawC(i-1); equal();
};
void DrawD::drawD(int i) {
    if(i==0) return;
    drawD(i-1); mX+=mH; mY+=mH; equal();
    DrawA a; a.drawA(i-1); mX+=2*mH; equal();
    DrawC c; c.drawC(i-1); mX-=mH; mY+=mH; equal();
    drawD(i-1); equal();
};
int main(int arqc, char* argv[])
{
    int mH = h0 / 4, x0 = 2*mH, y0 = 3*mH, i = 0;
    int brprolaza = 0;
    while(i!=n){
        i++;
        x0-=mH;
        mH=mH/2;
        y0+=mH;
        mX=x0;
        mY=y0;
        DrawA A;
        A.drawA(i);
        mX+=mH;
        mY-=mH;
        DrawB B;
        B.drawB(i);
        mX-=mH;
        mY-=mH;
        DrawC C;
        C.drawC(i);
        mX-=mH;
        mY+=mH;
        DrawD D;
        D.drawD(i);
        mX+=mH;
        mY+=mH;
    }
    cout << equalCoo << endl;
    return 0;
}