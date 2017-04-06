//
// Created by rols on 4/6/17.
//

#include <iostream>
using namespace std;
enum ShapeColor {RED, GREEN, BLUE};
class ShapeA {
public:
    virtual void draw(ShapeColor color = RED) = 0;
};
class ShapeB : public ShapeA {
public:
    virtual void draw(ShapeColor color = GREEN) {cout << "ShapeB-draw::" << color
                                                      << endl;}
};
class ShapeC : public ShapeB {
public:
    virtual void draw(ShapeColor color = BLUE) {cout << "ShapeC-draw::" << color <<
                                                     endl;}
};
int main(int argc, char argv[])
{
    ShapeA *ps2 = new ShapeC;
    ShapeA *ps3 = new ShapeB;
    ps2->draw(RED);
    ps3->draw(BLUE);
    ps3->draw();
    ps2->draw();

    return 0;
}