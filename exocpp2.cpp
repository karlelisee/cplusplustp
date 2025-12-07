#include <iostream>
#include <cmath>

/*****************************************************
 *                DUAL NUMBER TYPE
 *****************************************************/
struct DualNumber {
    double a; // real part
    double b; // dual part: coefficient of ε

    DualNumber(double real = 0.0, double dual = 0.0)
        : a(real), b(dual) {}
};

// Dual + Dual
DualNumber operator+(const DualNumber &x, const DualNumber &y) {
    return DualNumber(x.a + y.a, x.b + y.b);
}

// Dual * Dual
DualNumber operator*(const DualNumber &x, const DualNumber &y) {
    return DualNumber(
        x.a * y.a,
        x.a * y.b + x.b * y.a
    );
}

// Dual * double (scalar multiplication)
DualNumber operator*(const DualNumber &x, double s) {
    return DualNumber(x.a * s, x.b * s);
}

// Printing
std::ostream &operator<<(std::ostream &os, const DualNumber &d) {
    os << d.a << " + " << d.b << "ε";
    return os;
}

/*****************************************************
 *                SAFE VECTOR OF DUAL NUMBERS
 *****************************************************/
class DualVector {
private:
    int n;
    DualNumber *data;

public:
    DualVector(int size)
        : n(size), data(new DualNumber[size]) {}

    ~DualVector() {
        delete[] data;
    }

    int size() const { return n; }

    DualNumber &operator[](int i) { return data[i]; }
    const DualNumber &operator[](int i) const { return data[i]; }
};

/*****************************************************
 *                SAFE MATRIX OF DOUBLE
 *****************************************************/
class Matrix {
private:
    int rows, cols;
    double *data;

public:
    Matrix(int r, int c)
        : rows(r), cols(c), data(new double[r * c]) {}

    ~Matrix() {
        delete[] data;
    }

    int nrows() const { return rows; }
    int ncols() const { return cols; }

    double &operator()(int i, int j) {
        return data[i * cols + j];
    }

    const double &operator()(int i, int j) const {
        return data[i * cols + j];
    }
};

/*****************************************************
 *        MATRIX × DUALVECTOR  OPERATOR OVERLOAD
 *****************************************************/
DualVector operator*(const Matrix &M, const DualVector &v) {
    int r = M.nrows();
    int c = M.ncols();

    DualVector result(r);

    for (int i = 0; i < r; i++) {
        DualNumber sum(0, 0);
        for (int k = 0; k < c; k++) {
            sum = sum + (v[k] * M(i, k));  // scalar * dual
        }
        result[i] = sum;
    }

    return result;
}

/*****************************************************
 *                       MAIN
 *****************************************************/
int main() {
    // Build matrix M (3x2)
    Matrix M(3, 2);
    M(0,0) = 1;  M(0,1) = 2;
    M(1,0) = 3;  M(1,1) = 4;
    M(2,0) = 5;  M(2,1) = 6;

    // Build dual vector v (size 2)
    DualVector v(2);
    v[0] = DualNumber(10, 1); // 10 + 1ε
    v[1] = DualNumber(20, 2); // 20 + 2ε

    DualVector result = M * v;

    for (int i = 0; i < result.size(); i++) {
        std::cout << "row " << i << " = " << result[i] << "\n";
    }

    return 0;
}