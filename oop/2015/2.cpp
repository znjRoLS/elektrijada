//
// Created by rols on 4/6/17.
//

#include <iostream>
using namespace std;
int c = 0;
class Elektrijada {
public:
    Elektrijada(){ c++; }
};
class Becici : public Elektrijada {
public:
    Becici(){ c = c << 1; }
};
class OOP : public Becici {
public:
    OOP(){ c << 1; }
};
void f(int i) {
    switch (i) {
        case 1: throw 1.2f; break;
        case 2: throw Elektrijada(); break;
        case 3: throw 3.2; break;
        case 4: throw Becici(); break;
        case 5: throw new OOP(); break;
    }
}
void g(int i) {
    switch (i) {
        case 0: throw Elektrijada(); break;
        case 6: throw 2.3; break;
        case 7: throw 3.2f; break;
        case 8: throw OOP(); break;
        case 9: throw new Becici(); break;
    }
}
int main() {
    for (int i = 0; i<10; i++) {
        try {
            f(i);
            try {
                g(i);
            }
            catch (Becici &becici) { cout << "Becici"; }
            catch (OOP &my) { cout << "OOP"; }
            catch (Elektrijada &my) { cout << "Elektrijada"; }
            catch (double) { cout << "double"; }
            catch (float) { cout << "float"; }
            catch (OOP *my) { cout << "*00P*"; }
        }
        catch (Elektrijada *my) { cout << "*Elektrij@da*"; }
        catch (Becici *becici) { cout << "*Becici*"; }
        catch (float) { cout << "flo@t"; }
        catch (double) { cout << "d0uble"; }
        catch (OOP &my) { cout << "00P"; }
        catch (Elektrijada &my) { cout << "Elektrij@da"; }
        catch (Becici &becici) { cout << "Becici"; }
        cout << i << endl;
    }
    cout << c;
    return 0;
}