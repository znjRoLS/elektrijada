//
// Created by rols on 4/6/17.
//

#include <iostream>
using namespace std;
template <class Tip>
class Node {
public:
    Tip value;
    Node* pLeft;
    Node* pRight;
    Node* pParent;
    int status;
    Node(Tip val=0, Node* pL=NULL, Node* pR=NULL) {
        value = val; status = 0;
        pLeft = pL; pRight = pR; pParent = NULL;
    };
    void Connect(Node<Tip>* pL) {
        pRight = new Node<Tip>(0, pL, pRight);
    };
    Node<Tip>* Find(Tip val) {
        Node<Tip>* pNode = this;
        for ( ; pNode!=NULL && val!=pNode->value; pNode=pNode->pLeft);
        return pNode;
    };
};
template <class Tip, int n>
class Forest {
public:
    int size;
    Node<Tip>* arTree[n];
    Forest(Tip* aVal, int nVal) {
        size = 0;
        for (int i=0; i<n; i++)
            arTree[i] = NULL;
        Node<Tip> *pTree=NULL, *pI, *pII;
        for (int i=0; i<nVal; i+=2) {
            if ((pI = pTree->Find(aVal[i])) == NULL) {
                pI = pTree = new Node<Tip>(aVal[i], pTree);
                size++;
            }
            if ((pII = pTree->Find(aVal[i+1])) == NULL) {
                pII = pTree = new Node<Tip>(aVal[i+1], pTree);
                size++;
            }
            pI->Connect(pII);
        }
        arTree[0] = pTree;
    };
    void Print(Node<Tip>* pNode) {
        for (cout << endl; pNode != NULL; cout << endl, pNode=pNode->pLeft) {
            cout << pNode->value;
            if (pNode->pParent == NULL)
                cout << " " << pNode->status;
            else
                cout << " " << pNode->pParent->value;
            for (Node<Tip>* pTmp=pNode->pRight; pTmp!=NULL; pTmp=pTmp->pRight) {
                cout << " " << pTmp->pLeft->value;
            }
        }
    };
    Node<Tip>* Rotate(Node<Tip>* pTree) {
        Node<Tip>* pNew = new Node<Tip>(pTree->value, NULL), *pT = pNew;
        for (Node<Tip>* pNode=pTree->pLeft; pNode != NULL;
             pNode=pNode->pLeft, pT=pT->pLeft) {
            pT->pLeft = new Node<Tip>(pNode->value, NULL);
        }
        for (Node<Tip>* pNode=pTree; pNode != NULL; pNode=pNode->pLeft) {
            Node<Tip>* pI = pNew->Find(pNode->value);
            for (Node<Tip>* pTmp=pNode->pRight; pTmp!=NULL; pTmp=pTmp->pRight) {
                Node<Tip>* pII = pNew->Find(pTmp->pLeft->value);
                pII->Connect(pI);
            }
        }
        return pNew;
    };
    void Arrange(int ind) {
        arTree[ind+1] = Rotate(arTree[ind]);
        Process(arTree[ind+1]);
        Print(arTree[ind+1]);
        for (Node<Tip>* pI=arTree[ind], *pII=arTree[ind+1]; pI!= NULL;
             pI=pI->pLeft, pII=pII->pLeft) {
            pI->status = -pII->status;
        }
        Correct(arTree[ind]);
        Print(arTree[ind]);
    };
    void Process(Node<Tip>* pTree, bool bAssign=false) {
        int cnt = 0;
        for (Node<Tip>* pNode=pTree; pNode != NULL; pNode=pNode->pLeft)
            if (pNode->status <= 0)
                Assign(pNode, cnt, bAssign ? pNode : NULL);
    };
    void Correct(Node<Tip>* pTree) {
        int cnt = 0;
        int state = -size;
        for (Node<Tip>* pI=pTree, *pII; pI!=NULL; pI=pI->pLeft, state++) {
            for (pII=pTree; pII!=NULL && pII->status!=state; pII=pII->pLeft);
            if (pII != NULL)
                Assign(pII, cnt, pII);
        }
    };
    void Assign(Node<Tip>* pNode, int& cnt, Node<Tip>* pPar) {
        pNode->status = 1;
        if (pPar != NULL)
            pNode->pParent = pPar;
        for (Node<Tip>* pTmp=pNode->pRight; pTmp!=NULL; pTmp=pTmp->pRight)
            if (pTmp->pLeft->status <= 0)
                Assign(pTmp->pLeft, cnt, pPar);
        pNode->status = ++cnt;
    };
};
int main()
{
    char aVal[22] = { 'P','D', 'A','M', 'H','A', 'M','H', 'K','E', 'K','P',
                      'D','I', 'I','P', 'M','V', 'V','K', 'E','V'};
    Forest<char, 3> forest((char*)aVal,22);
    forest.Arrange(0);
    return (int)0;
}