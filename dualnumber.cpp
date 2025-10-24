#include <iostream>
#include <cmath>

struct DualNumber {
    double real;
    double imag;

    DualNumber(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
};


DualNumber operator+(const DualNumber& lhs, const DualNumber& rhs) {
    return DualNumber(lhs.real + rhs.real, lhs.imag + rhs.imag);
}


DualNumber operator-(const DualNumber& lhs, const DualNumber& rhs) {
    return DualNumber(lhs.real - rhs.real, lhs.imag - rhs.imag);
}


DualNumber operator*(const DualNumber& lhs, const DualNumber& rhs) {
    return DualNumber(
        lhs.real * rhs.real,
        lhs.real * rhs.imag + lhs.imag * rhs.real
    );
}


DualNumber operator/(const DualNumber& lhs, const DualNumber& rhs) {
    return DualNumber(
        lhs.real / rhs.real,
        (lhs.imag * rhs.real - lhs.real * rhs.imag) / (rhs.real * rhs.real)
    );
}


DualNumber operator+(const DualNumber& lhs, double rhs) {
    return DualNumber(lhs.real + rhs, lhs.imag);
}

DualNumber operator+(double lhs, const DualNumber& rhs) {
    return DualNumber(lhs + rhs.real, rhs.imag);
}

DualNumber operator-(const DualNumber& lhs, double rhs) {
    return DualNumber(lhs.real - rhs, lhs.imag);
}

DualNumber operator-(double lhs, const DualNumber& rhs) {
    return DualNumber(lhs - rhs.real, -rhs.imag);
}

DualNumber operator*(const DualNumber& lhs, double rhs) {
    return DualNumber(lhs.real * rhs, lhs.imag * rhs);
}

DualNumber operator*(double lhs, const DualNumber& rhs) {
    return DualNumber(lhs * rhs.real, lhs * rhs.imag);
}

DualNumber operator/(const DualNumber& lhs, double rhs) {
    return DualNumber(lhs.real / rhs, lhs.imag / rhs);
}



int main() {
    DualNumber one(1.0, 0.0);
    DualNumber epsilon(0.0, 1.0);
    DualNumber y = 2.0 + 4.0 * epsilon;
    DualNumber z = one + epsilon;

    DualNumber product = y * z;
    DualNumber quotient = y / z;


    return 0;
}
