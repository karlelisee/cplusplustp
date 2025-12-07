#include <iostream>
#include <cmath>

struct DualNumber {
    double real;
    double imag;
};

// Output stream
std::ostream& operator<<(std::ostream& os, const DualNumber& dn) {
    os << "(" << dn.real << " + " << dn.imag << "ε)";
    return os;
}

// Helper function to create a DualNumber
DualNumber make_dual(double real, double imag) {
    DualNumber dn;
    dn.real = real;
    dn.imag = imag;
    return dn;
}

// ---------------------------
// Operator overloads
// ---------------------------

DualNumber operator+(const DualNumber& lhs, const DualNumber& rhs) {
    DualNumber result;
    result.real = lhs.real + rhs.real;
    result.imag = lhs.imag + rhs.imag;
    return result;
}

DualNumber operator-(const DualNumber& lhs, const DualNumber& rhs) {
    DualNumber result;
    result.real = lhs.real - rhs.real;
    result.imag = lhs.imag - rhs.imag;
    return result;
}

DualNumber operator*(const DualNumber& lhs, const DualNumber& rhs) {
    DualNumber result;
    result.real = lhs.real * rhs.real;
    result.imag = lhs.real * rhs.imag + lhs.imag * rhs.real;
    return result;
}

DualNumber operator/(const DualNumber& lhs, const DualNumber& rhs) {
    DualNumber result;
    result.real = lhs.real / rhs.real;
    result.imag = (lhs.imag * rhs.real - lhs.real * rhs.imag) / (rhs.real * rhs.real);
    return result;
}

// ---------------------------
// DualNumber / double
// ---------------------------
DualNumber operator+(const DualNumber& lhs, double rhs) {
    DualNumber result;
    result.real = lhs.real + rhs;
    result.imag = lhs.imag;
    return result;
}

DualNumber operator+(double lhs, const DualNumber& rhs) {
    DualNumber result;
    result.real = lhs + rhs.real;
    result.imag = rhs.imag;
    return result;
}

DualNumber operator-(const DualNumber& lhs, double rhs) {
    DualNumber result;
    result.real = lhs.real - rhs;
    result.imag = lhs.imag;
    return result;
}

DualNumber operator-(double lhs, const DualNumber& rhs) {
    DualNumber result;
    result.real = lhs - rhs.real;
    result.imag = -rhs.imag;
    return result;
}

DualNumber operator*(const DualNumber& lhs, double rhs) {
    DualNumber result;
    result.real = lhs.real * rhs;
    result.imag = lhs.imag * rhs;
    return result;
}

DualNumber operator*(double lhs, const DualNumber& rhs) {
    DualNumber result;
    result.real = lhs * rhs.real;
    result.imag = lhs * rhs.imag;
    return result;
}

DualNumber operator/(const DualNumber& lhs, double rhs) {
    DualNumber result;
    result.real = lhs.real / rhs;
    result.imag = lhs.imag / rhs;
    return result;
}

// ---------------------------
// Math functions
// ---------------------------
DualNumber exp(const DualNumber& dn) {
    DualNumber result;
    double e_real = std::exp(dn.real);
    result.real = e_real;
    result.imag = e_real * dn.imag;
    return result;
}

DualNumber pow(const DualNumber& dn, double exponent) {
    DualNumber result;
    double base_pow = std::pow(dn.real, exponent);
    result.real = base_pow;
    result.imag = exponent * std::pow(dn.real, exponent - 1) * dn.imag;
    return result;
}

// ---------------------------
// Main program
// ---------------------------
int main() {
    DualNumber one;     one.real = 1.0; one.imag = 0.0;
    DualNumber epsilon; epsilon.real = 0.0; epsilon.imag = 1.0;

    DualNumber y = 2.0 + 4.0 * epsilon;
    DualNumber z = one + epsilon;

    DualNumber product = y * z;
    DualNumber quotient = y / z;
    DualNumber exponential = exp(z);
    DualNumber power = pow(z, 3.0);

    std::cout << "y        = " << y << "\n";
    std::cout << "z        = " << z << "\n";
    std::cout << "y * z    = " << product << "\n";
    std::cout << "y / z    = " << quotient << "\n";
    std::cout << "exp(z)   = " << exponential << "\n";
    std::cout << "z^3      = " << power << "\n";

    return 0;
}
