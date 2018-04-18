/*Отрезок в декартовой системе координат (длина, из первого отрезка вычесть длину второго, к первому отрезку добавить длину второго, отрезок, умноженный на число)*/

#include <iostream>
#include <clocale>
#include <cmath>

using namespace std;

class Segment
{
private:
    double x1;
    double y1;
    double x2;
    double y2;
public:
    Segment() : x1(0), y1(0), x2(0), y2(0) { cout << "Работает конструктор по умолчанию" << '\n'; };
    
    ~Segment() { cout << "Работает деструктор"; };
    
    void operator= (const Segment &other) { x1 = other.x1; y1 = other.y1; x2 = other.x2; y2 = other.y2; cout << "работает операция присваивания "; };
    
    Segment(Segment &other) { x1 = other.x1; y1 = other.y1; x2 = other.x2; y2 = other.y2; cout << "Работает копиконструктор"; };
    
    Segment(double a, double b, double c, double d) :x1(a), y1(b), x2(c), y2(d) { cout << "Работает конструктор с параметрами"; };
    
    double operator+ (Segment &other) {
        double length1;
        double length2;
        double length;
        
        length1 = sqrt((this->x2 - this->x1)*(this->x2 - this->x1) + (this->y2 - this->y1)*(this->y2 - this->y1));
        length2 = sqrt((other.x2 - other.x1)*(other.x2 - other.x1) + (other.y2 - other.y1)*(other.y2 - other.y1));
        length = length1 + length2;
        return length;
    }
    double operator- (Segment &other) {
        double length1;
        double length2;
        double length;
        
        length1 = sqrt((this->x2 - this->x1)*(this->x2 - this->x1) + (this->y2 - this->y1)*(this->y2 - this->y1));
        length2 = sqrt((other.x2 - other.x1)*(other.x2 - other.x1) + (other.y2 - other.y1)*(other.y2 - other.y1));
        length = length1 - length2;
        return length;
    }
    Segment operator*(const Segment &other) {
        Segment tmp;
        tmp.x1 = x1 * other.x1;
        tmp.y1 = y1 * other.y1;
        tmp.x2 = x2 * other.x2;
        tmp.y2 = y2 * other.y2;
        return tmp;
    }
    
    friend ostream &operator<<(ostream &output, Segment &tmp) {
        output << tmp.x1 << ' ' << tmp.y1 << ' ' << tmp.x2 << ' ' << tmp.y2;
        return output;
    }
    
    friend istream &operator>>(istream &input, Segment &tmp) {
        input >> tmp.x1;
        input.ignore();
        input >> tmp.y1;
        input.ignore();
        input >> tmp.x2;
        input.ignore();
        input >> tmp.y2;
        input.ignore();
        return input;
    }
    bool operator==(const Segment &tmp) const {
        return (x1 == tmp.x1) && (y1 == tmp.y1) && (x2 == tmp.x2) && (y2 == tmp.y2);
    }
    
    bool operator!=(const Segment &tmp) {
        return !((x1 == tmp.x1) && (y1 == tmp.y1) && (x2 == tmp.x2) && (y2 == tmp.y2));
    }
    
};

int main() {
    setlocale(LC_ALL, "ru");
    
    Segment a(7, 9, 4, 6);
    Segment b(6, 8, 1, 20);
    double z;
    cout << endl;
    z = a + b;
    cout << endl;
    cout << a + b;
    
    system("pause");
    return 0;
}
