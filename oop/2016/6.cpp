//
// Created by rols on 5/13/17.
//

#include <iostream>

using namespace std;

template <class T>

class Node {

    T value, data;

    Node<T> *prev, *par, *next;

public:

    Node<T>(T v, Node *p, Node *pr, Node *n, T d=T()) {

        prev = p; par = pr; next = n;

        value = v; data = d;

    }

    Node<T>* Choose(T val, bool b=true) {

        Node<T>* ptr = this;

        for ( ; ptr!=NULL && (b && ptr->value!=val || !b && ptr->data!=val);

                ptr=ptr->next);

        return ptr;

    }

    Node<T>* Update(T val, T data) {

        Node<T>* ptr = this, *pptr = NULL;

        for ( ; ptr!=NULL && ptr->value<val; pptr=ptr,ptr=ptr->next);

        if (ptr==NULL || ptr->value != val) {

            Node *nNode = new Node(val, NULL, NULL, ptr, data);

            if (ptr == this) {

                ptr = nNode;

            } else {

                pptr->next = nNode;

                ptr = this;

            }

        }

        return ptr;

    }

    void UpdateData(T val, T data) {

        Node<T>* ptr = this;

        for ( ; ptr!=NULL && ptr->value!=val; ptr=ptr->next);

        bool bFind = false;

        if (ptr->prev == NULL) {

            ptr->prev = new Node(ptr->value, NULL, ptr, NULL, ptr->data);

            ptr->data = 1;

        } else {

            bFind = ptr->prev->Choose(data, false) != NULL;

        }

        if (!bFind) {

            ptr->data++;

            for (ptr=ptr->prev; ptr->next!=NULL; ptr=ptr->next);

            ptr->next = new Node(val, NULL, ptr->prev, NULL, data);

        }

    }

    void Change(Node<T>* node) {

        Node<T>* ptr = par;

        for ( ; ptr!=NULL && ptr->prev!=node; ptr=ptr->next);

        if (ptr == NULL && this != node) {

            par = new Node(0, node, NULL, par);

            node->par = new Node(0, this, NULL, node->par);

        }

    }

    void Print(Node<T>* node) {

        cout << value << " " << data << " -> ";

        Node<T>* ptr = node == NULL ? prev : par;

        for (; ptr!=NULL; ptr=ptr->next)

            cout << (node != NULL ? ptr->prev->value : ptr->prev->data) << " ";

        cout << endl;

        if (node != NULL && prev != NULL)

            prev->Print(NULL);

        if (node != NULL)

            cout << endl;

        if (next != NULL)

            next->Print(node);

    }

    void UpdateData() {

        T start = T(1);

        Node<T>* ptr = prev;

        for ( ; ptr!=NULL; ptr=ptr->next) {

            T step = start;

            T val = ptr->data%10 + 1;

            for (Node<T>* pptr=ptr->next; pptr!=NULL; pptr=pptr->next) {

                for ( ; val < pptr->data%10+1; val+=step);

                if (val == pptr->data%10+1) {

                    ptr->prev = new Node(0, pptr, NULL, ptr->prev);

                    pptr->prev = new Node(0, ptr, NULL, pptr->prev);

                }

            }

            start = ptr->data%10 + 1;

        }

    }

    void CorrectData() {

        for (Node<T>* ptr=this; ptr!=NULL; ptr=ptr->next)

            ptr->UpdateData();

    }

};

template <class T>

class Collection {

    Node<T>* major;

    void Update(T val, T data) {

        data = val * 10 + data - 1;

        Node<T>* ptr = major->Choose(val);

        if (ptr == NULL) {

            major = major->Update(val, data);

        } else {

            major->UpdateData(val, data);

        }

    }

    void Change(T val1, T val2) {

        Node<T>* ptr1 = major->Choose(val1);

        Node<T>* ptr2 = major->Choose(val2);

        ptr1->Change(ptr2);

    }

public:

    Collection() {

        major = NULL;

    }

    void Create(int n) {

        Update(1, 1);

        for (int i=2; i<=n; i++) {

            int j = 1;

            for (j=i/2; j>1 && i!=j*(i/j); j--);

            if (j != 1) {

                j = i/j;

            }

            Update(j, i);

            Update(i/j, i);

            Change(j, i/j);

        }

    }

    void UpdateData() {

        major->CorrectData();

    }

    void Print() {

        major->Print(major);

    }

};

int main() {

    Collection<int> coll;

    coll.Create(10);

    coll.UpdateData();

    coll.Print();

    return 0;

}