#include <iostream>
using namespace std;
class Complex
{
private:
    double re;
    double im;
    
public:
    Complex() : re(0), im(0) { cout << "Default constructor is working" << '\n'; };                     //The GREAT 4
    
    ~Complex() { cout << "Destructor is working"; };
    
    void operator= (const Complex &other) { re = other.re; im = other.im; cout << "работает операция присваивания "; };//
    
    Complex(Complex &other) { re = other.re; im = other.im; cout << "Copyconstructor is working"; };//Операция копирования
    
    Complex(double a, double b = 0) :re(a), im(b) { cout << "Constructor with parameters is working"; };
    
    
    
    Complex operator+(const Complex &other) {
        Complex tmp;
        tmp.re = this->re + other.re;
        tmp.im = this->im + other.im;
        return tmp;
    }
    Complex operator-(const Complex &other) {
        Complex tmp;
        tmp.re = this->re - other.re;
        tmp.im = this->im - other.im;
        return tmp;
    }
    Complex operator*(const Complex &other) {
        Complex tmp;
        tmp.re = (re * other.re) - (im * other.im);
        tmp.im = (re * other.im) + (im * other.re);
        return tmp;
    }
    Complex operator/(const Complex &other) {
        double div = (other.re * other.re) + (other.im * other.im);
        Complex tmp;
        tmp.re = (re * other.re) + (im * other.im);
        tmp.re = tmp.re / division;
        tmp.im = (im * other.re) - (re * other.im);
        tmp.im = tmp.im / div;
        return tmp;
    }
    friend ostream &operator<<(ostream &output, Complex &tmp) {
        output << tmp.re << '+' << tmp.im << 'i';
        return output;
    }
    
    friend istream &operator>>(istream &input, Complex &tmp) {
        input >> tmp.re;
        input.ignore();
        input >> tmp.im;
        input.ignore();
        return input;
    }
    bool operator==(const Complex &tmp) const {
        return (re == tmp.re) && (im == tmp.im);
    }
    
    bool operator!=(const Complex &tmp) {
        return !((re == tmp.re) && (im == tmp.im));
    }
    
};



int main() {
    setlocale(LC_ALL, "ru");
    
    Complex a(7, 9);
    Complex b(6, 8);
    Complex z;
    cout << endl;
    z = a * b;
    cout << endl;
    cout << z;
    
    system("pause");
    return 0;
}
