#include <iostream>
using namespace std;

struct DualNumber {
    double real;
    double imag;
};
DualNumber operator+(const DualNumber& y, const DualNumber& z) {
    return {y.real + z.real, y.imag + z.imag};
}

DualNumber operator-(const DualNumber& y, const DualNumber& z) {
    return {y.real - z.real, y.imag - z.imag};
}

DualNumber operator*(const DualNumber& y, const DualNumber& z) {
    return {y.real * z.real, y.real * z.imag + y.imag * z.real};
}

DualNumber operator/(const DualNumber& y, const DualNumber& z) {
    return {y.real / z.real, (y.imag * z.real - y.real * y.imag) / (z.real * z.real)};
}

DualNumber operator*(const double& scalar, const DualNumber& y) {
    return {scalar * y.real, scalar * y.imag};
}

DualNumber operator+(double double& scalar, const DualNumber& z) {
    return {scalar + z.real, z.imag};
}

int main() {
    DualNumber one = {1.0, 0.0};
    DualNumber epsilon = {0.0, 1.0};
    DualNumber y = 2.0 + 4.0 * epsilon;
    DualNumber z = one + epsilon;
    DualNumber real = y * z;
    DualNumber img = y / z;


    return 0;
}
