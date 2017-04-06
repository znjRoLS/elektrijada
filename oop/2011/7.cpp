//
// Created by rols on 4/6/17.
//

#include <iostream>
using namespace std;
template <class T>
class EVector {
    int n, sz;
    T *ar;
public:
    EVector<T>(int no) { ar = new T[++no]; n=no; sz=0; };
    ~EVector<T>() { delete[] ar; };
    EVector<T>* clear() { for(int i=0; i<n; i++) ar[i]=T(); return this; };
    void insert(T el) { ar[++sz] = el; };
    bool operator < (const EVector<T>& bTree) { return ar[1] < bTree.ar[1]; };
    bool operator > (const EVector<T>& bTree) { return ar[1] > bTree.ar[1]; };
    void copy(EVector<T>* vec, bool mode) {
        int level = 0;
        int start = 1;
        int tmp = mode ? 3 : 2;
        while (level < vec->sz) {
            for (int part=start; part<start<<1; part++) {
                ar[tmp+part-start] = vec->ar[part];
            }
            level++;
            start <<= 1;
            tmp *= 2;
        }
        sz = max(sz, vec->sz + 1);
        if (mode) ar[1] = ar[2] + ar[3];
    };
    int inverse(T& val, int tmp, int& res) {
        int ret = 0;
        if (tmp > n || ar[tmp] == T()) { return 0; };
        if (ar[tmp] == val) { return 1; };
        if (ret += inverse(val, 2*tmp, res)) {
            res <<= 2; res = res | 0x1; return ++ret; }
        if (ret += inverse(val, 2*tmp+1, res)) {
            res <<= 2; res = res | 0x2; return ++ret; }
        return false;
    }
};
template <class T>
class EMatrix {
    int n, sz;
    EVector<T> **ar;
public:
    EMatrix(int no) { ar = new EVector<T>*[++no]; n=no; sz=0; };
    ~EMatrix() { delete[] ar; };
    bool isEmpty(){ return sz == 0; };
    void inverse(T val) {
        int res = 0;
        int inv = ar[1]->inverse(val, 1, res);
        while (inv != 0 && res > 0) {
            cout << ((res & 0x3) - 1);
            res >>=2;
        }
        cout << " " << inv << endl;
    };
    void create(T values[], int n) {
        EVector<T> *el;
        ar[0] = NULL;
        for (int i=0; i<n; i++) {
            el = new EVector<T>(8*n);
            el->insert(values[i]);
            write(el);
        }
    }
    void write(EVector<T> *el) {
        int tmp = ++sz;
        while (tmp > 1 && (*ar[tmp/2] > *el)) {
            ar[tmp] = ar[tmp/2];
            tmp /= 2;
        }
        ar[tmp] = el;
    }
    EVector<T>* read() {
        EVector<T>* res = ar[1];
        EVector<T>* last = ar[sz];
        ar[sz--] = NULL;
        long tmp = 1;
        while (2 * tmp < sz + 1) {
            long next = 2 * tmp;
            if (next + 1 < sz + 1 && *ar[next+1] < *ar[next])
                next++;
            if (!(*last > *ar[next])) break;
            ar[tmp] = ar[next];
            tmp = next;
        }
        ar[tmp] = last;
        return res;
    }
    void process() {
        EVector<T> *tmp = new EVector<T>(8*n);
        while (sz > 1) {
            EVector<T> *p1 = read();
            EVector<T> *p2 = read();
            tmp->copy(p1, false);
            tmp->copy(p2, true);
            write(tmp);
            tmp = p1->clear();
            delete p2;
        }
        delete tmp;
    }
};
class Point {
    int x, y;
public:
    Point() { x = -1; y = 0; };
    Point(int k, int v) { x = k; y = v; };
    bool operator < (const Point& ass) { return y < ass.y; };
    bool operator > (const Point& ass) { return y > ass.y; };
    bool operator == (const Point& ass)
    { return x == ass.x && (x != -1 || y == 0); };
    const Point operator + (const Point& ass)
    { Point res; res.x=-1; res.y=y+ass.y; return res; };
};
void main() {
    const int n = 8, m = 12;
    unsigned char e[] = { 0x16, 0x25, 0x4B, 0x72, 0x82, 0xAB, 0xD9, 0xE5 };
    unsigned char f[] = { 0xA2, 0x45, 0xCD, 0x38, 0x59, 0xFB, 0x84, 0x24,
                          0x7A, 0x0F, 0x15, 0xBD };
    Point a[8], b[12];
    for (int i=0; i<n; i++)
        a[i] = Point(e[i]&0xE0, e[i]&0x1F);
    for (int i=0; i<m; i++)
        b[i] = Point(f[i]&0xE0, f[i]&0x1F);
    EMatrix<Point> mat(n);
    mat.create(a, n);
    mat.process();
    for (int i=0; i<m; i++)
        mat.inverse(b[i]);
}