//
// Created by rols on 4/6/17.
//

#include "stdio.h"
class BaseClass {
    int id;
public:
    BaseClass() { printf("BaseClass()\n"); }
    virtual ~BaseClass() { printf("~BaseClass()\n"); }
};
class Class1 : public BaseClass
{
    int id;
public:
    Class1() { printf("Class1()\n"); }
    ~Class1() { printf("~Class1()\n"); }
};
class Class2 : public Class1
{
    BaseClass id;
public:
    Class2() { printf("Class2()\n"); }
    ~Class2() { printf("~Class2()\n"); }
};
class Class3 : virtual public BaseClass
{
    int id;
public:
    Class3() { printf("Class3()\n"); }
    ~Class3() { printf("~Class3()\n"); }
};
class Class4 : public Class3, virtual public Class1
{
    Class3 id;
public:
    Class4() { printf("Class4()\n"); }
    ~Class4() { printf("~Class4()\n"); }
};
int main(int argc, char* argv[])
{
    BaseClass *p = new Class2;
    Class2 *p1 = new Class2;
    Class3 *p2 = new Class3;
    delete p;
    delete p1;
    delete p2;
    return 0;
}