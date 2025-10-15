#ifndef FRACTION_HPP
#define FRACTION_HPP
#include <iostream>
using namespace std;
int gcd(int a, int b) {
    if(b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}
class fraction {
private:
    int num;
    int den;
public:
    fraction() {
        this->num = 0;
        this->den = 1;
    }
    fraction(int num, int den) {
        this->num = num;
        this->den = den;
    }
    void reduce() {
        int temp = gcd(num, den);
        num = num / temp;
        den = den / temp;
    }
    operator float() const {
        return float(num) / float(den);
    }
    void print() {
        cout << num << "/" << den;
    }
    fraction operator+(const fraction& f2) const {
        fraction f3(0, 0);
        int temp1, temp2;
        f3.den = lcm(this->den, f2.den);
        f3.num = this->num * (f3.den / this->den);
        f3.num += f2.num * (f3.den / f2.den);
        f3.reduce();
        return f3;
    }
    fraction operator-(const fraction& f2) const {
        fraction f3(0, 0);
        int temp1, temp2;
        f3.den = lcm(this->den, f2.den);
        f3.num = this->num * (f3.den / this->den);
        f3.num -= f2.num * (f3.den / f2.den);
        f3.reduce();
        return f3;
    }
    fraction operator*(const fraction& f2) const {
        fraction f3(0, 0);
        f3.num = this->num * f2.num;
        f3.den = this->den * f2.den;
        f3.reduce();
        return f3;
    }
    fraction operator/(const fraction& f2) const {
        fraction f3(0, 0);
        f3.num = this->num * f2.den;
        f3.den = this->den * f2.num;
        f3.reduce();
        return f3;
    }
    friend fraction operator-(const fraction& f1) {
        return fraction(-f1.num, f1.den);
    }
    bool operator==(const fraction& f2) const {
        return (this->num * f2.den == f2.num * this->den);
    }
    bool operator!=(const fraction& f2) const {
        return !(*this == f2);
    }
    bool operator<(const fraction& f2) const {
        if(this->den == f2.den) {
            return this->num < f2.num;
        } else {
            if(this->den * this->num < f2.den * f2.num) {
                return true;
            } else {
                return false;
            }
        }
    }
    bool operator<=(const fraction& f2) const {
        if(this->den == f2.den) {
            return this->num <= f2.num;
        } else {
            if(this->den * this->num <= f2.den * f2.num) {
                return true;
            } else {
                return false;
            }
        }
    }
    bool operator>(const fraction& f2) const {
        if(this->den == f2.den) {
            return this->num > f2.num;
        } else {
            if(this->den * this->num > f2.den * f2.num) {
                return true;
            } else {
                return false;
            }
        }
    }
    bool operator>=(const fraction& f2) const {
        if(this->den == f2.den) {
            return this->num >= f2.num;
        } else {
            if(this->den * this->num >= f2.den * f2.num) {
                return true;
            } else {
                return false;
            }
        }
    }
    friend ostream& operator<<(ostream& os, const fraction& f) {
        os << f.num << '/' << f.den;
        return os;
    }
    friend istream& operator>>(istream& is, fraction& f) {
        is >> f.num;
        is.ignore();
        is >> f.den;
        return is;
    }
};
#endif
//By Cartermue32 on Github
