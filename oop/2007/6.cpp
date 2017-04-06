//
// Created by rols on 4/6/17.
//

#include <iostream>
using namespace std;
class My {
public:
    My(){}
};
class Dy : public My {
public:
    Dy(){}
};
void f(int i) {
    switch (i) {
        case 1: throw 1.2f; break;
        case 2: throw 3.2; break;
        case 3: throw My(); break;
        case 4: throw Dy(); break;
    }
}
void g(int i) {
    switch (i) {
        case 0: throw 2.3; break;
        case 5: throw 3.2f; break;
        case 6: throw My(); break;
        case 7: throw Dy(); break;
    }
}
int main() {
    for(int i=0; i<8; i++) {
        try {
            f(i);
            try {
                g(i);
            }
            catch (Dy) {cout << "Alo";}
            catch (My) {cout << "Hey";}
            catch (double) {cout << "Uau";}
            catch (float ) {cout << "Kss";}
        }
        catch (My) {cout << "Uau";}
        catch (float ) {cout << "Alo";}
        catch (Dy) {cout << "Kss";}
        catch (double ) {cout << "Hey";}
        cout << i << endl;
    }
}