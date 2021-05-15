//
// Created by Bojan Roško on 5/22/17.
//

#include <stdio.h>

int funk(int a, int b) {
  printf("funkab %d %d\n", a, b);
  return 5;
}


int a() {
  printf("im first\n");
  return 2;
}

int b(){
  printf("no im first\n");
  return 3;
}



int main () {



  int i = 2;

  int j = 3;

  printf("what is funk %d %d", funk(a(), b()), funk(i++, ++j));

  i = 2;
  j = 3;

  printf("uh %d\n", i += i = a() + b() + i++);

  i = 4;
  i = i++;
  printf("%d\n",i);


  i = funk(i++, i++) + i++;
  printf("%d\n",i);

  printf("%d\n", (a(),b()));

}