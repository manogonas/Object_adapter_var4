#include <iostream>
#include <cmath>
const double PI = acos(-1.0);

class PointDecart { //Адаптировать к нему
public:
    PointDecart() {};
    virtual double get_x() { return 0; };
    virtual double get_y() { return 0; };
    virtual void set_x(double x_) {};
    virtual void set_y(double y_) {};
    virtual void out() {};
};

class PointPolar { //Адаптируемый класс
public:
    PointPolar(double f, double r_): fi(f), r(r_) {};
    double get_angle() { return fi; };
    double get_radius() { return r; };
    void set_angle(double f) { fi = f; };
    void set_radius(double r_) { r = r_; };
    void own_out() { std::cout << "Polar coordinates. Radius = " << r << ", angle = " << fi << std::endl; }
private:
    double fi;
    double r;
};

class ObjectPointPolarAdapter : public PointDecart {//Адаптер
public:
    ObjectPointPolarAdapter(PointPolar* adaptee_) { this->adaptee = adaptee_; };
    double get_x() { return (adaptee->get_radius() * (cos(adaptee->get_angle() * PI / 180))); };
    double get_y() { return (adaptee->get_radius() * (sin(adaptee->get_angle() * PI / 180))); };
    void set_x(double x_) {
        double y_ = ObjectPointPolarAdapter(adaptee).get_y();
        adaptee->set_angle(atan(y_ / x_)); adaptee->set_radius(sqrt((y_ * y_) + (x_ * x_)));
    };
    void set_y(double y_) {
        double x_ = ObjectPointPolarAdapter(adaptee).get_x();
        adaptee->set_angle(atan(y_ / x_)); adaptee->set_radius(sqrt((y_ * y_) + (x_ * x_)));
    };
    void out() {
        double x_ = ObjectPointPolarAdapter(adaptee).get_x();
        double y_ = ObjectPointPolarAdapter(adaptee).get_y();
        std::cout << "Cartesian coordinates. X = " << x_ << ", Y = " << y_ << std::endl;
    };
private:
    PointPolar* adaptee;
};

int main()
{
    PointPolar* polar = new PointPolar(90, 5);
    PointDecart* adapted = new ObjectPointPolarAdapter(polar);
    polar->own_out();
    adapted->out();
}