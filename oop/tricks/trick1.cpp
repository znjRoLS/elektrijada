//
// Created by Bojan Roško on 11/10/17.
//

#include <iostream>

using namespace std;

int  n = 0;

class test {
public:
  test();
  test(int testint);
  ~test();
  test(test&);
  test(test&&);

  test& operator=(const test& other);

  void intchange(int a);
private:
  int member;
};

test::test() {
  cout << "konst " << this << endl;
  n++;
  member = 0;
}

test::test(int testint) {
  cout << "konst int " << this << endl;
  n++;
  member = testint;
}

test::test(test& other) {
  cout << "konst kopi " << &other << " " << this << endl;
  n++;
}

test::test(test&& other) {
  cout << "konst move " << &other << " " << this << endl;
  n++;
}

test& test::operator=(const test& other) {
  cout << "operator = " << &other << " " << this << endl;
  n++;
  return *this;
}

test::~test() {
  cout << "destr " << this << endl;
  n++;
}

void test::intchange(int a) {
  member = a;
}

test funk2(test a) {
  return a;
}

test& funk3(test a) {
  return a;
}

test funk4(test& a) {
  return a;
}

test& funk5(test& a) {
  return a;
}

test funk6() {
  test b(3);
  b.intchange(2);
  return b;
}

test funk7() {
  return test();
}

int main (int argc, char* argv[]) {

  cout << "test 1" << endl;
  test(1);
  cout << "test 11" << endl;
  test t(1);

  cout << "test 2" << endl;
  funk2(t);
  cout << "test 22" << endl;
  test t2 = funk2(t);
  cout << "test 222" << endl;
  t2 = funk2(t);

  cout << "test 3" << endl;
  funk3(t);
  cout << "test 33" << endl;
  test t3 = funk3(t);
  cout << "test 333" << endl;
  t3 = funk3(t);

  cout << "test 4" << endl;
  funk4(t);
  cout << "test 44" << endl;
  test t4 = funk4(t);
  cout << "test 444" << endl;
  t4 = funk4(t);

  cout << "test 5" << endl;
  funk5(t);
  cout << "test 55" << endl;
  test t5 = funk5(t);
  cout << "test 555" << endl;
  t5 = funk5(t);

  cout << "test 6" << endl;
  funk6();
  cout << "test 66" << endl;
  test t6 = funk6();
  cout << "test 666" << endl;
  t6 = funk6();

  cout << "test 7" << endl;
  funk7();
  cout << "test 77" << endl;
  test t7 = funk7();
  cout << "test 777" << endl;
  t7 = funk7();

  cout << "end" << endl;

  cout << n << endl;

  return 0;
}