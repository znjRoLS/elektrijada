//
// Created by rols on 4/6/17.
//

#include <math.h>
#include <iostream>
using namespace std;
template <class Tip>
class Element {
public:
    Tip first, second;
    Element() { first = 0; second = -1; };
    Element(Tip f, Tip s) { first = f; second = s; };
    Element(const Element<Tip>& it) { first = it.first; second = it.second; };
    Element<Tip>& operator =(const Element<Tip>& it) {
        first = it.first; second = it.second;
        return *this;
    };
    bool operator !=(Element<Tip>& it) {
        return !(first == it.first && second == it.second); };
    bool IsValid() { return second < 0; };
    Tip Square() { return (second - first+1)*(second + first)/2; };
    Tip Difference() { return second - first + 1; };
};
template <class Tip>
class Item {
public:
    int index;
    Tip value;
    Item<Tip>* pItem;
    Item<Tip>* pRel;
    bool status;
    Item(Item<Tip>* pI=NULL, Item<Tip>* pR=NULL, int ind=0, Tip val=Tip()) {
        pItem = pI; pRel = pR; index = ind; value = val; status = false;
    };
};
template <class Tip>
class Relationship {
    int size;
    Tip* arValues;
public:
    Item<Element<Tip> > *pItem;
    Relationship(Tip* arVal, int sz) {
        arValues = new Tip[sz];
        size = (int)sqrt((double)sz);
        for (int i=0; i<sz; )
            for (unsigned int j=0, val=0xF0000000; j<8; val>>=4, i++, j++)
                arValues[i] = (arVal[i/8] & val) >> (28-4*j);
        pItem = NULL;
    };
    void Accumulate() {
        Item<Element<Tip> >* pTemp = pItem;
        Tip sum = 0, count = 0, acc = 0, diff;
        for ( ; pTemp != NULL; pTemp=pTemp->pItem) {
            count += (diff = pTemp->value.Difference());
            sum += pTemp->value.Square();
            acc += diff * pTemp->index;
            cout<<pTemp->index<<" "<<pTemp->value.first<<" "<<pTemp->value.second<<endl;
        }
        cout<<count<<" "<<(1.0 * sum / count)<<" "<<(1.0 * acc / count)<<endl;
    };
    Element<Tip> Compute(Element<Tip>& pos, Tip limit) {
        Element<Tip> el(pos.first, pos.first);
        for ( ; el.first>=0 && arValues[el.first+pos.second*size]>=limit; el.first--);
        for ( ; el.second<size && arValues[el.second+pos.second*size]>=limit; el.second++);
        el.first++; el.second--;
        return el;
    };
    void Create(Element<Tip> position, Tip limit) {
        Tip ind = position.second;
        Element<Tip> elPrev, el = Compute(position, limit);
        Item<Element<Tip> >* pItemTmp = new Item<Element<Tip> >(NULL, NULL, ind, el);
        Item<Element<Tip> >* pTemp1 = new Item<Element<Tip> >(NULL, pItemTmp),
                *pTemp2 = pTemp1;
        while (pTemp1 != NULL) {
            if (pItem == NULL)
                pItem = pItemTmp;
            else
                pItemTmp->pItem = pTemp1->pRel;
            pItemTmp = pTemp1->pRel;
            pTemp1 = pTemp1->pItem;
            pTemp2 = pTemp1 ? pTemp2 : pTemp1;
            ind = pItemTmp->index;
            for (int i=0; i<2; i++) {
                Element<Tip> elPrev = el = pItemTmp->value;
                ind += i ? i+1 : i-1;
                while (ind >= 0 && ind < size && el.first <= elPrev.second) {
                    el.second = ind;
                    for(;arValues[el.first+ind*size]<limit && el.first<=elPrev.second;el.first++);
                    if (el.first <= elPrev.second) {
                        el = Compute(el, limit);
                        Item<Element<Tip> >* pR=pItemTmp->pRel;
                        for ( ; pR!=NULL && (pR->pItem->index != ind || pR->pItem->value != el); )
                            pR=pR->pRel;
                        if (pR == NULL) {
                            Item<Element<Tip> >* pItemNew=new Item<Element<Tip> >(NULL,NULL,ind,el);
                            pItemTmp->pRel = new Item<Element<Tip> >(pItemNew, pItemTmp->pRel);
                            pItemNew->pRel = new Item<Element<Tip> >(pItemTmp, pItemNew->pRel);
                            if (pTemp1 == NULL) {
                                pTemp1 = pTemp2 = new Item<Element<Tip> >(NULL, pItemNew);
                            } else {
                                pTemp2->pItem = new Item<Element<Tip> >(NULL, pItemNew);
                                pTemp2 = pTemp2->pItem;
                            }
                        }
                        el.first = ++el.second;
                    }
                }
            }
        }
    };
};
int main()
{
    int n = 64;
    unsigned int arValues[] = { 0x02321300, 0x13454340, 0x04537241, 0x02237541,
                                0x04357352, 0x02463241, 0x05254521, 0x00312310};
    Relationship<unsigned int> rel((unsigned int *)arValues, n);
    Element<unsigned int> el(5,3);
    rel.Create(el, 4);
    rel.Accumulate();
    return (int)0;
}