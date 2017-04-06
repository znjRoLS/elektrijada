//
// Created by rols on 4/6/17.
//

#include <iostream>
using namespace std;
#define NN 8
class Item {
public:
    int x, y;
    Item() { x = 0; y = 0; };
    Item(int xx, int yy) { x = xx; y = yy; };
    void Print() { cout << x << " " << y << endl; };
    bool operator <(const Item& it) {
        return x < it.x || y < it.y;
    };
    Item operator +(const Item& it) {
        Item itsum(x + it.x, y + it.y);
        return itsum;
    };
};
template<class D, int n>
class Node {
public:
    D data, ref;
    int count, size;
    Node *link[n];
    Node() {
        data = D(); count = 0;
        for (int i=0; i<n; i++) { link[i] = NULL; }
    };
    Node(D r, int sz) {
        data = D(); ref = r; size = sz; count = 0;
        for (int i=0; i<n; i++) { link[i] = NULL; }
    };
    bool IsEmpty() { return count == 0; };
    void Update(D d) { data = d; count++; };
    Node<D,n>* Find(D d) {
        Node<D,n> *ptr = NULL;
        if (d < ref || ref+Item(size,size) < d)
            ptr = NULL;
        else if (link[0] == NULL)
            ptr = this;
        else
            for (int i=0; ptr==NULL && i<n; i++)
                ptr = link[i]->Find(d);
        return ptr;
    };
    void Split() {
        for (int i=0; i<n; i++) {
            Item it( (i & 0x1) * size/2, ((i & 0x2) >> 1) * size/2);
            link[i] = new Node<D,n>(ref+it, size/2);
        }
        Node<D,n>* ptr = Find(data);
        count--;
        ptr->Update(data);
    };
    void Traverse(int start) {
        if (link[0] == NULL) {
            if (count > 0)
                data.Print();
        } else {
            int delta = (start & 0x1) ? -1 : 1;
            int tmp = start++;
            for (int i=0; i<n; i++, tmp+=delta)
                link[tmp&0x3]->Traverse(start);
        }
    };
};
template<class D, int n>
class Container {
public:
    Node<D, n> *first;
    int size, count;
    Container(int sz) { size = sz; count = 0; first = NULL; };
    void Create(D data) {
        if (first == NULL) {
            first = new Node<D,n>(Item(0,0), size);
            first->Update(data);
        } else {
            Node<D,n> *ptr = first->Find(data);
            while (!ptr->IsEmpty()) {
                ptr->Split();
                ptr = ptr->Find(data);
            }
            ptr->Update(data);
        }
        count++;
    };
    void Traverse(int start) {
        first->Traverse(++start);
    };
};
int main(int argc, char* argv[]) {
    Item ar[] = { Item(1, 2), Item(12,3), Item(11,15), Item(6,2),
                  Item(10,11), Item(5,10), Item(14,15), Item(9,13)};
    int base[] = {2, 3, 5, 7};
    Container<Item, 4> con(2*NN);
    for (int i=0; i<NN; i++) {
        con.Create(ar[i]);
    }
    con.Traverse(0);
    return (int)0;
}