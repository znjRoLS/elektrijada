//
// Created by Bojan Roško on 5/22/17.
//

#include <stdio.h>
#include <stdlib.h>

int main() {
  char s;
  char s1[] = {'a', 'b', 'c'};
  int arr[] = {1,2,3,4};
  int arr1[10] = {1,2,3,4};
  int *arr2;

  arr2 = (int*)malloc(sizeof(int) * 5);

  int arr3[7][8];
  int *arr4[10];

  printf("%d\n",sizeof(s));
  printf("%d\n",sizeof(s1));
  printf("%d\n",sizeof(arr));
  printf("%d\n",sizeof(arr1));
  printf("%d\n",sizeof(arr2));
  printf("%d\n",sizeof(arr3));
  printf("%d\n",sizeof(arr4));
  printf("%d\n",sizeof(char *));
}