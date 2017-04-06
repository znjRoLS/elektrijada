//
// Created by rols on 4/6/17.
//

#include "stddef.h"
#include "iostream"

using namespace std;

template <class Xtype, int SD>
class Node
{
public:
    int axis;
    Xtype x[SD];
    unsigned int id ;
    Node* Parent;
    Node* Left;
    Node* Right;
    Node() {};
    virtual ~Node() {};
    Node(Xtype* x0, int split_axis);
    Node* Insert(Xtype* x);
    Node* FindParent(Xtype* x0);
    int Traverse(Xtype* xS, int level);
};
template <class Xtype, int SD> Node<Xtype, SD>::Node(Xtype* x0, int split_axis)
{
    for (int i=0; i<SD; i++)
        x[i] = x0[i];
    axis = split_axis;
    Parent = NULL;
    Left = NULL;
    Right = NULL;
}
template <class Xtype, int SD> Node<Xtype, SD>* Node<Xtype, SD>::FindParent(Xtype* x0)
{
    Node* parent;
    Node* next = this;
    int split;
    while(next) {
        split = next->axis;
        parent = next;
        if(x0[split] > next->x[split])
            next = next->Right;
        else
            next = next->Left;
    }
    return parent;
}
template <class Xtype, int SD> Node<Xtype, SD>* Node<Xtype, SD>::Insert(Xtype* p)
{
    Node* parent = FindParent(p);
    Node* newNode = new Node(p, parent->axis+1 < SD ? parent->axis+1:0);
    newNode->Parent = parent;
    if(p[parent->axis] > parent->x[parent->axis])
        parent->Right = newNode;
    else
        parent->Left = newNode;
    return newNode ;
}
template <class Xtype, int SD>
int Node<Xtype, SD>::Traverse(Xtype* xS, int level)
{
    int ret = 0;
    if (axis%2) {
        if (x[axis] > xS[axis]) {
            if (x[(axis+1)%SD] < xS[(axis+1)%SD])
                ret++;
            if (Left != NULL)
                ret += Left->Traverse(xS, ++level);
        }
        if (Right != NULL)
            ret += Right->Traverse(xS, ++level);
    } else {
        if (x[axis] < xS[axis]) {
            if (x[(axis+1)%SD] > xS[(axis+1)%SD])
                ret++;
            if (Right != NULL)
                ret += Right->Traverse(xS, ++level);
        }
        if (Left != NULL)
            ret += Left->Traverse(xS, ++level);
    }
    cout << "A_" << x[axis] << " B_" << x[(axis+1)%SD] << endl;
    return ret;
}
int main(int argc, char* argv[])
{
    int x[2];
    x[0] = 5; x[1] = 8;
    Node<int, 2> tree(x, 0);
    x[0] = 3; x[1] = 5;
    tree.Insert(x);
    x[0] = 10; x[1] = 7;
    tree.Insert(x);
    x[0] = 15; x[1] = 4;
    tree.Insert(x);
    x[0] = 1; x[1] = 8;
    tree.Insert(x);
    x[0] = 6; x[1] = 9;
    tree.Insert(x);
    x[0] = 2; x[1] = 3;
    tree.Insert(x);
    x[0] = 7; x[1] = 4;
    cout << tree.Traverse(x, 0) << endl;
    x[0] = 4; x[1] = 4;
    cout << tree.Traverse(x, 0) << endl;
    return 0;
}