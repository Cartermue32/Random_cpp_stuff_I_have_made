#ifndef COMPLEX_HPP
#define COMPLEX_HPP
#include <iostream>
using namespace std;
class complex {
private:
    float real;
    float imaginary;
public:
    complex() {
        this->real = 0;
        this->imaginary = 0;
    }
    complex(float real, float imaginary) {
        this->real = real;
        this->imaginary = imaginary;
    }
    complex operator+(const complex& c1) const {
        return complex(this->real + c1.real, this->imaginary + c1.imaginary);
    }
    complex operator-(const complex& c1) const {
        return complex(this->real - c1.real, this->imaginary - c1.imaginary);
    }
    friend complex operator-(const complex& c1) {
        return complex(-c1.real, -c1.imaginary);
    }
    complex operator*(const int& n1) const {
        return complex(n1 * this->real, n1 * this->imaginary);
    }
    bool operator==(const complex& c2) const {
        return c2.real == this->real && c2.imaginary == this->imaginary;
    }
    friend ostream& operator<<(ostream& os, const complex& c1) {
        if(c1.imaginary >= 0) {
            cout << c1.real << " + i" << c1.imaginary;
        } else {
            cout << c1.real << " - i" << -c1.imaginary;
        }
        return os;
    }
};
#endif
//By Cartermue32 on Github
