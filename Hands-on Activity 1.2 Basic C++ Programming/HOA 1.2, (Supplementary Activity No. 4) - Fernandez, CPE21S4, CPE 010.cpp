#include <iostream>
#include <cmath>
using namespace std;

class Triangle {
private:
    double totalAngle, angleA, angleB, angleC;
    double sideA, sideB, sideC, s;

public:
    Triangle(double A, double B, double C, double a, double b, double c);
    void totalAngles(double A, double B, double C);
    const bool isTriangle();
    double compArea();
    double compPerimeter();
    string type();
};

Triangle::Triangle(double aA, double aB, double aC, double sA, double sB, double sC) {
    angleA = aA;
    angleB = aB;
    angleC = aC;
    totalAngle = aA + aB + aC;
    sideA = sA;
    sideB = sB;
    sideC = sC;
}

void Triangle::totalAngles(double aA, double aB, double aC) {
    totalAngle = aA + aB + aC;
}

const bool Triangle::isTriangle() {
    return (totalAngle == 180);
}

double Triangle::compArea() {
    s = (sideA + sideB + sideC) / 2;
    return (sqrt(s * (s - sideA) * (s - sideB) * (s - sideC)));
}

double Triangle::compPerimeter() {
    return (sideA + sideB + sideC);
}

string Triangle::type() {
    if (angleA < 90 && angleB < 90 && angleC < 90) {
        return "Acute triangle";
    } else if (angleA > 90 || angleB > 90 || angleC > 90) {
        return "Obtuse triangle";
    } else {
        return "Right triangle";
    }
}

int main() {
    Triangle gate(20, 50, 110, 7, 8, 9);

    if (gate.isTriangle()) {
        cout << "The shape is a triangle." << endl;
        cout << "The area of the triangle is " << gate.compArea() << endl;
        cout << "The perimeter of the triangle is " << gate.compPerimeter() << endl;
        cout << "The type of triangle is " << gate.type() << endl;
    } else {
        cout << "The shape is not a triangle." << endl;
    }

    return 0;
}
