#ifndef CARTESIEN_HPP
#define CARTESIEN_HPP

#include "point.hpp"

class Cartesien: public Point {
private:
    double x;
    double y;
 
public:
    Cartesien(double x = 0.0, double y = 0.0);
    Cartesien(Polaire& p);
    double getX() const;
    double getY() const;
    void setX(double x);
    void setY(double y);
    void afficher(std::ostream& o) const;
    void convertir(Point& p);
    void convertir(Cartesien& c) const;
    void convertir(Polaire& p) const;
};

 
#endif