// Electricity Bill System
#include <iostream>
using namespace std;

// Abstract class
class Consumer {
protected:
    int units;
public:
    Consumer(int u) { units = u; }          // constructor
    virtual float bill() = 0;               // pure virtual
    friend void show(Consumer &c);          // friend function
};

// Derived classes (inheritance)
class Domestic : public Consumer {
public:
    Domestic(int u) : Consumer(u) {}
    float bill() { return units * 5; }
};

class Commercial : public Consumer {
public:
    Commercial(int u) : Consumer(u) {}
    float bill() { return units * 8; }
};

class Industrial : public Consumer {
public:
    Industrial(int u) : Consumer(u) {}
    float bill() { return units * 10; }
};

void show(Consumer &c) {
    cout << "Units : " << c.units << endl;
    cout << "Bill  : Rs " << c.bill() << endl;   // polymorphism
}

int main() {
    int type, units;

    cout << "1-Domestic 2-Commercial 3-Industrial: ";
    cin >> type;
    cout << "Enter units: ";
    cin >> units;

    if (type == 1) {
        Domestic d(units);
        show(d);
    }
    else if (type == 2) {
        Commercial c(units);
        show(c);
    }
    else {
        Industrial i(units);
        show(i);
    }
    return 0;
}
