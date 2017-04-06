//
// Created by rols on 4/6/17.
//

#include "iostream.h"
#include <vector>
using namespace std;
class Node {
    Node *left, *right;
public:
    Node(){left = NULL; right = NULL;}
    ~Node(){}
    int process();
    Node** getLeft(){return &left;}
    Node** getRight(){return &right;}
};
int Node::process(){
    int retValue=0;
    if(left==NULL && right==NULL) return 1;
    if(left!=NULL) retValue += left->process();
    if(right!=NULL) retValue += right->process();
    return retValue;
}
class Level {
    int mLevel;
public:
    Level(int i);
    ~Level(){for (int i = 0; i < mLevel; i++) delete mNodes[i];}
    vector<Node*> mNodes;
    friend void link(Level& l1, Level& l2);
};
Level::Level(int i):mLevel(i){
    for(int j=0; j<mLevel;j++){
        mNodes.push_back(new Node());
    }
}
void link(Level& l1, Level& l2){
    for(int j=0;j<l2.mLevel;j++){
        *(l1.mNodes[j]->getRight()) = l2.mNodes[j];
        *(l1.mNodes[j+1]->getLeft()) = l2.mNodes[j];
    }
}
int main(int argc, char* argv[])
{
    Level* levels[12]; int i;
    for( i=0; i<12; i++)
        levels[i] = new Level(i);
    for( i=0;i<11;i++){
        link(*(levels[i+1]),*(levels[i]));
    }
    cout << levels[11]->mNodes[5]->process() << endl;
    for( i=0; i<12; i++)
        delete levels[i];
    return 0;
}