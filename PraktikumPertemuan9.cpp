#include <iostream>
using namespace std;

class BelahKetupat; // forward declaration

class LayangLayang {
private:
    double d1, d2; // diagonal
    double s1, s2; // sisi

public:
    void input() {
        cout << "Input Layang-Layang\n";
        cout << "Diagonal 1: "; cin >> d1;
        cout << "Diagonal 2: "; cin >> d2;
        cout << "Sisi 1: "; cin >> s1;
        cout << "Sisi 2: "; cin >> s2;
    }

    double luas() {
        return 0.5 * d1 * d2;
    }

    double keliling() {
        return 2 * (s1 + s2);
    }

    void output() {
        cout << "\nLayang-Layang\n";
        cout << "Luas: " << luas() << endl;
        cout << "Keliling: " << keliling() << endl;
    }

    // friend function (keliling Belah Ketupat boleh akses LayangLayang)
    friend double kelilingBelahKetupat(BelahKetupat b, LayangLayang l);
};

class BelahKetupat {
private:
    double d1, d2; // diagonal
    double s;      // sisi

public:
    void input() {
        cout << "\nInput Belah Ketupat\n";
        cout << "Diagonal 1: "; cin >> d1;
        cout << "Diagonal 2: "; cin >> d2;
        cout << "Sisi: "; cin >> s;
    }

    double luas() {
        return 0.5 * d1 * d2;
    }

    void output() {
        cout << "\nBelah Ketupat\n";
        cout << "Luas: " << luas() << endl;
    }

    // friend function
    friend double kelilingBelahKetupat(BelahKetupat b, LayangLayang l);
};

// Friend function (keliling Belah Ketupat)
double kelilingBelahKetupat(BelahKetupat b, LayangLayang l) {
    return 4 * b.s; // keliling belah ketupat
}

int main() {
    LayangLayang l;
    BelahKetupat b;

    l.input();
    b.input();

    l.output();
    b.output();

    cout << "Keliling Belah Ketupat (friend): "
         << kelilingBelahKetupat(b, l) << endl;

    return 0;
}