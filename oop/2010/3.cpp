//
// Created by rols on 4/6/17.
//

#include <iostream>
static int b;
class C {
    int *pi;
public:
    int a;
    int c;
    C(){b=0;};
    C(int i) : pi(new int(i)), c(b), a(b++) { b++; }
    C(const C &C) : pi(new int(*C.pi)){b*=3;}
    C& operator= (const C&);
    ~C() {delete pi;}
};
C& C::operator= (const C& C) {
    if (this != &C) {
        delete pi;
        pi = new int(*C.pi);
    };
    return *this;
}
C funF(C Ca)
{
    C Cnew(5);
    Ca = Cnew;
    std::cout << b << Cnew.a << Cnew.c ;
    return Ca;
}
void g() {
    C Ca=4, Cb=2;
    C Cc = Ca;
    Ca = funF(Cb);
    Cc = Ca;
}
int main(int argc, char* argv[])
{
    b=3;
    C d();
    C d1 = C(4);
    g();
    std::cout << b << d1.a << d1.c << std::endl;
    exit(0);
}