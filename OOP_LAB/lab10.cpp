#include <iostream>
using namespace std;

class Shape {
private:
    int base;
    int height;

public:
    virtual double calculate_area() = 0;

    void setBase(int b) {
        base = b;
    }

    void setHeight(int h) {
        height = h;
    }

    int getBase() {
        return base;
    }

    int getHeight() {
        return height;
    }
};

class Rectangle : protected Shape {
public:
    void setDimensions(int base, int height) {
        setBase(base);
        setHeight(height);
    }

    double calculate_area() {
        return getBase() * getHeight();
    }
};

class Triangle : protected Shape {
public:
    void setDimensions(int base, int height) {
        setBase(base);
        setHeight(height);
    }

    double calculate_area() {
        return (getBase() * getHeight()) / 2.0;
    }
};

int main() {
    Rectangle rect;
    Triangle tri;

    rect.setDimensions(15, 12);
    tri.setDimensions(25, 19);

    cout << "The area of the rectangle is: " << rect.calculate_area() << endl;
    cout << "The area of the triangle is: " << tri.calculate_area() << endl;

    return 0;
}
