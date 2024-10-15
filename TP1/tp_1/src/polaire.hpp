#ifndef POLAIRE_HPP
#define POLAIRE_HPP

#include "point.hpp"
#include <iostream>

class Polaire: public Point {
private:
    double a;
    double d;
 
public:
    Polaire(double a = 0.0, double d = 0.0);
    Polaire(Cartesien c);
    double getAngle() const;
    double getDistance() const;
    void setAngle(double a);
    void setDistance(double d);
    void afficher(std::ostream& o) const;
    void convertir(Cartesien& c) const;
    void convertir(Polaire& p) const;
};


#endif