//
// Created by rols on 4/6/17.
//

#include <iostream>
#include <string>
using namespace std;
class Node {
public:
    int val;
    int code;
    Node *down, *right, *prev;
    Node() {down=right=prev=NULL; val=code=0;};
};
class Path {
    Node *start;
public:
    Path() { start = NULL; };
    void Traverse(char *arin, int nin);
    char* Process(char* ar);
    int Length(Node *pNode, char c);
};
class Net {
public:
    Node **ar;
    int ind, n;
    Net() { ar=NULL; ind=0; n=0;};
    void Init(Node *arin, int nin);
    void Connect();
    Node* GetLast() { return ar[n-1]; };
};
void Net::Init(Node *arin, int nin) {
    int i, j;
    ar = new Node*[n=nin];
    for (i=0; i<nin; i++) ar[i] = &arin[i];
    for (i=0; i<nin-1; i++)
        for (j=nin-1; j>i; j--)
            if (ar[j]->val<ar[j-1]->val) {
                Node *pNode=ar[j];
                ar[j]=ar[j-1];
                ar[j-1]=pNode;
            }
}
void Net::Connect() {
    Node *pNode = new Node();
    pNode->down = ar[ind];
    ar[ind]->prev = pNode;
    pNode->val = ar[ind]->val + ar[++ind]->val;
    pNode->right = ar[ind];
    ar[ind]->prev = pNode;
    ar[ind] = pNode;
    int i = ind-1;
    while (++i<n-1 && pNode->val>ar[i+1]->val)
        ar[i] = ar[i+1];
    ar[i] = pNode;
}
void Path::Traverse(char *arin, int nin) {
    int i, j;
    Node *artmp = new Node[2*nin];
    int ntmp = 0;
    for (i=0; i<nin; i++) {
        for (j=0; j<ntmp && arin[i]!=artmp[j].code; j++);
        if (j < ntmp) {
            artmp[j].val++;
        } else {
            artmp[ntmp].val=1;
            artmp[ntmp++].code = arin[i];
        }
    }
    Net frst;
    frst.Init(artmp, ntmp);
    for (i=0; i<ntmp-1; i++)
        frst.Connect();
    start=frst.GetLast();
}
char* Path::Process(char *ar) {
    int j=1, k=0, len=0;
    char c=0, *str = new char[strlen(ar)];
    for (int i=0; i<strlen(ar); i++) {
        int val = Length(start, ar[i]);
        for (k=0; val!=1; k++, j++, c<<=1, val/=2) {
            c |= val%2;
            if (j%8==0) { str[len++] = c; j=0; c=0; }
        }
        cout << k << " ";
    }
    cout << endl;
    if (j>1) str[len++] = c<<(9-j);
    str[len] = '\0';
    for (i=0; i<strlen(str); i++) {
        c = str[i];
        for (j=0; j<8; j++)
            cout << ((c & (0x1<<(7-j))) ? 1:0);
    }
    return str;
}
int Path::Length(Node *pNode, char c) {
    if (!pNode->down && !pNode->right)
        if (pNode->code == c) return 1;
        else return -1;
    int val;
    if ((val=Length(pNode->down, c))>=0)
        return val * 2 + 1;
    else
    if ((val=Length(pNode->right, c))>=0)
        return val * 2;
    return -1;
}
int main()
{
    char* niz="013554540320894670584241067130";
    Path stablo;
    stablo.Traverse(niz, strlen(niz));
    stablo.Process("0038163");
    return 0;
}