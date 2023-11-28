#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#define _USE_MATH_DEFINES

// Class Complex with parameters real and imaginary parts
class Complex {
private:
    double RE;
    double IM;
public:
    // Constructor with parameters
    Complex(double real, double imaginary) : RE(real), IM(imaginary) {}

    // Constructor with one parameter
    Complex(double real) : RE(real), IM(0) {}

    // Copy constructor
    Complex(const Complex& other) : RE(other.RE), IM(other.IM) {}

    // Default constructor
    Complex() = default;

    // Overload = operator
    Complex& operator=(const Complex& other) {
        RE = other.RE;
        IM = other.IM;
        return *this;
    }

    // Destructor
    ~Complex() {}

    // Method of transformation of complex number from exponential form to standard form with real and imaginary parts
    void expToStd(double r, double phi) {
        double phi_rad = phi * M_PI / 180;
        RE = r * cos(phi_rad);
        IM = r * sin(phi_rad);
    }

    // Overload << operator
    friend std::ostream& operator<<(std::ostream& out, const Complex& complex) {
        if (complex.IM < 0) {
            out << complex.RE << " - " << -complex.IM << "i";
        }
        else {
            out << complex.RE << " + " << complex.IM << "i";
        }
        return out;
    }

    // Overload ++ operator for ++Complex
    Complex operator++(int) {
        Complex old = *this;
        RE++;
        return old;
    }

    // Overload ++ operator for Complex++
    Complex& operator++() {
        RE++;
        return *this;
    }

    friend Complex operator+(const Complex& one, const Complex& other);
    friend Complex operator-(const Complex& one, const Complex& other);
    friend Complex operator*(const Complex& one, const Complex& other);
    friend Complex operator/(const Complex& one, const Complex& other);
};

// Overload + operator for Complex + double or double + Complex
Complex operator+(const Complex& one, const Complex& other) {
    return Complex(one.RE + other.RE, one.IM + other.IM);
}

// Overload - operator for Complex - double or double - Complex
Complex operator-(const Complex& one, const Complex& other) {
    return Complex(one.RE - other.RE, one.IM - other.IM);
}

// Overload * operator for Complex * double or double * Complex
Complex operator*(const Complex& one, const Complex& other) {
    return Complex(one.RE * other.RE - one.IM * other.IM, one.RE * other.IM + one.IM * other.RE);
}

// Overload / operator for Complex / double or double / Complex
Complex operator/(const Complex& one, const Complex& other){
    double denominator = other.RE * other.RE + other.IM * other.IM;
    double real = (one.RE * other.RE + one.IM * other.IM) / denominator;
    double imaginary = (one.IM * other.RE - one.RE * other.IM) / denominator;
    return Complex(real, imaginary);
}

int main() {
    std::ifstream input("INPUT.txt");
    std::ofstream output("OUTPUT.txt");

    double a, b;
    input >> a >> b;
    Complex x(a, b);
    output << "x = " << x << std::endl;

    double c, d;
    input >> c >> d;
    Complex y(c, d);

    double e;
    input >> e;
    Complex w(e);
    output << "w = " << w << std::endl;

    double r, phi;
    input >> r >> phi;

    Complex z(x);
    output << "z = " << z << std::endl;

    output << "x + y = " << x + y << std::endl;
    output << "y + x = " << y + x << std::endl;
    output << "x - y = " << x - y << std::endl;
    output << "y - x = " << y - x << std::endl;
    output << "x * y = " << x * y << std::endl;
    output << "y * x = " << y * x << std::endl;
    output << "x / y = " << x / y << std::endl;
    output << "y / x = " << y / x << std::endl;
    output << "x + e = " << x + e << std::endl;
    output << "e + x = " << e + x << std::endl;
    output << "x - e = " << x - e << std::endl;
    output << "e - x = " << e - x << std::endl;
    output << "x * e = " << x * e << std::endl;
    output << "e * x = " << e * x << std::endl;
    output << "x / e = " << x / e << std::endl;
    output << "e / x = " << e / x << std::endl;

    z= x;
    output << "z = " << z << std::endl;

    z = e;
    output << "z = " << z << std::endl;

    output << "++x = " << ++x << std::endl;
    output << "y++ = " << y++ << std::endl;
    output << "y++ = " << y << std::endl;

    z.expToStd(r, phi);
    output << "z = " << z << std::endl;

    input.close();
    output.close();

    return 0;
}
