#include <iostream>

class PointDecart {
    PointDecart(double a, double r_): alpha(a), r(r_) {};
    double get_angle() { return alpha; };
    double get_radius() { return r; };
    void set_angle(double a) { alpha = a; };
    void set_radius(double r_) { r = r_; };
    void out() { std::cout << "Полярные координаты. Радиус = " << r << ", угол = " << alpha; }
private:
    double alpha;
    double r;
};

class PointPolar {
    PointPolar(double x_, double y_): x(x_), y(y_) {};
    double get_x() { return x; };
    double get_y() { return y; };
    void set_x(double x_) { x = x_; };
    void set_y(double y_) { y = y_; };
    void out() { std::cout << "Декартовы координаты. X = " << x << ", Y = " << y; }
private:
    double x;
    double y;
};

int main()
{
    std::cout << "Hello World!\n";
}