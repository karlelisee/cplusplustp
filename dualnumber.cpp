#include <iostream>
#include <cmath>

// ======================================================
//      Dual Numbers:  a + bε   with ε² = 0
// ======================================================

struct DualNumber {
    double a;   // real part
    double b;   // dual part (coefficient of ε)

    DualNumber(double real = 0.0, double dual = 0.0)
        : a(real), b(dual) {}
};

// ------------------------------------------------------
// Operator overloads following EXACT rules from the PDF
// ------------------------------------------------------

DualNumber operator+(const DualNumber& x, const DualNumber& y) {
    return DualNumber(x.a + y.a, x.b + y.b);
}

DualNumber operator-(const DualNumber& x, const DualNumber& y) {
    return DualNumber(x.a - y.a, x.b - y.b);
}

DualNumber operator*(const DualNumber& x, const DualNumber& y) {
    // (a + bε)(c + dε) = ac + (ad + bc)ε
    double real = x.a * y.a;
    double dual = x.a * y.b + x.b * y.a;
    return DualNumber(real, dual);
}

DualNumber operator/(const DualNumber& x, const DualNumber& y) {
    // (a + bε) / (c + dε) = a/c + (bc - ad) / c² ε
    double real = x.a / y.a;
    double dual = (x.b * y.a - x.a * y.b) / (y.a * y.a);
    return DualNumber(real, dual);
}

// ------------------------------------------------------
// Exponential overload: exp(a + bε) = e^a + b e^a ε
// ------------------------------------------------------

DualNumber exp(const DualNumber& x) {
    double e = std::exp(x.a);
    return DualNumber(e, x.b * e);
}

// (needed so exp(double) still works normally)
using std::exp;

// ------------------------------------------------------
// Pretty printing
// ------------------------------------------------------

std::ostream& operator<<(std::ostream& os, const DualNumber& z) {
    os << z.a << " + " << z.b << "ε";
    return os;
}

// ------------------------------------------------------
// Main test program
// ------------------------------------------------------

int main() {
    DualNumber epsilon(0.0, 1.0);
    DualNumber one(1.0, 0.0);

    DualNumber y(2.0, 4.0);     // 2 + 4ε
    DualNumber z = one + epsilon;  // 1 + 1ε

    DualNumber product  = y * z;
    DualNumber quotient = y / z;
    DualNumber expo     = exp(z);

    std::cout << "y        = " << y        << "\n";
    std::cout << "z        = " << z        << "\n";
    std::cout << "y * z    = " << product  << "\n";
    std::cout << "y / z    = " << quotient << "\n";
    std::cout << "exp(z)   = " << expo     << "\n";

    return 0;
}