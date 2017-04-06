//
// Created by rols on 4/6/17.
//

#include <iostream>
#include <iomanip>
using namespace std;
template <class T1, class T2>
class Node {
public:
    T1 value;
    T2 data;
    Node<T1, T2> *prev, *par, *next;
    Node(T1 v, Node *p, Node *pr, Node *n, T2 d=T2())
            : prev(p), par(pr), next(n), value(v), data(d) { }
    void Update() {
        if (prev != NULL) prev->next = next;
        if (next != NULL) next->prev = prev;
    }
    Node<T1, T2>* Update(T2 newData) {
        Node<T1, T2> *ptr2 = NULL;
        if (prev != NULL || ptr2->prev->data > newData) {
            Update();
            for (ptr2=this; ptr2->prev!=NULL && ptr2->prev->data>newData; ptr2=ptr2->prev);
            if (ptr2->prev != NULL) ptr2->prev->next = this;
            prev = ptr2->prev;
            if (ptr2 != NULL) ptr2->prev = this;
            next = ptr2;
        }
        data = newData;
        return this;
    }
};
template <class T1, class T2>
class Content {
    Node<T1, T2> *first;
public:
    Content() : first(NULL) { }
    bool Empty() { return first == NULL; }
    void Add(Node<T1, T2> *node, T2 data) {
        Node<T1, T2> *ptr = first;
        if (ptr != NULL && ptr->data < data) {
            for ( ; ptr->next != NULL && ptr->next->data < data; ptr = ptr->next);
            Node<T1, T2> *ptrNew = new Node<T1, T2>(0, ptr, node, ptr->next, data);
            if (ptr->next != NULL) ptr->next->prev = ptrNew;
            ptr->next = ptrNew;
            node->prev = ptrNew;
        } else {
            first = new Node<T1, T2>(0, NULL, node, first, data);
            node->prev = first;
        }
    }
    Node<T1, T2>* Get() {
        Node<T1, T2> *ptr = first;
        first = first->next;
        return ptr;
    }
    bool Update(Node<T1, T2>* ptr) {
        if (ptr->next == first) first = ptr;
        return first == ptr;
    }
    Node<T1, T2>* Set(Node<T1, T2>* ptr) {
        ptr->next = first;
        ptr->prev = NULL;
        if (first) first->prev = ptr;
        return first = ptr;
    }
    void Print() {
        for (Node<T1, T2> *ptr = first; ptr != NULL; ptr = ptr->next)
            cout << ptr->data << " - " << ptr->par->value << endl;
        cout << endl;
    }
};
template <class T1, class T2>
class Collection {
    Node<T1, T2> *base;
    void Change(Content<T1, T2> &conn1, Content<T1, T2> &conn2, Node<T1, T2> *ptr1,
                T2 data, bool bFirst) {
        for (Node<T1, T2> *ptr2 = ptr1->par; ptr2 != NULL; ptr2 = ptr2->par) {
            int newData = data + ptr2->data + ptr2->next->data;
            if (bFirst && ptr2->next->prev == NULL) {
                conn1.Add(ptr2->next, newData);
            } else if (ptr2->next->prev->data > newData) {
                Node<T1, T2>* res = ptr2->next->prev->Update(newData);
                if (!conn1.Update(res))
                    conn2.Update(res);
                Change(conn1, conn2, ptr2->next, ptr2->next->prev->data-ptr2->next->data, false);
            }
        }
    }
public:
    Collection() : base(NULL) { }
    void Read(T1 *ar1, T2 *ar2, int n) {
        Node<T1, T2> **arCorr = new Node<T1, T2>*[n];
        for (int i=0; i<n; i++)
            arCorr[i] = NULL;
        for (int i=0; i<n; i+=3) {
            if (arCorr[ar1[i]] == NULL)
                arCorr[ar1[i]] = new Node<T1, T2>(ar1[i], NULL, NULL, NULL);
            if (arCorr[ar1[i+1]] == NULL)
                arCorr[ar1[i+1]] = new Node<T1, T2>(ar1[i+1], NULL, NULL, NULL);
            arCorr[ar1[i]]->par = new Node<T1, T2>(0, NULL, arCorr[ar1[i]]->par,
                                                   arCorr[ar1[i+1]], ar1[i+2]);
        }
        for (int i=1; i<n && arCorr[i] != NULL; i++) {
            arCorr[i]->next = arCorr[i+1];
            arCorr[i]->data = ar2[i-1];
        }
        base = arCorr[1];
        delete[] arCorr;
    }
    void Print() {
        for (Node<T1, T2> *ptr1 = base; ptr1 != NULL; ptr1 = ptr1->next, cout << endl) {
            cout << ptr1->value << " + " << ptr1->data;
            for (Node<T1, T2> *ptr2 = ptr1->par; ptr2 != NULL; ptr2 = ptr2->par)
                cout << " | " << ptr2->next->value << " " << ptr2->data;
        }
        cout << endl;
    }
    void Process(T1 val1, T1 val2) {
        Content<T1, T2> conn1, conn2;
        Node<T1, T2> *ptr1 = base;
        for ( ; ptr1 != NULL; ptr1 = ptr1->next)
            ptr1->prev = NULL;
        for (ptr1=base; ptr1->value != val1; ptr1 = ptr1->next);
        conn1.Add(ptr1, ptr1->data);
        while (!conn1.Empty() && ptr1->par->value != val2) {
            ptr1 = conn2.Set(conn1.Get());
            Change(conn1, conn2, ptr1->par, ptr1->data-ptr1->par->data, true);
        }
        conn1.Print();
        conn2.Print();
    }
};
int main() {
    const int num = 42;
    int arr1[] = { 2,4,8, 1,2,6, 5,3,8, 3,6,5, 4,3,5, 5,1,3, 1,4,7, 2,5,4, 6,1,5,
                   4,4,9, 3,2,2, 5,6,1, 2,3,5, 6,2,3 };
    int arr2[] = { 0, 4, 7, 9, 2, 3, 6, 8, 5 };
    Collection<int, int> coll;
    coll.Read(arr1, arr2, num);
    coll.Print();
    coll.Process(3, 1);
    return 0;
}
