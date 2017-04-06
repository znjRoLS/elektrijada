//
// Created by rols on 4/6/17.
//

#include <iostream>
using namespace std;
#define NN 8
class Link;
template<class T, int n>
class Node {
public:
    T val[n];
    Link *next, *prev;
    Node() {
        for (int i=0; i<n; i++) { val[i] = 0; }
        next = NULL; prev = NULL;
    };
    bool operator <(const Node &node) {
        int i;
        for (i=0; i<n && val[i]<=node.val[i]; i++);
        return i == n;
    };
    void Convert(T data, T base[]) {
        for (int i=0; i<n; i++) {
            val[i] = 0;
            while (!(data % base[i])) {
                val[i]++;
                data /= base[i];
            }
        }
    };
};
class Link {
public:
    int val[2];
    Link *next, *prev, *down, *up;
    Link(int x, int y, Link *nn, Link *pp) {
        val[0]=x; val[1]=y; next = nn; prev = pp;
    };
    void Update(Link *dd, Link *uu) { down = dd; up = uu; };
};
template<class T, int n>
class Collection {
public:
    int nNodes;
    Node<T, n> *arNodes;
    T base[n];
    Collection(T arN[], int nN, T b[]) {
        for (int i=0; i<nN; i++) { base[i] = b[i]; }
        arNodes = new Node<T,n>[nNodes = nN];
        for (int i=0; i<nN; i++) {
            arNodes[i].Convert(arN[i], base);
        }
    };
    void Process() {
        for (int i=0; i<nNodes; i++)
            for (int j=0; j<nNodes; j++)
                if (i != j && arNodes[i] < arNodes[j])
                    Connect(i, j);
    };
    void Connect(int u, int v) {
        Link *p = arNodes[u].next, *pp = NULL, *pt;
        for ( ; p!=NULL && p->val[1]<v; pp=p, p=p->next);
        if (pp == NULL) {
            pt = arNodes[u].next = new Link(u, v, p, pp);
        } else {
            pt = pp->next = new Link(u, v, p, pp);
        }
        if (p != NULL)
            p->prev = pt;
        p = arNodes[v].prev; pp = NULL;
        for ( ; p!=NULL && p->val[0]<u; pp=p, p=p->down);
        pt->Update(p, pp);
        if (pp == NULL) {
            arNodes[v].prev = pt;
        } else {
            pp->down = pt;
        }
        if (p != NULL)
            p->up = pt;
    };
    void Traverse() {
        int arr[NN];
        for (int i=0; i<nNodes; i++)
            arr[i] = i;
        int ind;
        for (int cnt=nNodes; cnt > 0; cnt--) {
            for (ind=0; ind<cnt && arNodes[arr[ind]].prev != NULL; ind++);
            Delete(arr[ind]);
            cout << arr[ind]; (cnt-1)%2 ? cout << " " : cout << endl;
            for (int i=ind; i<cnt-1; i++) {
                arr[i] = arr[i+1];
            }
        }
    };
    void Delete(int u) {
        Link *p = arNodes[u].next;
        for ( ; p!=NULL; p=p->next) {
            if (p->up == NULL)
                arNodes[p->val[1]].prev = p->down;
            else
                p->up->down = p->down;
            if (p->down != NULL)
                p->down->up = p->up;
        }
    };
    void Print() {
        for (int i=0; i<nNodes; i++)
            for (Link *p=arNodes[i].next; p!=NULL; p=p->next)
                cout << p->val[0] << " " << p->val[1] << endl;
        cout << endl;
    };
};
int main(int argc, char* argv[]) {
    int ar[] = { 50400, 5040, 1035, 7056, 6552, 952, 7425, 18900 };
    int base[] = {2, 3, 5, 7};
    Collection<int, 4> col(ar,NN, base);
    col.Process();
    col.Print();
    col.Traverse();
    return (int)0;
}