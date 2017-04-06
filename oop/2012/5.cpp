//
// Created by rols on 4/6/17.
//

#include <cstring>
#include <iostream>
using namespace std;
class Seed {
protected:
    char data;
public:
    virtual int Length() = 0;
    virtual int Count(int &min, int &max) = 0;
    virtual char Process() = 0;
};
class Starter : public Seed
{
public:
    Starter(char d) { data = d; };
    virtual int Length() { return 1; };
    virtual int Count(int &min, int &max) {
        min = data & 1 ? 0 : 1;
        max = data & 1 ? 1 : 0;
        return 0;
    };
    virtual char Process() { return '0'; };
};
class Block : public Seed {
protected:
    Seed *seed;
public:
    virtual int Length() { return seed->Length()+2; };
};
class BlockDefault : public Block {
public:
    BlockDefault(Seed *s, char d) { seed = s; data = d; };
    virtual int Count(int &min, int &max) {
        int cnt = seed->Count(min, max);
        min++; max++;
        return cnt;
    };
    virtual char Process() { return seed->Process() + (data & 1? 0 : 1); };
};
class BlockComplex : public Block {
public:
    BlockComplex(Seed *s, char d) { seed = s; data = d; };
    virtual int Count(int &min, int &max) {
        int cnt = seed->Count(min, max);
        if (data & 1) {
            max += 2;
            return cnt+min;
        } else {
            min += 2;
            return cnt+max;
        }
    };
    virtual char Process() { return seed->Process(); };
};
class Creator {
    bool status;
    Seed *seed;
public:
    Creator(char c) { status = true; seed = new Starter(c); };
    bool GetState() { return status; };
    int GetLength() { return seed->Length(); };
    void ChangeStatus() {
        int min, max;
        status = !status;
        cout << seed->Process() << " " << seed->Count(min, max) << endl;
    };
    void Modify(char cc, char cp) {
        if (!cp) { status = false; return; }
        if (cc & 0x1 ^ cp & 0x1)
            seed = new BlockDefault(seed, cc);
        else
            seed = new BlockComplex(seed, cc);
    };
};
class Sequence {
    int lenght;
    int count;
    char *arSeq;
    Creator **arCreator;
public:
    Sequence(char arr[], int n) {
        arSeq = new char[lenght=n];
        strcpy(arSeq, arr);
        arCreator = new Creator*[lenght];
        count = 0;
    };
    void Add(Creator *cr) { arCreator[count++] = cr; };
    void Remove(Creator *cr) {
        int i;
        for (i=0; i<count && arCreator[i] != cr; i++);
        arCreator[i]->ChangeStatus();
        for (count--; i<count; i++)
            arCreator[i] = arCreator[i+1];
    };
    void Step(int ind) {
        for (int i=0; i<count; i++) {
            int indS = ind - arCreator[i]->GetLength() - 1;
            arCreator[i]->Modify(arSeq[ind], indS < 0 ? 0 : arSeq[indS]);
        }
    };
};
int main(int argc, char* argv[]) {
    char arr[] = "0101001110001011";
    Sequence seq(arr, strlen(arr));
    Creator **aCreators = new Creator*[strlen(arr)];
    for (int i=0; i<strlen(arr); i++) {
        seq.Step(i);
        for (int j=0; j<i; j++)
            if (!aCreators[j]->GetState())
                seq.Remove(aCreators[j]);
        aCreators[i] = new Creator(arr[i]);
        seq.Add(aCreators[i]);
    }
    return (int)0;
}