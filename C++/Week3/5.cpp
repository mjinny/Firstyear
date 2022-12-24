#include <iostream>
using namespace std;
class Circle{
    double radius;
    double pi = 3.1415;

public:
    Circle(){
        radius = 0.0;
    }
    Circle(double r){
        radius = r;
    }
    void setRadius(){
        cin >> radius;
    }
    double getRadius(){
        return radius;
    }
    double getArea(){
        return pi * radius * radius;
    }
    double getDiameter(){
        return 2 * radius;
    }
    double getCircumference(){
        return 2 * pi * radius;
    }
};
int main(){
    cout << "Enter Radius of the circle: ";
    Circle circle(0);
    circle.setRadius();
    cout << "Area : " << circle.getArea() << endl;
    cout << "Diameter : " << circle.getDiameter() << endl;
    cout << "Circumference : " << circle.getCircumference() << endl;
    return 0;
}