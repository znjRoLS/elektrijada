//
// Created by rols on 4/6/17.
//

#include <iostream>
using namespace std;
template <class T>
class Array {
    T *ar;
    int n;
    void Swap(int a, int b) { T tmp=ar[a]; ar[a]=ar[b]; ar[b]=tmp; };
    int FindTarget(int a, int b);
    int Rewrite(int a, int b);
    T Write(int a, int b, int c);
public:
    void SetArray(T *arr, int nn);
    void Insert(T data);
    void Calc(int a);
    int Shift(int a);
    void Print(T val);
};
template <class T>
void Array<T>::SetArray(T *arr, int nn) {
    n = nn; ar = new T[n];
    for (int i=0; i<n; i++) ar[i] = arr[i];
}
template <class T>
void Array<T>::Insert(T data) {
    T *arr = ar;
    ar = new T[++n];
    int i;
    for (i=n-1; i>0; i--)
        if (arr[i-1] > data) { ar[i] = arr[i-1]; break; }
    ar[--i] = data;
    for (--i; i>=0; i--)
        ar[i] = arr[i];
    delete[] arr;
}
template <class T>
T Array<T>::Write(int a, int b, int c) {
    if (b == c) return ar[b];
    int d = Rewrite(b, c);
    int e = d - b + 1;
    if (a == e) return ar[d];
    else if (a < e) return Write(a, b, d-1);
    else return Write(a-e, d+1, c);
}
template <class T>
int Array<T>::FindTarget(int a, int b) {
    int tar, min=100, sum;
    for (int i=a; i<b; i++) {
        T a = ar[i] | ar[i+1];
        for (sum=0; a; a>>=1)
            sum += a & 0x1;
        if (min > sum) { min = sum; tar = i; }
    }
    return tar;
}
template <class T>
int Array<T>::Rewrite(int a, int b) {
    int c = FindTarget(a, b);
    Swap(c, b);
    T x = ar[b];
    int d, e;
    for (d=a-1, e=a; e<b; e++)
        if (ar[e] <= x) Swap(++d, e);
    Swap(++d, b);
    return d;
}
template <class T>
int Array<T>::Shift(int a) {
    T str=0;
    for (int i=0; i<a; i++)
        str += ar[i];
    return str;
}
template <class T>
void Array<T>::Print(T val) {
    for (int i=0; i<8*sizeof(T); val>>=1, i++) {
        char b = (val & 0x1) + '0';
        cout << b;
    }
    cout << endl;
}
template <class T>
void Array<T>::Calc(int a) {
    T val;
    if (a <= 1)
        val = Write(a, 0, n-1);
    else {
        Calc(a / 2);
        val = Write(a, 0, n-1);
    }
    Print(val);
}
int main () {
    char n=7, ar[] = {'g', 'D', 'Z', 'a', 'i', '5', 'l'};
    Array<char> a;
    a.SetArray(ar ,n);
    a.Calc(n/2);
    cout << a.Shift(n/2) << endl;
    a.Insert('P'); a.Insert('8');
    a.Calc(n/2+1);
    cout << a.Shift(n/2+1) << endl;
    return 0;
}