//
// Created by rols on 4/6/17.
//

#include "iostream"
using namespace std;
class Student;
class Person {
public:
    Person(){cout << "constructor Person" << endl;}
    ~Person(){cout << "destructor Person" << endl;}
};
const Student& returnPerson(const Student& p){return p;}
class Student : public Person {
public:
    Student(){cout << "constructor Student" << endl;}
    ~Student(){cout << "destructor Student" << endl;}
};
Student returnStudent(Student s){ return s;}
class PhDStudent : public Student {
public:
    PhDStudent(){cout << "constructor PhDStudent" << endl;}
    ~PhDStudent(){cout << "destructor PhDStudent" << endl;}
};
Student returnPhDStudent(Student s){ return s; }
int main(int argc, char* argv[])
{
    PhDStudent laza;
    returnPhDStudent(returnStudent(returnPerson(laza)));
}