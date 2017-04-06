//
// Created by rols on 4/6/17.
//

#include <iostream>
using namespace std;
template <class T> class ENode {
public:
    T info;
    ENode<T>* next;
    ENode<T>* prev;
    ENode(T i) { info = i; next = NULL; prev = NULL; };
    ENode(ENode<T>* nx, ENode<T>* pr) { next = nx; prev = pr; };
};
template <class T> ostream& operator << (ostream& output, const ENode<T>& node)
{ output << node.info; return output; };
template <class T> class EList {
protected:
    ENode<T> *head, *tail;
public:
    EList() { head = tail = NULL; }
    bool isEmpty() { return head == NULL; }
    T getHead() {
        if (head != NULL) return head->info;
        else return T();
    }
    void insertHead(ENode<T> *ptr, bool b=true) {
        par = b;
        ENode<T> *ptr1 = head, *prev1 = NULL;
        while (ptr1!=NULL && ptr->info>ptr1->info) {
            prev1 = ptr1; ptr1 = ptr1->next;
        }
        if (prev1 != NULL) {
            prev1->next = ptr; ptr->next = ptr1;
        } else {
            head = ptr; ptr->next = ptr1;
        }
    }
    ENode<T>* deleteHead() {
        ENode<T>* tmp = head;
        if (head == tail) head = tail = NULL;
        else head = head->next;
        return tmp;
    }
    void traverse(ENode<T> *pNode) {
        int cnt = 0;
        for (ENode<T> *ptr=head; ptr!=NULL; ptr=ptr->next, cnt++) {
            if (pNode->info <= ptr->info) {
                ENode<T> *pN1, *pN2;
                if (pNode->info < ptr->info) {
                    pN1 = pNode; pN2 = ptr;
                } else {
                    pN1 = ptr; pN2 = pNode;
                }
                ENode<T> *pE = pN1->prev, *pEp = NULL;
                while (pE != NULL && pE->next->info < pN2->info) {
                    pEp = pE; pE = pE->prev;
                }
                if (pEp == NULL)
                    pN1->prev = new ENode<T>(pN2, pN1->prev);
                else
                    pEp->prev = new ENode<T>(pN2, pE);
            }
        }
        cout << (cnt/4&0x1) << (cnt/2&0x1) << (cnt&0x1) << endl;
    }
    void print() {
        for (ENode<T>* tmp = head; tmp != NULL; tmp = tmp->next) {
            cout << endl << *tmp << " ";
            for (ENode<T>* ptr = tmp->prev; ptr != NULL; ptr = ptr->prev)
                cout << *(ptr->next) << " ";
        }
    }
};
bool par = false;
class EMap {
public:
    int k1, v1, k2, v2;
    EMap() { k1 = v1 = k2 = v2 = 0; };
    EMap(int x1, int y1, int x2, int y2)
    { k1 = x1; v1 = y1; k2 = x2; v2 = y2; };
    EMap(const EMap& rc)
    { k1 = rc.k1; v1 = rc.v1; k2 = rc.k2; v2 = rc.v2; };
    bool operator < (const EMap& rc) { return k1 < rc.k1; };
    bool operator > (const EMap& rc) { return par ? v1 > rc.v1 : v2 > rc.v2; };
    bool operator <= (const EMap& rc) { return k1 <= rc.k2 && k2 >= rc.k1; };
};
ostream& operator << (ostream& output, const EMap& rc)
{ output << "( " << rc.k1 << " " << rc.v1 << " " << rc.k2 << " "
         << rc.v2 << " ) " ; return output; };
void createList(ENode<EMap> *nodes[], int n) {
    EList<EMap> ltmp, llist;
    for (int i=0; i<n; i++) {
        bool bStop = false;
        while (!bStop && !ltmp.isEmpty()) {
            if (nodes[i]->info.v1 > ltmp.getHead().v2) {
                ENode<EMap> *pNode = ltmp.deleteHead();
                llist.insertHead(pNode);
            } else {
                bStop = true;
            }
        }
        ENode<EMap> *pNode = nodes[i];
        ltmp.traverse(pNode);
        ltmp.insertHead(pNode, false);
    }
    while (!ltmp.isEmpty())
        llist.insertHead(ltmp.deleteHead());
    llist.print();
}
void main() {
    ENode<EMap> *nodes[8];
    nodes[0] = new ENode<EMap>(EMap(10, 10, 20, 20));
    nodes[1] = new ENode<EMap>(EMap(15, 15, 45, 25));
    nodes[2] = new ENode<EMap>(EMap(25, 30, 35, 45));
    nodes[3] = new ENode<EMap>(EMap(15, 35, 25, 50));
    nodes[4] = new ENode<EMap>(EMap(20, 40, 30, 55));
    nodes[5] = new ENode<EMap>(EMap(40, 35, 50, 70));
    nodes[6] = new ENode<EMap>(EMap(0, 60, 25, 80));
    nodes[7] = new ENode<EMap>(EMap(15, 70, 20, 75));
    createList(nodes, 8);
}