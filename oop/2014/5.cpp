//
// Created by rols on 4/6/17.
//

#include "iostream"
using namespace std;
class Item {
public:
    int simbol;
    Item() { simbol = -1; };
    Item(int s) { simbol = s; };
    virtual int GetType() = 0;
    virtual Item* Process(Item& it, Item* pItem = NULL) = 0;
    virtual void Print() { cout << simbol << " "; };
};
class Type : public Item {
public:
    Type(int t) : Item(t) {};
    int GetType() {
        int type = 0;
        if (simbol >= 0) for (int t=simbol; t; t>>=1) type++;
        else type = simbol;
        return type+1;
    };
    Item* Process(Item& it, Item* pItem = NULL) { return this; };
};
class Value : public Item {
public:
    Value(int v) : Item(v) {};
    int GetType() { return simbol / 0x10; };
    Item* Process(Item& it, Item* pItem) { return this; };
};
class Creator;
class Data : public Item {
protected:
    Item *pCurr, *pPrev;
    Creator *pCreate;
    friend class Creator;
public:
    Data() : Item() {
        pCurr = pPrev = NULL;
        pCreate = NULL;
    };
    Data(Creator *pCrt, Item* pC, Item* pP, int s)
            : pCurr(pC), pPrev(pP), pCreate(pCrt), Item(s) { };
    int GetType() {
        int type = 0;
        for (int t=simbol; t; t>>=1) type++;
        return type+1;
    };
    Item* Process(Item& it, Item* pItem = NULL);
    void Print() {
        if (pPrev) pPrev->Print();
        cout << simbol << " ";
    };
};
class DataValue : public Data {
public:
    DataValue(Creator* pCr, Item* p, int s) : Data(pCr, NULL, p, s) { };
};
class DataProcess : public Data {
public:
    DataProcess(Creator* pCr, Item* pC, Item* pP, int s) : Data(pCr, pC, pP, s) { };
};
class Creator {
    Item& makeItem(int v) {
        Item *rItem = NULL;
        if (v / 0x10) rItem = new Value(v);
        else rItem = new Type(v);
        return *rItem;
    };
public:
    Data* makeData(Data* pData, int s, int type) {
        Item* pPrev = NULL;
        if (pData != NULL) pPrev = pData->pPrev;
        if (type == 0) return new DataValue(this, pPrev, s);
        else return new DataProcess(this, pData, pPrev, s);
    };
    Item* makeData(Data* pData, int v) {
        Item& it = makeItem(v);
        if (pData == NULL) return
                    new DataProcess(this, NULL, new DataValue(this, NULL, v), -1);
        else
        if (v / 0x10) return pData->Process(it);
        else return pData->Process(it, pData->pPrev);
    };
};
Item* Data::Process(Item& it, Item* pItem) {
    if (simbol == -1) {
        simbol = it.simbol;
        return this;
    } else if (pItem == NULL) {
        pPrev = pCreate->makeData(this, it.simbol, 0);
        return this;
    } else {
        this->pPrev = pItem;
        if (it.GetType() < GetType()) {
            Item* pTmp = pCurr;
            pPrev = pItem = pCreate->makeData(this, simbol, 0);
            if (pTmp == NULL) {
                simbol = it.simbol;
                return this;
            } else return pTmp->Process(it, pItem);
        } else if (it.GetType() == GetType()) {
            pPrev = pItem = pCreate->makeData(this, simbol, 0);
            simbol = it.simbol;
            return this;
        } else
            return pCreate->makeData(this, it.simbol, 1);
    }
}
int main() {
    char arr[] = {16,2,17,4,18,5,16,3,19,5,17,4,20,8,21,5,22,-1};
    Data *pData = NULL;
    Creator create;
    for (int i=0; i<18; i++)
        pData = (Data *) create.makeData(pData, arr[i]);
    pData->Print();
    return 0;
}