#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>

class Cartesien;
class Polaire;
  
class Point {
private:
    double x;
    double y;

public:
    Point();
    virtual void afficher(std::ostream& o) const = 0;
    virtual void convertir(Cartesien& c) const = 0;
    virtual void convertir(Polaire& p) const = 0;
    friend std::ostream& operator<<(std::ostream& s, const Point& p);
};

#endif