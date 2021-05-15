//
// Created by Bojan Roško on 5/22/17.
//

#include<stdio.h>

union {
  int a;
  char b;
} nekaunija;

int main() {

  nekaunija.a = 0x01020314;
  printf("%d\n", nekaunija.b);
  printf("%d\n", *(((char*)(&nekaunija.a))));
}